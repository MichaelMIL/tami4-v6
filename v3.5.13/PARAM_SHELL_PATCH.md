# v3.5.13 firmware patch: edit parameters from the serial shell (`par`)

> **Fix note (2026-10-19).** The first build of this patch put one of its routines (`ee_read`)
> in a flash gap at **0x9134** that looked erased but is actually referenced **display/font
> data** (the LCD code reads that block). Flashing it corrupted that data and broke the
> on-unit UI (the OK/Menu screen). The patch was rebuilt to use only two regions that are
> provably dead: the unprogrammed flash tail (0xFF5E-0xFFFF) and the old command table
> (0xFE1C, made dead by relocating the table). **Re-flash the current
> `PIC18F8621-3.5.13-par-patch.hex`.** If the unit is misbehaving now, flash the stock
> `PIC18F8621-3.5b.hex` first to confirm the UI returns, then flash the corrected patch.


Stock v3.5.13 removed every parameter command (`GP`/`SP`/`GPL` from v3.47); its shell can
only *display* a static parameter reference, not read or change the live EEPROM values.
This patch adds one new shell command, **`par`**, that reads and writes the 77 EEPROM
parameters, with the firmware's own min/max limits enforced on every write.

* Base image: `PIC18F8621-3.5b.hex` (T6 3.5.13 Feb 07 2019).
* Patched image: **`PIC18F8621-3.5.13-par-patch.hex`** (flash this).
* Build/verify tools: `patch_tools/` (see "Reproducing the build").

## 1. What `par` does

Same 38400 8N1 shell as before (see `SERIAL_SHELL.md`). Two forms:

| Command | Action | Reply |
|---|---|---|
| `par=<index>` | Read one parameter value | `<value>` then `OK` |
| `par=<index>,<value>` | Write one parameter value | `OK`, or `ERROR -127` if rejected |

* `<index>` is the parameter number **0..76** (the `#` column in `PARAMETERS.md`).
* Values are bytes, **0..255**.
* A write is accepted only when `min[index] <= value <= max[index]`, using the per-parameter
  limits already stored in EEPROM (`index+0x9A` = min, `index+0x4D` = max). Out-of-range
  values, bad indexes, non-byte values, or the wrong argument count all return `ERROR -127`
  and change nothing.
* `ls` now lists `par` as command 19, and the command count it prints is 20.

### Examples (verified in the instruction-set simulator)
```
par=1          -> 3            OK          # TSENSORSRATE = 3
par=37         -> 126          OK          # SYSTEMCONFIG = 126
par=76         -> 50           OK          # PLASTICSLEEPMODESTARTHEATING = 50
par=1,8        -> OK                       # TSENSORSRATE := 8  (min 1, max 10)
par=1,99       -> ERROR -127               # 99 > max(10); EEPROM unchanged
par=1,0        -> ERROR -127               # 0  < min(1);  EEPROM unchanged
par=76,44      -> ERROR -127               # 44 < min(45)
par=77         -> ERROR -127               # index out of range (valid 0..76)
par            -> ERROR -127               # needs an index
```

**Caution.** These are live control parameters (heater limits, cut-outs, valve timings).
Writing a valid-but-wrong value can still change how the appliance heats and dispenses.
The patch enforces the firmware's min/max, nothing more. Read a value, note it, then change it.
`restore_factory_settings` still restores ROM defaults if needed.

## 2. How it works

The shell matches a typed command against a name table, gets its index, then runs a
compiler `switch` on that index. The patch:

1. **Grows the command table from 19 to 20 entries.** A fresh 20-pointer table is written to
   free flash; entries 0..18 are the original command strings, entry 19 points to the new
   string `"par"`. The table-reader (`0x83D4`, used by both the matcher and `ls`) is
   repointed to it, and the match-loop limit (`0x840E`) is raised from 19 to 20.
2. **Hooks the switch default.** Index 19 (and any unknown command) falls through the stock
   `switch` to its default at `0x7E22`. That default is replaced with `GOTO` into new code
   (`newdisp`) which sends index 19 to the `par` handler and sends everything else to the
   original "unknown command" error (`ERROR -123`). The stock switch cases (0..18) are
   untouched.
3. **Adds the handler** (`par`), plus small `ee_read`/`ee_write` byte routines that use the
   EEPROM control registers directly (EEADR/EEADRH/EEDATA/EECON1/EECON2), bracketing the
   `0x55/0xAA` unlock with GIE off/on exactly like the firmware's own writes.

New code lives only in free/erased flash and in the 38 bytes freed by relocating the command
table. No existing function is moved or shortened.

