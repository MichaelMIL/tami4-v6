// ESP32 Wi-Fi bridge for the PIC18F8621 water-dispenser service console.
// Web UI + JSON API over the EUSART2 console, home Wi-Fi with AP fallback, ArduinoOTA and web OTA.
#include <Arduino.h>
#include <ArduinoOTA.h>
#include <DNSServer.h>
#include <ESPmDNS.h>
#include <Preferences.h>
#include <Update.h>
#include <WebServer.h>
#include <WiFi.h>
#include <time.h>

#include "pic_console.h"

extern const char index_html_start[] asm("_binary_web_index_html_start");
extern const char baseline_gpl_start[] asm("_binary_embed_baseline_GPL_txt_start");
extern const char baseline_gcl_start[] asm("_binary_embed_baseline_GCL_txt_start");
extern const char param_info_start[] asm("_binary_embed_param_info_json_start");

// ---------------------------------------------------------------- settings (NVS)

struct Settings {
  String ssid, wpass;        // home Wi-Fi
  String host;               // mDNS / OTA hostname
  String webUser, webPass;   // HTTP basic auth
  String apPass, otaPass;
  String tz;                 // POSIX TZ string
  bool apAlways;             // keep the AP up even when connected to home Wi-Fi
  bool allowEeprom;          // allow SP SMN SMX RP RPL RC RCL g / v3.5.13 restore_factory_settings set_* par=i,v
  bool allowHw;              // allow DCW DHW CP* EH* NM SM PD RS XC / output=n,v hot cold mix manual_press
                             // testing_mode reset ex (STP and v3.5.13 valves-off are always allowed)
  String picFw;              // "auto", "3.47" or "3.5.13"
} cfg;

static Preferences prefs;

static void loadSettings() {
  prefs.begin("bridge", true);
  cfg.ssid = prefs.getString("ssid", DEFAULT_WIFI_SSID);
  cfg.wpass = prefs.getString("wpass", DEFAULT_WIFI_PASS);
  cfg.host = prefs.getString("host", "picservice");
  cfg.webUser = prefs.getString("wuser", DEFAULT_WEB_USER);
  cfg.webPass = prefs.getString("wweb", DEFAULT_WEB_PASS);
  cfg.apPass = prefs.getString("apass", DEFAULT_AP_PASS);
  cfg.otaPass = prefs.getString("opass", DEFAULT_OTA_PASS);
  cfg.tz = prefs.getString("tz", "UTC0");
  cfg.apAlways = prefs.getBool("apalw", false);
  cfg.allowEeprom = prefs.getBool("aeep", false);
  cfg.allowHw = prefs.getBool("ahw", false);
  cfg.picFw = prefs.getString("picfw", "auto");
  prefs.end();
}

static void saveSettings() {
  prefs.begin("bridge", false);
  prefs.putString("ssid", cfg.ssid);
  prefs.putString("wpass", cfg.wpass);
  prefs.putString("host", cfg.host);
  prefs.putString("wuser", cfg.webUser);
  prefs.putString("wweb", cfg.webPass);
  prefs.putString("apass", cfg.apPass);
  prefs.putString("opass", cfg.otaPass);
  prefs.putString("tz", cfg.tz);
  prefs.putBool("apalw", cfg.apAlways);
  prefs.putBool("aeep", cfg.allowEeprom);
  prefs.putBool("ahw", cfg.allowHw);
  prefs.putString("picfw", cfg.picFw);
  prefs.end();
}

// Baselines (GPL / GCL text) live in NVS; the pre-test dumps from the PC are compiled in as the default.
static String loadBaseline(const char *key, const char *fallback) {
  prefs.begin("baseline", true);
  String s = prefs.getString(key, fallback);
  prefs.end();
  return s;
}

// ---------------------------------------------------------------- exchange log (RAM ring)

static String logBuf;
static constexpr size_t LOG_MAX = 16 * 1024;

static String stamp() {
  time_t now = time(nullptr);
  char buf[32];
  if (now > 1700000000) {
    struct tm tm;
    localtime_r(&now, &tm);
    strftime(buf, sizeof buf, "%Y-%m-%d %H:%M:%S", &tm);
  } else {
    snprintf(buf, sizeof buf, "+%lus", (unsigned long)(millis() / 1000));
  }
  return buf;
}

