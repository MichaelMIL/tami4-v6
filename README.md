# tami4-v6 — PIC18F8621 water-dispenser firmware RE + ESP32 Wi-Fi bridge

Reverse engineering of the controller firmware of a Strauss "Tami4" hot/cold water dispenser
(Microchip **PIC18F8621**, Microchip C18 + Salvo RTOS), custom firmware patches for it, and an
**ESP32 Wi-Fi bridge** that exposes the dispenser's service console as a web UI / JSON API.

> The original `PIC18F8621.hex` dump is the only backup of the unit. Never modify it.

## What's here

| Path | What |
|---|---|
| `AGENT_README.md` | Detailed handoff: current state, toolchain, key technical facts, rules for working on the live unit. **Read this first if you plan to do any work.** |
| `PIC18F8621.hex` | Original dump of firmware **T6 3.47** (program + config + EEPROM) |
| `PIC18F8621_ghidra/` | Ghidra project (PIC-18 language) with all names applied. `names.tsv` is the master name list; `scripts/` has the headless Ghidra scripts |
| `PIC18F8621_decompiled/` | Generated outputs for v3.47: full decompile, disassembly, ROM / EEPROM / menu maps, serial protocol docs, `parameter_info.json`, and `serial_gui.py` (Tkinter service-console GUI for both firmwares) |
| `analysis/` | Python scripts that regenerate the decompiled outputs and help with naming / analysis |
| `v3.5.13/` | Firmware **T6 3.5.13** (the image currently on the unit): stock hex, the new 38400-baud text shell docs, a self-built PIC18 assembler / disassembler / emulator (`patch_tools/`), and patched images |
| `esp32_bridge/` | PlatformIO firmware for an ESP32-S3 Super Mini (also S2 Mini / ESP32 DevKit): web UI, JSON API, AP fallback, OTA |
| `PIC18F8621_decompiled_v1_255funcs/`, `..._numeric_masks_backup/` | Obsolete early versions, kept for history |

## Highlights

- **v3.47 firmware fully reverse engineered**: 1195 named functions, every RAM address and ROM byte classified, EEPROM mapped, serial protocol decoded and verified on the unit.
- **v3.5.13 patch images** (`v3.5.13/PIC18F8621-3.5.13-par-settext.hex` is the deliverable): a `par` command to read/write any parameter, a `settext` command that replaces the idle-screen logo with two rows of custom text, and a "JUG WATER QTY" menu item. EEPROM, config words and vectors are byte-identical to stock.
- **ESP32 bridge** auto-detects which PIC firmware is connected, puts every EEPROM write and hardware action behind explicit opt-in plus confirmation, and runs at `tami.local` on the bench.

## Quick start

- **Talk to the unit from a PC**: `cd PIC18F8621_decompiled && python3 serial_gui.py [--port /dev/ttyUSB0] [--demo]`
- **Build / flash the ESP bridge**: copy `esp32_bridge/secrets.ini` from the `[secrets]` defaults in `platformio.ini`, then `pio run -e esp32s3 -t upload`. See `esp32_bridge/README.md` for wiring, level shifting and mains-isolation warnings.
- **Build the v3.5.13 patch**: `cd v3.5.13/patch_tools && python3 build_full.py out.hex`, then flash with a PICkit (MPLAB IPE v6.20). There is no UART bootloader; LVP and MCLRE are disabled in the config bits.
- **Regenerate the v3.47 decompile** after renaming: see "How to change a name and regenerate everything" in `AGENT_README.md`.

## Safety

The service console can write EEPROM and actuate heaters, valves and pumps. Prefer reversible read/write/verify/restore
tests, keep the baselines in `PIC18F8621_decompiled/write_tests/`, and check the PIC's supply voltage and mains isolation
before wiring an ESP to the board. `esp32_bridge/secrets.ini`, `.pio/` and `.vscode/` are gitignored. Keep it that way.
