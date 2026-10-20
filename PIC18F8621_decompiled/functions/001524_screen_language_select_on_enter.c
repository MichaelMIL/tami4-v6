// address 0x001524  size 20 bytes
// callers: (none: entry point, task, or reached via pointer)

/* Menu/screen handler (callback analysis) */

void screen_language_select_on_enter(void)

{
  byte unaff_BSR;
  
  ui_set_cfg_systemconfig2_285a();
  *(undefined1 *)((ushort)unaff_BSR * 0x100 + 0x25) = 0x82;
  *(undefined1 *)((ushort)unaff_BSR * 0x100 + 0x26) = 0xe5;
  *(undefined1 *)((ushort)unaff_BSR * 0x100 + 0x27) = 0;
  menu_draw();
  ui_bank1_ui_set_menu_cb_up_2454();
  return;
}

