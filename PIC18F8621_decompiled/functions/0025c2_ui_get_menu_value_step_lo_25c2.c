// address 0x0025c2  size 10 bytes
// callers: 000da0,001cb6,001d9e,001d16,001c74,

/* Auto: reads menu_value_step_lo,menu_value_step_hi; 3 instr */

void ui_get_menu_value_step_lo_25c2(void)

{
  menu_value_lo = menu_value_step_lo;
  menu_value_hi = menu_value_step_hi;
  return;
}

