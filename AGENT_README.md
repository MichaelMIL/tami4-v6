# Agent handoff: PIC18F8621 water-dispenser firmware RE

Read this first. It explains what exists, how to regenerate it, and what is still open.
The human-facing overview is `PIC18F8621_decompiled/README.md`.

---

## ⇢ Current state — 2026-10-20 (read this first)

The RE below is v3.47-era background. The **active work** is firmware patching on **v3.5.13** (the image on the
unit) plus the **ESP Wi-Fi bridge**. Quick orientation:

* **Git.** This tree is a git repo; remote `git@github.com:MichaelMIL/tami4-v6.git`, branch `main`. Commits are
  authored `mmkingmil`. **Push is currently BLOCKED**: the authenticated account (`michaelmark-strikeco`) has only
  *pull* on that repo. Latest local commit is ready to push once the owner grants write access (or the owning
  account is authenticated). `secrets.ini`, `.vscode/`, `.pio/` are gitignored — never commit them.

* **v3.5.13 patch images** (in `v3.5.13/`, built from stock `PIC18F8621-3.5b.hex`; see `v3.5.13/README.md` §6):
  the deliverable is **`PIC18F8621-3.5.13-par-settext.hex`** = `par` (read/write any parameter) + bulk `par`
  (read all 77) + **two-row `settext`** idle text (replaces the "Strauss Water" logo) + a "JUG WATER QTY" menu
  item (×100 editor). EEPROM, config words and vectors are byte-identical to stock; checksums valid. Per-image
  docs: `PAR_SETTEXT_PATCH.md`, `JUG_MENU_PATCH.md`, `LOGOTEXT_PATCH.md`, `PARAM_SHELL_PATCH.md`, `JUG1000_PATCH.md`.

* **Patch toolchain is self-built** in `v3.5.13/patch_tools/` — `asm.py` / `dis.py` / `emu.py` (a PIC18 emulator
  that also renders the ST7565 LCD framebuffer) / `hexparse.py`. Build the deliverable with
  `python3 build_full.py /tmp/full.hex`; it prints region usage (top / bitmap / brand-body) and the byte diff.
  Verify shell behaviour with `verify.py` / `vc.py`; render the idle text with the `/tmp/render_logo.py` harness
  (stubs the `cmd`/`dat` LCD wrappers and reconstructs the framebuffer).

* **⚠ `PIC18F8621_decompiled/` is firmware v3.47, NOT v3.5.13.** High-address function addresses there do **not**
  match the v3.5.13 image. All v3.5.13 display/shell addresses were found directly in `3.5b.hex` with the emulator.
  Don't trust `decompiled/` addresses for patching the live firmware.

* **ESP bridge** (`esp32_bridge/`): flashed and running on an **ESP32-S3 Super Mini** at **`tami.local`**, kept
  current over OTA (`pio run -e esp32s3_ota -t upload --upload-port tami.local`, auth = `secrets.ini` `ota_pass`).
  Board quirks (4 MB flash pin, GPIO43/44 UART0, USB-CDC console) are in `esp32_bridge/README.md`. The v3.5.13
  web UI has: editable Parameters (bulk read, warn-on-range), two-line Idle-screen text (uppercased, joined with `|`).

* **Flashing the PIC needs a PICkit** (MPLAB IPE v6.20). Config bits disable LVP (`CONFIG4L=0x81`) and MCLRE
  (`CONFIG3H=0x02`), and there is no UART bootloader, so UART/ESP flashing is **not** possible — a conclusion
  reached this session. **The two-row idle text requires re-flashing the PIC** with the new `par-settext.hex`;
  the previously-flashed image draws a literal `|` instead of a row break. Single-line uppercase text works
  without re-flashing (the ESP does the uppercasing).

* **Font gotcha:** the built-in 5×8 font at `0x6C88` is **uppercase-only**; lowercase (0x61-0x7A) renders garbage.
  That is why the ESP uppercases idle text before `settext`.

