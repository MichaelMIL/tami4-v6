// address 0x00013a  size 14 bytes
// callers: (none: entry point, task, or reached via pointer)

/* Menu/screen handler (callback analysis) */

void menu_spout_light_on_enter(void)

{
  byte *pbVar1;
  byte unaff_BSR;
  byte bVar2;
  
  bVar2 = ui_get_menu_edit_mode_2770();
  pbVar1 = (byte *)((ushort)unaff_BSR * 0x100 + 0x59);
  *pbVar1 = *pbVar1 & 0xbf;
  if ((bVar2 & 1) != 0) {
    pbVar1 = (byte *)((ushort)unaff_BSR * 0x100 + 0x59);
    *pbVar1 = *pbVar1 | 0x40;
  }
  ui_get_cfg_systemconfig3_2bfa();
  return;
}

