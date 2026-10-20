// address 0x00cc90

/* WARNING: Restarted to delay deadcode elimination for space: DATA */

void FUN_CODE_00cc5a(void)

{
  BADSPACEBASE *in_FSR2;
  undefined1 *puVar1;
  undefined1 *puVar2;
  byte *pbVar3;
  byte *pbVar4;
  undefined1 *puVar5;
  byte *pbVar6;
  BADSPACEBASE *in_FSR1;
  byte *pbVar7;
  byte *pbVar8;
  byte bVar9;
  char cVar10;
  byte *in_TBLPTR;
  undefined2 uVar12;
  undefined3 uVar11;
  bool bVar13;
  
  FUN_CODE_00cdd2();
  puVar2 = (undefined1 *)((short)in_FSR2 + 1);
  puVar1 = (undefined1 *)((short)in_FSR2 + 1);
  if ((*(byte *)((short)in_FSR2 + -3) & 1) == 0) {
    bVar9 = FUN_CODE_00cdec();
    DAT_DATA_01e9 = bVar9 & 0xf;
  }
  else {
    FUN_CODE_00cdec();
    DAT_DATA_01e9 = FUN_CODE_00cda0();
    puVar2 = puVar1;
  }
  DAT_DATA_01e7 = 0;
  pbVar3 = puVar2;
  do {
    uVar12 = (undefined2)((uint3)in_TBLPTR >> 8);
    if (DAT_DATA_01e9 <= DAT_DATA_01e7) {
      pbVar8 = (byte *)((short)in_FSR1 + 1);
      *(byte *)in_FSR1 = pbVar3[-3];
      FUN_CODE_00cc2c();
      *pbVar8 = *pbVar8;
      FUN_CODE_00cd24();
      return;
    }
    if ((pbVar3[-3] & 0x20) == 0) {
LAB_CODE_00cc90:
      pbVar4 = pbVar3 + 2;
      if ((pbVar3[-2] & 1) == 0) {
        pbVar4 = pbVar3 + 3;
        bVar9 = (byte)((ushort)*pbVar3 * 5);
        DAT_DATA_0016 = bVar9 - 0x20;
        DAT_DATA_0017 = (char)((ushort)*pbVar3 * 5 >> 8) + 'z' + (0x1f < bVar9);
        uVar11 = CONCAT21(uVar12,DAT_DATA_0016 + DAT_DATA_01e7);
        cVar10 = DAT_DATA_0017 + CARRY1(DAT_DATA_0016,DAT_DATA_01e7);
      }
      else {
        bVar9 = FUN_CODE_00cd7c();
        uVar11 = CONCAT21(uVar12,DAT_DATA_0014 + bVar9);
        cVar10 = DAT_DATA_0015 + CARRY1(DAT_DATA_0014,bVar9);
      }
      in_TBLPTR = (byte *)CONCAT12((char)((uint3)uVar11 >> 0x10),CONCAT11(cVar10,(char)uVar11));
      DAT_DATA_01e8 = *in_TBLPTR;
      puVar5 = pbVar4 + 1;
      if ((pbVar4[-3] & 0x80) != 0) {
        DAT_DATA_01e8 = ~DAT_DATA_01e8;
      }
      pbVar7 = (byte *)((short)in_FSR1 + 1);
      *(byte *)in_FSR1 = DAT_DATA_01e8;
      FUN_CODE_00cefe();
      in_FSR1 = (BADSPACEBASE *)(pbVar7 + -1);
      *pbVar7 = *pbVar7;
      pbVar6 = puVar5;
    }
    else {
      DAT_DATA_0014 = DAT_DATA_01ea;
      bVar9 = DAT_DATA_01ea + 1;
      bVar13 = -1 < (char)DAT_DATA_01ea;
      pbVar6 = pbVar3 + 1;
      DAT_DATA_01ea = bVar9;
      if ((bVar13) && (pbVar6 = pbVar3 + 1, bVar9 < DAT_DATA_01eb)) goto LAB_CODE_00cc90;
    }
    DAT_DATA_01e7 = DAT_DATA_01e7 + 1;
    pbVar3 = pbVar6;
  } while( true );
}

