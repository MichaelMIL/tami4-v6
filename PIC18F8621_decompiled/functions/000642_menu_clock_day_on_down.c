// address 0x000642  size 20 bytes
// callers: (none: entry point, task, or reached via pointer)

/* Menu/screen handler (callback analysis) */

void menu_clock_day_on_down(void)

{
  byte unaff_BSR;
  byte bVar1;
  byte unaff_Z;
  
  bVar1 = ui_set_menu_value_lo_2678();
  if (((unaff_Z & 1) != 0) && (bVar1 = ~*(byte *)((ushort)unaff_BSR * 0x100 + 0x95), bVar1 == 0)) {
    bVar1 = 6;
    *(undefined1 *)((ushort)unaff_BSR * 0x100 + 0x94) = 6;
    *(undefined1 *)((ushort)unaff_BSR * 0x100 + 0x95) = 0;
  }
  ui_set_text_fill_width_0606(bVar1);
  return;
}

