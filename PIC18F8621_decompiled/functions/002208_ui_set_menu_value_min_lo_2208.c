// address 0x002208  size 24 bytes
// callers: 001f12,001f6a,001e3e,

/* Auto: writes menu_value_min_lo; reads progress_bar_width,progress_bar_value; 12 instr */

undefined1 ui_set_menu_value_min_lo_2208(void)

{
  bool bVar1;
  
  ui_get_menu_value_min_lo_293a(progress_bar_width + -1);
  ui_get_menu_value_min_lo_293a(progress_bar_value + progress_bar_width);
  bVar1 = 0xfe < menu_value_min_lo;
  menu_value_min_lo = menu_value_min_lo + 1;
  menu_value_min_hi = menu_value_min_hi + bVar1;
  return 0;
}

