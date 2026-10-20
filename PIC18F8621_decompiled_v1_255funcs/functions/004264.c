// address 0x004264

/* WARNING: Instruction at (CODE,0x004354) overlaps instruction at (CODE,0x004352)
    */
/* WARNING: Restarted to delay deadcode elimination for space: DATA */

undefined1 FUN_CODE_004264(void)

{
  undefined1 *puVar1;
  byte *pbVar2;
  byte *pbVar3;
  undefined1 *puVar4;
  undefined1 *puVar5;
  BADSPACEBASE *in_FSR1;
  undefined1 *puVar6;
  undefined1 *puVar7;
  undefined1 *puVar8;
  byte *pbVar9;
  byte *pbVar10;
  undefined1 *puVar11;
  undefined1 *puVar12;
  undefined1 *puVar13;
  byte *pbVar14;
  undefined1 *puVar15;
  undefined1 *puVar16;
  undefined1 *puVar17;
  undefined1 *puVar18;
  undefined1 *puVar19;
  undefined1 *puVar20;
  byte bVar21;
  char cVar22;
  bool bVar23;
  
  pbVar3 = (byte *)CONCAT11((char)((ushort)&FramePointer10x0002 >> 8),(char)&FramePointer10x0002);
  bVar21 = PORTH;
  PORTH = bVar21 & ~RH6;
  if ((DAT_DATA_015b & 8) == 0) {
    bVar21 = PORTH;
    PORTH = bVar21 & ~RH6;
  }
  else {
    bVar21 = PORTH;
    PORTH = bVar21 & ~RH4;
  }
  bVar21 = PORTH;
  PORTH = bVar21 | RH7;
  bVar21 = PORTB;
  PORTB = bVar21 | RB0;
  bVar21 = PORTB;
  PORTB = bVar21 & ~RB1;
  bVar21 = PORTC;
  PORTC = bVar21 | RC0;
  bVar21 = PORTC;
  PORTC = bVar21 & ~RC1;
  DAT_DATA_010c = 0;
  DAT_DATA_010f = 0;
  DAT_DATA_0119 = 0;
  DAT_DATA_0104 = 0xff;
  DAT_DATA_0105 = 0;
  DAT_DATA_0108 = 0;
  DAT_DATA_0109 = 0;
  DAT_DATA_010a = 0;
  DAT_DATA_010b = 0;
  DAT_DATA_0123 = 0;
  puVar6 = &FramePointer10x0006;
  DAT_DATA_0111 = FUN_CODE_00d67e();
  puVar7 = puVar6 + -1;
  *puVar6 = *puVar6;
  DAT_DATA_0014 = (DAT_DATA_0158 & 0x38) >> 3;
  if (7 < DAT_DATA_0014) {
    DAT_DATA_0158 = DAT_DATA_0158 & 199;
  }
  FUN_CODE_00ce44(DAT_DATA_0014 - 8);
  FUN_CODE_00cfee();
  puVar8 = puVar7 + 1;
  *puVar7 = 0x5f;
  FUN_CODE_001ae2();
  pbVar9 = puVar8 + -1;
  *puVar8 = *puVar8;
  bVar21 = FUN_CODE_00485a();
  if ((bVar21 & 0x20) == 0) {
    cVar22 = FUN_CODE_00b53c();
    if (cVar22 == '\0') {
      if (((DAT_DATA_015a & 1) == 0) || (bVar21 = FUN_CODE_00485a(), (bVar21 & 0x40) == 0)) {
        if ((DAT_DATA_015a & 1) == 0) {
          puVar17 = pbVar9 + 1;
          *pbVar9 = 0x88;
          FUN_CODE_004850();
          puVar13 = puVar17 + -1;
          *puVar17 = *puVar17;
        }
        else {
          puVar16 = pbVar9 + 1;
          *pbVar9 = 0x80;
          FUN_CODE_004850();
          puVar13 = puVar16 + -1;
          *puVar16 = *puVar16;
        }
        FUN_CODE_00f278();
      }
      else {
        DAT_DATA_015a = DAT_DATA_015a & 0xfe;
        *pbVar9 = DAT_DATA_015a;
        pbVar14 = pbVar9 + 2;
        pbVar9[1] = 0x3a;
        FUN_CODE_00d5ec();
        *pbVar14 = *pbVar14;
        pbVar14[-1] = pbVar14[-1];
        pbVar14[-2] = 3;
        pbVar14[-1] = 0x6d;
        FUN_CODE_009316();
        *pbVar14 = *pbVar14;
        pbVar14[-1] = pbVar14[-1];
        puVar15 = pbVar14 + -1;
        pbVar14[-2] = 0xf0;
        FUN_CODE_004850();
        puVar13 = puVar15 + -1;
        *puVar15 = *puVar15;
      }
    }
    else {
      DAT_DATA_015a = DAT_DATA_015a & 0xfe;
      *pbVar9 = 3;
      puVar11 = pbVar9 + 2;
      pbVar9[1] = 0x6f;
      FUN_CODE_009316();
      *puVar11 = *puVar11;
      puVar11[-1] = puVar11[-1];
      puVar12 = puVar11 + -1;
      puVar11[-2] = 0xaa;
      FUN_CODE_004850();
      puVar13 = puVar12 + -1;
      *puVar12 = *puVar12;
    }
    DAT_DATA_0107 = 0;
    DAT_DATA_0106 = 0;
    DAT_DATA_0142 = 8;
    DAT_DATA_0143 = 6;
    DAT_DATA_0144 = 0x28;
    DAT_DATA_0145 = 7;
    DAT_DATA_0146 = 0x2f;
    DAT_DATA_0113 = 0x32;
    puVar18 = puVar13 + 1;
    *puVar13 = 0x15;
    DAT_DATA_0114 = FUN_CODE_00d67e();
    *puVar18 = *puVar18;
    DAT_DATA_0147 = 8;
    DAT_DATA_0148 = 0x73;
    DAT_DATA_0149 = 0x28;
    DAT_DATA_014a = 7;
    DAT_DATA_014b = 0x2f;
    puVar18[-1] = 3;
    DAT_DATA_0115 = FUN_CODE_00d5a8();
    *puVar18 = *puVar18;
    puVar18[-1] = 3;
    DAT_DATA_0116 = FUN_CODE_00d5ca();
    *puVar18 = *puVar18;
    puVar18[-1] = 0;
    cVar22 = FUN_CODE_00d67e();
    puVar20 = puVar18 + -1;
    *puVar18 = *puVar18;
    if (cVar22 != '\0') {
      puVar18[-1] = 0;
      puVar19 = puVar18 + 1;
      *puVar18 = 0;
      FUN_CODE_00d5ec();
      *puVar19 = *puVar19;
      puVar20 = puVar19 + -2;
      puVar19[-1] = puVar19[-1];
    }
    *puVar20 = *puVar20;
    puVar20[-1] = puVar20[-1];
    puVar20[-2] = puVar20[-2];
    puVar20[-3] = puVar20[-3];
    return 0;
  }
  DAT_DATA_015a = DAT_DATA_015a | 1;
  *pbVar9 = DAT_DATA_015a;
  pbVar10 = pbVar9 + 2;
  pbVar9[1] = 0x3a;
  FUN_CODE_00d5ec();
  *pbVar10 = *pbVar10;
  pbVar10[-1] = pbVar10[-1];
  pbVar10[-2] = 3;
  pbVar10[-1] = 0x6c;
  FUN_CODE_009316();
  *pbVar10 = *pbVar10;
  pbVar10[-1] = pbVar10[-1];
  *pbVar3 = 0;
  while (*pbVar3 < 3) {
    bVar21 = PORTB;
    PORTB = bVar21 | RB3;
    pbVar3[2] = 0;
    pbVar3[4] = 0;
    pbVar2 = pbVar3 + 2;
    while( true ) {
      puVar4 = pbVar2;
      bVar21 = puVar4[4];
      bVar23 = false;
      if (-1 < (char)bVar21) {
        bVar23 = bVar21 < (byte)~(0x99 < (byte)puVar4[2]) || 2 < bVar21 - ~(0x99 < (byte)puVar4[2]);
      }
      if (bVar23) break;
      cVar22 = '<';
      do {
        cVar22 = cVar22 + -1;
      } while (cVar22 != '\0');
      puVar4[4] = puVar4[5] + '\x01';
      pbVar2 = puVar4 + 4;
      if (puVar4[5] == -1) {
        puVar4[7] = puVar4[8] + '\x01';
        pbVar2 = puVar4 + 6;
      }
    }
    bVar21 = PORTB;
    PORTB = bVar21 & ~RB3;
    puVar4[4] = 0;
    puVar4[6] = 0;
    puVar1 = puVar4 + 4;
    while( true ) {
      puVar5 = puVar1;
      pbVar3 = puVar5 + 2;
      bVar21 = puVar5[4];
      bVar23 = false;
      if (-1 < (char)bVar21) {
        bVar23 = bVar21 < (byte)~(0x99 < (byte)puVar5[2]) || 2 < bVar21 - ~(0x99 < (byte)puVar5[2]);
      }
      if (bVar23) break;
      cVar22 = '<';
      do {
        cVar22 = cVar22 + -1;
      } while (cVar22 != '\0');
      puVar5[4] = puVar5[5] + '\x01';
      puVar1 = puVar5 + 4;
      if (puVar5[5] == -1) {
        puVar5[7] = puVar5[8] + '\x01';
        puVar1 = puVar5 + 6;
      }
    }
    puVar5[2] = puVar5[2] + '\x01';
  }
  do {
                    /* WARNING: Do nothing block with infinite loop */
  } while( true );
}

