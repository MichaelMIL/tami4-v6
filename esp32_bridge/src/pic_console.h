// PIC18F8621 service console: command classification and one-line exchanges over UART.
// Two firmware protocols:
//   v3.47   9600 baud, hashed 2-3 letter commands (../PIC18F8621_decompiled/serial_commands.md)
//   v3.5.13 38400 baud, lowercase text shell "cmd=a,b" (../v3.5.13/README.md)
#pragma once
#include <Arduino.h>
#include <vector>

enum class CmdCat : uint8_t { Read, Eeprom, Hardware, Unknown };
enum class PicFw : uint8_t { V347, V35 };

struct CmdInfo {
  const char *name;
  CmdCat cat;
  bool untested;  // reconstructed from the firmware but never verified on the unit
  bool bulk;      // RPL / RCL / restore_factory_settings: must be confirmed by typing the name
  bool slow;      // long multi-line reply
};

struct Reply {
  bool ok = false;               // last line was "OK"
  std::vector<String> lines;     // reply body (echo and OK stripped, fault bytes / error codes labelled)
  String raw;                    // everything received
};

namespace pic {
void begin(int rxPin, int txPin);  // starts at 9600 (v3.47)
void setFw(PicFw fw);              // switches the UART speed
PicFw fw();
const char *fwName(PicFw fw);
uint32_t baud();
size_t maxLine();
bool detect(String &version);      // probe VER at 9600, then ver at 38400; keeps the speed that answered

uint8_t hash(const String &line);             // v3.47 effective command hash, as the firmware computes it
const CmdInfo *classify(const String &line);  // nullptr: no known command (v3.47 hash / v3.5.13 exact name)
bool isStop(const String &line);              // STP (v3.47) or output=4|5|6,0 (v3.5.13 valves off)
const char *catName(const CmdInfo *c);
const char *faultName(uint8_t code);
Reply exchange(const String &line);
}  // namespace pic
