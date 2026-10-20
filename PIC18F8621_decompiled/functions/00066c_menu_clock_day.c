// address 0x00066c  size 62 bytes
// callers: (none: entry point, task, or reached via pointer)

/* Menu/screen handler (callback analysis) */

void menu_clock_day(void)

{
  if ((cfg_systemconfig5 & 0x10) == 0) {
    return;
  }
  ui_get_TBLPTRL_22ba();
  ui_to_ui_set_text_row_245a();
  ui_stack_adjust_21f4(0x38);
  clock_get_day();
  ui_set_menu_value_lo_2bae();
  ui_set_text_fill_width_0606();
  menu_item = 1;
  menu_cb_enter = 0x34;
  menu_cb_enter_hi = 6;
  menu_cb_up = 0x56;
  menu_cb_up_hi = 6;
  menu_cb_down = 0x42;
  menu_set_cbs_down_hi(6);
  return;
}