### Open items (current work)
1. **Git push** — needs write access for `michaelmark-strikeco` on `MichaelMIL/tami4-v6` (or auth the owner).
2. **Hardware-verify** the `par-settext` image on the unit: re-flash via PICkit, then check `par`/`par=i,v`,
   bulk `par`, the two-row idle text (`settext=GOOD|MORNING`), and the JUG WATER QTY menu edit. Nudge text
   position via `PAGE`/`XPOS` in `build_full.py` if needed.
3. The older RE open items (below) still stand.

---

## The project in one paragraph

`PIC18F8621.hex` was read from a hot/cold water dispenser controller with a PICkit 3 (MPLAB IPE **v6.20**, because v6.25+ dropped
PICkit 3 support). It is firmware **"T6 3.47V"**, built with Microchip **C18** and the **Salvo RTOS**, with an XT crystal (4 MHz assumed).
The firmware is fully reverse engineered:
* 1195 functions, all named.
* Every directly referenced RAM address named.
* Every byte of program memory classified (`rom_map.txt`, 0 unclassified).
* EEPROM fully mapped.
* The serial service protocol decoded and partly verified on the live unit.

## Layout (`~/Desktop/PIC18F8621_RE/`)

| Path | What |
|---|---|
| `PIC18F8621.hex` | Original dump (program + config + EEPROM). **The only backup of the unit. Never modify.** |
| `PIC18F8621_ghidra/` | Ghidra project (PIC-18 language), all names applied. `names.tsv` here is the **master** name list |
| `PIC18F8621_ghidra/scripts/` | Headless Ghidra scripts: `ApplyNames`, `DecompileAll`, `ExportListing`, `SeedCallTargets`, `RemoveDataFunctions`, `SeedEntries` |
| `PIC18F8621_decompiled/` | Generated outputs (do not hand-edit `all_functions.c` / `functions/`; regenerate) |
| `PIC18F8621_decompiled/README.md` | Architecture, I/O map, faults, findings |
| `…/serial_commands.md` | Serial command reference (syntax, hashes, confidence) |
| `…/serial_results.md` | Results of the live serial sessions |
| `…/parameter_info.json` | **Master** explanation of every parameter and counter (group, unit, meaning, SYSTEMCONFIG bit fields). Read by `serial_gui.py` and embedded into `esp32_bridge`. Edit it, then run `analysis/gen_param_doc.py` |
| `…/parameters_explained.md` | Generated readable reference (this unit's values converted to real units) |
| `…/eeprom_parameters.txt`, `menu_tree.txt`, `ui_words_english.txt`, `rom_map.txt`, `config_bits_decoded.txt` | Decoded data |
| `…/serial_readonly_dump.py` | Read-only serial dump (safe) |
| `…/serial_gui.py` | Tkinter GUI for the service console, **both firmwares** (v3.47: status, parameters, counters, controls; v3.5.13: status, outputs/dispense, setup, parameter reference) plus raw console. Auto-detects the firmware; `--demo` simulates the unit. Logs to `serial_gui_log.txt` |
| `…/write_tests/` | `ser.py` (send one command), `run_write_tests.py` (reversible write tests), baselines, log |
| `v3.5.13/` | Firmware **T6 3.5.13** (`PIC18F8621-3.5b.hex`, now on the unit): changes from v3.47 and the new 38400-baud text shell. Read its `README.md` / `SERIAL_SHELL.md`. First-pass Ghidra project in `ghidra/` |
| `esp32_bridge/` | PlatformIO firmware (LOLIN S2 Mini / ESP32): Wi-Fi web UI + JSON API for the service console, AP fallback, OTA. See its `README.md`. `secrets.ini` there holds passwords: do not share |
| `analysis/` | Python analysis and regeneration scripts plus their inputs (`pic18f8621_prog.bin` = program memory 0-0xFFFF, `strings.txt`, `listing_named.txt`) |
| `PIC18F8621_decompiled_v1_255funcs/`, `…_numeric_masks_backup/` | Obsolete early versions, kept for history |

Tools live in `~/tools`: `ghidra_12.1.4_PUBLIC`, `jdk-21.0.12.1+1`, `node-v22.23.3-linux-x64` (with `rea-agents` 6.7.0). Set:
```
export JAVA_HOME=~/tools/jdk-21.0.12.1+1 PATH=~/tools/jdk-21.0.12.1+1/bin:$PATH
G=~/tools/ghidra_12.1.4_PUBLIC/support/analyzeHeadless
P=~/Desktop/PIC18F8621_RE/PIC18F8621_ghidra
A=~/Desktop/PIC18F8621_RE/analysis
```

## How to change a name and regenerate everything

1. Edit `$P/names.tsv`. The format is `kind<TAB>0xaddr<TAB>name<TAB>comment`, where kind is:
   * `func`: CODE function
   * `var`: DATA (RAM) label
   * `rom`: CODE data label

   Later lines override earlier ones for the same address. Keep names unique.
2. Apply the names and re-export:
   ```
   rm -rf $A/decn $A/decnb
   $G $P PIC18F8621 -process PIC18F8621.hex -noanalysis -scriptPath $P/scripts \
      -postScript ApplyNames.java $P/names.tsv -postScript DecompileAll.java $A/decn \
      -postScript ExportListing.java $A/listing_named.txt
   ```
   The log should say `applied N, failed 0`.
3. Rebuild the outputs:
   ```
   cd $A && python3 applybits.py decn decnb && python3 rebuild.py
   cp listing_named.txt ../PIC18F8621_decompiled/disassembly.lst
   cp $P/names.tsv ../PIC18F8621_decompiled/
   ```

Other useful scripts in `analysis/`:
* `view.py <addr...>`: compact named decompile view.
* `summ.py lo hi`: one-line summaries.
* `varctx.py <ramaddr...>`: assembly context for RAM addresses, with bank tracking.
* `words.py`: UI word decoder. Strings are compressed: `0x01 k` means dictionary word k-1.
* `cbsim2.py`: menu callback simulator.
* `coverage.py`: code coverage.
* `autoname*.py`: behaviour-based fragment naming.

## Key technical facts (save yourself the rediscovery)

* **C18 calling convention:** arguments are pushed on a software stack (FSR1, stack at RAM 0xD00). In decompiled code, `*puVar = 0x23; f();` means `f(0x23)`.
  RAM 0x00-0x23 is compiler scratch and 0x24-0x3F is overlaid locals. 688 tiny compiler fragments are machine-named (`ui_/mod_/ser_/os_…_<addr>`, comment `Auto:`).
* **Ghidra misses much of the code by default:** UI handlers are reached only through menu-callback pointers (`menu_cb_*` at RAM 0x134-0x141) and Salvo resume addresses.
  Functions were seeded from a CALL-target sweep plus gap/fragment seeding. Program memory 0x98-0x33B is code; the C18 init table is only 0x2A-0x97.
* **Bank tracking:** UI fragments inherit the BSR value (bank) from their caller. Bank 1 is the safe default for UI variables.
  Linear bank tracking produces a few false addresses (for example 0x26B really means 0x16B).
* **Data tables:**
  * Parameter table 0xDD5B: 75 entries x 7 bytes `{name ptr, default, min, max, unit, id}`. Entry 0 = `FT`.
  * Counter descriptors 0xDF67.
  * Menu records 0xE49E (0x26 bytes each).
  * NTC tables 0xEA96 / 0xEB4A / 0xEBD6.
  * Word tables (group A / dictionary B) for EN 0xF114/0xF22E, RU 0xEF8E/0xF0A8, HE 0xEE06/0xEF20.
  * Command table 0xFAB0: 28 entries x `{hash, name ptr}`.
  * Heater burst patterns 0xFC5C.
* **Parameter unit codes** (ROM table field): 0 = °C or plain, 1 = 10 ms (OS tick), 2 = 100 ms, 3 = s, 4 = 10 s, 5 = min, 6 = TPOWERDELAY only (likely h), 7 = 10 min.
  Derived from which tick decrements each timer (`task_second` 1 s / 10 s / 60 s blocks, `task_tick_10ms`). Not read anywhere in this build:
  TMAXCOLDDIFF, TMAXPRESS, CHILDPROTECTTIME, TEMPCOLDCHNGTIME, MAXVOLPERFILTER.
* **EEPROM layout:**
  * 0x000-0x04A: parameter values (index = address; index 0 = FT flag).
  * +0x4B: per-parameter maximum. +0x96: per-parameter minimum.
  * 0x0E4-0x123: 16 x 32-bit usage counters.
  * 0x124 / 0x125: byte statistics CMM / CGT.
* **REA** (`rea-agents`) cannot load Intel HEX or PIC directly. To use it, wrap the binary in a fake x86 ELF and set `REA_GHIDRA_LANGUAGE_ID=PIC-18:LE:24:PIC-18`.
  Plain headless Ghidra (above) is simpler and is what the current outputs come from.

## Hardware / serial access

* PICkit 3 on USB (`04d8:900a`) for reading and programming via MPLAB IPE **v6.20**: `/opt/microchip/mplabx/v6.20/mplab_platform/bin/mplab_ipe`. The PIC18F8621 device works.
* Service console: EUSART2 (RG1 = TX2, RG2 = RX2), CH340 adapter at `/dev/ttyUSB0` (enumerated as `/dev/ttyUSB1` after a replug).
  * v3.47: 9600 8N1, CR-terminated, echoed, max 11 characters per line.
  * **v3.5.13 (on the unit since 2026-10-18): 38400 8N1**, lowercase text shell `cmd=a,b`, max 29 characters; replies end in `OK` or `ERROR -123` (unknown command) / `ERROR -127` (wrong argument count or value out of range). See `v3.5.13/README.md`.
  Send one command with `cd PIC18F8621_decompiled/write_tests && python3 ser.py "GP 21"` (every exchange is logged to `write_test_log.txt`).
* GUI: `cd PIC18F8621_decompiled && python3 serial_gui.py [--port /dev/ttyUSB0] [--fw auto|3.47|3.5.13] [--demo]`.
  * On connect it always probes `VER` at 9600 first, then `ver` at 38400, and shows that firmware's tabs. That order is deliberate:
    garbage at 9600 can never equal a v3.5.13 command name (exact strcmp), but garbage sent to a v3.47 unit at 38400 could later be run through its command *hash*.
    `--fw` is only the fallback if nothing answers (and selects the simulated firmware with `--demo`).
  * v3.5.13 has no parameter or counter commands; its Parameters tab is a read-only ROM-table reference. There is no dispense-stop command either:
    the STOP button sends `output=5,0`, `output=4,0`, `output=6,0` (hot, cold, inlet valve off) ahead of anything queued and is never blocked.
  * It asks for confirmation before every EEPROM write or hardware action; `RPL` / `RCL` must be typed back. `STP` is never blocked.
  * Typed console commands are classified by the firmware's **hash**, not by spelling (for example `FOO` hashes to `RCL`).
  * "Restore from baseline" buttons rebuild `SP`/`SMN`/`SMX` and `g` commands from `write_tests/baseline_*.txt` and list them before sending.
  * `g` lines longer than 11 characters drop the space (`g1334706271`); this relies on `atol` skipping spaces and is untested.
  * v3.47 mode was used on the live unit (see open items). v3.5.13 mode is tested in `--demo` and against the reply shapes of `v3.5.13/serial/shell_readonly_*.txt`, not yet on the unit.
* At the last session the board was powered **without** NTC sensors or UV lamp (temperatures read -1, sensor faults 0x8D, UV fault 0x8B). That is expected on the bench.

## Serial command status

* **Confirmed on the unit:**
  * Listed commands: VER/ST output and all status queries (`ST GHT GCT GDT COT GHS GCS HTS UVS IVS CVS HVS CWC`).
  * Hidden commands: `GP GPL GC GCL VER LCL SP RP`.
* **Reconstructed but untested:**
  * `SMN SMX` (set min/max), `RC` (clear counter), `RPL` (reset all parameters), `RCL` (clear all counters).
  * `XC` (execute command #n), `g` (set counter, syntax `gNN <value>`).
* **Known firmware bug:** `GCH` collides with `CWC` and is rejected (0x82). `CWC` returns the child-protection state instead.

## Rules for working on the live unit (important)

* **Ask the user before any command that writes EEPROM or actuates hardware:**
  * v3.47 EEPROM writes: `SP SMN SMX RP RPL RC RCL g`. Hardware actions: `DCW DHW STP CP0 CP1 EH1 EH0 NM SM PD RS`.
  * v3.5.13 EEPROM writes: `restore_factory_settings set_language set_shipping_mode set_production_mode`.
    Hardware / mode: `output=n,v hot cold mix manual_press testing_mode reset ex`.

  Claude Code's auto mode blocks these unless the user has approved the specific action. Get approval each time; don't try to route around a denial.
* Prefer reversible tests: read, write, verify, restore, verify. Use `write_tests/baseline_GPL.txt` / `baseline_GCL.txt` (taken before any writes) as the restore reference.
  `RPL` and `RCL` are bulk-destructive. Only run them with explicit consent, and restore from the baseline afterwards with `SP` / `g`.
* Last-resort recovery: write the EEPROM section of `PIC18F8621.hex` back with IPE v6.20 and the PICkit 3.
* The serial GUI (`serial_gui.py`) was built on 2026-10-18 and verified against the simulator only.
  The format of real fault replies (0x81/0x82/0x85) has never been captured; the GUI shows the raw bytes, labelled.

## Open items

1. Flash `esp32_bridge/` (check PIC VDD and use a level shifter first) and test it on the live unit. Firmware 1.1.0 supports both PIC firmwares
   (auto-detect at boot, `/api/picfw`); build verified, web UI verified headless against a mock API only.
   `serial_gui.py` has been used on the live unit by the user (2026-10-18 20:20-20:46, `serial_gui_log.txt`): parsing works; SP 40 / RP 66 / RP 58 / SM / PD / STP sent.
   **After that session SYSTEMCONFIG4 = 35 (0x23; baseline 231 = 0xE7) and QTYHOTWATER = 14 (baseline 12)** because of RP 58 / RP 66.
   Restore with `SP 58,231` and `SP 66,12` if that was not intended.
2. v3.5.13: run `serial_gui.py` against the unit (read commands only first). Then decode the `hot/cold/mix` argument (stored at RAM 0x10A),
   `manual_press` key numbers / time unit, the error numbers of `get_errors_bitmap`, the `get_wu` unit and `ex`. Untested write commands need the same per-action approval as v3.47's.
3. v3.47 only: test the remaining write commands (`SMN SMX RC g XC`, then `RPL RCL` only with consent), reversibly. Update `serial_commands.md` / `serial_results.md`.
4. Optional refinement:
   * Parameter unit codes are decoded (see above); cup/jug volume steps, WATERFLOW scale and TPOWERDELAY hours are still *(inferred)*.
     The SYSTEMCONFIG bits marked *(inferred)* / 'not decoded' in `parameter_info.json` are the remaining gaps.
   * A few UI variables are marked *(inferred)*.
   * The 4 MHz clock is an assumption (based on XT oscillator config, Timer0 reload 0xD900 = 10 ms, SPBRG2 = 25 → 9600 baud).
