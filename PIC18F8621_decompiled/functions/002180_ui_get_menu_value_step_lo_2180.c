// address 0x002180  size 24 bytes
// callers: 001cb6,001c32,001d5e,001d9e,001d16,001c74,

/* Auto: reads menu_value_step_lo,menu_value_max_lo,menu_value_max_hi; 12 instr */

byte ui_get_menu_value_step_lo_2180(void)

{
  c18_tmp0 = menu_value_max_lo - menu_value_step_lo;
  c18_tmp1 = (menu_value_max_hi - menu_value_step_hi) - ~(menu_value_step_lo <= menu_value_max_lo);
  ui_to___divs16_28c8(0xc);
  return math_aarg_hi | math_aarg_lo;
}

