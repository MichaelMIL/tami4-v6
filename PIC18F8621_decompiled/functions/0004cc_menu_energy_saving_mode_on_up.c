// address 0x0004cc  size 22 bytes
// callers: (none: entry point, task, or reached via pointer)

/* Menu/screen handler (callback analysis) */

void menu_energy_saving_mode_on_up(void)

{
  byte unaff_BSR;
  byte bVar1;
  
  ui_set_menu_value_lo_2720();
  bVar1 = *(byte *)((ushort)unaff_BSR * 0x100 + 0x94) ^ 9;
  if ((bVar1 == 0) && (bVar1 = *(byte *)((ushort)unaff_BSR * 0x100 + 0x95), bVar1 == 0)) {
    *(undefined1 *)((ushort)unaff_BSR * 0x100 + 0x94) = 0;
    *(undefined1 *)((ushort)unaff_BSR * 0x100 + 0x95) = 0;
  }
  screen_energy_saving_draw(bVar1);
  return;
}

