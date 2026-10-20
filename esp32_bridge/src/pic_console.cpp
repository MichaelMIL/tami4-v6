#include "pic_console.h"

static HardwareSerial &PicSerial = Serial1;

static const CmdInfo CMDS[] = {
    // read-only
    {"VER", CmdCat::Read}, {"ST", CmdCat::Read}, {"GHT", CmdCat::Read}, {"GCT", CmdCat::Read},
    {"GDT", CmdCat::Read}, {"COT", CmdCat::Read}, {"GHS", CmdCat::Read}, {"GCS", CmdCat::Read},
    {"HTS", CmdCat::Read}, {"UVS", CmdCat::Read}, {"IVS", CmdCat::Read}, {"CVS", CmdCat::Read},
    {"HVS", CmdCat::Read}, {"CWC", CmdCat::Read}, {"GCH", CmdCat::Read}, {"TC", CmdCat::Read},
    {"AC", CmdCat::Read}, {"GP", CmdCat::Read}, {"GC", CmdCat::Read},
    {"LCL", CmdCat::Read, false, false, true}, {"GPL", CmdCat::Read, false, false, true},
    {"GCL", CmdCat::Read, false, false, true},
    // EEPROM writes
    {"SP", CmdCat::Eeprom}, {"RP", CmdCat::Eeprom}, {"SMN", CmdCat::Eeprom, true},
    {"SMX", CmdCat::Eeprom, true}, {"RC", CmdCat::Eeprom, true}, {"g", CmdCat::Eeprom, true},
    {"RPL", CmdCat::Eeprom, true, true, true}, {"RCL", CmdCat::Eeprom, true, true, true},
    // hardware actions
    {"DCW", CmdCat::Hardware}, {"DHW", CmdCat::Hardware}, {"STP", CmdCat::Hardware},
    {"CP0", CmdCat::Hardware}, {"CP1", CmdCat::Hardware}, {"EH1", CmdCat::Hardware},
    {"EH0", CmdCat::Hardware}, {"NM", CmdCat::Hardware}, {"SM", CmdCat::Hardware},
    {"PD", CmdCat::Hardware}, {"RS", CmdCat::Hardware}, {"XC", CmdCat::Hardware, true},
};

// v3.5.13 shell, table at ROM 0xFE1C. Only the read commands have been sent to the unit.
static const CmdInfo SHELL[] = {
    {"ls", CmdCat::Read}, {"temp", CmdCat::Read}, {"input", CmdCat::Read}, {"output", CmdCat::Read},
    {"hot", CmdCat::Hardware, true}, {"cold", CmdCat::Hardware, true}, {"mix", CmdCat::Hardware, true},
    {"ex", CmdCat::Hardware, true}, {"par", CmdCat::Read},  // par: added by the par/jug patch (stock = ERROR -123)
    {"settext", CmdCat::Eeprom},  // settext=TEXT: added by the logo-text patch (stock/par image = ERROR -123)
    {"ver", CmdCat::Read}, {"get_hwt_type", CmdCat::Read},
    {"get_errors_bitmap", CmdCat::Read}, {"get_wu", CmdCat::Read},
    {"restore_factory_settings", CmdCat::Eeprom, true, true}, {"set_language", CmdCat::Eeprom, true},
    {"set_shipping_mode", CmdCat::Eeprom, true}, {"set_production_mode", CmdCat::Eeprom, true},
    {"manual_press", CmdCat::Hardware, true}, {"testing_mode", CmdCat::Hardware, true},
    {"reset", CmdCat::Hardware, true},
};
static const CmdInfo OUTPUT_SET = {"output", CmdCat::Hardware, true};  // output=n,v
static const CmdInfo PAR_SET = {"par", CmdCat::Eeprom};  // par=i reads (read), par=i,v writes EEPROM

static const struct { int code; const char *name; } SHELL_ERRORS[] = {
    {-123, "unknown command"}, {-127, "wrong number of arguments or value out of range"},
};

static PicFw curFw = PicFw::V347;

