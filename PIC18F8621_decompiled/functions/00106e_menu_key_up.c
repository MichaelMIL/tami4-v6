// address 0x00106e  size 26 bytes
// callers: 002d86,

/* Up key (0x01) in menus: call menu_cb_up */

undefined1 menu_key_up(void)

{
  char cVar1;
  
  if ((menu_cb_up_hi | menu_cb_up) != 0) {
    menu_call_up_cb(menu_cb_up_hi | menu_cb_up);
    return 1;
  }
  if (menu_item == '\0') {
    cVar1 = menu_item_count + -1;
    menu_item = menu_item_count + -1;
  }
  else {
    cVar1 = menu_item;
    menu_item = menu_item + -1;
  }
  menu_draw(cVar1);
  return 0;
}

