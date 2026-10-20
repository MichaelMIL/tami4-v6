# v3.5.13 patch: edit the jug quantity from the on-device menu (+ keep `par`)

Image: **`PIC18F8621-3.5.13-par-jug.hex`**. This is the stock `PIC18F8621-3.5b.hex` with two features
added, nothing else touched (EEPROM, config words, and all interrupt/reset vectors are byte-identical).
It supersedes `PIC18F8621-3.5.13-par-patch.hex` (flash this one instead; don't flash both).

> The new menu item is a 6th entry in the WATER TEMP & QTY menu, labeled **"JUG WATER QTY."**, that edits
> the jug quantity. Verified on the unit (the item appears and edits the jug value). Keep the stock hex
> ready to re-flash in case of trouble.

## 1. What it adds

**A 6th item in the "WATER TEMP & QTY" menu** that opens the standard quantity editor on
**QTYJUGWATER** (parameter 67, EEPROM 0x43). The firmware's own editor applies its limits
automatically (min 3, max 15; default 10, where 10 = 1.0 L). It is the **last item** in that menu,
after "COLD WATER QTY".

**The `par` serial command is kept** (read `par=<i>`, write `par=<i>,<v>`), with two changes from the
earlier par-only patch:
* It is now triggered by reusing the unused **`ex`** command slot. You still type `par` / `par=i` /
  `par=i,v`. The old `ex` command is gone (it now returns `ERROR -123`); `ex` was an unidentified,
  unused service call.
* **`par` writes are no longer range-checked by the firmware** (there wasn't room for both the jug
  handler and the validation). The GUI now **blocks** out-of-range writes instead, and the jug menu
  editor still clamps the jug value. Raw hand-typed serial writes (`par=i,v` in a terminal) are
  **not** range-checked — stay within each parameter's min/max (see `PARAMETERS.md`).

## 2. How it works

* **Free flash:** the command table entry for `ex` (ROM 0xFE2A) is repointed to a new `"par"` string,
  and the `ex` switch case (0x7B70) is replaced with `GOTO` into new code. This reuses the existing
  dispatch slot, so no 40-byte command-table relocation is needed — that is what frees room for the
  jug handler.
* **Jug editor:** a handler cloned from the real COLD-quantity editor (0x0CB0), using parameter index
  **0x43** instead of 0x3E. The firmware's editor setup (0x23EC/0x2200/0x2A4A) reads the value and
  limits for that index from EEPROM, so the jug min/max come through automatically. Its save-callback
  writes the edited value back to parameter 67.
* **Menu item:** the "WATER TEMP & QTY" record (ROM 0xE39F) item count is raised 5→6, the 6th name
  byte is set to a borrowed label, and the 6th action pointer points at the jug handler.

### Byte changes (program memory only)
| Address | Purpose |
|---|---|
| `0x7B70..0x7B72` | `ex` switch case → `GOTO par_code` |
| `0xE3A1` | WATER-QTY menu item count 5 → 6 |
| `0xE3A8` | 6th item name byte -> 0x36 (JUG label) |
| `0xF2DC..0xF2DD` | English name-table entry 0x36 -> "JUG WATER QTY" string |
| `0xEFBA..0xEFBB` | Hebrew name-table entry 0x36 -> "מים קנקן" string |
| `0xE3C4..0xE3C5` | 6th item action → jug handler |
| `0xFE2A..0xFE2B` | `ex` command-table entry → `"par"` string |
| `0xFF5E..0xFFF3` | new code: `"par"`, par read/write + EEPROM routines, jug handler |
| `0xFF..` (top tail) | English "JUG WATER QTY" + Hebrew "מים קנקן" menu strings |

EEPROM, configuration words, and the reset/high/low interrupt vectors are unchanged.

## 3. The label ("JUG WATER QTY.")

v3.5.13 builds menu labels from `0x01`-compressed strings: a word reference is `01 <dict_index+1>`,
rendered through the English dictionary at ROM **0xF394** (WATER = index 0, QTY = index 27, COLD = 36),
with the per-language name->string table for English at **0xF270** (indexed by a menu item's name byte).
"COLD WATER QTY." lives at 0x55D5 as `01 25 20 01 01 20 01 1C 2E`.

The jug label is a new string **"JUG WATER QTY."** at 0xFFF4, written as plain ASCII `"JUG"` followed by
the WATER and QTY word references and ".": `4A 55 47 20 01 01 20 01 1C 2E 00` (no new dictionary word
needed). An unused name-byte index (**0x36**) has its English table entry (0xF2DC) pointed at it, and the
jug menu item's name byte is set to 0x36.

The label uses index 0x36 (an unused name byte). **English** (table 0xF270) reads **"JUG WATER QTY"**.
**Hebrew** (table 0xEF4E, dictionary 0xF072) reads **"מים קנקן"** ("jug water", using קנקן = jug), via a
Hebrew string at 0xFFF6 and the Hebrew table entry at 0xEFBA. Russian (table 0xF0E0) is not set; if you
switch the unit to Russian the item would show that table's index-0x36 string. Say the word and I'll add it.

## 4. What was verified (and what wasn't)

In the PIC18 simulator (`patch_tools/`):
* `par` works via the `par` keyword: reads (`par=1`→3, `par=37`→126) and writes (`par=1,8` sets
  EEPROM[1]=8); invalid index rejected; `ver`/`get_wu` unaffected; `ex` now returns `ERROR -123`;
  software stack balanced after every command.
* `par=1,99` now *writes* 99 (validation removed, as described) — the GUI blocks this.
* The jug handler calls the editor setup three times with parameter index **0x43** and enters the
  standard editor; its save path targets parameter 67.
* Byte diff: only the addresses above changed; EEPROM/config/vectors identical; hex checksums valid.

**Not verified:** the on-screen menu navigation, rendering, and the actual edit-and-save round trip —
the simulator can't drive the LCD/keypad, and there is no second unit. The jug handler is a faithful
clone of the working COLD editor, so it should behave the same, but the menu behaviour must be
confirmed on the unit.

## 5. Flashing and testing

1. Keep `PIC18F8621-3.5b.hex` (or the original `../PIC18F8621.hex`) ready to restore.
2. Flash `PIC18F8621-3.5.13-par-jug.hex` (program + config). EEPROM is identical to stock, so including
   or excluding Data memory makes no difference to this patch.
3. Test, in order:
   * `ver` over serial still replies — firmware booted OK.
   * `par=67` reads the jug value; `par=1` reads parameter 1 — `par` still works.
   * Open **WATER TEMP & QTY** on the unit. There should be **6** items; the last one reads **"JUG WATER QTY"** (Hebrew: "מים קנקן"). Open it, change it, save, then read back with `par=67` to confirm it changed
     the jug value.
4. If anything misbehaves (garbled menu, no boot, etc.), re-flash the stock hex. Report what you saw.

## 6. Reproduce the build
From `patch_tools/`: `python3 build_combined.py` writes the hex; `python3 vc.py` runs the checks.
