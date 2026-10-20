// address 0x00cc0c

void FUN_CODE_00cc0c(void)

{
  BADSPACEBASE *in_FSR2;
  BADSPACEBASE *in_FSR1;
  byte *pbVar1;
  
  FUN_CODE_00cdd2();
  *(byte *)in_FSR1 = *(byte *)((short)in_FSR2 + -4) | 0x10;
  *(undefined1 *)((short)in_FSR1 + 1) = *(undefined1 *)((short)in_FSR2 + -2);
  pbVar1 = (byte *)((short)in_FSR1 + 3);
  *(undefined1 *)((short)in_FSR1 + 2) = *(undefined1 *)in_FSR2;
  FUN_CODE_00cb86();
  *pbVar1 = *pbVar1;
  pbVar1[-1] = pbVar1[-1];
  pbVar1[-2] = pbVar1[-2];
  FUN_CODE_00cd24();
  return;
}

