// address 0x00f9f4  size 10 bytes
// callers: 00b256,

/* Hot water valve (RH1): clear state */

undefined1 hot_valve_init(void)

{
  hot_valve_timeout = 0;
  hot_valve_fault = 0;
  return 0;
}

