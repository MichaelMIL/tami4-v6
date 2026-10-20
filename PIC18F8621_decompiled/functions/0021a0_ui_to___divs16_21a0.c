// address 0x0021a0  size 42 bytes
// callers: 001cb6,001c32,001d5e,001d9e,001d16,001c74,

/* Auto: writes menu_value_min_lo,menu_value_min_hi; reads
   menu_value_step_lo,menu_value_max_lo,menu_value_step_hi,menu_value_min_lo,menu_value_min_hi,math_aarg_lo;
   calls __divs16; 16 instr */

void ui_to___divs16_21a0(void)

{
  math_aarg_lo = menu_value_max_lo - menu_value_step_lo;
  math_aarg_hi = (menu_value_max_hi - menu_value_step_hi) -
                 ~(menu_value_step_lo <= menu_value_max_lo);
  math_barg_lo = 0xc;
  math_barg_hi = 0;
  menu_value_min_lo = math_aarg_lo;
  menu_value_min_hi = math_aarg_hi;
  __divs16();
  menu_value_min_lo = math_aarg_lo;
  menu_value_min_hi = math_aarg_hi;
  return;
}

