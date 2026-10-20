// address 0x001096  size 24 bytes
// callers: 002d86,

/* Down key (0x10) in menus: call menu_cb_down */

undefined1 menu_key_down(void)

{
  char cVar1;
  
  if ((menu_cb_down_hi | menu_cb_down) != 0) {
    menu_call_down_cb(menu_cb_down_hi | menu_cb_down);
    return 1;
  }
  menu_item = menu_item + 1;
  cVar1 = menu_item - menu_item_count;
  if (menu_item_count <= menu_item) {
    menu_item = 0;
  }
  menu_draw(cVar1);
  return 0;
}

