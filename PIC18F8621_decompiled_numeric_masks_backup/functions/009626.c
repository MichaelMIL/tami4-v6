// address 0x009626

/* WARNING: Restarted to delay deadcode elimination for space: DATA */

char FUN_CODE_0095f2(void)

{
  byte bVar1;
  BADSPACEBASE *in_FSR1;
  undefined1 *puVar2;
  undefined1 *puVar3;
  byte *pbVar4;
  undefined1 *puVar5;
  undefined1 *puVar6;
  undefined1 uVar7;
  BADSPACEBASE *in_FSR0;
  undefined1 *puVar8;
  byte in_PRODL;
  bool bVar9;
  
  if (DAT_DATA_0e09 == 'd') {
    DAT_DATA_0e0e = DAT_DATA_0e0e + -2;
    FUN_CODE_0099ea();
    puVar8 = (undefined1 *)((short)in_FSR0 + 1);
    *(undefined1 *)in_FSR1 = *(undefined1 *)in_FSR0;
    puVar3 = (undefined1 *)((short)in_FSR1 + 2);
    *(undefined1 *)((short)in_FSR1 + 1) = *(undefined1 *)((short)in_FSR0 + 1);
    FUN_CODE_00c328();
    puVar2 = puVar3 + -1;
    *puVar3 = *puVar3;
  }
  else {
    puVar8 = (undefined1 *)in_FSR0;
    if (DAT_DATA_0e09 != 'b') goto LAB_CODE_009626;
    DAT_DATA_0e0e = DAT_DATA_0e0e + -1;
    FUN_CODE_0099ea();
    puVar2 = (undefined1 *)((short)in_FSR1 + 1);
    *(undefined1 *)in_FSR1 = *(undefined1 *)in_FSR0;
    FUN_CODE_00c226();
    puVar8 = (undefined1 *)in_FSR0;
  }
  *puVar2 = *puVar2;
  puVar2[-1] = puVar2[-1];
  in_FSR1 = (BADSPACEBASE *)(puVar2 + -3);
  puVar2[-2] = puVar2[-2];
LAB_CODE_009626:
  *(byte *)in_FSR1 = DAT_DATA_0e0c;
  pbVar4 = (byte *)((short)in_FSR1 + 2);
  *(char *)((short)in_FSR1 + 1) = DAT_DATA_0e0d;
  FUN_CODE_00f5c4();
  DAT_DATA_0e05 = in_PRODL;
  *pbVar4 = *pbVar4;
  puVar5 = pbVar4 + -2;
  pbVar4[-1] = pbVar4[-1];
  DAT_DATA_0015 = 0;
  bVar9 = CARRY1(DAT_DATA_0e0c,DAT_DATA_0e05);
  DAT_DATA_0e0c = DAT_DATA_0e0c + DAT_DATA_0e05;
  DAT_DATA_0e0d = DAT_DATA_0e0d + bVar9;
  if (DAT_DATA_0e08 != '\0') {
    if (DAT_DATA_0e07 <= DAT_DATA_0e05) {
      return DAT_DATA_0e05 - DAT_DATA_0e07;
    }
    DAT_DATA_0e06 = DAT_DATA_0e07 - DAT_DATA_0e05;
    DAT_DATA_0015 = 0;
    bVar9 = CARRY1(DAT_DATA_0e0c,DAT_DATA_0e06 - 1);
    DAT_DATA_0e0c = DAT_DATA_0e0c + (DAT_DATA_0e06 - 1);
    DAT_DATA_0e0d = DAT_DATA_0e0d + bVar9;
    while( true ) {
      bVar1 = DAT_DATA_0e05 - 1;
      bVar9 = DAT_DATA_0e05 == 0;
      DAT_DATA_0e05 = bVar1;
      if (bVar9) break;
      DAT_DATA_0014 = DAT_DATA_0e06;
      DAT_DATA_0015 = 0;
      puVar8 = (undefined1 *)
               CONCAT11(DAT_DATA_0e0d - ~(DAT_DATA_0e06 <= DAT_DATA_0e0c),
                        DAT_DATA_0e0c - DAT_DATA_0e06);
      uVar7 = FUN_CODE_0099b6(*puVar8);
      *puVar8 = uVar7;
      bVar9 = DAT_DATA_0e0c != 0;
      DAT_DATA_0e0c = DAT_DATA_0e0c - 1;
      DAT_DATA_0e0d = DAT_DATA_0e0d - ~bVar9;
    }
    while( true ) {
      if (DAT_DATA_0e06 == 0) break;
      if (DAT_DATA_0e08 == '\x01') {
        uVar7 = 0x20;
      }
      else {
        uVar7 = 0x30;
      }
      puVar6 = puVar5 + 1;
      *puVar5 = uVar7;
      DAT_DATA_0e06 = DAT_DATA_0e06 - 1;
      FUN_CODE_0099b6();
      bVar9 = DAT_DATA_0e0c != 0;
      DAT_DATA_0e0c = DAT_DATA_0e0c - 1;
      DAT_DATA_0e0d = DAT_DATA_0e0d - ~bVar9;
      puVar5 = puVar6 + -1;
      *puVar6 = *puVar6;
      *puVar8 = puVar6[-1];
    }
    bVar9 = CARRY1(DAT_DATA_0e0c,DAT_DATA_0e07 + 1);
    DAT_DATA_0e0c = DAT_DATA_0e0c + DAT_DATA_0e07 + 1;
    DAT_DATA_0e0d = DAT_DATA_0e0d + bVar9;
    DAT_DATA_0e06 = 0xff;
  }
  DAT_DATA_0015 = 0;
  return '\0';
}

