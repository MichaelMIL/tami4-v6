// address 0x002020  size 56 bytes
// callers: (none: entry point, task, or reached via pointer)

/* Menu/screen handler (callback analysis) */

undefined1 menu_service_application(void)

{
  byte unaff_Z;
  
  ui_to_ui_get_menu_table_ptr_lo_28f6();
  ui_get_menu_item_2296();
  if ((unaff_Z & 1) == 0) {
    ui_get_menu_item_2254();
  }
  menu_item = (cfg_systemconfig5 & 0x60) >> 5;
  menu_draw();
  menu_cb_enter = 0x5a;
  menu_cb_enter_hi = 0x20;
  menu_cb_back = 0x58;
  menu_cb_back_hi = 0x20;
  return 0x20;
}

