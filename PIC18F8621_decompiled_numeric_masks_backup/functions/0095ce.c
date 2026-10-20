// address 0x0095ce

/* WARNING: Restarted to delay deadcode elimination for space: DATA */

void FUN_CODE_0094d8(void)

{
  undefined1 *puVar1;
  undefined1 *puVar2;
  undefined1 *puVar3;
  BADSPACEBASE *in_FSR2;
  BADSPACEBASE *in_FSR1;
  undefined1 *puVar4;
  byte *pbVar6;
  undefined1 *puVar7;
  byte *pbVar9;
  byte *pbVar10;
  byte *pbVar11;
  byte bVar12;
  undefined1 uVar13;
  char cVar14;
  undefined1 *puVar5;
  undefined1 *puVar8;
  
  FUN_CODE_009a5a();
  if ((DAT_DATA_0e00 & 0x10) != 0) {
    FUN_CODE_0099a8();
    DAT_DATA_0e06 = FUN_CODE_00cbf2();
    puVar4 = (undefined1 *)((short)in_FSR1 + -1);
    puVar5 = (undefined1 *)((short)in_FSR1 + -1);
    *(undefined1 *)in_FSR1 = *(undefined1 *)in_FSR1;
    in_FSR1 = (BADSPACEBASE *)((short)in_FSR1 + -2);
    *puVar4 = *puVar5;
    DAT_DATA_0e03 = DAT_DATA_0e03 - (DAT_DATA_0e06 + -1);
  }
  if ((DAT_DATA_0e00 & 0x60) == 0) {
    pbVar6 = (byte *)((short)in_FSR1 + 1);
    *(byte *)in_FSR1 = DAT_DATA_0e00 & 0xcf;
    FUN_CODE_0099a8();
    DAT_DATA_0e05 = FUN_CODE_00cb86();
    *pbVar6 = *pbVar6;
    pbVar6[-1] = pbVar6[-1];
    pbVar6[-2] = pbVar6[-2];
    pbVar9 = pbVar6 + -3;
    if (0x80 < DAT_DATA_0e05) {
      DAT_DATA_0e05 = 0x80;
      pbVar9 = pbVar6 + -3;
    }
  }
  else {
    DAT_DATA_0e05 = DAT_DATA_0e02;
    pbVar9 = (byte *)in_FSR1;
  }
  bVar12 = DAT_DATA_0e00 & 6;
  if (bVar12 == 6) {
    DAT_DATA_0014 = 0x40;
    bVar12 = 0x40 - (DAT_DATA_0e05 >> 1);
    DAT_DATA_0e04 = bVar12;
  }
  else if (bVar12 == 4) {
    bVar12 = 0x82 - DAT_DATA_0e05;
    DAT_DATA_0e04 = bVar12;
  }
  else {
    bVar12 = bVar12 ^ 2;
    if (bVar12 == 0) {
      DAT_DATA_0e04 = 0;
    }
  }
LAB_CODE_009546:
  FUN_CODE_0099a8(bVar12);
  FUN_CODE_0093ee();
  puVar7 = pbVar9 + -1;
  puVar8 = pbVar9 + -1;
  *pbVar9 = *pbVar9;
  pbVar9 = pbVar9 + -2;
  *puVar7 = *puVar8;
  do {
    while( true ) {
      puVar1 = (undefined1 *)((short)in_FSR2 + -3);
      *(char *)((short)in_FSR2 + -2) = *(char *)((short)in_FSR2 + -1) + '\x01';
      puVar2 = (undefined1 *)((short)in_FSR2 + 1);
      puVar3 = (undefined1 *)((short)in_FSR2 + 4);
      if (*(char *)((short)in_FSR2 + -1) == -1) {
        *(char *)((short)in_FSR2 + 2) = *(char *)((short)in_FSR2 + 3) + '\x01';
        puVar3 = (undefined1 *)((short)in_FSR2 + 6);
      }
      in_FSR2 = (BADSPACEBASE *)puVar3;
      DAT_DATA_0e09 = *(char *)CONCAT11(*puVar2,*puVar1);
      if (*(char *)CONCAT11(*puVar2,*puVar1) == '\0') {
        cVar14 = '\0';
        if ((DAT_DATA_0e00 & 0x60) != 0) {
          while (cVar14 = DAT_DATA_0e07 - DAT_DATA_0e05, DAT_DATA_0e07 < DAT_DATA_0e05) {
            if ((DAT_DATA_0e00 & 0x80) == 0) {
              uVar13 = 0;
            }
            else {
              uVar13 = 0xff;
            }
            FUN_CODE_009a3e(uVar13);
          }
        }
        FUN_CODE_009972(cVar14);
        return;
      }
      if ((DAT_DATA_0e00 & 8) == 0) break;
LAB_CODE_0095bc:
      *pbVar9 = DAT_DATA_0e00 & 0xcf | 0x20;
      pbVar10 = pbVar9 + 2;
      pbVar9[1] = DAT_DATA_0e09;
      FUN_CODE_00cc5a();
      pbVar11 = pbVar10 + -1;
      *pbVar10 = *pbVar10;
LAB_CODE_0095ce:
      pbVar9 = pbVar11 + -1;
      *pbVar11 = *pbVar11;
    }
    if (DAT_DATA_0e09 == '\n') break;
    if (DAT_DATA_0e09 != '\b') {
      if (DAT_DATA_0e09 == '\r') {
        DAT_DATA_0e00 = ~(DAT_DATA_0e00 & 0x80) | DAT_DATA_0e00 & 0x7f;
      }
      else if (DAT_DATA_0e09 != '\t') goto LAB_CODE_0095bc;
      pbVar11 = pbVar9 + 1;
      *pbVar9 = DAT_DATA_0e00 & 0xcf | 0x20;
      FUN_CODE_00cc2c();
      goto LAB_CODE_0095ce;
    }
    DAT_DATA_0e00 = ~(DAT_DATA_0e00 & 1) | DAT_DATA_0e00 & 0xfe;
  } while( true );
  bVar12 = 0;
  DAT_DATA_0e09 = '\n';
  if ((DAT_DATA_0e00 & 0x60) != 0) {
    while (bVar12 = DAT_DATA_0e07 - DAT_DATA_0e05, DAT_DATA_0e07 < DAT_DATA_0e05) {
      if ((DAT_DATA_0e00 & 0x80) == 0) {
        uVar13 = 0;
      }
      else {
        uVar13 = 0xff;
      }
      FUN_CODE_009a3e(uVar13);
    }
  }
  DAT_DATA_0e03 = DAT_DATA_0e03 + '\x01';
  goto LAB_CODE_009546;
}

