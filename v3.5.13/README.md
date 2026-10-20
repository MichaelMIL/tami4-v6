# Firmware v3.5.13: changes from v3.47, and the new serial shell

File: `PIC18F8621-3.5b.hex`, which reports itself as **"T6 3.5.13 Feb 07 2019 17:37:44"**.
Same hardware and controller (PIC18F8621 water dispenser, C18 + Salvo RTOS) as v3.47. Analysis of v3.47 is in `../PIC18F8621_decompiled/`.

Status of this analysis: the serial shell is fully decoded and tested read-only on the unit. Changes were identified by comparing
strings, data tables and the UART/shell code. The v3.5.13 code is **not** fully named or decompiled. The Ghidra project in `ghidra/` holds
the first-pass functions only.

## 1. What changed from v3.47

### Build
* Rebuilt and relinked: almost every program byte differs, because code and data moved. Configuration words are identical (XT oscillator, no protection).
* Data tables that moved unchanged: icons, fonts, NTC thermistor tables, heater burst patterns, bitmaps.
  Pointer tables (parameters, words, menus, commands) were rebuilt because the strings moved.

### Serial service port
* **Baud rate is now 38,400** (was 9,600). The code sets BRG16 = 1 in BAUDCON2 with the same divisor (SPBRG2 = 25, BRGH = 1),
  which gives Fosc/(4 x 26). This is why a 9,600-baud terminal shows garbage.
* **The old command set is removed:** RS, NM, SM, ST, PD, GHT, GCT, DHW, DCW, HVS, CVS, the hidden GP/SP/GPL/GC… and their debug texts.
  It is replaced by a lowercase text shell (section 2).
* Line buffer is larger: 29 characters (was 11).

### Parameters (EEPROM settings): 77 instead of 75
| Change | Parameter | v3.47 (default, min, max) | v3.5.13 |
|---|---|---|---|
| **New** #75 | `SYSTEMCONFIG7` | n/a | 2, 0, 255 |
| **New** #76 | `PLASTICSLEEPMODESTARTHEATING` | n/a | 50, 45, 60 (deg C, for the plastic hot tank in sleep mode) |
| Changed | `TNORMALCOLDCUTOUT` | 10, 3, 20 | 10, **5**, 20 |
| Changed | `TDELTAHOTTOPNORMALCUTOUT` | 7, 5, 15 | **4, 0, 10** |
| Changed | `THOTCONTALLOWDISPENSE` | 85, 80, 90 | **0**, 80, 90 |
| Changed | `THEATERMAXON` | 9, 5, 20 | **20**, 5, 20 |
| Changed | `TMMIUPDATERATE` | 10, 1, 100 | **15**, 1, 100 |

All other parameters keep their order and values. New parameters are appended, so indexes 0-74 mean the same as in v3.47.

### New features (from new strings and words)
* **Hot tank type:** `HOT TANK TYPE` with options `PLASTIC` / `STAINLESS STEEL`. The firmware keeps a flag (RAM 0xEDF bit 0) that the shell
  reports as "Hot Tank Plastic" / "Stainless". The new `PLASTICSLEEPMODESTARTHEATING` parameter suggests the plastic tank uses a lower sleep temperature.
* **`PURIFIER`:** a new word, likely a new APPLICATION choice (not yet confirmed in the menu tables).
* `ACTIVE` / `INACTIVE` words (new settings shown as active/inactive).
* Jug size text changed: "PUT **5** LITER JUG UNDER THE SPOUT" (was 2 litres).
* Water-usage counter readable over serial (`get_wu`).
* Error bitmap readable over serial (`get_errors_bitmap`).

### Removed
* The old serial protocol and its texts (see above), the component/fault-variable table used by the old `ST` command, and the `FWU` counter name.
* Some UI words (e.g. `FRANCAIS`, `FILTER`).

## 2. The new serial shell

### What it is
A small line-based command interpreter for service and production use, on EUSART2 (pins RG1 = TX, RG2 = RX).
It replaces v3.47's hashed 2-3 letter commands with readable lowercase words, and adds production functions:
shipping/production mode, language, factory reset, testing mode, manual output control and simulated key presses.

### Connecting
* **38400 baud, 8N1, CR line ending.** Characters are echoed. Example: `picocom -b 38400 --omap crlf /dev/ttyUSB1`
* Send a bare Enter first to clear any noise. A stray character in front of a command makes it fail.
* Commands are lowercase and case-sensitive. `VER` fails, `ver` works.

### How it works internally
1. **Receive interrupt (0x7EB0):**
   * Each received byte is read from RCREG2. A receive overrun is cleared by toggling CREN.
   * While receiving is enabled (RAM 0x100 bit 0), the byte is echoed and stored in the line buffer at **RAM 0x11A**, up to 29 characters.
   * On CR, receiving is disabled and a semaphore wakes the shell task.
