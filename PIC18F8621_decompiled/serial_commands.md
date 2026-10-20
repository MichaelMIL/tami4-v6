# Serial service console (EUSART2, 9600 baud, 8N1)

* Characters are echoed. A line is at most 11 characters, terminated by CR.
* The command word is hashed: `hash ^= (char << position) & 0xFF`. Collisions are resolved by the first letter:
  0xD4 becomes 0xD3 unless the word starts with `R`; 0xFB becomes 0xFA unless `S`; 0xF1 becomes 0xF0 unless `G`;
  0xA9 becomes 0xA7 unless `S`; 0xE1 becomes 0xE0 unless `G`; 0x8D becomes 0x8C unless `G`; any word starting with `g` becomes 0x67.
* Arguments are **numbers**, parsed with `atol` from the 4th character on (leading spaces skipped): `<index>` or `<index>,<value>`.
  Parameter index = EEPROM address 0..74 (index 0 = FT flag; id - 1, see `eeprom_parameters.txt`). Counter index 0..17 (16 counters + CMM, CGT).
* Fault replies: 0x81 unknown command, 0x82 rejected, 0x85 bad argument.

## Listed commands (28-entry ROM command table at 0xFAB0; the help command prints them)

| Command | Action |
|---|---|
| `PD` | Power down (standby); entry 0 of the help list |
| `RS` | Reset the controller |
| `NM` | Normal mode (wake) |
| `SM` | Sleep mode |
| `ST` | Status of every component (fault codes) |
| `GHT` / `GCT` | Hot / cold tank temperatures |
| `GDT` / `COT` | Device (AN6) / dryer-condenser (AN7) temperature |
| `DCW` / `DHW` / `STP` | Dispense cold / dispense hot / stop |
| `CP0` / `CP1` | Child protection off / on |
| `EH1` / `EH0` | Extra-hot on / off |
| `GCS` / `GHS` | Cooling / heating system state |
| `HTS` `UVS` `IVS` `CVS` `HVS` | Heater / UV lamp / inlet / cold / hot valve state |
| `CWC` | Child-protection state (see bug) |
| `GCH` | **Bug:** rejected (0x82); its hash collides with CWC and is not remapped |
| `TC`, `AC` | Rejected (0x82), not implemented in this build |
| `g` | Set counter: `gNN <value>` (2-digit index right after `g`, 32-bit value) |

## Hidden commands (handled by the firmware, not in the help table)

| Command | Hash | Confidence | Action / syntax |
|---|---|---|---|
| `GP` | 0xE7 | **Confirmed on device** | `GP <i>`: print raw EEPROM value of parameter i |
| `SP` | 0xF3 | **Confirmed on device** | `SP <i>,<v>`: set parameter i to v (checked against min/max) |
| `RP` | 0xF2 | **Confirmed on device** | `RP <i>`: restore parameter i to its ROM default |
| `GPL` | 0xD7 | **Confirmed on device** | Print all 75 parameters as `index,name,min,max,value,default` |
| `RPL` | 0xC2 | High | Restore all parameters to ROM defaults |
| `SMN` | 0xF0 | High | `SMN <i>,<v>`: set minimum of parameter i |
| `SMX` | 0xA9 | High | `SMX <i>,<v>`: set maximum of parameter i |
| `GC` | 0xC1 | **Confirmed on device** | `GC <i>`: print usage counter i |
| `RC` | 0xD4 | High (only 2-letter `R` word) | `RC <i>`: clear usage counter i and save |
| `GCL` | 0xF1 | **Confirmed on device** | Print all counters with names |
| `RCL` | 0xE4 | High | Clear all 16 counters and both byte statistics |
| `VER` | 0x94 | **Confirmed on device** | Print firmware version "T6 3.47V" |
| `XC` | 0xDE | Medium | `XC <n>`: execute entry n of the command table |
| `LCL` | 0xFA | **Confirmed on device** | Help: print the command names |

How the hidden words were found: they are not stored anywhere in the firmware, and an
8-bit hash cannot be inverted uniquely. Each word was chosen because it reproduces the exact hash (including the first-letter
rules), matches the handler's behaviour, and follows the naming scheme of the listed commands. The scheme shows clear
symmetries: GP/SP/RP, GC/RC, GPL/RPL, GCL/RCL, SMN/SMX. Any other word with the same (effective) hash triggers the same command.

**Caution:** `SP`, `SMN`, `SMX`, `RP`, `RPL`, `RC`, `RCL` and `g` write EEPROM (settings, limits, usage counters).
