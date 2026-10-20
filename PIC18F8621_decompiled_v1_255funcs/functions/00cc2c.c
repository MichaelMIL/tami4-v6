// address 0x00cc2c

void FUN_CODE_00cc2c(void)

{
  byte bVar1;
  BADSPACEBASE *in_FSR2;
  BADSPACEBASE *in_FSR1;
  undefined1 *puVar2;
  byte bVar3;
  bool bVar4;
  
  FUN_CODE_00cdd2();
  if ((*(byte *)((short)in_FSR2 + -2) & 0x20) != 0) {
    DAT_DATA_0014 = DAT_DATA_01ea;
    bVar1 = DAT_DATA_01ea + 1;
    bVar4 = (char)DAT_DATA_01ea < '\0';
    bVar3 = DAT_DATA_01ea << 1 | 0xfe < DAT_DATA_01ea;
    DAT_DATA_01ea = bVar1;
    if ((bVar4) || (bVar3 = bVar1 - DAT_DATA_01eb, DAT_DATA_01eb <= bVar1)) goto LAB_CODE_00cc58;
  }
  if ((*(byte *)((short)in_FSR2 + -1) & 0x80) == 0) {
    *(undefined1 *)in_FSR1 = 0;
  }
  else {
    *(undefined1 *)in_FSR1 = 0xff;
  }
  puVar2 = (undefined1 *)((short)in_FSR1 + 1);
  bVar3 = FUN_CODE_00cefe();
  *puVar2 = *puVar2;
LAB_CODE_00cc58:
  FUN_CODE_00cd24(bVar3);
  return;
}

