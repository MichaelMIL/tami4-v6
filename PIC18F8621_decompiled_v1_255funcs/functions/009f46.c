// address 0x009f46

void FUN_CODE_009f46(void)

{
  BADSPACEBASE *in_FSR2;
  BADSPACEBASE *in_FSR0;
  
  FUN_CODE_00a2b2();
  *(undefined1 *)in_FSR0 = 0;
  *(undefined1 *)((short)in_FSR0 + 1) = 0;
  FUN_CODE_00a286();
  *(undefined1 *)in_FSR0 = *(undefined1 *)((short)in_FSR2 + -4);
  FUN_CODE_00a18c();
  FUN_CODE_00a180(0);
  return;
}

