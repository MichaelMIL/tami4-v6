// address 0x00f278

void FUN_CODE_00f278(void)

{
  BADSPACEBASE *in_FSR2;
  undefined1 *puVar1;
  undefined1 *puVar2;
  undefined1 *puVar3;
  undefined1 *puVar4;
  BADSPACEBASE *in_FSR1;
  undefined1 *puVar5;
  undefined1 *puVar6;
  byte bVar7;
  undefined1 *in_TBLPTR;
  
  FUN_CODE_00f394();
  *(undefined1 *)in_FSR1 = *(undefined1 *)in_FSR1;
  *(undefined1 *)((short)in_FSR1 + 1) = *(undefined1 *)((short)in_FSR1 + 1);
  *(undefined1 *)((short)in_FSR1 + 2) = *(undefined1 *)((short)in_FSR1 + 2);
  puVar5 = (undefined1 *)((short)in_FSR1 + 4);
  *(undefined1 *)((short)in_FSR1 + 3) = *(undefined1 *)((short)in_FSR1 + 3);
  *(undefined1 *)((short)in_FSR2 + 5) = 4;
  *(undefined1 *)((short)in_FSR2 + 5) = 0x33;
  puVar1 = (undefined1 *)((short)in_FSR2 + 3);
  DAT_DATA_0008 = 0x82 - *(char *)((short)in_FSR2 + 6);
  DAT_DATA_0009 = '\x02';
  DAT_DATA_000d = 2;
  DAT_DATA_000e = 0;
  DAT_DATA_0014 = DAT_DATA_0008;
  DAT_DATA_0015 = DAT_DATA_0009;
  FUN_CODE_00f3ce();
  DAT_DATA_0014 = DAT_DATA_0008;
  DAT_DATA_0015 = DAT_DATA_0009;
  puVar1[3] = DAT_DATA_0008;
  puVar1[1] = 0;
  while( true ) {
    if ((byte)puVar1[6] <= (byte)puVar1[2]) break;
    puVar2 = puVar1 + 3;
    *puVar5 = puVar1[5];
    puVar6 = puVar5 + 2;
    puVar5[1] = puVar1[3] + '\x02';
    FUN_CODE_00cfc6();
    *puVar6 = *puVar6;
    puVar5 = puVar6 + -2;
    puVar6[-1] = puVar6[-1];
    puVar3 = puVar2 + 1;
    puVar2[2] = 0;
    while( true ) {
      puVar1 = puVar3 + 1;
      if ((byte)puVar3[4] <= (byte)puVar3[3]) break;
      bVar7 = (byte)((ushort)(byte)puVar3[2] * 0x33);
      DAT_DATA_0014 = bVar7 + 0x10;
      DAT_DATA_0015 = (char)((ushort)(byte)puVar3[2] * 0x33 >> 8) + -0x70 + (0xef < bVar7);
      puVar4 = puVar3 + 3;
      in_TBLPTR = (undefined1 *)
                  CONCAT12((char)((uint3)in_TBLPTR >> 0x10),
                           CONCAT11(DAT_DATA_0015 + CARRY1(DAT_DATA_0014,puVar3[4]),
                                    DAT_DATA_0014 + puVar3[4]));
      FUN_CODE_00f3c4(*in_TBLPTR);
      puVar3 = puVar4 + 2;
      puVar4[2] = puVar4[3] + '\x01';
    }
    puVar3[2] = puVar3[2] + '\x01';
  }
  if ((byte)puVar5 < 5) {
    *(undefined1 *)((ushort)puVar5 & 0xff00) = *(undefined1 *)((ushort)puVar5 & 0xff00);
  }
  FUN_CODE_00f3a8((byte)puVar5 - 5);
  return;
}

