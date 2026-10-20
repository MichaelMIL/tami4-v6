// address 0x009af0

void FUN_CODE_009af0(void)

{
  BADSPACEBASE *in_FSR2;
  undefined1 *puVar1;
  BADSPACEBASE *in_FSR1;
  BADSPACEBASE *in_FSR0;
  undefined1 *puVar2;
  
  FUN_CODE_00a16e();
  FUN_CODE_00a1aa();
  puVar1 = (undefined1 *)((short)in_FSR2 + 1);
  *(byte *)in_FSR1 = *(byte *)((short)in_FSR2 + -6) & 0x7f;
  FUN_CODE_00a244();
  FUN_CODE_009b2c();
  FUN_CODE_00a2e4();
  FUN_CODE_00a19c();
  FUN_CODE_00a260();
  FUN_CODE_00a19c();
  *(byte *)in_FSR0 = *(byte *)in_FSR0 & 0x7f;
  FUN_CODE_00a19c();
  puVar2 = (undefined1 *)((short)in_FSR0 + 1);
  *(undefined1 *)in_FSR0 = *(undefined1 *)in_FSR0;
  FUN_CODE_00a200();
  FUN_CODE_00a19c();
  FUN_CODE_00a1ca();
  *puVar2 = DAT_DATA_00b0;
  if ((puVar1[-6] & 0x80) == 0) {
    FUN_CODE_00a19c();
    FUN_CODE_00a220();
    FUN_CODE_00a244();
    FUN_CODE_00a1e6();
  }
  FUN_CODE_00a18c();
  FUN_CODE_00a180(0);
  return;
}

