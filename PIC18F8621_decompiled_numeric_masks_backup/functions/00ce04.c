// address 0x00ce04

undefined1 FUN_CODE_00ce04(void)

{
  undefined1 uVar1;
  BADSPACEBASE *in_FSR2;
  byte unaff_BSR;
  BADSPACEBASE *in_FSR0;
  
  uVar1 = *(undefined1 *)((ushort)unaff_BSR * 0x100 + 0xe8);
  *(char *)((ushort)unaff_BSR * 0x100 + 0xe8) = *(char *)((ushort)unaff_BSR * 0x100 + 0xe8) + '\x01'
  ;
  FUN_CODE_00cd30(uVar1);
  *(undefined1 *)in_FSR2 = *(undefined1 *)in_FSR0;
  return *(undefined1 *)in_FSR2;
}