static void logLine(const String &s) {
  logBuf += s;
  if (logBuf.length() > LOG_MAX) {
    int cut = logBuf.indexOf('\n', logBuf.length() - LOG_MAX * 3 / 4);
    logBuf.remove(0, cut < 0 ? logBuf.length() - LOG_MAX * 3 / 4 : cut + 1);
  }
  Serial.print(s);
}

// ---------------------------------------------------------------- Wi-Fi

static WebServer server(80);
static DNSServer dns;
static bool apOn = false;
static uint32_t staLostAt = 0;
static bool rebootPending = false;

static String apSsid() {
  uint8_t mac[6];
  WiFi.macAddress(mac);
  char buf[24];
  snprintf(buf, sizeof buf, "PIC-Service-%02X%02X", mac[4], mac[5]);
  return buf;
}

static void startAp() {
  if (apOn) return;
  WiFi.mode(cfg.ssid.length() ? WIFI_AP_STA : WIFI_AP);
  WiFi.softAP(apSsid().c_str(), cfg.apPass.c_str());
  dns.start(53, "*", WiFi.softAPIP());  // captive portal: every name resolves to us
  apOn = true;
  logLine(stamp() + " AP " + apSsid() + " up at " + WiFi.softAPIP().toString() + "\n");
}

static void stopAp() {
  if (!apOn) return;
  dns.stop();
  WiFi.softAPdisconnect(true);
  WiFi.mode(WIFI_STA);
  apOn = false;
  logLine(stamp() + " AP off (home Wi-Fi connected)\n");
}

static void startWifi() {
  WiFi.persistent(false);
  WiFi.setHostname(cfg.host.c_str());
  if (cfg.ssid.length()) {
    WiFi.mode(cfg.apAlways ? WIFI_AP_STA : WIFI_STA);
    WiFi.setAutoReconnect(true);
    WiFi.begin(cfg.ssid.c_str(), cfg.wpass.c_str());
    uint32_t t0 = millis();
    while (WiFi.status() != WL_CONNECTED && millis() - t0 < 15000) delay(200);
  }
  if (WiFi.status() == WL_CONNECTED) {
    logLine(stamp() + " Wi-Fi " + cfg.ssid + " " + WiFi.localIP().toString() + "\n");
    configTzTime(cfg.tz.c_str(), "pool.ntp.org", "time.google.com");
  }
  if (cfg.apAlways || WiFi.status() != WL_CONNECTED) startAp();
}

// AP comes up when home Wi-Fi is lost for 30 s, and goes away again once it is back (unless apAlways).
static void wifiTick() {
  bool sta = WiFi.status() == WL_CONNECTED;
  if (sta) {
    staLostAt = 0;
    if (apOn && !cfg.apAlways && WiFi.softAPgetStationNum() == 0) stopAp();
  } else if (!apOn) {
    if (!staLostAt) staLostAt = millis();
    if (millis() - staLostAt > 30000) startAp();
  }
}

// ---------------------------------------------------------------- PIC firmware / protocol

static String picVer;          // version lines from the last detection
static bool picDetected = false;

static void applyPicFw() {
  if (cfg.picFw == "auto") {
    picDetected = pic::detect(picVer);
    logLine(stamp() + " PIC firmware: " + (picDetected ? String(pic::fwName(pic::fw())) + " (" + picVer + ")"
                                                         : String("no reply at 9600 or 38400; using 3.47 speed")) + "\n");
  } else {
    pic::setFw(cfg.picFw == "3.5.13" ? PicFw::V35 : PicFw::V347);
    picDetected = false;
    picVer = "";
    logLine(stamp() + " PIC firmware set to " + cfg.picFw + "\n");
  }
}

// ---------------------------------------------------------------- HTTP helpers

static String jsonEsc(const String &s) {
  String o;
  o.reserve(s.length() + 8);
  for (size_t i = 0; i < s.length(); i++) {
    uint8_t c = s[i];
    if (c == '"' || c == '\\') { o += '\\'; o += (char)c; }
    else if (c == '\n') o += "\\n";
    else if (c == '\r') o += "\\r";
    else if (c < 0x20 || c >= 0x7F) { char b[8]; snprintf(b, sizeof b, "\\u%04x", c); o += b; }
    else o += (char)c;
  }
  return o;
}

static String q(const String &s) { return "\"" + jsonEsc(s) + "\""; }
static const char *b(bool v) { return v ? "true" : "false"; }

