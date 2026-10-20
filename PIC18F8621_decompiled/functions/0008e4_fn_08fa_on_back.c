// address 0x0008e4  size 8 bytes
// callers: (none: entry point, task, or reached via pointer)

/* Menu/screen handler (callback analysis) */

void fn_08fa_on_back(void)

{
  ui_set_menu_value_lo_26a6();
  screen_wakeup2_edit_hour();
  return;
}