### Byte-level changes (program memory)
| Address | Was | Now | Purpose |
|---|---|---|---|
| `0x8414` | `13` | `14` | match-loop limit 19 -> 20 |
| `0x83E0` | `1C` | `5E` | command-table base low byte -> `0xFF5E` |
| `0x83E4` | `FE` | `FF` | command-table base high byte |
| `0x7E22..0x7E25` | `02 01 85 0E` | `C5 EF 7F F0` | `GOTO newdisp` from the switch default |
| `0xFF5E..0xFF85` | erased | — | new 20-entry command-pointer table |
| `0xFF86..0xFF89` | erased | — | string `"par\0"` |
| `0xFF8A..0xFFF5` | erased | — | `newdisp` + `par` handler (`pcmd`/`pread`/`perr`) |
| `0xFFF6..0xFFFF` | erased | — | `ee_read` |
| `0xFE1C..0xFE3F` | old 19-entry table (now dead) | — | `ee_write` |

All new code lives in exactly two regions, both confirmed dead: the unprogrammed flash tail
`0xFF5E..0xFFFF` (nothing follows it, so it cannot be a gap inside a table) and the old
command-pointer table `0xFE1C..0xFE41` (preceded by a `RETURN`, referenced only by the table
reader at `0x83D4`, which step 1 repoints). **No other flash gap is used** — the earlier
0x9134 location turned out to be live font data. **EEPROM and configuration words are not
touched** (0 bytes changed). `ee_read` omits the EEPGD/CFGS clear because the firmware never
sets those bits (they stay 0 from reset); `ee_write` clears them anyway before writing.

## 3. Flashing

Use the same chain that read the unit (see `../AGENT_README.md`): MPLAB IPE **v6.20** with the
PICkit 3.

1. **Back up first.** `PIC18F8621.hex` in the project root is the only dump of the unit; keep it.
   Also read the current device (its EEPROM holds *this unit's* settings, which differ from the
   values in `PIC18F8621-3.5b.hex`).
2. In IPE, program **`PIC18F8621-3.5.13-par-patch.hex`**.
   * Program Memory and Configuration only. **Do not erase/overwrite EEPROM** if you want to
     keep the unit's current settings. (This hex carries the EEPROM image from
     `PIC18F8621-3.5b.hex`, which is *not* this unit's live settings. Deselect the EEPROM/Data
     region when programming, or re-write the unit's own EEPROM afterward.)
3. Reconnect the service console (38400 8N1) and try `ls` — `par` should appear as #19.
4. Recovery: reprogram `PIC18F8621-3.5b.hex` (or the original `PIC18F8621.hex`).

## 4. How it was verified

There is no second unit to test against, so the patch was checked in a purpose-built PIC18
instruction-set simulator (`patch_tools/emu.py`) that executes the real firmware:

* The simulator was validated against the stock image first: `ver`, `get_wu`, `get_hwt_type`
  and `ls` produce byte-for-byte the documented replies.
* On the patched image: reads return the correct EEPROM values; valid writes land the correct
  byte; out-of-range / bad-index / wrong-arg-count writes are rejected and leave EEPROM
  unchanged; boundary values (exactly min and max) are accepted, min-1 and max+1 rejected.
* The C18 software stack (FSR1) returns to its baseline after every command, including a mixed
  sequence of 11 commands run back-to-back — so there is no per-command stack leak.
* A byte diff confirms only the addresses in the table above changed, and that EEPROM and
  config words are identical to the base image.

This exercises the decode/dispatch, argument parsing, EEPROM access and reply paths. It does
not model analog inputs or real EEPROM write timing; the `par` write uses the same unlock
sequence and byte-write wait as the firmware's existing EEPROM writers.

Not yet run on the physical unit. Treat the first on-unit write as a reversible test: read a
parameter, change it by one within range, read it back, then restore it.

## 5. Reproducing the build

From `patch_tools/`:
```
python3 build.py      # writes PIC18F8621-3.5.13-par-patch.hex
python3 verify.py     # reads/writes/range/existing-commands checks
python3 verify2.py    # accumulation, boundary, and byte-diff checks
```
`build.py` assembles the handler (`asm.py`), applies the byte patches, and emits the hex.
`emu.py` is the simulator, `dis.py` the disassembler, `hexparse.py`/`sfr.py` helpers.

## 6. Notes / possible follow-ups

* One combined command (`par`) rather than separate `getp`/`setp` was used because only ~219
  bytes of flash are free in reachable pieces; `par` fits with margin. Argument count selects
  read vs write.
* `serial_gui.py` now has a **"Parameters (edit)"** tab for v3.5.13 that uses `par` (Read all,
  Read/Set selected, Restore default), with the same confirm-before-write guard as the other
  write commands; Demo mode simulates `par` too. `esp32_bridge/` does not know about `par` yet
  and can send it over the raw console.
* Writing resolved the open question in `AGENT_README.md` item 2/5: for 77 parameters the
  EEPROM min/max blocks are still at `index+0x4D` (max) and `index+0x9A` (min), confirmed
  against parameters 74-76.
