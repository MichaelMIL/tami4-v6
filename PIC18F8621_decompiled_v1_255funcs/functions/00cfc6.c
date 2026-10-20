// address 0x00cfc6

void FUN_CODE_00cfc6(void)

{
  BADSPACEBASE *in_FSR2;
  BADSPACEBASE *in_FSR1;
  undefined1 *puVar1;
  byte bVar2;
  
  bVar2 = FUN_CODE_00d16c();
  FUN_CODE_00d15c(bVar2 | 0xb0);
  puVar1 = (undefined1 *)((short)in_FSR1 + 1);
  *(undefined1 *)in_FSR1 = *(undefined1 *)((short)in_FSR2 + -3);
  FUN_CODE_00cfd8();
  *puVar1 = *puVar1;
  FUN_CODE_00d130();
  return;
}

