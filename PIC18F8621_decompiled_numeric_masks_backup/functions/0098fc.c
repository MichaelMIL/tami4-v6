// address 0x0098fc

void FUN_CODE_0098fc(void)

{
  BADSPACEBASE *in_FSR2;
  byte unaff_BSR;
  BADSPACEBASE *in_FSR1;
  byte bVar1;
  
  bVar1 = FUN_CODE_009a00();
  *(byte *)((ushort)unaff_BSR * 0x100 + 0xe) = bVar1 - 5;
  *(char *)((ushort)unaff_BSR * 0x100 + 0xf) = (char)((ushort)in_FSR1 >> 8) + -1 + (4 < bVar1);
  FUN_CODE_00999c();
  *(undefined1 *)in_FSR1 = *(undefined1 *)((short)in_FSR2 + -4);
  FUN_CODE_009a9c(0xfc);
  return;
}

