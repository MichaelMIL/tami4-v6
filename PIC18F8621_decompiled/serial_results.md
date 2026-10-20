# Live serial session (2026-10-18, adapter CH340 on /dev/ttyUSB0, 9600 8N1)

Raw log: `serial_dump_20261018_192713.txt`. Only read-only commands were sent.

## Hidden commands confirmed working
| Command | Result |
|---|---|
| `VER` | "T6 / 3.47V" |
| `LCL` | Help: lists 28 commands, PD first (PD RS NM SM ST GHT GCT DCW DHW STP CP0 CP1 EH1 EH0 TC AC GCS GHS CWC HTS UVS IVS CVS HVS GCH GDT COT g) |
| `GCL` | All 18 counters (name, value) |
| `GPL` | All 75 parameters: `index,name,min,max,value,default` (bytes printed signed, so -1 = 255, -56 = 200) |
| `GP <i>` | Parameter value; all 75 match GPL |
| `GC <i>` | Counter value; all 18 match GCL (FM ticked 61 to 63 during the run, a live minute counter) |
Not tested because they write EEPROM: SP, RP, RPL, SMN, SMX, RC, RCL, g. Also not tested: XC (it executes other commands).

## Unit state at the time
* ST: HEATER -115, COMPRESSOR -115, HOT SENSORS -115, COLD SENSORS -115 (0x8D = sensor open), UVLAMP -117 (0x8B = lamp not lit), valves 0.
* GHT/GCT/GDT/COT all -1 (open sensor). The board appears to be powered without its NTC sensors and UV lamp connected.
* GHS "Heating System - Normal", GCS "Cooling System - Delay", heater/UV/valves OFF, child protection not active.
* Counters and parameters match the EEPROM read exactly (e.g. CSS 34,706,271 s compressor, TBOIL 100, cold cut-out 9).

## New finding
* Parameter 0 is **FT** (EEPROM 0x000), a first-time/factory flag, currently 0. When non-zero at power-up the usage counters are
  cleared, and the heater power-up delay becomes 120 s instead of 30 s.
* GCL counter order (descriptor table): ... 11 CGT, 12 CMM, 13 CSS, 14 HSS ... (byte stats are listed among the 32-bit counters).

## Write commands tested (reversible)
| Command | Test | Result |
|---|---|---|
| `SP` | `SP 55,7` on WKUPMINUTE1 (was 0) | `GP 55` read 7: **confirmed** |
| `RP` | `RP 55` | `GP 55` read 0 (= default and original): **confirmed**, value restored |
Untested so far: SMN, SMX, RC, g, XC, RPL, RCL.
