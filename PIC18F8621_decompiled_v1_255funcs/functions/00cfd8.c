// address 0x00cfd8

void FUN_CODE_00cfd8(void)

{
  BADSPACEBASE *in_FSR2;
  byte bVar1;
  
  bVar1 = FUN_CODE_00d16c();
  FUN_CODE_00d15c(bVar1 >> 4 | 0x10);
  FUN_CODE_00d15c(*(byte *)((short)in_FSR2 + -2) & 0xf);
  FUN_CODE_00d130();
  return;
}

