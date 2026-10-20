# PIC18F8621 water dispenser firmware: reverse engineering

> **Note (2026-10-20):** this document covers firmware **v3.47**. The unit now runs **v3.5.13**, and the
> active work is firmware patching + the ESP bridge. For current state and the patch images read
> **`../AGENT_README.md`** (top) and **`../v3.5.13/README.md`**. v3.47 high-address addresses here do **not**
> match the v3.5.13 image.


**Device:** hot/cold (point-of-use) water dispenser controller. Compressor-cooled cold tank, burst-fired heater in a hot tank,
UV sterilising lamp, filter and UV-lamp presence switches, 128x64 graphic LCD, 7-key keypad, buzzer, serial service console.
**Firmware:** version **3.47** ("T6 3.47V" on the diagnostics screen). Microchip **C18** compiler, **Salvo RTOS**, XT crystal (4 MHz assumed).
**Languages:** English, Russian, Hebrew (this unit is set to Hebrew).

This is reconstructed pseudo-C, not original source. Every function, RAM variable and data table has a name.
Comments marked *(inferred)*, *(probable)* or *Auto:* are lower confidence or machine-derived (see "Confidence").

## Files

| File | Contents |
|---|---|
| `all_functions.c` | All 1195 functions, named, in address order |
| `functions/` | One file per function: `<address>_<name>.c` |
| `names.tsv` | Master list of every name (functions, RAM, ROM tables) with descriptions |
| `disassembly.lst` | Full named assembly listing |
| `rom_map.txt` | Every byte of program memory classified (code / named table / erased) |
| `menu_tree.txt` | Complete menu tree incl. hidden INSTALLATION and SERVICE menus |
| `ui_words_english.txt` | All 178 UI words/messages |
| `serial_commands.md` | Serial console command set (real names from ROM) |
| `eeprom_parameters.txt` | 74 settings (value/min/max/default), EEPROM layout, usage counters |
| `config_bits_decoded.txt` | Configuration words decoded |
| `pic18f8621_bits.h` | SFR bit names used in the code |
| `~/Desktop/PIC18F8621_RE/PIC18F8621_ghidra/` | Ghidra project with all names applied (`~/tools/ghidra_12.1.4_PUBLIC/ghidraRun`) |

## Coverage

* **Code:** 47,950 bytes in 1195 functions, all named. No unknown or bogus functions.
* **Data:** every non-code byte is assigned to a named table (`rom_map.txt`). 0 unclassified bytes.
* **RAM:** every directly referenced RAM address is named. Six are only cleared at start-up (`unused_*`).
* **EEPROM:** fully mapped (parameters, per-unit min/max limits, usage counters).
* **Config words:** fully decoded. No code protection.

## Architecture

| Task (Salvo) | Pri | Role |
|---|---|---|
| `task_tick_10ms` | 1 | 10 ms tick: heater burst timing; 100 ms / 1 s sub-ticks |
| `task_ui` | 2 | Keypad, menus, screens, buzzer |
| `task_uv_lamp` | 2 | UV cycles, filament warm-up, lamp verification |
| `task_dispense` | 3 | Valve sequencing, refill, measured cups/jugs (hot/cold mixing) |
| `task_second` | 4 | Per-second / 10 s / minute jobs of all modules; sleep timer |
| `task_heating` | 4 | Hot tank thermostat (normal, sleep, extra-hot), boil and fault detection |
| `task_cooling` | 4 | Cold tank thermostat, compressor, pull-down measurement |
| `task_fan_and_safety` | 4 | Condenser fan, device and dryer sensors, lamp/filter presence |
| `task_serial_protocol` | 5 | Service console |

Program-memory layout: vectors, then the C18 init table at 0x2A, UI and menus at 0x98-0x5000, strings at 0x50C0-0x6D69,
serial console at 0x6D6A, fonts at 0x7AE0-0x9281, text engine at 0x9282, Salvo at 0x9AD4, modules at 0xA312-0xFC08, and data tables
(parameters 0xDD62, counters 0xDF67, menus 0xE49E, NTC 0xEA96, words 0xEE06-0xF277, commands 0xFAB3, heater patterns 0xFC5C).

## I/O map

