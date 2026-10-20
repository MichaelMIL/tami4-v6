// address 0x009a6c

void FUN_CODE_009a6c(void)

{
  BADSPACEBASE *in_FSR2;
  BADSPACEBASE *in_FSR1;
  undefined1 *puVar1;
  undefined1 uVar2;
  
  uVar2 = FUN_CODE_009aba();
  *(undefined1 *)in_FSR1 = uVar2;
  puVar1 = (undefined1 *)((short)in_FSR1 + 2);
  *(undefined1 *)((short)in_FSR1 + 1) = *(undefined1 *)((short)in_FSR2 + -2);
  FUN_CODE_009282();
  *puVar1 = *puVar1;
  puVar1[-1] = puVar1[-1];
  return;
}

