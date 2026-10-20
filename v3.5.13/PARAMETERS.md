# v3.5.13 parameter table

Source: EEPROM section of `PIC18F8621-3.5b.hex` (the file you gave me, which may differ from what is in the unit now) and the ROM parameter table at 0xDDCF.

* **Value address** = parameter index. **Max address** = index + 0x4D. **Min address** = index + 0x9A.
* Edit only the value byte, and keep it within min..max. The firmware validates values against these limits.
* Defaults are from ROM, so `restore_factory_settings` would apply them.
* Descriptions come from the v3.47 analysis. Parameters 75 and 76 are new.

| # | Value addr | Max addr | Min addr | Name | Value | Min | Max | Default | Meaning | Note |
|---|---|---|---|---|---|---|---|---|---|---|
| 0 | 0x00 | 0x4D | 0x9A | `FT` | 0 | 255 | 255 | 0 | First-time/factory flag; non-zero at power-up clears usage counters |  |
| 1 | 0x01 | 0x4E | 0x9B | `TSENSORSRATE` | 3 | 1 | 10 | 3 | Temperature sampling period |  |
| 2 | 0x02 | 0x4F | 0x9C | `TSLEEPCOLDCUTOUT` | 6 | 3 | 20 | 10 | Cold cut-out in sleep mode (deg C) | changed |
| 3 | 0x03 | 0x50 | 0x9D | `TNORMALCOLDCUTOUT` | 6 | 5 | 20 | 10 | Cold cut-out, normal (deg C) | changed |
| 4 | 0x04 | 0x51 | 0x9E | `TTOPDELTACOLD` | 8 | 5 | 20 | 8 | Cold top sensor hysteresis |  |
| 5 | 0x05 | 0x52 | 0x9F | `TBOTTOMDELTACOLD` | 4 | 1 | 5 | 4 | Cold bottom sensor hysteresis |  |
| 6 | 0x06 | 0x53 | 0xA0 | `TMAXCOLDDIFF` | 50 | 1 | 100 | 50 | Max difference between cold sensors |  |
| 7 | 0x07 | 0x54 | 0xA1 | `TCOLDOPENDELAY` | 20 | 1 | 100 | 20 | Cold valve open delay |  |
| 8 | 0x08 | 0x55 | 0xA2 | `TCOLDCLOSEDELAY` | 30 | 1 | 100 | 30 | Cold valve close delay |  |
| 9 | 0x09 | 0x56 | 0xA3 | `TCOMPOFFDELAY` | 18 | 6 | 30 | 18 | Compressor restart delay |  |
| 10 | 0x0A | 0x57 | 0xA4 | `TCOMPMAXON` | 45 | 9 | 120 | 45 | Compressor max continuous run (min) |  |
| 11 | 0x0B | 0x58 | 0xA5 | `TVALVEON` | 30 | 30 | 60 | 30 | Valve max open time (safety) |  |
| 12 | 0x0C | 0x59 | 0xA6 | `TCOLDPRESS` | 20 | 0 | 200 | 20 | Cold key press time |  |
| 13 | 0x0D | 0x5A | 0xA7 | `TMAXPRESS` | 30 | 6 | 60 | 30 | Max key press time |  |
| 14 | 0x0E | 0x5B | 0xA8 | `TUVPERIOD_T3_26` | 12 | 6 | 24 | 12 | UV cycle period |  |
| 15 | 0x0F | 0x5C | 0xA9 | `TMINFILAMENTS_T6` | 8 | 1 | 180 | 8 | UV filament warm-up (s) |  |
| 16 | 0x10 | 0x5D | 0xAA | `TUVKEEP` | 40 | 10 | 120 | 40 | UV on-time, keep cycle |  |
| 17 | 0x11 | 0x5E | 0xAB | `TUVOPERATING_T3_26` | 3 | 0 | 5 | 3 | UV lamp verify delay |  |
| 18 | 0x12 | 0x5F | 0xAC | `TUVON` | 40 | 10 | 120 | 40 | UV on-time per cycle |  |
| 19 | 0x13 | 0x60 | 0xAD | `TMAXHOTDIFF` | 70 | 1 | 100 | 70 | Max difference between hot sensors |  |
| 20 | 0x14 | 0x61 | 0xAE | `TSLEEPHOTCUTOUT` | 60 | 50 | 80 | 60 | Hot tank temperature in sleep (deg C) |  |
| 21 | 0x15 | 0x62 | 0xAF | `TBOIL` | 100 | 80 | 100 | 100 | Boil / extra-hot target (deg C) |  |
| 22 | 0x16 | 0x63 | 0xB0 | `TDELTAHOTTOPNORMALCUTOUT` | 4 | 0 | 10 | 4 | Hot top cut-out offset, normal |  |
| 23 | 0x17 | 0x64 | 0xB1 | `THOTTOPSLEEPDELTA` | 3 | 1 | 5 | 3 | Hot top hysteresis, sleep |  |
| 24 | 0x18 | 0x65 | 0xB2 | `THOTTOPNORMALDELTA` | 2 | 1 | 3 | 2 | Hot top hysteresis, normal |  |
| 25 | 0x19 | 0x66 | 0xB3 | `THOTBOTTOMSLEEPDELTA` | 3 | 1 | 30 | 3 | Hot bottom hysteresis, sleep |  |
| 26 | 0x1A | 0x67 | 0xB4 | `THOTBOTTOMNORMALDELTA` | 10 | 1 | 30 | 10 | Hot bottom hysteresis, normal |  |
| 27 | 0x1B | 0x68 | 0xB5 | `TDELTAHOTTOPEXHOTCUTOUT` | 1 | 1 | 5 | 1 | Hot top cut-out offset, extra-hot |  |
| 28 | 0x1C | 0x69 | 0xB6 | `TDELTAHOTFULLPOWER` | 4 | 1 | 20 | 4 | Below target by this much: full heater power |  |
| 29 | 0x1D | 0x6A | 0xB7 | `THOTCONTALLOWDISPENSE` | 0 | 80 | 90 | 0 | Min hot temperature to allow hot dispense (deg C) | OUT OF RANGE |
| 30 | 0x1E | 0x6B | 0xB8 | `THEATERMAXON` | 20 | 5 | 20 | 20 | Heater max on-time (min) |  |
| 31 | 0x1F | 0x6C | 0xB9 | `THOTWATERDISPMIN` | 150 | 10 | 255 | 150 | Hot dispense time limit (x100 ms) |  |
| 32 | 0x20 | 0x6D | 0xBA | `THOTOPENDELAY` | 20 | 1 | 100 | 20 | Hot valve open delay |  |
| 33 | 0x21 | 0x6E | 0xBB | `THOTCLOSEDELAY` | 30 | 1 | 100 | 30 | Hot valve close delay |  |
| 34 | 0x22 | 0x6F | 0xBC | `ZCCYCLELENGTH` | 10 | 1 | 200 | 10 | Heater burst-fire cycle length |  |
| 35 | 0x23 | 0x70 | 0xBD | `TSLEEPDELAY_T3_26` | 3 | 3 | 24 | 6 | Inactivity before auto sleep | changed |
| 36 | 0x24 | 0x71 | 0xBE | `TMMIUPDATERATE` | 15 | 1 | 100 | 15 | Display update rate |  |
| 37 | 0x25 | 0x72 | 0xBF | `SYSTEMCONFIG` | 126 | 0 | 255 | 126 | Config bits: 0-1 heater type, 3 UV fitted, 6 dual hot sensors |  |
| 38 | 0x26 | 0x73 | 0xC0 | `WATERFLOW` | 12 | 0 | 100 | 12 | Flow rate for measured portions |  |
| 39 | 0x27 | 0x74 | 0xC1 | `TEMPHOTCHNGTIME` | 30 | 3 | 60 | 30 | Extra-hot timeout |  |
| 40 | 0x28 | 0x75 | 0xC2 | `CHILDPROTECT` | 0 | 0 | 1 | 1 | Child protection enabled | changed |
| 41 | 0x29 | 0x76 | 0xC3 | `CHILDPROTECTTIME` | 55 | 2 | 200 | 55 | Child protection timing |  |
| 42 | 0x2A | 0x77 | 0xC4 | `TEMPCOLDCHNGTIME` | 15 | 1 | 60 | 15 | Cold temp change time |  |
| 43 | 0x2B | 0x78 | 0xC5 | `SYSTEMCONFIG2` | 41 | 0 | 255 | 41 | Config bits: 3-5 language |  |
| 44 | 0x2C | 0x79 | 0xC6 | `SYSTEMCONFIG3` | 68 | 0 | 255 | 68 | Config bits: 0 cold sensor sel, 2 Celsius, 4/5 wake-up 1/2, 7 clock style |  |
| 45 | 0x2D | 0x7A | 0xC7 | `TCOMPPAUSEMIN` | 30 | 10 | 60 | 30 | Compressor pause after max run |  |
| 46 | 0x2E | 0x7B | 0xC8 | `TDELTAHOTBOTEXHOTCUTOUT` | 35 | 1 | 50 | 35 | Hot bottom cut-out offset, extra-hot |  |
| 47 | 0x2F | 0x7C | 0xC9 | `TDELTAHOTBOTNORMALCUTOUT` | 15 | 5 | 20 | 15 | Hot bottom cut-out offset, normal |  |
| 48 | 0x30 | 0x7D | 0xCA | `DBNCCNTR` | 10 | 1 | 100 | 10 | Key debounce counter |  |
| 49 | 0x31 | 0x7E | 0xCB | `TPOWERDELAY` | 0 | 0 | 72 | 0 | Power-on delay |  |
| 50 | 0x32 | 0x7F | 0xCC | `TNORMALCOOLCUTOUT` | 15 | 10 | 20 | 15 | Cool cup target (deg C) |  |
| 51 | 0x33 | 0x80 | 0xCD | `TNORMALWARMCUTOUT` | 30 | 10 | 50 | 30 | Warm cup target (deg C) |  |
| 52 | 0x34 | 0x81 | 0xCE | `QTYCOOLWATER` | 14 | 6 | 30 | 14 | Cool cup quantity |  |
| 53 | 0x35 | 0x82 | 0xCF | `QTYWARMWATER` | 14 | 6 | 30 | 14 | Warm cup quantity |  |
| 54 | 0x36 | 0x83 | 0xD0 | `WKUPHOUR1` | 0 | 0 | 23 | 0 | Wake-up 1 hour |  |
| 55 | 0x37 | 0x84 | 0xD1 | `WKUPMINUTE1` | 0 | 0 | 59 | 0 | Wake-up 1 minute |  |
| 56 | 0x38 | 0x85 | 0xD2 | `WKUPHOUR2` | 0 | 0 | 23 | 0 | Wake-up 2 hour |  |
| 57 | 0x39 | 0x86 | 0xD3 | `WKUPMINUTE2` | 0 | 0 | 59 | 0 | Wake-up 2 minute |  |
| 58 | 0x3A | 0x87 | 0xD4 | `SYSTEMCONFIG4` | 255 | 0 | 255 | 35 | Config bits: 0 shipping mode, 2 filter switch, 3 dryer sensor, 4 device sensor, 5 UV lamp switch (v3.47 meaning) | changed |
| 59 | 0x3B | 0x88 | 0xD5 | `TDEVICECUTOUT` | 55 | 20 | 75 | 55 | Device sensor: fan on above (deg C) |  |
| 60 | 0x3C | 0x89 | 0xD6 | `TDELTADEVICE` | 10 | 5 | 20 | 10 | Device sensor hysteresis |  |
| 61 | 0x3D | 0x8A | 0xD7 | `TFANOPERATING` | 1 | 0 | 10 | 1 | Fan run-on after compressor stop (min) |  |
| 62 | 0x3E | 0x8B | 0xD8 | `QTYCOLDWATER` | 18 | 6 | 30 | 14 | Cold cup quantity | changed |
| 63 | 0x3F | 0x8C | 0xD9 | `TMAXDRYER` | 60 | 50 | 80 | 60 | Dryer over-temperature cut-out (deg C) |  |
| 64 | 0x40 | 0x8D | 0xDA | `TDELTAREPLACE` | 10 | 1 | 25 | 10 | Replacement reminder interval |  |
| 65 | 0x41 | 0x8E | 0xDB | `SYSTEMCONFIG5` | 86 | 0 | 255 | 82 | Config bits: 1 jug, 2 hot key hold, 5-6 APPLICATION | changed |
| 66 | 0x42 | 0x8F | 0xDC | `QTYHOTWATER` | 14 | 6 | 30 | 14 | Hot cup quantity |  |
| 67 | 0x43 | 0x90 | 0xDD | `QTYJUGWATER` | 10 | 3 | 15 | 10 | Jug quantity |  |
| 68 | 0x44 | 0x91 | 0xDE | `THOTPRESS` | 100 | 0 | 200 | 100 | Hot key press time |  |
| 69 | 0x45 | 0x92 | 0xDF | `SYSTEMCONFIG6` | 0 | 0 | 255 | 0 | Config bits: 0 periodic UV |  |
| 70 | 0x46 | 0x93 | 0xE0 | `MAXVOLPERFILTER` | 100 | 0 | 255 | 100 | Volume per filter |  |
| 71 | 0x47 | 0x94 | 0xE1 | `TUVVERIFYOFF` | 60 | 10 | 120 | 60 | UV verify-off delay |  |
| 72 | 0x48 | 0x95 | 0xE2 | `TUVVERIFYOFFPERIOD` | 3 | 1 | 12 | 3 | UV verify retry period |  |
| 73 | 0x49 | 0x96 | 0xE3 | `TUVLONGVERIFY` | 60 | 30 | 120 | 60 | UV long verify period |  |
| 74 | 0x4A | 0x97 | 0xE4 | `TABNORMALCOLDHIGH` | 45 | 20 | 100 | 45 | Cold water abnormally warm threshold (forces UV) |  |
| 75 | 0x4B | 0x98 | 0xE5 | `SYSTEMCONFIG7` | 3 | 0 | 255 | 2 | NEW in v3.5.13: config bits (meaning not decoded) | changed |
| 76 | 0x4C | 0x99 | 0xE6 | `PLASTICSLEEPMODESTARTHEATING` | 50 | 45 | 60 | 50 | NEW in v3.5.13: sleep-mode start-heating temperature for plastic hot tank (deg C) |  |
