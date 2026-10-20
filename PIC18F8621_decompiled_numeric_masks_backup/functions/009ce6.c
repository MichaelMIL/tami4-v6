// address 0x009ce6

/* WARNING: Restarted to delay deadcode elimination for space: DATA */

byte FUN_CODE_009ce6(void)

{
  byte bVar1;
  undefined1 uVar2;
  byte bVar3;
  char cVar4;
  BADSPACEBASE *in_FSR1;
  undefined1 *puVar5;
  byte *pbVar6;
  byte *pbVar7;
  undefined1 *puVar8;
  byte *pbVar9;
  byte *pbVar10;
  byte *pbVar11;
  byte *pbVar12;
  byte *pbVar13;
  byte *pbVar14;
  short sVar15;
  char *pcVar16;
  byte *pbVar17;
  byte *pbVar18;
  undefined1 *puVar19;
  
  clearWatchDogTimer();
  uVar2 = INTCON;
  pbVar7 = &FramePointer10x0001;
  bVar1 = INTCON;
  INTCON = bVar1 & 0x3f;
  while (DAT_DATA_00ad != '\0' || DAT_DATA_00ac != 0) {
    DAT_DATA_0060 = DAT_DATA_00ac;
    DAT_DATA_0061 = DAT_DATA_00ad;
    pbVar14 = (byte *)CONCAT11(DAT_DATA_00ad + (0xfc < DAT_DATA_00ac),DAT_DATA_00ac + 3);
    sVar15 = CONCAT11(DAT_DATA_00ad,DAT_DATA_00ac);
    DAT_DATA_00ac = *pbVar14;
    DAT_DATA_00ad = pbVar14[1];
    *(undefined1 *)(sVar15 + 4) = 0;
    *(undefined1 *)(sVar15 + 6) = 0;
    *(byte *)CONCAT11(DAT_DATA_0061,DAT_DATA_0060) =
         *(byte *)CONCAT11(DAT_DATA_0061,DAT_DATA_0060) & 0x8f | 0x50;
    *pbVar7 = 0x98;
    pbVar7[1] = 0;
    pbVar7[2] = DAT_DATA_0060;
    puVar5 = pbVar7 + 4;
    pbVar7[3] = DAT_DATA_0061;
    FUN_CODE_009b64();
    *puVar5 = *puVar5;
    puVar5[-1] = puVar5[-1];
    puVar5[-2] = puVar5[-2];
    puVar5[-3] = puVar5[-3];
    if (DAT_DATA_00ad == '\0' && DAT_DATA_00ac == 0) {
      DAT_DATA_00aa = 0;
      DAT_DATA_00ab = 0;
    }
    pbVar6 = (byte *)CONCAT11((char)((ushort)(puVar5 + -4) >> 8) - ~((char)(puVar5 + -4) != '\0'),
                              (char)(puVar5 + -4) + -1);
    bVar1 = INTCON;
    INTCON = bVar1 & 0x3f;
    bVar1 = INTCON;
    INTCON = bVar1 | *pbVar6;
    bVar1 = INTCON;
    pbVar7 = pbVar6 + 1;
    *pbVar6 = bVar1 & 0xc0;
    bVar1 = INTCON;
    INTCON = bVar1 & 0x3f;
  }
  while (cDATA00b1 != '\0') {
    cDATA00b1 = cDATA00b1 + -1;
    DAT_DATA_0060 = DAT_DATA_00ae;
    DAT_DATA_0061 = DAT_DATA_00af;
    if (DAT_DATA_00af != '\0' || DAT_DATA_00ae != 0) {
      pcVar16 = (char *)CONCAT11(DAT_DATA_00af + (0xfa < DAT_DATA_00ae),DAT_DATA_00ae + 5);
      *pcVar16 = *pcVar16 + -1;
    }
    while ((DAT_DATA_0061 != '\0' || DAT_DATA_0060 != 0 &&
           (*(char *)CONCAT11(DAT_DATA_0061 + (0xfa < DAT_DATA_0060),DAT_DATA_0060 + 5) == '\0'))) {
      pbVar17 = (byte *)CONCAT11(DAT_DATA_0061 + (0xfc < DAT_DATA_0060),DAT_DATA_0060 + 3);
      DAT_DATA_00ae = *pbVar17;
      DAT_DATA_00af = pbVar17[1];
      *(undefined1 *)CONCAT11(DAT_DATA_0061 + (0xfa < DAT_DATA_0060),DAT_DATA_0060 + 5) =
           DAT_DATA_00b0;
      *(byte *)CONCAT11(DAT_DATA_0061,DAT_DATA_0060) =
           *(byte *)CONCAT11(DAT_DATA_0061,DAT_DATA_0060) & 0x8f | 0x50;
      *pbVar7 = 0x98;
      pbVar7[1] = 0;
      pbVar7[2] = DAT_DATA_0060;
      puVar8 = pbVar7 + 4;
      pbVar7[3] = DAT_DATA_0061;
      FUN_CODE_009b64();
      *puVar8 = *puVar8;
      puVar8[-1] = puVar8[-1];
      puVar8[-2] = puVar8[-2];
      puVar8[-3] = puVar8[-3];
      DAT_DATA_0060 = DAT_DATA_00ae;
      DAT_DATA_0061 = DAT_DATA_00af;
      pbVar9 = (byte *)CONCAT11((char)((ushort)(puVar8 + -4) >> 8) - ~((char)(puVar8 + -4) != '\0'),
                                (char)(puVar8 + -4) + -1);
      bVar1 = INTCON;
      INTCON = bVar1 & 0x3f;
      bVar1 = INTCON;
      INTCON = bVar1 | *pbVar9;
      bVar1 = INTCON;
      pbVar7 = pbVar9 + 1;
      *pbVar9 = bVar1 & 0xc0;
      bVar1 = INTCON;
      INTCON = bVar1 & 0x3f;
    }
  }
  DAT_DATA_0060 = DAT_DATA_0098;
  DAT_DATA_0061 = DAT_DATA_0099;
  cVar4 = (char)pbVar7;
  if (DAT_DATA_0099 == '\0' && DAT_DATA_0098 == 0) {
    pbVar13 = (byte *)CONCAT11((char)((ushort)pbVar7 >> 8) - ~(cVar4 != '\0'),cVar4 + -1);
    bVar1 = INTCON;
    INTCON = bVar1 & 0x3f;
    bVar1 = INTCON;
    INTCON = bVar1 | *pbVar13;
    FUN_CODE_00b49e(*pbVar13);
    bVar1 = INTCON;
    pbVar12 = pbVar13 + 1;
    *pbVar13 = bVar1 & 0xc0;
    bVar1 = INTCON;
    INTCON = bVar1 & 0x3f;
  }
  else {
    pbVar18 = (byte *)CONCAT11(DAT_DATA_0099 + (0xfc < DAT_DATA_0098),DAT_DATA_0098 + 3);
    pbVar10 = (byte *)CONCAT11((char)((ushort)pbVar7 >> 8) - ~(cVar4 != '\0'),cVar4 + -1);
    bVar1 = INTCON;
    INTCON = bVar1 & 0x3f;
    bVar1 = *pbVar10;
    bVar3 = INTCON;
    INTCON = bVar3 | bVar1;
    puVar19 = (undefined1 *)CONCAT11(DAT_DATA_0099,DAT_DATA_0098);
    DAT_DATA_0098 = *pbVar18;
    DAT_DATA_0099 = pbVar18[1];
    *puVar19 = *puVar19;
    DAT_DATA_0014 = puVar19[1];
    DAT_DATA_0015 = puVar19[2];
    FUN_CODE_009e94(bVar1);
    bVar1 = INTCON;
    pbVar12 = pbVar10 + 1;
    *pbVar10 = bVar1 & 0xc0;
    bVar1 = INTCON;
    INTCON = bVar1 & 0x3f;
    if ((*(byte *)CONCAT11(DAT_DATA_0061,DAT_DATA_0060) & 0x70) == 0x50) {
      pbVar10[1] = 0x98;
      pbVar10[2] = 0;
      pbVar10[3] = DAT_DATA_0060;
      pbVar11 = pbVar10 + 5;
      pbVar10[4] = DAT_DATA_0061;
      FUN_CODE_009b64();
      *pbVar11 = *pbVar11;
      pbVar11[-1] = pbVar11[-1];
      pbVar11[-2] = pbVar11[-2];
      pbVar12 = pbVar11 + -4;
      pbVar11[-3] = pbVar11[-3];
    }
  }
  bVar1 = INTCON;
  INTCON = bVar1 & 0x3f;
  bVar1 = *(byte *)CONCAT11((char)((ushort)pbVar12 >> 8) - ~((char)pbVar12 != '\0'),
                            (char)pbVar12 + -1);
  bVar3 = INTCON;
  INTCON = bVar3 | bVar1;
  return bVar1;
}

