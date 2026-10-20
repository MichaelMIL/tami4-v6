// address 0x0024fa  size 18 bytes
// callers: 001cb6,001c32,001d5e,

/* Auto: reads menu_value_lo,menu_value_min_lo,menu_value_hi,menu_value_max_hi; 9 instr */

byte ui_get_menu_value_lo_24fa(void)

{
  byte bVar1;
  byte bVar2;
  byte unaff_BSR;
  
  bVar1 = *(byte *)((ushort)unaff_BSR * 0x100 + 0x94);
  bVar2 = *(byte *)((ushort)unaff_BSR * 0x100 + 0x96);
  c18_tmp0 = bVar2 + bVar1;
  c18_tmp1 = *(char *)((ushort)unaff_BSR * 0x100 + 0x97) +
             *(char *)((ushort)unaff_BSR * 0x100 + 0x95) + CARRY1(bVar2,bVar1);
  return *(byte *)((ushort)unaff_BSR * 0x100 + 0x99) ^ c18_tmp1;
}

