// address 0x00d67e

void FUN_CODE_00d67e(void)

{
  BADSPACEBASE *in_FSR2;
  undefined1 *puVar1;
  BADSPACEBASE *in_FSR1;
  undefined1 *puVar2;
  undefined1 uVar3;
  
  FUN_CODE_00d6b4();
  puVar2 = (undefined1 *)((short)in_FSR1 + 1);
  puVar1 = (undefined1 *)((short)in_FSR2 + 1);
  *(undefined1 *)in_FSR1 = *(undefined1 *)((short)in_FSR2 + -2);
  FUN_CODE_00d668();
  *puVar2 = *puVar2;
  uVar3 = DAT_DATA_0032;
  if (DAT_DATA_0201 < '\0') {
    puVar2[-1] = puVar1[-2];
    uVar3 = FUN_CODE_00d58c();
    *puVar2 = *puVar2;
  }
  FUN_CODE_00d6c6(uVar3);
  return;
}

