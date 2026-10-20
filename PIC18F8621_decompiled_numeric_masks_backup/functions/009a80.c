// address 0x009a80

undefined1 FUN_CODE_009a80(void)

{
  byte bVar1;
  byte unaff_BSR;
  
  FUN_CODE_0099b6();
  bVar1 = *(byte *)((ushort)unaff_BSR * 0x100 + 0xc);
  *(byte *)((ushort)unaff_BSR * 0x100 + 0xc) = bVar1 + 1;
  *(char *)((ushort)unaff_BSR * 0x100 + 0xd) =
       *(char *)((ushort)unaff_BSR * 0x100 + 0xd) + (0xfe < bVar1);
  return 0;
}

