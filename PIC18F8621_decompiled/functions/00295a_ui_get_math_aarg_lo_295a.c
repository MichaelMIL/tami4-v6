// address 0x00295a  size 10 bytes
// callers: 000da0,000cee,000d18,000d4e,

/* Auto: reads math_aarg_lo; 4 instr */

void ui_get_math_aarg_lo_295a(void)

{
  BADSPACEBASE *in_FSR1;
  
  ui_get_menu_value_lo_22aa(10);
  *(undefined1 *)in_FSR1 = math_aarg_lo;
  return;
}

