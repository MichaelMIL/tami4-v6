// address 0x000656  size 22 bytes
// callers: (none: entry point, task, or reached via pointer)

/* Menu/screen handler (callback analysis) */

void menu_clock_day_on_up(void)

{
  byte unaff_BSR;
  byte bVar1;
  
  ui_set_menu_value_lo_2720();
  bVar1 = *(byte *)((ushort)unaff_BSR * 0x100 + 0x94) ^ 7;
  if ((bVar1 == 0) && (bVar1 = *(byte *)((ushort)unaff_BSR * 0x100 + 0x95), bVar1 == 0)) {
    *(undefined1 *)((ushort)unaff_BSR * 0x100 + 0x94) = 0;
    *(undefined1 *)((ushort)unaff_BSR * 0x100 + 0x95) = 0;
  }
  ui_set_text_fill_width_0606(bVar1);
  return;
}

