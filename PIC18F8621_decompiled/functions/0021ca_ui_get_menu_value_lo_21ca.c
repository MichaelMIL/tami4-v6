// address 0x0021ca  size 14 bytes
// callers: 0028fe,001e3e,

/* Auto: reads menu_value_lo,menu_value_max_lo,menu_value_max_hi; 7 instr */

char ui_get_menu_value_lo_21ca(void)

{
  byte bVar1;
  byte bVar2;
  byte unaff_BSR;
  
  ui_get_progress_bar_x_2922();
  bVar1 = *(byte *)((ushort)unaff_BSR * 0x100 + 0x94);
  bVar2 = *(byte *)((ushort)unaff_BSR * 0x100 + 0x98);
  c18_tmp2 = bVar2 - bVar1;
  return (*(char *)((ushort)unaff_BSR * 0x100 + 0x99) - *(char *)((ushort)unaff_BSR * 0x100 + 0x95))
         - ~(bVar1 <= bVar2);
}

