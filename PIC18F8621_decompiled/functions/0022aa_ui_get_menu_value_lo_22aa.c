// address 0x0022aa  size 16 bytes
// callers: 00295a,0005d0,

/* Auto: reads menu_value_lo,menu_value_hi; 5 instr */

void ui_get_menu_value_lo_22aa(undefined1 param_1)

{
  math_barg_hi = 0;
  math_aarg_lo = menu_value_lo;
  math_aarg_hi = menu_value_hi;
  math_barg_lo = param_1;
  ui_to___divs16_289c();
  return;
}