2. **Shell task (0x79B0, Salvo priority 5)** waits on that semaphore, then:
   * splits the line at **`=`** into command and arguments;
   * splits the arguments at **`,`** into up to two numbers (`atoi`, stored at RAM 0x13D and 0x13F, with the argument count at 0x141);
   * compares the command word against the **19-entry command table at ROM 0xFE1C** (`strcmp`, exact match);
   * jumps to the handler for that table index;
   * prints the result followed by `OK`, or `ERROR -123` (0x85) for an unknown command or a wrong number of arguments;
   * re-enables receiving.
3. Created unconditionally at boot by main (0xA238). It does not depend on any setting.

### Syntax
```
command
command=arg1
command=arg1,arg2
```

### Command reference
| # | Command | Arguments | What it does | Effect |
|---|---|---|---|---|
| 0 | `ls` | none | List all commands with their numbers | read |
| 1 | `temp` | none | Temperatures `HT, HB, CB` (hot top, hot bottom, cold bottom) in deg C; -1 = open sensor | read |
| 2 | `input` | none | Raw A2D values (HT, HB, CT, CB; 1023 = open), button state, inputs `UV_POS` (UV lamp present, RJ0), `UV_READY` (lamp lit, RJ1), `HEATER_FEEDBACK`, then all output states | read |
| 3 | `output` | none | List outputs: 0 UV_DRIVE, 1 FAN, 2 COMPRESSOR, 3 HEATER, 4 COLD_VALVE, 5 HOT_VALVE, 6 INLET_VALVE, 7 LCDBKLT | read |
| 3 | `output=n,v` | 2 | Switch output *n* on (1) / off (0) | **switches hardware** |
| 4 / 5 / 6 | `hot=…` / `cold=…` / `mix=…` | required | Dispense hot / cold / mixed water | **switches hardware** |
| 7 | `ex` | ? | Calls two routines (0xA322, 0xABFC) not yet identified | unknown |
| 8 | `ver` | none | Version and build date, plus hot tank type | read |
| 9 | `get_hwt_type` | none | Hot tank type: Plastic / Stainless | read |
| 10 | `get_errors_bitmap` | none | Active error numbers, comma separated | read |
| 11 | `get_wu` | none | Water usage counter | read |
| 12 | `restore_factory_settings` | none | Reset settings to factory defaults | **writes EEPROM** |
| 13 | `set_language=n` | 1 | Set display language | **writes EEPROM** |
| 14 | `set_shipping_mode=n` | 1 | Shipping mode on (1) / off (0). Shipping mode = first-installation flow at next power-up | **writes EEPROM** |
| 15 | `set_production_mode=n` | 1 | Production mode, then resets the controller | **writes EEPROM, resets** |
| 16 | `manual_press=k,t` | 2 | Simulate a key press (key number, duration) | **acts like a button press** |
| 17 | `testing_mode=n` | 1 | Enter (1) / leave (0) testing mode | **changes operating mode** |
| 18 | `reset` | none | Print OK, then reset the controller | **resets** |

Only the "read" commands have been sent to the unit so far.

### Example session (this unit, read-only)
```
ver           -> T6 / 3.5.13 Feb 07 2019 17:37:44 / OK
temp          -> HT= -1, HB= -1, CB= -1
input         -> A2D: HT=1023, HB=1023, CT=1023, CB=1023
                 Buttons:  110
                 Inputs: UV_POS=0, UV_READY=0, HEATER_FEEDBACK=1
                 Outputs: all 0
get_hwt_type  -> Hot Tank Plastic
get_errors_bitmap -> 6,21,
get_wu        -> Water Usage 10667
```
(Sensors read open because the board is on the bench without its NTCs and UV lamp.) Full log: `serial/shell_readonly_*.txt`.

## 3. Findings from the shell task decompile (0x79B0), added with GUI support

* **Error codes:** `ERROR -123` (0x85) = no command matched. `ERROR -127` (0x81) = wrong argument count or value out of range
  (the shell starts every command with 0x81 and clears it only on success). Commands that check arguments do nothing on error.
* **Argument checks:** `hot` / `cold` / `mix` need at least one argument (stored at RAM 0x10A; meaning not decoded). `output` switches only
  with exactly 2 arguments, otherwise it lists. `set_language` needs n = 0-7 and writes bits 0x38 of SYSTEMCONFIG2 (EEPROM 0x2B).
  `set_shipping_mode` / `set_production_mode` / `testing_mode` need exactly 1, `manual_press` exactly 2 (k = 0-6, t > 0).
  Read commands ignore arguments.
