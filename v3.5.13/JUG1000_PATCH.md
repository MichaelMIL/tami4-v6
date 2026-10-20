# v3.5.13 patch: jug quantity menu editor that reads **1000** (×100)

Image: **`PIC18F8621-3.5.13-jug1000.hex`**.

This is an alternative to `PIC18F8621-3.5.13-par-jug.hex`. It fixes the "missing 0": the jug (QTYJUGWATER,
parameter 67) menu editor now displays and edits in the same scale the firmware dispenses in — **1000**, not 100.

## The trade-off (read this first)

**`jug1000` has NO `par` serial command.** You flash *one* of these two, not both:

| Image | Jug menu shows | `par` serial read/write | Use when |
|---|---|---|---|
| `PIC18F8621-3.5.13-par-jug.hex` | 100 (×10) | **yes** | you want to read/write parameters over serial / from the GUI / ESP bridge |
| `PIC18F8621-3.5.13-jug1000.hex` | **1000 (×100)** | no | you want the on-screen jug number to read correctly |

Both can't fit: the ×100 editor needs the same free flash the `par` handler uses (~150 of the 162 free bytes
in the top region). The stock `PIC18F8621-3.5b.hex` restores either.

## Why the stock jug item showed 100

v3.5.13's quantity editor hardcodes a **×10** display scale (shared by every quantity item: cold, hot, …).
Cold water (raw 18) shows "180"; the jug reuses that editor, so raw 10 shows "100". But the jug is dispensed
at **×100** (raw 10 = 1000 ml), so the right on-screen number is 1000. The ×10 is baked into three shared
routines, so the fix is a jug-only ×100 copy of each.

## What `jug1000` changes

The jug editor calls jug-specific clones of the three scale routines, with the scale literal 0x0A→0x64:

| Jug routine | Clone of | Does |
|---|---|---|
| `jug_disp` (0xFF84) | `0x2A4A`+`0x2332` | display value = raw **× 100** (was ×10) |
| `mm100` (0xFFB2) via `jug_minmax` (0xFFA6) | `0x2864`/`0x2200` | min/max bounds **× 100** |
| `jug_save` (0xFF9A) via `jug_oe` (0xFF7A) | `0x294A` | stored value = display **÷ 100** (was ÷10) |

Everything else (the editor loop, the +/- step callbacks installed by `0x245C`, the EEPROM write at `0x2840`)
is the stock, already-proven path. The **raw stored value is unchanged** (raw 10 ⇒ 1000 ml dispense); only the
displayed/edited number and its bounds are rescaled.

Menu wiring is identical to `par-jug`: WATER-QTY record `0xE39F` item count 5→6, 6th name byte `0xE3A8`=0x36,
6th action `0xE3C4/C5`→`jug_qty`, EN label `0xF2DC/DD`→"JUG WATER QTY", HE label `0xEFBA/BB`→"מים קנקן".

### Byte changes (program memory only)
| Address | Purpose |
|---|---|
| `0xE3A1` | WATER-QTY menu item count 5 → 6 |
| `0xE3A8` | 6th item name byte → 0x36 (JUG label index) |
| `0xE3C4..0xE3C5` | 6th action → `jug_qty` |
| `0xF2DC..0xF2DD` | English label[0x36] → "JUG WATER QTY" |
| `0xEFBA..0xEFBB` | Hebrew label[0x36] → "מים קנקן" |
| `0xFF5E..0xFFF3` | jug ×100 handler + the three scale clones + labels |

EEPROM, configuration words, and all reset/interrupt vectors are **byte-identical** to stock. 156 program bytes
changed; hex checksums valid.

## Verified (simulator) / not verified

Verified in `patch_tools/`:
* `jug_disp`: raw 10 → display **1000**.
* `mm100`: value 10 → 1000, max 15 → **1500** (bounds scale with the display).
* `jug_save`: display 1000 → raw **10**, 1500 → 15, 1050 → 10, 300 → 3 — the raw/dispense value is preserved.
* Byte diff: only the addresses above; EEPROM/config/vectors identical; checksums valid.

**Not verified:** the on-screen menu navigation, the +/- stepping granularity and the edit-and-save round trip
on the LCD — the simulator can't drive the keypad/display editor loop. Test on the unit:
1. Keep `PIC18F8621-3.5b.hex` (and `PIC18F8621-3.5.13-par-jug.hex`) ready to re-flash.
2. Flash `PIC18F8621-3.5.13-jug1000.hex` (program + config; EEPROM unchanged).
3. `ver` over serial still replies → booted OK. (`par` is gone here; it returns ERROR -123.)
4. WATER TEMP & QTY → last item "JUG WATER QTY" should now read around **1000**. Change it, save, re-open to
   confirm it stuck; dispense a jug and check the amount is unchanged.
5. Anything odd → re-flash the stock hex.

## Reproduce
From `patch_tools/`: `python3 build_jug100.py` writes the hex.
