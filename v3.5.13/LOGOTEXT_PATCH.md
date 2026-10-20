# v3.5.13 patch: replace the "Strauss Water" logo with your own text (set over serial)

Image: **`PIC18F8621-3.5.13-logotext.hex`**. Patch of stock `PIC18F8621-3.5b.hex`; EEPROM, config words and
all reset/interrupt vectors are byte-identical; hex checksums valid.

## What it does
* Adds a serial command **`settext=YOUR TEXT`** that stores a custom string (up to 20 chars) in spare EEPROM
  (0x130). It survives reboot. `settext=` with nothing after the `=` clears it.
* The idle screen's **"Strauss Water" logo is replaced by that text**, drawn in the firmware's built-in 5x8
  font. If the text is empty, the centre is left **blank** (logo gone, nothing shown).

## How it was found / built
The reference RE in `../PIC18F8621_decompiled/` is for firmware **v3.47**, so its addresses don't match your
v3.5.13 unit. Everything here was located directly in `PIC18F8621-3.5b.hex` and **verified by rendering the
LCD inside the emulator** (the emulator reconstructs the ST7565 framebuffer from the LCD writes):
* LCD driver: command `0xD8C0`, data `0xD8E4` (PORTD data bus, PORTE strobes).
* The idle brand is drawn by `0xF67E`, called at **`0x431C`** inside the idle-screen routine `0x424E`.
* Built-in 5x8 ASCII font at **`0x6C88`** (glyph = `0x6C88 + char*5`, 5 columns).

The patch:
* Reuses the unused **`ex`** command slot for `settext` (table entry `0xFE2A`-> "settext", switch case `0x7B70`
  -> `GOTO` our handler). `ex` is gone (returns `ERROR -123`).
* Replaces the brand-draw call at **`0x431C`** (`CALL 0xF67E`) with a call to our text routine. Because this is
  *inside* `0x424E`, it applies every time the idle screen is drawn (boot and redraws).
* All new code (settext handler + EEPROM read/write + the text/LCD draw) lives in the erased flash tail
  `0xFF5E`-`0xFFFD` (160/162 bytes).

## Verified in the emulator (rendered)
* Idle screen shows the custom text (e.g. `settext=MY CAFE` -> "MY CAFE") instead of "Strauss Water".
* Empty text -> blank centre, "T6 3.5.13" title unaffected.
* `settext=MY CAFE` / `settext=Joe's Bar` / `settext=` store the right bytes; `ver`/`ls` still work; serial
  stack balanced.
* Byte diff: only the addresses above changed; EEPROM/config/vectors identical; checksums valid.

**Not verified on hardware.** Flash it, keep the stock hex ready, then:
1. `ver` over serial still replies -> booted OK.
2. `settext=HELLO` -> the idle centre should read **HELLO**. `settext=` -> centre blank.
3. Send a photo if the position needs adjusting.

## Position / font notes (tunable)
* Text is drawn **left-aligned** at a fixed column (not centred) to fit the 162-byte flash budget. Default
  start column `XPOS=0x1E` (30), LCD page `PAGE=0xB3` (row 3). Both are constants at the top of
  `patch_tools/build_logo.py`; change them and rebuild to move the text. Centring needs ~26 more bytes than
  are free here.
* Font is the firmware's small 5x8 ASCII (same as menu text), uppercase/numbers/punctuation; not the big
  rounded logo font (that font is the brand bitmap, not a reusable alphabet).

## Reproduce
From `patch_tools/`: `python3 build_logo.py` writes the hex.
