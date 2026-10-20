// address 0x00ec76

undefined1 FUN_CODE_00ec76(void)

{
  byte bVar1;
  BADSPACEBASE *in_FSR1;
  undefined1 *puVar2;
  undefined1 *puVar3;
  undefined1 *puVar4;
  undefined1 *puVar5;
  undefined1 *puVar6;
  undefined1 *puVar7;
  undefined1 *puVar8;
  char cVar9;
  
  puVar2 = &FramePointer10x0001;
  cVar9 = FUN_CODE_00d668();
  puVar4 = puVar2 + -1;
  *puVar2 = *puVar2;
  if (cVar9 != '\0') {
    puVar2[-1] = 0x42;
    *puVar2 = 0;
    puVar2[1] = 0xe4;
    puVar3 = puVar2 + 3;
    puVar2[2] = 0;
    FUN_CODE_00e1aa();
    *puVar3 = *puVar3;
    puVar3[-1] = puVar3[-1];
    puVar3[-2] = puVar3[-2];
    puVar4 = puVar3 + -4;
    puVar3[-3] = puVar3[-3];
  }
  *puVar4 = 0xb2;
  puVar4[1] = 0;
  puVar4[2] = 0x40;
  puVar4[3] = 0;
  puVar4[4] = 0xe4;
  puVar5 = puVar4 + 6;
  puVar4[5] = 0;
  DAT_DATA_0014 = FUN_CODE_00dfd6();
  bVar1 = (byte)puVar5;
  if (bVar1 < 6) {
    puVar6 = (undefined1 *)((ushort)puVar5 & 0xff00);
    puVar5 = puVar6 + -1;
    *puVar6 = *puVar6;
  }
  puVar7 = (undefined1 *)CONCAT11((char)((ushort)puVar5 >> 8),bVar1 - 6);
  *puVar7 = 0xf2;
  puVar7[1] = 0;
  puVar7[2] = 2;
  puVar7[3] = 0;
  puVar7[4] = 0x24;
  puVar8 = puVar7 + 6;
  puVar7[5] = 1;
  DAT_DATA_0014 = FUN_CODE_00dfd6();
  if ((byte)puVar8 < 6) {
    *(undefined1 *)((ushort)puVar8 & 0xff00) = *(undefined1 *)((ushort)puVar8 & 0xff00);
  }
  return 0;
}

