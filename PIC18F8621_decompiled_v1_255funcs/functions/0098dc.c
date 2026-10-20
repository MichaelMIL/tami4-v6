// address 0x0098dc

void FUN_CODE_0098dc(void)

{
  char cVar1;
  BADSPACEBASE *in_FSR1;
  undefined1 *puVar2;
  undefined1 *puVar3;
  undefined1 uVar4;
  byte unaff_Z;
  
  uVar4 = FUN_CODE_009a5a();
  puVar3 = (undefined1 *)in_FSR1;
  while( true ) {
    FUN_CODE_009a08(uVar4);
    if ((unaff_Z & 1) != 0) break;
    FUN_CODE_0099a8();
    FUN_CODE_0096c0();
    *puVar3 = *puVar3;
    puVar2 = puVar3 + -2;
    puVar3[-1] = puVar3[-1];
    unaff_Z = DAT_DATA_0e12 == '\0';
    uVar4 = 0;
    puVar3 = puVar3 + -2;
    if (!(bool)unaff_Z) {
      FUN_CODE_009a26();
      uVar4 = FUN_CODE_0094d8();
      *puVar2 = *puVar2;
      puVar3 = puVar2 + -2;
      cVar1 = puVar2[-1];
      puVar2[-1] = cVar1;
      unaff_Z = cVar1 == '\0';
    }
  }
  FUN_CODE_009972();
  return;
}

