// address 0x0093ee

/* WARNING: Restarted to delay deadcode elimination for space: DATA */

void FUN_CODE_0093ee(void)

{
  BADSPACEBASE *in_FSR1;
  byte *pbVar1;
  undefined1 *puVar2;
  undefined1 *puVar3;
  byte bVar4;
  undefined1 uVar5;
  
  FUN_CODE_009a5a();
  pbVar1 = (byte *)((short)in_FSR1 + 1);
  *(byte *)in_FSR1 = DAT_DATA_0e00 & 0xcf;
  FUN_CODE_0099a8();
  DAT_DATA_0e06 = FUN_CODE_00cc0c();
  *pbVar1 = *pbVar1;
  pbVar1[-1] = pbVar1[-1];
  pbVar1[-2] = pbVar1[-2];
  DAT_DATA_01ea = '\0';
  DAT_DATA_01eb = DAT_DATA_0e05;
  DAT_DATA_0e07 = DAT_DATA_0e04;
  bVar4 = DAT_DATA_0e00 & 0x60;
  if (bVar4 == 0) {
    bVar4 = DAT_DATA_0e00 & 6;
    if (bVar4 == 6) {
      DAT_DATA_0014 = 0x40;
      DAT_DATA_0e07 = 0x40 - (DAT_DATA_0e06 >> 1);
    }
    else if (bVar4 == 4) {
      DAT_DATA_0e07 = 0x82 - DAT_DATA_0e06;
    }
    else if (bVar4 == 2) {
      DAT_DATA_0e07 = 0;
    }
    goto LAB_CODE_00948a;
  }
  if (bVar4 == 0x60) {
    if (DAT_DATA_0e05 < 0xfe || DAT_DATA_0e06 < DAT_DATA_0e05 + 2) {
      DAT_DATA_0e07 = DAT_DATA_0e04 + (DAT_DATA_0e05 - DAT_DATA_0e06 >> 1);
      goto LAB_CODE_00948a;
    }
    bVar4 = DAT_DATA_0e06 - DAT_DATA_0e05 >> 1;
  }
  else {
    if (bVar4 != 0x40) goto LAB_CODE_00948a;
    if (DAT_DATA_0e05 < 0xfe || DAT_DATA_0e06 < DAT_DATA_0e05 + 2) {
      DAT_DATA_0e07 = ((DAT_DATA_0e05 + DAT_DATA_0e04) - DAT_DATA_0e06) + 2;
      goto LAB_CODE_00948a;
    }
    bVar4 = DAT_DATA_0e06 - DAT_DATA_0e05;
  }
  DAT_DATA_01ea = -bVar4;
LAB_CODE_00948a:
  bVar4 = DAT_DATA_0e00 & 0x60;
  if (bVar4 == 0) {
    pbVar1[-3] = DAT_DATA_0e07;
    FUN_CODE_009a30(0);
  }
  else {
    puVar2 = pbVar1 + -2;
    pbVar1[-3] = DAT_DATA_0e04;
    FUN_CODE_009a30(bVar4);
    for (DAT_DATA_0e08 = DAT_DATA_0e04; DAT_DATA_0e08 < DAT_DATA_0e07;
        DAT_DATA_0e08 = DAT_DATA_0e08 + 1) {
      if ((DAT_DATA_0e00 & 0x80) == 0) {
        uVar5 = 0;
      }
      else {
        uVar5 = 0xff;
      }
      puVar3 = puVar2 + 1;
      *puVar2 = uVar5;
      FUN_CODE_00cefe();
      puVar2 = puVar3 + -1;
      *puVar3 = *puVar3;
    }
    DAT_DATA_0e07 = DAT_DATA_0e07 - DAT_DATA_0e04;
  }
  DAT_DATA_0e07 = DAT_DATA_01ea + DAT_DATA_0e06 + DAT_DATA_0e07;
  FUN_CODE_009972();
  return;
}