| Pin | Use |
|---|---|
| RH0 / RH1 / RH2 | Inlet / hot water / cold water valve |
| RH5 | Condenser fan |
| RG0 | Heater (burst-fire power levels) |
| RG3 | Compressor |
| RF6 | UV lamp. **RJ1** = lamp lit sense (low = lit) |
| RF5 | Spout light / UV service output *(inferred)* |
| **RJ0** | UV-lamp presence switch ("UV LAMP IS REMOVED") |
| **RC3** | Filter presence switch ("FILTER IS REMOVED") |
| RB3 | Buzzer |
| RB4, RE6, RE7 / RB5-RB7 | 7-key matrix. RB5 held low at power-up = factory jumper |
| RH7, RB0, RB1, RC0, RC1 | Indicator LEDs / backlight |
| PORTD + RE1-RE5 | ST7565-type graphic LCD |
| AN0 / AN1 | Hot tank top / bottom NTC |
| AN4 / AN5 | Cold tank NTCs |
| AN6 / AN7 | Device (ambient) / dryer-condenser NTC |
| EUSART2 | Service console, 9600 8N1 |

## User-visible features (from menus and messages)

* Main menu: Time & Date (Clock, Wake Up 1/2, Energy Saving Mode, Power Down Mode), Water Temp & Qty
  (hot qty, mix temp, mix qty, cold temp, cold qty), Settings (Child Lock, Display: spout light / clock view / units, Beep,
  Language, Restore Factory, Reset), Replacement (filter / UV lamp counters), Enter Power Down.
* Hidden **INSTALLATION** menu (boiling temp, fill tanks with flushing) and **SERVICE** menu (boiling temp, temperature sensors,
  configuration: menu / APPLICATION = COLD ONLY, HOT ONLY, COLD/HOT, COLD/ROOM / back light, UV).
* Shipping mode, production mode, drop-collector messages, filter/UV replacement countdowns, extra-hot ("boiling") mode,
  measured cups (cold/hot/cool/warm) and 2-litre jug.

## Fault codes

0x82 rejected / UV lamp removed, 0x83 compressor restart delay, 0x84 output on too long (valve, heater or compressor),
0x87 ADC near full scale, 0x8A hot tank over-temperature, 0x8B UV lamp did not light, 0x8D / 0x8F sensor open / short,
0x90 UV fault / cold water abnormally warm.

## This unit

* APPLICATION = COLD/HOT, heater fitted, dual hot sensors, UV lamp fitted, lamp and filter switches enabled, Celsius, Hebrew.
* 11 settings changed from defaults (cold cut-out 9 deg C, warm cup 44 deg C, child lock off, ...).
* Usage counters: compressor ~402 days on, heater ~25 days, 64,284 cold and 9,218 hot dispenses (`eeprom_parameters.txt`).

## Findings worth knowing

* Hidden menus: SERVICE = hold MENU/OK (key 0x20) + BACK (key 0x40) on the running unit. INSTALLATION = first-install flow after shipping mode (hold 0x20 at power-on; SYSTEMCONFIG4 bit 0). This unit has SYSTEMCONFIG4 bit 0 set. Details in `menu_tree.txt`.

* Serial commands: 28 listed (help `LCL` prints them) plus 14 hidden service commands recovered from their hashes (GP SP RP GPL RPL SMN SMX GC RC GCL RCL VER XC LCL); GP GPL GC GCL VER LCL confirmed on the device. See `serial_commands.md`, `serial_results.md`.
* Serial command `GCH` (get child protection) cannot work. Its hash collides with `CWC`, and the collision fix-up sends `GCH`
  to the "rejected" handler while `CWC` returns the child-protection state.
* Commands `TC` and `AC` are listed but rejected (0x82) in this build.
* The EEPROM stores per-unit **minimum and maximum** for every parameter, not backup copies.

## Confidence

* **High:** hardware drivers, RTOS, tasks, thermostats, valves, compressor/heater/fan/UV logic, EEPROM, menus, words,
  serial commands, counters, data tables.
* **Medium:** some UI-internal variables and the 4 MHz clock assumption.
* **Machine-derived (`Auto:`):** 688 tiny compiler-generated code fragments. They are named from what they do (parameters read, words
  shown, variables touched, calls, or compiler idiom such as prologue/epilogue). Their full behaviour is in the comment.

## Reading tips

* C18 passes arguments on a software stack at RAM 0xD00 (FSR1). `*puVar = 0x23; f();` means `f(0x23)`.
* RAM 0x00-0x23 is compiler scratch; 0x24-0x3F is overlaid locals.
* The 11 "instruction overlaps" warnings are skip-over-2-word-instruction idioms, which are harmless.