static bool auth() {
  if (server.authenticate(cfg.webUser.c_str(), cfg.webPass.c_str())) return true;
  server.requestAuthentication(BASIC_AUTH, "PIC service console");
  return false;
}

static void sendJson(int code, const String &body) {
  server.sendHeader("Cache-Control", "no-store");
  server.send(code, "application/json", body);
}

static void sendError(int code, const String &msg) { sendJson(code, "{\"error\":" + q(msg) + "}"); }

// ---------------------------------------------------------------- API handlers

static void handleCmd() {
  if (!auth()) return;
  String line = server.arg("line");
  String confirm = server.arg("confirm");
  if (!line.length()) return sendError(400, "empty command");
  if (line.length() > pic::maxLine())
    return sendError(400, "line longer than " + String(pic::maxLine()) + " characters");
  for (size_t i = 0; i < line.length(); i++)
    if ((uint8_t)line[i] < 0x20 || (uint8_t)line[i] > 0x7E) return sendError(400, "printable ASCII only");

  const CmdInfo *ci = pic::classify(line);
  // v3.5.13 compares names exactly, so an unknown word runs nothing (ERROR -123)
  bool harmless = !ci && pic::fw() == PicFw::V35;
  if (!pic::isStop(line) && !harmless && (!ci || ci->cat != CmdCat::Read)) {
    // server-side enforcement; the UI asks the user first and then sends confirm
    if (ci && ci->cat == CmdCat::Eeprom && !cfg.allowEeprom)
      return sendError(403, "EEPROM writes are disabled (Settings)");
    if ((!ci || ci->cat == CmdCat::Hardware) && !cfg.allowHw)
      return sendError(403, ci ? "hardware actions are disabled (Settings)"
                               : "unknown command hash; enable hardware actions to send raw words");
    if (ci && ci->bulk ? confirm != ci->name : confirm != "1")
      return sendError(428, String("confirmation required") + (ci && ci->bulk ? ": type " + String(ci->name) : ""));
  }

  digitalWrite(LED_PIN, HIGH);
  Reply r = pic::exchange(line);
  digitalWrite(LED_PIN, LOW);

  String t = stamp() + " >>> " + line + "\n";
  for (auto &l : r.lines) t += "    " + l + "\n";
  t += r.ok ? "    OK\n" : "    ERR\n";
  logLine(t);

  String out = "{\"line\":" + q(line) + ",\"fw\":" + q(pic::fwName(pic::fw())) + ",\"cmd\":" + (ci ? q(ci->name) : "null") +
               ",\"cat\":" + q(pic::catName(ci)) + ",\"status\":" + q(r.ok ? "OK" : "ERR") + ",\"lines\":[";
  for (size_t i = 0; i < r.lines.size(); i++) out += (i ? "," : "") + q(r.lines[i]);
  out += "]}";
  sendJson(200, out);
}

static void handleInfo() {
  if (!auth()) return;
  bool sta = WiFi.status() == WL_CONNECTED;
  String o = "{\"fw\":" + q(FW_VERSION) + ",\"chip\":" + q(ESP.getChipModel()) +
             ",\"uptime\":" + String(millis() / 1000) + ",\"heap\":" + String(ESP.getFreeHeap()) +
             ",\"time\":" + q(stamp()) + ",\"host\":" + q(cfg.host) +
             ",\"sta\":{\"ssid\":" + q(cfg.ssid) + ",\"connected\":" + b(sta) +
             ",\"ip\":" + q(sta ? WiFi.localIP().toString() : "") + ",\"rssi\":" + String(sta ? WiFi.RSSI() : 0) +
             "},\"ap\":{\"on\":" + b(apOn) + ",\"ssid\":" + q(apSsid()) + ",\"ip\":" + q(WiFi.softAPIP().toString()) +
             ",\"clients\":" + String(apOn ? WiFi.softAPgetStationNum() : 0) +
             "},\"pins\":{\"rx\":" + String(PIC_RX_PIN) + ",\"tx\":" + String(PIC_TX_PIN) +
             "},\"pic\":{\"fw\":" + q(pic::fwName(pic::fw())) + ",\"mode\":" + q(cfg.picFw) +
             ",\"baud\":" + String(pic::baud()) + ",\"maxLine\":" + String(pic::maxLine()) +
             ",\"detected\":" + b(picDetected) + ",\"ver\":" + q(picVer) +
             "},\"settings\":{\"apAlways\":" + b(cfg.apAlways) + ",\"allowEeprom\":" + b(cfg.allowEeprom) +
             ",\"allowHw\":" + b(cfg.allowHw) + ",\"tz\":" + q(cfg.tz) + ",\"webUser\":" + q(cfg.webUser) + "}}";
  sendJson(200, o);
}

