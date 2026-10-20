// address 0x00016a  size 14 bytes
// callers: (none: entry point, task, or reached via pointer)

/* Menu/screen handler (callback analysis) */

void menu_clock_view_on_enter(void)

{
  byte *pbVar1;
  byte unaff_BSR;
  byte bVar2;
  
  bVar2 = ui_get_menu_edit_mode_2770();
  pbVar1 = (byte *)((ushort)unaff_BSR * 0x100 + 0x59);
  *pbVar1 = *pbVar1 & 0x7f;
  if ((bVar2 & 1) != 0) {
    pbVar1 = (byte *)((ushort)unaff_BSR * 0x100 + 0x59);
    *pbVar1 = *pbVar1 | 0x80;
  }
  ui_get_cfg_systemconfig3_2bfa();
  return;
}

