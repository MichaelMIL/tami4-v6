// address 0x009a8a

void FUN_CODE_009a8a(void)

{
  byte bVar1;
  byte unaff_BSR;
  char cVar2;
  BADSPACEBASE *in_FSR0;
  
  bVar1 = *(byte *)((ushort)unaff_BSR * 0x100 + 0x10);
  *(byte *)((ushort)unaff_BSR * 0x100 + 0x10) = bVar1 + 1;
  *(char *)((ushort)unaff_BSR * 0x100 + 0x11) =
       *(char *)((ushort)unaff_BSR * 0x100 + 0x11) + (0xfe < bVar1);
  cVar2 = FUN_CODE_0099b6();
  bVar1 = *(byte *)((ushort)unaff_BSR * 0x100 + 0xc);
  *(byte *)((ushort)unaff_BSR * 0x100 + 0xc) = bVar1 + 1;
  *(char *)((ushort)unaff_BSR * 0x100 + 0xd) =
       *(char *)((ushort)unaff_BSR * 0x100 + 0xd) + cVar2 + (0xfe < bVar1);
  *(undefined1 *)in_FSR0 = DAT_DATA_0e09;
  return;
}

