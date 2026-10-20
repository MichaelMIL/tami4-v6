# v3.5.13 combined patch: `par` (edit parameters) **and** `settext` (custom logo text) in one image

Image: **`PIC18F8621-3.5.13-par-settext.hex`**. One firmware with both features — supersedes the separate
`par-jug` and `logotext` images. EEPROM, config words and all reset/interrupt vectors are byte-identical to
stock; checksums valid.

## What it has
* **`par`** (no args) — dump **all** 77 parameter values at once (0..76, one per line).
* **`par=i` / `par=i,v`** — read / write one EEPROM parameter (no firmware range-check; the GUI warns).
* **JUG WATER QTY menu item** — edits QTYJUGWATER (param 67) from the on-device WATER TEMP & QTY menu, shown **x100 (e.g. 1000)**.
* **`settext=YOUR TEXT`** — store text in EEPROM 0x130; the idle screen's **"Strauss Water" logo is
  replaced by that text** (blank if empty), in the built-in 5x8 font. Both the idle screen and the sleep screen
  are covered.
  * **Two rows:** a `|` (0x7C) in the text is a row break — the draw drops 2 LCD pages (16 px) and resets the
    column, so `settext=GOOD|MORNING` shows "GOOD" over "MORNING". Multiple `|` give more rows.
  * **Uppercase only:** the 5x8 font at 0x6C88 has no lowercase glyphs. The ESP web UI uppercases text before
    sending; lowercase sent raw over the serial console renders as garbage. Keep text A-Z / 0-9 / punctuation.
* `ls` lists all 21 commands (par = 19, settext = 20). `ex` is unchanged.

## How both fit (the trick you suggested)
Removing the logo frees its data. The "Strauss Water" bitmap lives at **0x950A-0x95D5 (204 bytes)** and is only
read by the brand-draw routine `0xF67E`, which is called from two places — `0x431C` (idle) and `0xAE28`
(sleep). Repointing **both** to our text draw makes the bitmap dead, and that reclaimed 204 bytes (plus the
erased flash tail) is exactly the room needed for the second command:
* The JUG menu item + its x100 editor and the bulk-read loop live in the reclaimed brand-routine body (0xF67E-0xF735, 184 bytes; the still-used big-font helpers at 0xF79A+ are left intact).
* The command table is grown 19 -> 21 (table relocated to the flash tail, reader repointed `0x83E0/0x83E4`,
  match limit `0x8414` and the `ls` count `0x7B2E` raised to 21). Index 19 = `par`, 20 = `settext`; the shell's
  switch default (`0x7E22`) routes them.
* `par` + EEPROM helpers live in the flash tail (`0xFF5E`); `settext` + the text draw live in the reclaimed
  bitmap (`0x950A`).

## Verified in the emulator (rendered)
* `par=1` -> 3; `par=1,8` writes EEPROM[1]=8; `par` (no args) -> all 77 values then OK.
* JUG editor: display 10 -> **1000** (x100), save 1000 -> raw 10 (dispense value preserved).
* `settext=MY CAFE` stores "MY CAFE"; `settext=GOOD|MORNING` renders "GOOD" over "MORNING" (two rows);
  `settext=` clears it; the idle screen renders the text in place of the logo.
* `ls` -> 21 commands including `par` and `settext`; `ex`/`ver` unaffected; serial stack balanced.
* Byte diff: only the patched addresses + the flash tail + the dead bitmap region changed; EEPROM/config/
  vectors identical; checksums valid.

**Not verified on hardware.** Keep the stock hex ready. Flash, then: `ver` replies; `par=1` reads; `settext=HELLO`
shows HELLO on the idle screen; `settext=` blanks it. Send a photo if the text position needs nudging
(`PAGE`/`XPOS` in `patch_tools/build_both.py`).

## Two-row draw + flash fit (2026-10-20)
The text-draw routine tracks the LCD page in reg 0x1A via a shared `setpos` subroutine; on a `|` it bumps the
page by 2 and re-runs `setpos` (label `lbrk`). To make room for this in the near-full reclaimed bitmap region,
the duplicated EEPROM byte-write strobe (previously inline in both `ee_write` for `par` and `teew` for
`settext`) was factored into a single `wrstrobe` helper (~18 bytes freed; bitmap region 198/204 used). The
ESP web UI (`esp32_bridge/web/index.html`) gained a second line field and uppercases both lines before joining
them with `|`. Build: `patch_tools/build_full.py`. Render check: `/tmp/render_logo.py "GOOD|MORNING"`.

## Reproduce
From `patch_tools/`: `python3 build_both.py` writes the hex.
