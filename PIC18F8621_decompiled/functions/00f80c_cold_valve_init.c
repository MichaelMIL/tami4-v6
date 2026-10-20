// address 0x00f80c  size 10 bytes
// callers: 00b256,

/* Cold water valve (RH2): clear state */

undefined1 cold_valve_init(void)

{
  cold_valve_timeout = 0;
  cold_valve_fault = 0;
  return 0;
}

