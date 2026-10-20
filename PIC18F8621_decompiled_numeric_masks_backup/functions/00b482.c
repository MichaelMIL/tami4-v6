// address 0x00b482

void FUN_CODE_00b482(void)

{
  BADSPACEBASE *in_FSR1;
  undefined1 *puVar1;
  
  FUN_CODE_009f10();
  *(undefined1 *)in_FSR1 = 0x9e;
  puVar1 = (undefined1 *)((short)in_FSR1 + 2);
  *(undefined1 *)((short)in_FSR1 + 1) = 0;
  FUN_CODE_009f7a();
  *puVar1 = *puVar1;
  puVar1[-1] = puVar1[-1];
  return;
}

