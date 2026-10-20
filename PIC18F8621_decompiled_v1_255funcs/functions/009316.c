// address 0x009316

void FUN_CODE_009316(void)

{
  char cVar1;
  BADSPACEBASE *in_FSR2;
  char *pcVar2;
  byte bVar3;
  BADSPACEBASE *in_FSR1;
  undefined1 *puVar4;
  undefined1 *puVar5;
  undefined1 *puVar6;
  undefined1 *puVar7;
  char *pcVar8;
  char *pcVar9;
  undefined1 *puVar10;
  undefined1 uVar11;
  undefined1 in_PRODL;
  undefined1 in_PRODH;
  
  FUN_CODE_009a5a();
  puVar4 = (undefined1 *)((short)in_FSR1 + 1);
  pcVar8 = (char *)((short)in_FSR1 + 1);
  *(undefined1 *)in_FSR1 = *(undefined1 *)in_FSR1;
  if (((((DAT_DATA_015a & 1) == 0) && (DAT_DATA_0100 != '\x04')) && (DAT_DATA_0100 != '\x05')) &&
     ((DAT_DATA_0100 != '\x14' && (DAT_DATA_0100 + -0x1f != '\0')))) {
    FUN_CODE_009ac8(DAT_DATA_0100 + -0x1f);
    DAT_DATA_0016 = 0;
    *puVar4 = in_PRODL;
    puVar4[1] = in_PRODH;
    puVar5 = puVar4 + 3;
    puVar4[2] = DAT_DATA_0016;
    FUN_CODE_009a26();
    DAT_DATA_0017 = FUN_CODE_00f592();
    bVar3 = (byte)puVar5;
    if (bVar3 < 5) {
      puVar6 = (undefined1 *)((ushort)puVar5 & 0xff00);
      puVar5 = puVar6 + -1;
      *puVar6 = *puVar6;
    }
    puVar7 = (undefined1 *)CONCAT11((char)((ushort)puVar5 >> 8),bVar3 - 5);
    FUN_CODE_009a26(DAT_DATA_0017);
    uVar11 = FUN_CODE_00cbf2();
    *puVar7 = *puVar7;
    pcVar8 = puVar7 + -2;
    puVar7[-1] = puVar7[-1];
    *(undefined1 *)in_FSR2 = uVar11;
    while (*(char *)in_FSR2 != '\0') {
      pcVar2 = (char *)((short)in_FSR2 + 1);
      pcVar9 = pcVar8 + 1;
      *pcVar8 = *(char *)((short)in_FSR2 + 1) + *(char *)((short)in_FSR2 + -3) + -1;
      FUN_CODE_0093c6();
      pcVar8 = pcVar9 + -1;
      *pcVar9 = *pcVar9;
      *pcVar2 = *pcVar2 + -1;
      in_FSR2 = (BADSPACEBASE *)pcVar2;
    }
    cVar1 = *(char *)((short)in_FSR2 + -3);
  }
  else {
    cVar1 = *(char *)((short)in_FSR2 + -3);
  }
  if (cVar1 == '\a') {
    DAT_DATA_0e03 = *(undefined1 *)((short)in_FSR2 + -2);
    uVar11 = 0x16;
  }
  else {
    DAT_DATA_0e03 = *(undefined1 *)((short)in_FSR2 + -2);
    uVar11 = 6;
  }
  *pcVar8 = uVar11;
  pcVar8[1] = 0;
  puVar10 = pcVar8 + 3;
  pcVar8[2] = *(undefined1 *)in_FSR2;
  FUN_CODE_0098fc();
  *puVar10 = *puVar10;
  FUN_CODE_009aa8();
  return;
}

