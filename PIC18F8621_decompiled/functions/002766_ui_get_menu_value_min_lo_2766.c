// address 0x002766  size 10 bytes
// callers: 001d9e,001d16,001c74,

/* Auto: reads menu_value_min_lo,menu_value_lo,menu_value_min_hi; 5 instr */

char ui_get_menu_value_min_lo_2766(void)

{
  byte bVar1;
  byte bVar2;
  char cVar3;
  byte unaff_BSR;
  
  bVar1 = *(byte *)((ushort)unaff_BSR * 0x100 + 0x96);
  bVar2 = *(byte *)((ushort)unaff_BSR * 0x100 + 0x94);
  *(byte *)((ushort)unaff_BSR * 0x100 + 0x94) = bVar2 - bVar1;
  cVar3 = *(char *)((ushort)unaff_BSR * 0x100 + 0x97);
  *(char *)((ushort)unaff_BSR * 0x100 + 0x95) =
       (*(char *)((ushort)unaff_BSR * 0x100 + 0x95) - cVar3) - ~(bVar1 <= bVar2);
  return cVar3;
}

