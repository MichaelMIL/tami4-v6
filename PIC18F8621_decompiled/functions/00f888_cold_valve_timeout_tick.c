// address 0x00f888  size 36 bytes
// callers: 00b104,

/* Cold water valve: 10 s safety timeout countdown; closes and latches fault 0x84 */

byte cold_valve_timeout_tick(byte param_1)

{
  byte bVar1;
  byte unaff_C;
  
  if ((outputs_shadow & 4) != 0) {
    if (cold_valve_timeout != 0) {
      unaff_C = cold_valve_timeout != 0;
      cold_valve_timeout = cold_valve_timeout - 1;
    }
    param_1 = cold_valve_timeout;
    if (cold_valve_timeout == 0) {
      bVar1 = PORTH;
      PORTH = bVar1 & ~RH2;
      outputs_shadow = outputs_shadow & 0xfb;
      param_1 = cold_valve_fault << 1 | unaff_C & 1;
      if (-1 < cold_valve_fault) {
        param_1 = 0x84;
        cold_valve_fault = -0x7c;
      }
    }
  }
  return param_1;
}

