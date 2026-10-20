// address 0x00a2f2

void FUN_CODE_00a2f2(void)

{
  BADSPACEBASE *in_FSR2;
  char cVar1;
  BADSPACEBASE *in_FSR0;
  
  FUN_CODE_00a160();
  cVar1 = FUN_CODE_00a292();
  *(undefined1 *)((short)in_FSR2 + (short)cVar1 + 1) = *(undefined1 *)in_FSR0;
  return;
}

