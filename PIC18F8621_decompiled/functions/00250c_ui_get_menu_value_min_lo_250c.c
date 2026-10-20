// address 0x00250c  size 18 bytes
// callers: 001d9e,001d16,001c74,

/* Auto: reads menu_value_min_lo,menu_value_lo,menu_value_hi,menu_value_step_hi; 9 instr */

byte ui_get_menu_value_min_lo_250c(void)

{
  byte bVar1;
  byte bVar2;
  byte unaff_BSR;
  
  bVar1 = *(byte *)((ushort)unaff_BSR * 0x100 + 0x96);
  bVar2 = *(byte *)((ushort)unaff_BSR * 0x100 + 0x94);
  c18_tmp0 = bVar2 - bVar1;
  c18_tmp1 = (*(char *)((ushort)unaff_BSR * 0x100 + 0x95) -
             *(char *)((ushort)unaff_BSR * 0x100 + 0x97)) - ~(bVar1 <= bVar2);
  return c18_tmp1 ^ *(byte *)((ushort)unaff_BSR * 0x100 + 0x9b);
}

