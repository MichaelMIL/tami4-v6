// address 0x00009a  size 24 bytes
// callers: (none: entry point, task, or reached via pointer)

/* Menu/screen handler (callback analysis) */

void menu_enter_power_down_on_enter(void)

{
  if (menu_edit_mode != '\0') {
    system_request_wake(menu_edit_mode);
  }
  lcd_clear();
  ui_bank1_ui_set_menu_cb_up_2454();
  menu_table_ptr_lo = 0;
  menu_table_ptr_hi = 0;
  return;
}

