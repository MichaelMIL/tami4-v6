// address 0x00f7e2  size 36 bytes
// callers: 00b104,

/* Inlet valve: 10 s safety timeout countdown; closes and latches fault 0x84 */

byte inlet_valve_timeout_tick(byte param_1)

{
  byte bVar1;
  byte unaff_C;
  
  if ((outputs_shadow & 1) != 0) {
    if (inlet_valve_timeout != 0) {
      unaff_C = inlet_valve_timeout != 0;
      inlet_valve_timeout = inlet_valve_timeout - 1;
    }
    param_1 = inlet_valve_timeout;
    if (inlet_valve_timeout == 0) {
      bVar1 = PORTH;
      PORTH = bVar1 & ~RH0;
      outputs_shadow = outputs_shadow & 0xfe;
      param_1 = inlet_valve_fault << 1 | unaff_C & 1;
      if (-1 < inlet_valve_fault) {
        param_1 = 0x84;
        inlet_valve_fault = -0x7c;
      }
    }
  }
  return param_1;
}

