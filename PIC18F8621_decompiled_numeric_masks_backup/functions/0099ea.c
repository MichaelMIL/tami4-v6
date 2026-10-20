// address 0x0099ea

undefined1 FUN_CODE_0099ea(void)

{
  byte unaff_BSR;
  byte unaff_C;
  
  *(byte *)((ushort)unaff_BSR * 0x100 + 0xf) =
       *(char *)((ushort)unaff_BSR * 0x100 + 0xf) - ~(unaff_C & 1);
  return 0;
}

