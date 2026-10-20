// address 0x00b054  size 12 bytes
// callers: 00aa56,

/* Wait close delay then close inlet valve */

undefined1 dispense_close_inlet_after(void)

{
  mod_to_dispense_read_param_afe2();
  inlet_valve_close();
  return portion_mode;
}

