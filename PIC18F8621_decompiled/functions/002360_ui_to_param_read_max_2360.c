// address 0x002360  size 16 bytes
// callers: 000cf8,000d58,000ccc,000c62,000a90,000b2c,000d22,

/* Auto: writes menu_value_max_lo,menu_value_max_hi; calls param_read_max; 7 instr */

void ui_to_param_read_max_2360(void)

{
  BADSPACEBASE *in_FSR1;
  undefined1 *puVar1;
  
  puVar1 = &FramePointer10x0001;
  menu_value_max_lo = param_read_max();
  *puVar1 = *puVar1;
  menu_value_max_hi = 0;
  return;
}

