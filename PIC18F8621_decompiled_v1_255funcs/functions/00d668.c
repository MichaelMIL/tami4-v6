// address 0x00d668

void FUN_CODE_00d668(void)

{
  BADSPACEBASE *in_FSR2;
  BADSPACEBASE *in_FSR1;
  byte bVar1;
  byte unaff_C;
  
  FUN_CODE_00d6b4();
  FUN_CODE_00d700();
  bVar1 = (byte)((ushort)((short)in_FSR1 + 1) >> 8);
  *(undefined1 *)in_FSR1 = *(undefined1 *)((short)in_FSR2 + -2);
  FUN_CODE_00d724();
  if ((unaff_C & 1) == 0) {
    *(undefined1 *)((ushort)bVar1 << 8) = *(undefined1 *)((ushort)bVar1 << 8);
  }
  FUN_CODE_00d76a();
  FUN_CODE_00d6c6();
  return;
}

