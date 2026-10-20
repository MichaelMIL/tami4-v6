// address 0x00089a  size 42 bytes
// callers: (none: entry point, task, or reached via pointer)

/* Menu/screen handler (callback analysis) */

void menu_wakeup_1_on_enter(void)

{
  byte *pbVar1;
  byte unaff_BSR;
  BADSPACEBASE *in_FSR1;
  byte bVar2;
  byte unaff_Z;
  
  bVar2 = ui_get_menu_edit_mode_2770();
  pbVar1 = (byte *)((ushort)unaff_BSR * 0x100 + 0x59);
  *pbVar1 = *pbVar1 & 0xef;
  if ((bVar2 & 1) != 0) {
    pbVar1 = (byte *)((ushort)unaff_BSR * 0x100 + 0x59);
    *pbVar1 = *pbVar1 | 0x10;
  }
  ui_get_cfg_systemconfig3_2a28();
  if ((unaff_Z & 1) != 0) {
    menu_default_back();
    return;
  }
  *(undefined1 *)in_FSR1 = 0x36;
  ui_to_ui_set_text_row_245a();
  ui_chain_fn21f4_ui_set_menu_value__2ac6(0x49);
  clock_edit_load_wake1();
  screen_wakeup1_edit_hour();
  return;
}

