// address 0x000f9e  size 28 bytes
// callers: 000f9e,

/* Call menu enter callback (menu_cb_enter) */

undefined1 menu_call_enter_cb(void)

{
  menu_call_enter_cb(menu_cb_enter);
  if ((menu_table_ptr_hi == '\0' && menu_table_ptr_lo == '\0') && (menu_mode == '\0')) {
    return 0x80;
  }
  return 1;
}

