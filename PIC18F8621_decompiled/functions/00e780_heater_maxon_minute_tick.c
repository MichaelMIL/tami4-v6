// address 0x00e780  size 36 bytes
// callers: 00b104,

/* Per minute: heater maximum on-time countdown; on expiry off + fault 0x84 */

byte heater_maxon_minute_tick(void)

{
  byte bVar1;
  byte unaff_C;
  
  bVar1 = 0;
  if (heater_power_level != '\0') {
    if (heater_maxon_timer != 0) {
      unaff_C = heater_maxon_timer != 0;
      heater_maxon_timer = heater_maxon_timer - 1;
    }
    bVar1 = heater_maxon_timer;
    if (heater_maxon_timer == 0) {
      heater_output_off(0);
      heater_output_enable = 0;
      heater_power_level = '\0';
      bVar1 = heater_fault << 1 | unaff_C & 1;
      if (-1 < heater_fault) {
        bVar1 = 0x84;
        heater_fault = -0x7c;
      }
    }
  }
  return bVar1;
}