static void handleSettings() {
  if (!auth()) return;
  auto has = [](const char *k) { return server.hasArg(k); };
  bool wifiChanged = false;
  if (has("ssid") && server.arg("ssid") != cfg.ssid) { cfg.ssid = server.arg("ssid"); wifiChanged = true; }
  if (has("wpass") && server.arg("wpass").length()) { cfg.wpass = server.arg("wpass"); wifiChanged = true; }
  if (has("clearwpass")) { cfg.wpass = ""; wifiChanged = true; }
  if (has("host") && server.arg("host").length()) cfg.host = server.arg("host");
  if (has("tz") && server.arg("tz").length()) cfg.tz = server.arg("tz");
  if (has("webUser") && server.arg("webUser").length()) cfg.webUser = server.arg("webUser");
  if (has("webPass") && server.arg("webPass").length()) cfg.webPass = server.arg("webPass");
  if (has("otaPass") && server.arg("otaPass").length()) cfg.otaPass = server.arg("otaPass");
  if (has("apPass") && server.arg("apPass").length()) {
    if (server.arg("apPass").length() < 8) return sendError(400, "AP password needs at least 8 characters");
    cfg.apPass = server.arg("apPass");
  }
  if (has("apAlways")) cfg.apAlways = server.arg("apAlways") == "1";
  if (has("allowEeprom")) cfg.allowEeprom = server.arg("allowEeprom") == "1";
  if (has("allowHw")) cfg.allowHw = server.arg("allowHw") == "1";
  saveSettings();
  logLine(stamp() + " settings saved\n");
  sendJson(200, String("{\"saved\":true,\"rebootSuggested\":") + b(wifiChanged) + "}");
}

// fw=auto (detect now) | 3.47 | 3.5.13; saved in NVS
static void handlePicFw() {
  if (!auth()) return;
  String f = server.arg("fw");
  if (f != "auto" && f != "3.47" && f != "3.5.13") return sendError(400, "fw must be auto, 3.47 or 3.5.13");
  cfg.picFw = f;
  saveSettings();
  digitalWrite(LED_PIN, HIGH);
  applyPicFw();
  digitalWrite(LED_PIN, LOW);
  sendJson(200, "{\"fw\":" + q(pic::fwName(pic::fw())) + ",\"mode\":" + q(cfg.picFw) +
                    ",\"detected\":" + b(picDetected) + ",\"ver\":" + q(picVer) + "}");
}

static void handleScan() {
  if (!auth()) return;
  int n = WiFi.scanNetworks();
  String o = "[";
  for (int i = 0; i < n; i++)
    o += String(i ? "," : "") + "{\"ssid\":" + q(WiFi.SSID(i)) + ",\"rssi\":" + String(WiFi.RSSI(i)) +
         ",\"open\":" + b(WiFi.encryptionType(i) == WIFI_AUTH_OPEN) + "}";
  WiFi.scanDelete();
  sendJson(200, o + "]");
}

static void handleBaselineGet() {
  if (!auth()) return;
  sendJson(200, "{\"gpl\":" + q(loadBaseline("gpl", baseline_gpl_start)) +
                    ",\"gcl\":" + q(loadBaseline("gcl", baseline_gcl_start)) + "}");
}

static void handleBaselineSave() {
  if (!auth()) return;
  prefs.begin("baseline", false);
  if (server.arg("reset") == "1") {
    prefs.clear();
  } else {
    if (server.hasArg("gpl")) prefs.putString("gpl", server.arg("gpl"));
    if (server.hasArg("gcl")) prefs.putString("gcl", server.arg("gcl"));
  }
  prefs.end();
  sendJson(200, "{\"saved\":true}");
}

static void handleUpdateDone() {
  if (!auth()) return;
  bool ok = !Update.hasError();
  sendJson(ok ? 200 : 500, ok ? "{\"ok\":true}" : "{\"error\":" + q(Update.errorString()) + "}");
  if (ok) rebootPending = true;
}

