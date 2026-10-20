// address 0x00f760  size 10 bytes
// callers: 00b256,

/* Inlet valve (RH0): clear state */

undefined1 inlet_valve_init(void)

{
  inlet_valve_timeout = 0;
  inlet_valve_fault = 0;
  return 0;
}

