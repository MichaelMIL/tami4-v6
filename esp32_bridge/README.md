# ESP32 Wi-Fi bridge for the PIC18F8621 service console

A PlatformIO / Arduino firmware that sits on the dispenser's service UART (EUSART2) and serves a web UI
with everything `../PIC18F8621_decompiled/serial_gui.py` has. It needs no PC once it is set up.

**Both PIC firmwares are supported** (bridge firmware 1.1.0):
* **v3.47:** 9600 baud, hashed commands. Tabs Status, Parameters, Counters, Controls.
* **v3.5.13:** 38400 baud, text shell (`../v3.5.13/README.md`). Tabs Status, Controls (outputs, dispense, key press, testing mode), Setup
  (language, shipping / production mode, factory reset), a **two-row Idle-screen text** control (logo-text / par-settext image, `settext`), an editable **Parameters** tab (par-jug image, `par`) and a read-only ROM reference.

> **v3.5.13 patch images.** `PIC18F8621-3.5.13-par-settext.hex` (recommended) has **both** `par` (edit parameters) and `settext=TEXT` (replace the idle "Strauss Water" logo with **up to two rows** of custom text) in one image, by reclaiming the freed logo bitmap. The LCD font is **uppercase-only**, so the web UI uppercases the text before storing it; a `|` in the stored text is a row break (the web UI's two line fields join with it). Older single-feature images also exist (`par-jug.hex`, `logotext.hex`). The UI offers both features; a command the flashed image lacks returns `ERROR -123`.

At boot the ESP probes `VER` at 9600, then `ver` at 38400 (the order that is harmless for both), and the UI shows the matching tabs.
Settings → PIC firmware can force a version or re-run detection (saved in NVS). If nothing answers it stays at 9600.

* **Tabs (v3.47):** Status (readings + decoded `ST` faults, auto-refresh), Parameters (GPL table with group, value in real units,
  full explanation and decoded option bits, filter; SP/SMN/SMX/GP/RP, baseline compare/restore, CSV), Counters (GCL, GC/RC/gNN, baseline restore, CSV), Controls (dispense,
  child protection, extra-hot, modes, XC), Console (raw commands with live hash preview), Log, Settings, Firmware.
* **Wi-Fi:** joins home Wi-Fi; if that fails or is lost for 30 s it starts its own AP `PIC-Service-XXXX`
  with a captive setup page at `192.168.4.1`. The AP shuts off again when home Wi-Fi is back (unless "Keep AP on").
  mDNS name `picservice.local`. NTP time when on home Wi-Fi.
* **OTA:** ArduinoOTA and a web upload page (Firmware tab). The unit on the bench answers at **`tami.local`**; OTA to it with `~/.platformio/penv/bin/pio run -e esp32s3_ota -t upload --upload-port tami.local` (auth = `ota_pass` in `secrets.ini`).
* **Security / safety:**
  * Everything is behind HTTP basic auth, and the AP uses WPA2.
  * EEPROM writes and hardware actions are **disabled by default** and are enforced on the ESP, not just in the
    browser. Enable them under Settings.
  * Even when enabled, every write or hardware action needs a confirmation flag. `RPL` / `RCL` need the name
    typed back (v3.5.13: `restore_factory_settings`). STOP is always allowed: `STP` on v3.47; on v3.5.13, which has no stop command,
    `output=4,0` / `output=5,0` / `output=6,0` (cold, hot, inlet valve off).
  * v3.47 commands are classified by the firmware's **hash**, like the PC GUI, so look-alike words (e.g. `FOO` = `RCL`)
    can't sneak through. v3.5.13 compares names exactly, so unknown words run nothing (`ERROR -123`) and are allowed.

## Hardware

Default board: **ESP32-S3 Super Mini**, env `esp32s3`. Its silkscreen **RX = GPIO44**, **TX = GPIO43** (UART0 pins), onboard WS2812 RGB LED on GPIO48. Wire **board RX (44) <- PIC TX2 (RG1)** and **board TX (43) -> PIC RX2 (RG2)** through a level shifter. The env moves the USB-CDC console (`ARDUINO_USB_CDC_ON_BOOT=1`) so the debug log does not collide with the PIC TX line on GPIO43, and pins 4 MB flash. A WEMOS LOLIN S2 Mini (env `s2mini`, RX=18 TX=17 LED=15) and a classic ESP32 DevKit (env `esp32dev`, RX=16 TX=17 LED=2) also build.

> At each ESP reset the ROM prints its boot log on GPIO43 (U0TXD) at 115200, so the PIC briefly sees that burst on RX2 and answers `ERROR`; it is harmless. A different S3 board (e.g. DevKitC-1) uses other pins — set `PIC_RX_PIN`/`PIC_TX_PIN` to match.

> **S3 flash size.** The `esp32-s3-devkitc-1` board default assumes 8 MB flash. A 4 MB S3 module boot-loops with `partition ... exceeds flash chip size 0x400000`; the `esp32s3` env pins `flash_size = 4MB` and the `default.csv` (4 MB, dual-OTA) partition table to fix that. For an 8 MB/16 MB S3, remove those two lines.

| PIC side | Level shifter | ESP32-S2 (S2 Mini) |
|---|---|---|
| RG1 / TX2 | HV1 ↔ LV1 | GPIO 18 (RX) |
| RG2 / RX2 | HV2 ↔ LV2 | GPIO 17 (TX) |
| PIC VDD (5 V?) | HV | — |
| — | LV | 3V3 |
| GND | GND | GND |

**Check the PIC's supply voltage before wiring.**
* The PIC18F8621 (non-LF) normally runs at 5 V, and **ESP32 pins are not 5 V tolerant.**
* The PIC's RX2 is a Schmitt-trigger input that needs about 0.8 × VDD (≈ 4 V at 5 V). A bare 3.3 V TX may not be read reliably.
* Use a BSS138 bidirectional level-shifter module (HV = PIC VDD, LV = 3.3 V).
* If you measure 3.3 V on the PIC's VDD, wire it directly.

**Mains safety.** Before connecting anything permanently, check that the controller's logic ground is isolated
from mains. Some appliance boards use non-isolated (capacitive-dropper) supplies; then the ESP would sit at mains
potential. The bench setup with the CH340 has been fine so far, but powering the ESP from the dispenser board
is only safe on an isolated supply.

Pins are set per environment in `platformio.ini` (`PIC_RX_PIN`, `PIC_TX_PIN`, `LED_PIN`).
Status LED (GPIO 15 on the S2 Mini): on during a serial exchange, blinking when only the AP is up.

## Build and flash

```
cd esp32_bridge
~/.platformio/penv/bin/pio run -e esp32s3 -t upload       # first time over USB (default board; use 6.2.0+ pio)
~/.platformio/penv/bin/pio device monitor                 # USB log (115200)
~/.platformio/penv/bin/pio run -e esp32s3_ota -t upload    # later, over Wi-Fi
```
A boot-looping board cannot take an OTA update; flash over USB to recover. (For the S2 Mini use `-e s2mini` / `-e s2mini_ota`.)

If the S2 Mini doesn't show up as a serial port, hold **0**, tap **RST**, release **0** (download mode), upload,
then tap RST.

Explanations come from `../PIC18F8621_decompiled/parameter_info.json`; `copy_info.py` copies it into `embed/` before each build
(served at `/api/paraminfo`).

`secrets.ini` (not shared) holds the first-boot web, AP and OTA passwords and optionally the home Wi-Fi.
Change them later under Settings. They are stored in NVS and survive OTA updates.

## First use

1. Connect to Wi-Fi `PIC-Service-XXXX` (AP password from `secrets.ini`). The setup page should pop up; if not,
   open `http://192.168.4.1`. Log in with the web user / password.
2. Settings → Home Wi-Fi → Scan, pick the network, enter its password, Save, Reboot.
3. Browse to `http://picservice.local` (or the IP shown in your router).
4. Status → Refresh all. Parameters → Read all. Counters → Read all. Compare against the earlier dumps before
   enabling any writes.

## API (all behind basic auth)

| Method | Path | Notes |
|---|---|---|
| POST | `/api/cmd` | `line=GP 21` / `line=temp` (+ `confirm=1`, or `confirm=RPL`/`RCL`/`restore_factory_settings` for bulk). Returns `{line,fw,cmd,cat,status,lines[]}`. 403 = disabled in Settings, 428 = needs confirmation. Max 11 (v3.47) / 29 (v3.5.13) characters |
| GET | `/api/info` | firmware, Wi-Fi/AP state, settings, `pic` = `{fw, mode, baud, maxLine, detected, ver}` |
| POST | `/api/picfw` | `fw=auto` (detect now) / `3.47` / `3.5.13`; saved in NVS |
| POST | `/api/settings` | `ssid wpass host webUser webPass apPass otaPass tz apAlways allowEeprom allowHw` |
| GET | `/api/scan` | Wi-Fi networks |
| GET/POST | `/api/baseline` | stored GPL/GCL baseline (default: the pre-test dumps compiled in); POST `gpl=`/`gcl=`, or `reset=1` |
| GET | `/api/log`, POST `/api/log/clear` | last 16 KB of exchanges (RAM) |
| POST | `/api/reboot`, `/update` | reboot, web OTA (multipart `.bin`) |

Example: `curl -u admin:PASS -d 'line=GPL' http://picservice.local/api/cmd`

## Status

Builds for `esp32s3` (default), `s2mini` and `esp32dev` (1.1.0). **Flashed and running on the unit** (ESP32-S3 Super Mini, `tami.local`, kept current over OTA). The v3.5.13 **Parameters** tab reads all values in one `par` bulk read (with per-param fallback) and writes with `par=i,v`; out-of-range writes are **warned** (not blocked, since this firmware no longer range-checks) and gated by "Allow EEPROM writes". The **Idle-screen text** card has two line fields, uppercased and joined with `|`. Single-line uppercase text works on the currently-flashed PIC; the second row needs the PIC re-flashed with the two-row `par-settext.hex` (older firmware draws a literal `|`).