static void handleUpdateUpload() {
  if (!server.authenticate(cfg.webUser.c_str(), cfg.webPass.c_str())) return;
  HTTPUpload &up = server.upload();
  if (up.status == UPLOAD_FILE_START) {
    logLine(stamp() + " web OTA: " + up.filename + "\n");
    Update.begin(UPDATE_SIZE_UNKNOWN);
  } else if (up.status == UPLOAD_FILE_WRITE) {
    Update.write(up.buf, up.currentSize);
  } else if (up.status == UPLOAD_FILE_END) {
    Update.end(true);
    logLine(stamp() + " web OTA: " + String(up.totalSize) + " bytes, " +
            (Update.hasError() ? Update.errorString() : "ok") + "\n");
  } else if (up.status == UPLOAD_FILE_ABORTED) {
    Update.abort();
  }
}

static void setupWeb() {
  server.on("/", HTTP_GET, [] {
    if (!auth()) return;
    server.send_P(200, "text/html", index_html_start);
  });
  server.on("/api/paraminfo", HTTP_GET, [] {  // parameter / counter explanations
    if (!auth()) return;
    server.send_P(200, "application/json", param_info_start);
  });
  server.on("/api/cmd", HTTP_POST, handleCmd);
  server.on("/api/info", HTTP_GET, handleInfo);
  server.on("/api/settings", HTTP_POST, handleSettings);
  server.on("/api/scan", HTTP_GET, handleScan);
  server.on("/api/picfw", HTTP_POST, handlePicFw);
  server.on("/api/baseline", HTTP_GET, handleBaselineGet);
  server.on("/api/baseline", HTTP_POST, handleBaselineSave);
  server.on("/api/log", HTTP_GET, [] {
    if (!auth()) return;
    server.send(200, "text/plain; charset=utf-8", logBuf);
  });
  server.on("/api/log/clear", HTTP_POST, [] {
    if (!auth()) return;
    logBuf = "";
    sendJson(200, "{\"ok\":true}");
  });
  server.on("/api/reboot", HTTP_POST, [] {
    if (!auth()) return;
    sendJson(200, "{\"ok\":true}");
    rebootPending = true;
  });
  server.on("/update", HTTP_POST, handleUpdateDone, handleUpdateUpload);
  server.onNotFound([] {  // captive-portal probes land here when in AP mode
    if (apOn) {
      server.sendHeader("Location", "http://" + WiFi.softAPIP().toString() + "/");
      server.send(302, "text/plain", "");
    } else {
      server.send(404, "text/plain", "not found");
    }
  });
  server.begin();
}

static void setupOta() {
  ArduinoOTA.setHostname(cfg.host.c_str());
  ArduinoOTA.setPassword(cfg.otaPass.c_str());
  ArduinoOTA.onStart([] { logLine(stamp() + " ArduinoOTA start\n"); });
  ArduinoOTA.onEnd([] { logLine(stamp() + " ArduinoOTA done\n"); });
  ArduinoOTA.onError([](ota_error_t e) { logLine(stamp() + " ArduinoOTA error " + String(e) + "\n"); });
  ArduinoOTA.begin();
}

// ---------------------------------------------------------------- main

void setup() {
  Serial.begin(115200);
  pinMode(LED_PIN, OUTPUT);
  digitalWrite(LED_PIN, LOW);
  pic::begin(PIC_RX_PIN, PIC_TX_PIN);
  loadSettings();
  logLine(stamp() + " PIC service bridge " FW_VERSION " starting\n");
  applyPicFw();
  startWifi();
  MDNS.begin(cfg.host.c_str());
  MDNS.addService("http", "tcp", 80);
  setupOta();  // ArduinoOTA also registers the arduino OTA service with mDNS
  setupWeb();
}

void loop() {
  server.handleClient();
  ArduinoOTA.handle();
  if (apOn) dns.processNextRequest();

  static uint32_t lastTick = 0;
  if (millis() - lastTick > 1000) {
    lastTick = millis();
    wifiTick();
    if (!WiFi.isConnected() && apOn) digitalWrite(LED_PIN, (millis() / 1000) & 1);  // blink: AP only
  }
  if (rebootPending) {
    delay(500);
    ESP.restart();
  }
}
