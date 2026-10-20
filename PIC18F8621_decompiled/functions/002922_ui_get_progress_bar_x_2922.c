// address 0x002922  size 24 bytes
// callers: 0021ca,002378,

/* Auto: reads progress_bar_x,menu_value_step_lo,menu_value_max_lo,menu_value_max_hi; 12 instr */

char ui_get_progress_bar_x_2922(void)

{
  c18_tmp8 = progress_bar_x;
  c18_tmp9 = 0;
  c18_tmp6 = menu_value_max_lo - menu_value_step_lo;
  c18_tmp7 = (menu_value_max_hi - menu_value_step_hi) - ~(menu_value_step_lo <= menu_value_max_lo);
  return c18_tmp7;
}

