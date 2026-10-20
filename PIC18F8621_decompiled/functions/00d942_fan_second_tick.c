// address 0x00d942  size 44 bytes
// callers: 00b104,

/* Per second: count down fan run-on timers */

byte fan_second_tick(void)

{
  byte bVar1;
  byte bVar2;
  bool bVar3;
  bool bVar4;
  
  bVar3 = (char)fan_runon_hi < '\0';
  if (!bVar3) {
    bVar2 = ~(fan_runon_lo == '\0');
    bVar3 = bVar2 != 0 || fan_runon_hi < -bVar2;
    if (bVar2 == 0 && fan_runon_hi >= -bVar2) {
      bVar4 = fan_runon_lo != '\0';
      fan_runon_lo = fan_runon_lo + -1;
      bVar3 = fan_runon_hi != ~bVar4;
      fan_runon_hi = fan_runon_hi - ~bVar4;
    }
  }
  bVar2 = fan_heater_runon_hi << 1 | bVar3;
  if (-1 < (char)fan_heater_runon_hi) {
    bVar1 = ~(fan_heater_runon_lo == '\0');
    bVar2 = -~(fan_heater_runon_lo == '\0') - fan_heater_runon_hi;
    if (bVar1 == 0 && -bVar1 <= fan_heater_runon_hi) {
      bVar3 = fan_heater_runon_lo != '\0';
      fan_heater_runon_lo = fan_heater_runon_lo + -1;
      bVar2 = 0;
      fan_heater_runon_hi = fan_heater_runon_hi - ~bVar3;
    }
  }
  return bVar2;
}

