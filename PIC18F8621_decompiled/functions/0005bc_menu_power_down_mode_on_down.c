// address 0x0005bc  size 20 bytes
// callers: (none: entry point, task, or reached via pointer)

/* Menu/screen handler (callback analysis) */

void menu_power_down_mode_on_down(void)

{
  byte unaff_BSR;
  byte bVar1;
  byte unaff_Z;
  
  bVar1 = ui_set_menu_value_lo_2678();
  if (((unaff_Z & 1) != 0) && (bVar1 = ~*(byte *)((ushort)unaff_BSR * 0x100 + 0x95), bVar1 == 0)) {
    bVar1 = 3;
    *(undefined1 *)((ushort)unaff_BSR * 0x100 + 0x94) = 3;
    *(undefined1 *)((ushort)unaff_BSR * 0x100 + 0x95) = 0;
  }
  screen_power_down_draw(bVar1);
  return;
}

