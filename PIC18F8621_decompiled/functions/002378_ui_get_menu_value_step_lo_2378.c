// address 0x002378  size 14 bytes
// callers: 001d5e,001d9e,001e3e,

/* Auto: reads menu_value_step_lo,menu_value_lo,menu_value_hi; 7 instr */

char ui_get_menu_value_step_lo_2378(void)

{
  byte bVar1;
  byte bVar2;
  byte unaff_BSR;
  
  ui_get_progress_bar_x_2922();
  bVar1 = *(byte *)((ushort)unaff_BSR * 0x100 + 0x9a);
  bVar2 = *(byte *)((ushort)unaff_BSR * 0x100 + 0x94);
  c18_tmp2 = bVar2 - bVar1;
  return (*(char *)((ushort)unaff_BSR * 0x100 + 0x95) - *(char *)((ushort)unaff_BSR * 0x100 + 0x9b))
         - ~(bVar1 <= bVar2);
}

