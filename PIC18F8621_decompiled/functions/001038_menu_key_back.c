// address 0x001038  size 40 bytes
// callers: 002670,002d86,

/* Back key (0x40) in menus: call menu_cb_back */

undefined1 menu_key_back(void)

{
  if ((menu_cb_back_hi | menu_cb_back) != 0) {
    menu_call_back_cb(menu_cb_back_hi | menu_cb_back);
    return 1;
  }
  if ((menu_table_ptr_hi | menu_table_ptr_lo) != 0) {
    ui_get_menu_item_2270(menu_table_ptr_hi | menu_table_ptr_lo);
    if (menu_table_ptr_hi != 0 || menu_table_ptr_lo != 0) {
      menu_draw();
      return 1;
    }
    lcd_clear(0);
    return 0;
  }
  return 0x80;
}

