// address 0x00037c  size 80 bytes
// callers: (none: entry point, task, or reached via pointer)

/* Menu/screen handler (callback analysis) */

undefined1 menu_language(undefined1 param_1)

{
  char cVar1;
  byte unaff_Z;
  
  if ((cfg_systemconfig5 & 0x10) == 0) {
    return param_1;
  }
  ui_to_ui_get_menu_table_ptr_lo_28f6();
  ui_get_menu_item_2296();
  if ((unaff_Z & 1) == 0) {
    ui_get_menu_item_2254();
    menu_item = 0;
    while( true ) {
      cVar1 = menu_item - 8;
      if (7 < menu_item) break;
      ui_get_menu_item_24ba(cVar1);
      ui_get_c18_tmp0_25e8();
      if (cVar1 == '\0') break;
      menu_item = menu_item + 1;
    }
    cVar1 = menu_item - 8;
    if (7 < menu_item) {
      menu_item = 0;
    }
    menu_draw(cVar1);
  }
  menu_cb_enter = 0xcc;
  menu_cb_enter_hi = 3;
  menu_cb_back = 0xe2;
  menu_cb_back_hi = 3;
  return 3;
}

