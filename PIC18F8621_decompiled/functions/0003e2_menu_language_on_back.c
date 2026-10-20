// address 0x0003e2  size 20 bytes
// callers: (none: entry point, task, or reached via pointer)

/* Menu/screen handler (callback analysis) */

void menu_language_on_back(void)

{
  if ((menu_table_ptr_hi | menu_table_ptr_lo) != 0) {
    ui_get_menu_item_2270(menu_table_ptr_hi | menu_table_ptr_lo);
    menu_draw();
  }
  ui_bank1_ui_set_menu_cb_enter_26ce();
  return;
}

