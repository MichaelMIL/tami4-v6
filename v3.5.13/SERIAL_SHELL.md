# v3.5.13 serial shell (EUSART2)

## Why "the UART is not working"
v3.5.13 sets **BRG16 = 1** in BAUDCON2 (`BSF BAUDCON2,3` in hw_init at 0xC1F8) with the same divisor as v3.47
(SPBRG2 = 25, SPBRGH2 = 0, BRGH = 1). That gives Fosc/(4*26) = **38,400 baud** (4 MHz crystal) instead of 9,600.
At 9,600 the replies look like garbage. Nothing needs to be enabled. The shell task is created unconditionally at boot.

**Settings: 38400 8N1, CR line ending, characters echoed, max 29 characters per line.**
`picocom -b 38400 --omap crlf /dev/ttyUSB1` (the adapter enumerated as ttyUSB1 after being replugged).
Send a bare CR first to flush any noise. Commands are lowercase and case-sensitive.

## Syntax
`command` or `command=arg1` or `command=arg1,arg2` (numbers parsed with atoi). Unknown command or wrong argument count: `ERROR -123`.

## Commands (table at ROM 0xFE1C, printed by `ls`)
| # | Command | Args | Effect | Safety |
|---|---|---|---|---|
| 0 | `ls` | - | List commands | read |
| 1 | `temp` | - | Temperatures HT, HB, CB (deg C, -1 = open) | read |
| 2 | `input` | - | Raw A2D (HT, HB, CT, CB), buttons, inputs UV_POS (RJ0), UV_READY (RJ1), HEATER_FEEDBACK, output states | read |
| 3 | `output` | none / `n,v` | No args: list outputs 0 UV_DRIVE, 1 FAN, 2 COMPRESSOR, 3 HEATER, 4 COLD_VALVE, 5 HOT_VALVE, 6 INLET_VALVE, 7 LCDBKLT. With `n,v`: set output n | read / **actuates** |
| 4/5/6 | `hot` / `cold` / `mix` | required | Dispense hot / cold / mix | **actuates** |
| 7 | `ex` | ? | Calls 0xA322 and 0xABFC (not yet identified) | unknown |
| 8 | `ver` | - | "T6 3.5.13 Feb 07 2019 17:37:44" plus hot tank type | read |
| 9 | `get_hwt_type` | - | Hot tank type: Plastic / Stainless | read |
| 10 | `get_errors_bitmap` | - | List of active error ids | read |
| 11 | `get_wu` | - | Water usage counter | read |
| 12 | `restore_factory_settings` | - | Restore EEPROM defaults | **writes** |
| 13 | `set_language` | 1 | Set language | **writes** |
| 14 | `set_shipping_mode` | 1 | Shipping mode on/off | **writes** |
| 15 | `set_production_mode` | 1 | Production mode, then reset | **writes** |
| 16 | `manual_press` | 2 | Simulate a key press | **actuates** |
| 17 | `testing_mode` | 1 | Enter/leave testing mode | **changes state** |
| 18 | `reset` | - | Reset controller | **resets** |

## First read-only session (this unit)
ver = T6 3.5.13 Feb 07 2019 17:37:44 · temp: all -1 (sensors open, A2D 1023) · Buttons 110 · UV_POS=0 UV_READY=0
HEATER_FEEDBACK=1 · all outputs 0 · hot tank Plastic · errors bitmap "6,21," · water usage 10667.
Log: `serial/shell_readonly_*.txt`.
