// address 0x0010bc  size 10 bytes
// callers: 002d86,

/* Other keys in menus: call menu_cb_key */

undefined1 menu_key_other(void)

{
  if ((menu_cb_key_hi | menu_cb_key) != 0) {
    menu_call_key_cb(menu_cb_key_hi | menu_cb_key);
  }
  return 0;
}

