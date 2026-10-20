// address 0x00d4a4

char FUN_CODE_00d4a4(void)

{
  BADSPACEBASE *in_FSR1;
  undefined1 *puVar1;
  byte bVar7;
  undefined1 *puVar2;
  undefined1 *puVar3;
  undefined1 *puVar4;
  undefined1 *puVar5;
  undefined1 *puVar6;
  byte unaff_C;
  bool bVar8;
  
  FUN_CODE_00d700();
  puVar1 = (undefined1 *)((short)in_FSR1 + 1);
  *(undefined1 *)in_FSR1 = 0;
  FUN_CODE_00d724();
  bVar7 = (byte)((ushort)puVar1 >> 8);
  if ((unaff_C & 1) == 0) {
    puVar2 = (undefined1 *)((ushort)puVar1 & 0xff00);
    bVar7 = (byte)((ushort)(puVar2 + -1) >> 8);
    *puVar2 = *puVar2;
  }
  puVar4 = (undefined1 *)((ushort)bVar7 << 8);
  DAT_DATA_0201 = DAT_DATA_0014;
  if (DAT_DATA_0014 < '\0') {
    return DAT_DATA_0014;
  }
  if (DAT_DATA_0032 == '\0') {
    return '\0';
  }
  for (DAT_DATA_0033 = 1; DAT_DATA_0033 < 0x4b; DAT_DATA_0033 = DAT_DATA_0033 + 1) {
    FUN_CODE_00d6a0(DAT_DATA_0033);
    FUN_CODE_00d6d2(3);
    FUN_CODE_00d740(DAT_DATA_0033);
    puVar3 = (undefined1 *)((ushort)puVar4 & 0xff00);
    puVar4 = puVar3 + -1;
    *puVar3 = *puVar3;
    FUN_CODE_00d75e();
  }
  DAT_DATA_0033 = 1;
  while( true ) {
    if (0x4a < DAT_DATA_0033) {
      return '\0';
    }
    FUN_CODE_00d6a0(DAT_DATA_0033);
    FUN_CODE_00d6d2(5);
    bVar8 = 0xb4 < DAT_DATA_0033;
    FUN_CODE_00d740(DAT_DATA_0033 + 0x4b);
    if (!bVar8) {
      puVar5 = (undefined1 *)((ushort)puVar4 & 0xff00);
      puVar4 = puVar5 + -1;
      *puVar5 = *puVar5;
    }
    FUN_CODE_00d75e();
    if (bVar8) break;
    FUN_CODE_00d6a0(DAT_DATA_0033);
    FUN_CODE_00d6d2(4);
    bVar8 = 0x69 < DAT_DATA_0033;
    FUN_CODE_00d740(DAT_DATA_0033 + 0x96);
    if (!bVar8) {
      puVar6 = (undefined1 *)((ushort)puVar4 & 0xff00);
      puVar4 = puVar6 + -1;
      *puVar6 = *puVar6;
    }
    FUN_CODE_00d75e();
    if (bVar8) {
      return DAT_DATA_0201;
    }
    DAT_DATA_0033 = DAT_DATA_0033 + 1;
  }
  return DAT_DATA_0201;
}

