// address 0x0023d8  size 18 bytes
// callers: 0004a0,002952,

/* Auto: reads menu_value_hi,menu_value_lo; 7 instr */

char ui_get_menu_value_hi_23d8(byte param_1)

{
  byte unaff_BSR;
  short sVar1;
  char cVar2;
  
  menu_value_hi = *(char *)((ushort)unaff_BSR * 0x100 + 0x95) * param_1;
  sVar1 = (ushort)*(byte *)((ushort)unaff_BSR * 0x100 + 0x94) * (ushort)param_1;
  menu_value_lo = (undefined1)sVar1;
  cVar2 = (char)((ushort)sVar1 >> 8);
  *(char *)((ushort)unaff_BSR * 0x100 + 0x95) = *(char *)((ushort)unaff_BSR * 0x100 + 0x95) + cVar2;
  return cVar2;
}

