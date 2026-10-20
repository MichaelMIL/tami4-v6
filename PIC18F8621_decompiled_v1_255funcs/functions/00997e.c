// address 0x00997e

undefined1 FUN_CODE_00997e(void)

{
  byte bVar1;
  byte unaff_BSR;
  undefined1 *in_TBLPTR;
  
  FUN_CODE_009ab0();
  bVar1 = *(byte *)((ushort)unaff_BSR * 0x100 + 10);
  *(byte *)((ushort)unaff_BSR * 0x100 + 10) = bVar1 + 1;
  *(char *)((ushort)unaff_BSR * 0x100 + 0xb) =
       *(char *)((ushort)unaff_BSR * 0x100 + 0xb) + (0xfe < bVar1);
  DAT_DATA_0e09 = *in_TBLPTR;
  return 0;
}

