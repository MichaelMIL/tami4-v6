// address 0x00a298

void FUN_CODE_00a298(void)

{
  BADSPACEBASE *in_FSR2;
  BADSPACEBASE *in_FSR0;
  
  FUN_CODE_00a1ee();
  *(undefined1 *)in_FSR0 = *(undefined1 *)in_FSR2;
  *(undefined1 *)((short)in_FSR0 + 1) = *(undefined1 *)((short)in_FSR2 + 1);
  return;
}

