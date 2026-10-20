// address 0x0003cc  size 22 bytes
// callers: (none: entry point, task, or reached via pointer)

/* Menu/screen handler (callback analysis) */

void menu_language_on_enter(void)

{
  byte bVar1;
  byte unaff_BSR;
  
  ui_set_cfg_systemconfig2_285a();
  bVar1 = *(byte *)((ushort)unaff_BSR * 0x100 + 0x26) | *(byte *)((ushort)unaff_BSR * 0x100 + 0x25);
  if (bVar1 != 0) {
    ui_get_menu_item_2270(bVar1);
    menu_draw();
  }
  ui_bank1_ui_set_menu_cb_enter_26ce();
  return;
}

