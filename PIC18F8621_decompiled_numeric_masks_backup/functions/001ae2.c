// address 0x001ae2

/* WARNING: Restarted to delay deadcode elimination for space: DATA */

void FUN_CODE_001ae2(void)

{
  BADSPACEBASE *in_FSR2;
  BADSPACEBASE *in_FSR1;
  byte *pbVar1;
  byte *pbVar2;
  undefined1 uVar3;
  char cVar4;
  
  FUN_CODE_002af8();
  pbVar1 = (byte *)((short)in_FSR1 + 1);
  *(undefined1 *)in_FSR1 = 9;
  FUN_CODE_0025cc();
  uVar3 = FUN_CODE_009936();
  *pbVar1 = *pbVar1;
  pbVar1[-1] = pbVar1[-1];
  *(undefined1 *)in_FSR2 = uVar3;
  DAT_DATA_0e03 = 0;
  pbVar1[-2] = *(byte *)in_FSR2 < 0x79 | 0x8e;
  pbVar1[-1] = 0;
  FUN_CODE_0025cc();
  FUN_CODE_0028b4();
  pbVar2 = pbVar1 + -1;
  *pbVar1 = *pbVar1;
  cVar4 = DAT_DATA_0e04 - 3;
  if (2 < DAT_DATA_0e04) {
    DAT_DATA_0e04 = DAT_DATA_0e04 - 3;
    pbVar1[-1] = 0x98;
    FUN_CODE_0023f6(0x58);
    pbVar2 = pbVar1 + 1;
    *pbVar1 = DAT_DATA_0e04;
    FUN_CODE_00cfd8();
    *pbVar2 = *pbVar2;
    pbVar2[-1] = 0x93;
    cVar4 = FUN_CODE_0023f6(0x58);
  }
  *pbVar2 = *pbVar2;
  FUN_CODE_0021d8(cVar4);
  return;
}