static const struct { uint8_t code; const char *name; } FAULTS[] = {
    {0x81, "unknown command"}, {0x82, "rejected / UV lamp removed"}, {0x83, "compressor restart delay"},
    {0x84, "output on too long"}, {0x85, "bad argument"}, {0x87, "ADC near full scale"},
    {0x8A, "hot tank over-temperature"}, {0x8B, "UV lamp did not light"}, {0x8D, "sensor open"},
    {0x8F, "sensor short"}, {0x90, "UV fault / cold water abnormally warm"},
};

namespace pic {

void begin(int rxPin, int txPin) { PicSerial.begin(9600, SERIAL_8N1, rxPin, txPin); }

PicFw fw() { return curFw; }
const char *fwName(PicFw f) { return f == PicFw::V35 ? "3.5.13" : "3.47"; }
uint32_t baud() { return curFw == PicFw::V35 ? 38400 : 9600; }
size_t maxLine() { return curFw == PicFw::V35 ? 29 : 11; }

void setFw(PicFw f) {
  curFw = f;
  PicSerial.flush();
  PicSerial.updateBaudRate(baud());
  delay(20);
  if (f == PicFw::V35) {  // a bare CR clears any noise in the shell's line buffer
    PicSerial.print('\r');
    delay(300);
  }
  while (PicSerial.available()) PicSerial.read();
}

// 9600 first, on purpose: at that speed a v3.5.13 shell only sees garbage, which can never equal a command name
// (exact strcmp). Probing a v3.47 unit at 38400 instead could leave garbage in its line buffer that the next CR
// runs through the command hash, which can match a real (even destructive) command.
bool detect(String &version) {
  for (PicFw f : {PicFw::V347, PicFw::V35}) {
    setFw(f);
    Reply r = exchange(f == PicFw::V35 ? "ver" : "VER");
    version = "";
    for (auto &l : r.lines) version += (version.length() ? " " : "") + l;
    if (r.ok && version.indexOf("T6") >= 0) return true;
  }
  setFw(PicFw::V347);  // nothing answered: stay at the speed that is harmless for both
  version = "";
  return false;
}

uint8_t hash(const String &line) {
  if (line.startsWith("g")) return 0x67;
  int sp = line.indexOf(' ');
  String w = sp < 0 ? line : line.substring(0, sp);
  if (w.length() > 3) w = w.substring(0, 3);
  uint8_t h = 0;
  for (size_t i = 0; i < w.length(); i++) h ^= (uint8_t)(w[i] << i);
  char first = w.length() ? w[0] : 0;
  static const struct { uint8_t raw, mapped; char keep; } REMAP[] = {
      {0xD4, 0xD3, 'R'}, {0xFB, 0xFA, 'S'}, {0xF1, 0xF0, 'G'},
      {0xA9, 0xA7, 'S'}, {0xE1, 0xE0, 'G'}, {0x8D, 0x8C, 'G'},
  };
  for (auto &r : REMAP)
    if (h == r.raw && first != r.keep) h = r.mapped;
  return h;
}

// "cmd=a,b" -> word, argument count (the shell splits at '=' and then ',')
static String shellWord(const String &line, int &nargs) {
  int eq = line.indexOf('=');
  nargs = eq < 0 ? 0 : line.indexOf(',', eq) >= 0 ? 2 : 1;
  return eq < 0 ? line : line.substring(0, eq);
}

const CmdInfo *classify(const String &line) {
  if (curFw == PicFw::V35) {
    int nargs;
    String w = shellWord(line, nargs);
    for (auto &c : SHELL)
      if (w == c.name) return (w == "output" && nargs == 2) ? &OUTPUT_SET
                            : (w == "par" && nargs == 2) ? &PAR_SET
                            : &c;
    return nullptr;
  }
  uint8_t h = hash(line);
  for (auto &c : CMDS)
    if (hash(c.name) == h) return &c;
  return nullptr;
}

bool isStop(const String &line) {
  if (curFw == PicFw::V347) {
    const CmdInfo *c = classify(line);
    return c && !strcmp(c->name, "STP");
  }
  return line == "output=4,0" || line == "output=5,0" || line == "output=6,0";
}

const char *catName(const CmdInfo *c) {
  if (!c) return "unknown";
  switch (c->cat) {
    case CmdCat::Read: return "read";
    case CmdCat::Eeprom: return "eeprom";
    case CmdCat::Hardware: return "hardware";
    default: return "unknown";
  }
}

const char *faultName(uint8_t code) {
  for (auto &f : FAULTS)
    if (f.code == code) return f.name;
  return "?";
}

// Fault replies are raw bytes >= 0x80; make them readable.
static String describe(const String &l) {
  String out;
  for (size_t i = 0; i < l.length(); i++) {
    uint8_t b = l[i];
    if (b >= 0x80 || b < 0x20) {
      char buf[48];
      snprintf(buf, sizeof buf, "<0x%02X %s>", b, faultName(b));
      out += buf;
    } else {
      out += (char)b;
    }
  }
  return out;
}

// true once a complete "OK" line (both versions) or "ERROR -nnn" line (v3.5.13) follows the echo line
static bool replyDone(const String &raw) {
  String cur;
  int n = 0;
  for (size_t i = 0; i < raw.length(); i++) {
    char c = raw[i];
    if (c != '\r' && c != '\n') { cur += c; continue; }
    cur.trim();
    if (cur.length() && n++ > 0 && (cur == "OK" || cur.startsWith("ERROR -"))) return true;
    cur = "";
  }
  return false;
}

static Reply exchangeOnce(const String &line, bool &echoBad) {
  const CmdInfo *ci = classify(line);
  const uint32_t limit = (ci && ci->slow) ? 8000 : 2500;
  while (PicSerial.available()) PicSerial.read();
  PicSerial.print(line);
  PicSerial.print('\r');

  Reply r;
  uint32_t start = millis(), last = start;
  bool done = false;
  while (millis() - start < limit) {
    while (PicSerial.available()) {
      r.raw += (char)PicSerial.read();
      last = millis();
    }
    if (!done) done = replyDone(r.raw);
    uint32_t idle = millis() - last;
    if ((done && idle >= 150) || idle >= 900) break;
    delay(2);
  }

  // split into lines at CR or LF; keep 0x85 etc. (only spaces/tabs count as blank)
  String cur;
  std::vector<String> lines;
  auto flush = [&]() {
    bool blank = true;
    for (size_t i = 0; i < cur.length(); i++)
      if (cur[i] != ' ' && cur[i] != '\t') blank = false;
    if (!blank) lines.push_back(cur);
    cur = "";
  };
  for (size_t i = 0; i < r.raw.length(); i++) {
    if (r.raw[i] == '\n' || r.raw[i] == '\r') flush();
    else cur += r.raw[i];
  }
  flush();
  echoBad = false;
  if (!lines.empty()) {
    String first = lines.front();
    first.trim();
    if (first == line) lines.erase(lines.begin());
    else echoBad = true;
  }
  if (!lines.empty()) {
    String lastLine = lines.back();
    lastLine.trim();
    if (lastLine == "OK") {
      r.ok = true;
      lines.pop_back();
    }
  }
  if (!r.ok && lines.empty()) lines.push_back("(no reply)");
  for (size_t i = 0; i < lines.size(); i++) {
    String l = lines[i];
    if (curFw == PicFw::V35) {
      String t = l;
      t.trim();
      if (i == 0 && echoBad && !r.ok) {
        r.lines.push_back("(echo was '" + t + "': characters were lost on the line)");
        continue;
      }
      if (t.startsWith("ERROR "))
        for (auto &e : SHELL_ERRORS)
          if (t.substring(6).toInt() == e.code) t += String("  (") + e.name + ")";
      r.lines.push_back(t);
    } else {
      r.lines.push_back(describe(l));
    }
  }
  return r;
}

Reply exchange(const String &line) {
  bool echoBad;
  Reply r = exchangeOnce(line, echoBad);
  // v3.5.13 at 38400 sometimes drops a character ("ge_wu"); resend read commands once
  const CmdInfo *ci = classify(line);
  if (!r.ok && echoBad && curFw == PicFw::V35 && ci && ci->cat == CmdCat::Read) r = exchangeOnce(line, echoBad);
  return r;
}

}  // namespace pic
