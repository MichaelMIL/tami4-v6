// address 0x00fa64  size 36 bytes
// callers: 00b104,

/* Hot water valve: 10 s safety timeout countdown; closes and latches fault 0x84 */

byte hot_valve_timeout_tick(byte param_1)

{
  byte bVar1;
  byte unaff_C;
  
  if ((outputs_shadow & 2) != 0) {
    if (hot_valve_timeout != 0) {
      unaff_C = hot_valve_timeout != 0;
      hot_valve_timeout = hot_valve_timeout - 1;
    }
    param_1 = hot_valve_timeout;
    if (hot_valve_timeout == 0) {
      bVar1 = PORTH;
      PORTH = bVar1 & ~RH1;
      outputs_shadow = outputs_shadow & 0xfd;
      param_1 = hot_valve_fault << 1 | unaff_C & 1;
      if (-1 < hot_valve_fault) {
        param_1 = 0x84;
        hot_valve_fault = -0x7c;
      }
    }
  }
  return param_1;
}

