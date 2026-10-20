// address 0x00b256

/* WARNING: Instruction at (CODE,0x00b276) overlaps instruction at (CODE,0x00b274)
    */

void FUN_CODE_00b256(void)

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
  undefined1 *puVar9;
  undefined1 *puVar10;
  undefined1 *puVar11;
  undefined1 *puVar12;
  char cVar13;
  byte unaff_C;
  
  DAT_DATA_0167 = 0;
  DAT_DATA_015d = 0;
  DAT_DATA_015e = 0;
  DAT_DATA_015f = 0;
  DAT_DATA_0160 = 0;
  bVar1 = INTCON2;
  INTCON2 = bVar1 & 0x7f;
  cVar13 = '<';
  do {
    cVar13 = cVar13 + -1;
  } while (cVar13 != '\0');
  bVar1 = TRISB;
  TRISB = bVar1 | 0x20;
  bVar1 = PORTB;
  DAT_DATA_0165 = (bVar1 & 0x20) == 0;
  bVar1 = INTCON2;
  INTCON2 = bVar1 | 0x80;
  FUN_CODE_009ad4();
  bVar1 = INTCON;
  INTCON = bVar1 & 0x3f;
  *(undefined1 *)in_FSR1 = 0;
  *(undefined1 *)((short)in_FSR1 + 1) = 0x9e;
  puVar2 = (undefined1 *)((short)in_FSR1 + 3);
  *(undefined1 *)((short)in_FSR1 + 2) = 0;
  FUN_CODE_009f46();
  *puVar2 = *puVar2;
  puVar2[-1] = puVar2[-1];
  puVar2[-2] = puVar2[-2];
  puVar2[-3] = 0;
  puVar2[-2] = 0xa2;
  puVar2[-1] = 0;
  FUN_CODE_009f46();
  *puVar2 = *puVar2;
  puVar2[-1] = puVar2[-1];
  puVar3 = puVar2 + -3;
  puVar2[-2] = puVar2[-2];
  FUN_CODE_00bc26();
  uDATA0163 = 0xff;
  uDATA0162 = 0xff;
  FUN_CODE_00b068();
  FUN_CODE_0075e2();
  FUN_CODE_00d4a4();
  uDATA0166 = 0;
  puVar4 = puVar3 + 1;
  *puVar3 = 0x23;
  uDATA0161 = FUN_CODE_00d67e();
  *puVar4 = *puVar4;
  uDATA0164 = 10;
  puVar4[-1] = 0x25;
  DAT_DATA_0157 = FUN_CODE_00d67e();
  *puVar4 = *puVar4;
  puVar4[-1] = 0x2b;
  DAT_DATA_0158 = FUN_CODE_00d67e();
  *puVar4 = *puVar4;
  puVar4[-1] = 0x2c;
  DAT_DATA_0159 = FUN_CODE_00d67e();
  *puVar4 = *puVar4;
  puVar4[-1] = 0x3a;
  DAT_DATA_015a = FUN_CODE_00d67e();
  *puVar4 = *puVar4;
  puVar4[-1] = 0x41;
  DAT_DATA_015b = FUN_CODE_00d67e();
  *puVar4 = *puVar4;
  puVar4[-1] = 0x45;
  uDATA015c = FUN_CODE_00d67e();
  puVar5 = puVar4 + -1;
  *puVar4 = *puVar4;
  if (DAT_DATA_0165 != '\0') {
    DAT_DATA_0157 = DAT_DATA_0157 | 0xbf;
    DAT_DATA_0158 = 0x68;
    DAT_DATA_0159 = DAT_DATA_0159 & 0x46 | 0x44;
    DAT_DATA_015a = 0xe7;
  }
  FUN_CODE_00ec76(DAT_DATA_0165);
  FUN_CODE_00e8ae();
  FUN_CODE_00e6ba();
  FUN_CODE_00f8b2();
  FUN_CODE_00f760();
  FUN_CODE_00f80c();
  FUN_CODE_00f9f4();
  FUN_CODE_00fca2();
  FUN_CODE_00fc98();
  FUN_CODE_00d3a2();
  FUN_CODE_00c8e4();
  FUN_CODE_00ac34();
  FUN_CODE_00dbe6();
  FUN_CODE_004264();
  FUN_CODE_00d8ea();
  DAT_DATA_0014 = FUN_CODE_00bff8();
  FUN_CODE_0075fe(DAT_DATA_0014 << 1 | unaff_C & 1);
  FUN_CODE_00d3b0();
  FUN_CODE_00c8f6();
  FUN_CODE_00ac46();
  FUN_CODE_00dc08();
  FUN_CODE_0044d4();
  FUN_CODE_00d8fc();
  *puVar5 = 1;
  puVar5[1] = 0x86;
  puVar5[2] = 0;
  puVar5[3] = 0xaa;
  puVar6 = puVar5 + 5;
  puVar5[4] = 0xb0;
  DAT_DATA_0014 = FUN_CODE_009af0();
  bVar1 = (byte)puVar6;
  if (bVar1 < 5) {
    puVar7 = (undefined1 *)((ushort)puVar6 & 0xff00);
    puVar6 = puVar7 + -1;
    *puVar7 = *puVar7;
  }
  puVar8 = (undefined1 *)CONCAT11((char)((ushort)puVar6 >> 8),bVar1 - 5);
  *puVar8 = 4;
  puVar8[1] = 0x8c;
  puVar8[2] = 0;
  puVar8[3] = 4;
  puVar9 = puVar8 + 5;
  puVar8[4] = 0xb1;
  DAT_DATA_0014 = FUN_CODE_009af0();
  bVar1 = (byte)puVar9;
  if (bVar1 < 5) {
    puVar10 = (undefined1 *)((ushort)puVar9 & 0xff00);
    puVar9 = puVar10 + -1;
    *puVar10 = *puVar10;
  }
  puVar11 = (undefined1 *)CONCAT11((char)((ushort)puVar9 >> 8),bVar1 - 5);
  bVar1 = INTCON;
  INTCON = bVar1 | 0xc0;
  puVar12 = puVar11 + 1;
  *puVar11 = 0x88;
  FUN_CODE_004850();
  *puVar12 = *puVar12;
  do {
    bVar1 = INTCON;
    INTCON = bVar1 | 0xc0;
    FUN_CODE_009ce6(0xc0);
  } while( true );
}