* **Resets:** `set_shipping_mode` and `set_production_mode` reset the controller afterwards (same path as `reset`).
* **Config mirrors in RAM** (loaded at boot by 0xA05E): 0xEDA SYSTEMCONFIG (0x25), 0xEDB SYSTEMCONFIG2 (0x2B), 0xEDC SYSTEMCONFIG3 (0x2C),
  0xEDD SYSTEMCONFIG4 (0x3A), 0xEDE SYSTEMCONFIG5 (0x41), 0xEDF SYSTEMCONFIG6 (0x45), 0xEE0 SYSTEMCONFIG7 (0x4B).
  * Shipping mode = SYSTEMCONFIG4 bit 0 (the v3.47 "installation pending" bit).
  * Production mode = SYSTEMCONFIG3 bit 0x02. When it is set (or the factory jumper is fitted), boot forces SYSTEMCONFIG |= 0xBF,
    SYSTEMCONFIG2 = 0x40, SYSTEMCONFIG3 = (x & 0x46) | 0x44, SYSTEMCONFIG4 = 0xE7, SYSTEMCONFIG7 |= 1.
  * Hot tank type (`get_hwt_type`, "RAM 0xEDF bit 0" above) = SYSTEMCONFIG6 bit 0.
  * `testing_mode=1` clears SYSTEMCONFIG4 bits 0x26 in RAM; `testing_mode=0` reloads it from EEPROM.
* `get_errors_bitmap` prints the numbers (1-27) of the set bits of a 32-bit error word.
* There is **no dispense-stop command**. `serial_gui.py` and the ESP bridge implement STOP as `output=5,0`, `output=4,0`, `output=6,0`.

## 4. Tools

* `../PIC18F8621_decompiled/serial_gui.py` auto-detects this firmware (probes 9600, then 38400) and offers Status, Controls, Setup,
  a Parameters reference (v3.47 table + the changes above, from `parameter_info.json` → `versions`) and the raw console.
* `../esp32_bridge/` (1.1.0) does the same over Wi-Fi.

## 5. Open points
* Decode `ex`, the meaning of error numbers (6, 21, …), the `SYSTEMCONFIG7` bits, and where `PURIFIER` appears in the menus.
* Confirm the new EEPROM layout for 77 parameters (min/max blocks and counters may have moved).
* Full naming and decompilation of v3.5.13 (only the first Ghidra pass exists).

## 6. Patch images (added features)

Besides stock `PIC18F8621-3.5b.hex`, this folder holds patched images that add service features
**without touching EEPROM, config words, or the reset/interrupt vectors** (all byte-identical to stock;
every Intel-HEX checksum valid). Build + verify tooling is in `patch_tools/` (a self-built PIC18
assembler/disassembler/emulator — see that folder and `PARAM_SHELL_PATCH.md`).

| Image | Adds | Doc |
|---|---|---|
| **`PIC18F8621-3.5.13-par-settext.hex`** | **The current deliverable.** `par` (read/write any parameter) + bulk `par` (read all) + `settext` (two-row idle text, replaces the Strauss Water logo) + the "JUG WATER QTY" menu item (×100 jug editor) | `PAR_SETTEXT_PATCH.md` |
| `PIC18F8621-3.5.13-par-jug.hex` | `par` + the jug menu item (no settext) | `JUG_MENU_PATCH.md` |
| `PIC18F8621-3.5.13-logotext.hex` | `settext` only (logo replacement) | `LOGOTEXT_PATCH.md` |
| `PIC18F8621-3.5.13-par-patch.hex` | `par` only (earliest) | `PARAM_SHELL_PATCH.md` |
| `PIC18F8621-3.5.13-jug1000.hex` | ×100 jug display fix only | `JUG1000_PATCH.md` |

Flash **one** of these (not several). Keep `PIC18F8621-3.5b.hex` ready to restore.

### `par` — read/write parameters over the shell
* `par` → prints **all** 77 parameter values (one per line), then `OK`.
* `par=i` → read parameter *i*. `par=i,v` → write *i*=*v*.
* Added by relocating the 19-entry command table to ROM `0xFF5E` and growing it to 21 (`par`, `settext`);
  the match-count (`0x8414`) and the `ls` print-count (`0x7B2E`) constants were both bumped to 21.
* **`par` writes are NOT range-checked by the firmware** (no room alongside the other handlers). The
  web UI warns on out-of-range; raw serial writes are unchecked — stay within each param's min/max (`PARAMETERS.md`).

### `settext` — custom idle text (two rows)
* `settext=TEXT` stores TEXT in free EEPROM (`0x130+`); the idle screen draws it where the
  "Strauss Water" logo was. `settext=` (empty) blanks it.
* The brand draw at `0xF67E` (callers `0x431C` idle, `0xAE28` sleep) is repointed to a new text-draw
  routine in the reclaimed logo bitmap/body space. Font = the built-in 5×8 at `0x6C88`, which is
  **uppercase-only** (the ESP uppercases before sending; lowercase sent raw renders as garbage).
* A `|` (0x7C) in the text is a **row break**: the draw drops 2 LCD pages (16 px) and resets the column.
  So `settext=GOOD|MORNING` shows "GOOD" over "MORNING". (ESP web UI: two line fields joined with `|`.)
* Verified in the emulator (`patch_tools/` + `/tmp/render_logo.py` harness): renders both rows correctly.

The `ex` shell slot (stock index 7, an unidentified call) is unchanged in `par-settext`; the earlier
`par-jug` image instead reused that slot. See the per-image `*_PATCH.md` for exact byte changes.
