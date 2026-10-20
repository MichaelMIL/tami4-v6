// PIC18F8621 firmware - Ghidra 12.1.4 (PIC-18) decompilation via REA
// Reconstructed pseudo-C, not original source. Names are addresses.
// DAT_DATA_xxxx = general-purpose RAM variable at that address (all SFRs at 0xF60-0xFFF are named).
// SFR names checked against the PIC18F8621 register map (MPLAB DFP 1.7.171); 0xF6F renamed SPBREG2 -> SPBRG2.

// ===== 0x000000 =====

void thunk_FUN_CODE_00fc08(void)

{
  DAT_DATA_0001 = DAT_DATA_0001 & 0xbf;
  FUN_CODE_00f956();
  do {
    FUN_CODE_00fcbc();
    FUN_CODE_00b256();
  } while( true );
}


// ===== 0x000008 =====

undefined1 thunk_FUN_CODE_00bcc0(void)

{
  BADSPACEBASE *in_FSR1;
  undefined1 *puVar1;
  undefined1 *puVar2;
  undefined1 *puVar3;
  undefined1 *puVar4;
  undefined1 *puVar5;
  char cVar6;
  undefined1 *puVar7;
  bool bVar8;
  undefined1 in_WS;
  
  puVar2 = &FramePointer10x0008;
  cVar6 = '\x14';
  puVar5 = (undefined1 *)0x0;
  while (bVar8 = cVar6 != '\0', cVar6 = cVar6 + -1, bVar8) {
    puVar1 = puVar2 + 1;
    puVar2 = puVar2 + 1;
    *puVar1 = *puVar5;
    puVar5 = puVar5 + 1;
  }
  cVar6 = '\x10';
  puVar5 = &DAT_DATA_0014;
  while (bVar8 = cVar6 != '\0', cVar6 = cVar6 + -1, bVar8) {
    puVar3 = puVar2 + 1;
    puVar2 = puVar2 + 1;
    *puVar3 = *puVar5;
    puVar5 = puVar5 + 1;
  }
  puVar4 = puVar2 + 1;
  *puVar2 = *puVar2;
  thunk_FUN_CODE_007628();
  *puVar4 = *puVar4;
  cVar6 = '\x10';
  puVar5 = puVar4 + -1;
  puVar7 = &DAT_DATA_0023;
  while (bVar8 = cVar6 != '\0', cVar6 = cVar6 + -1, bVar8) {
    *puVar7 = *puVar5;
    puVar5 = puVar5 + -1;
    puVar7 = puVar7 + -1;
  }
  cVar6 = '\x14';
  puVar7 = &DAT_DATA_0013;
  while (bVar8 = cVar6 != '\0', cVar6 = cVar6 + -1, bVar8) {
    *puVar7 = *puVar5;
    puVar5 = puVar5 + -1;
    puVar7 = puVar7 + -1;
  }
  return in_WS;
}


// ===== 0x000018 =====

/* WARNING: Restarted to delay deadcode elimination for space: DATA */

undefined1 thunk_FUN_CODE_00bd4a(void)

{
  byte bVar1;
  BADSPACEBASE *in_FSR1;
  undefined1 *puVar2;
  undefined1 *puVar3;
  undefined1 *puVar4;
  undefined1 *puVar5;
  undefined1 *puVar6;
  undefined1 *puVar7;
  char cVar8;
  undefined1 *puVar9;
  bool bVar10;
  
  puVar3 = &FramePointer10x000b;
  cVar8 = '\x14';
  puVar7 = (undefined1 *)0x0;
  while (bVar10 = cVar8 != '\0', cVar8 = cVar8 + -1, bVar10) {
    puVar2 = puVar3 + 1;
    puVar3 = puVar3 + 1;
    *puVar2 = *puVar7;
    puVar7 = puVar7 + 1;
  }
  cVar8 = '\x10';
  puVar7 = &DAT_DATA_0014;
  while (bVar10 = cVar8 != '\0', cVar8 = cVar8 + -1, bVar10) {
    puVar4 = puVar3 + 1;
    puVar3 = puVar3 + 1;
    *puVar4 = *puVar7;
    puVar7 = puVar7 + 1;
  }
  puVar5 = puVar3 + 1;
  puVar6 = puVar3 + 1;
  *puVar3 = *puVar3;
  bVar1 = INTCON;
  if (((bVar1 & 0x20) == 0) || (bVar1 = INTCON, (bVar1 & 4) == 0)) {
    FUN_CODE_00b49c();
    puVar7 = puVar6;
  }
  else {
    bVar1 = INTCON;
    INTCON = bVar1 & 0xfb;
    bVar1 = TMR0L;
    cVar8 = TMR0H;
    DAT_DATA_0edc = bVar1 + DAT_DATA_0eda;
    DAT_DATA_0edd = cVar8 + DAT_DATA_0edb + CARRY1(bVar1,DAT_DATA_0eda);
    TMR0H = DAT_DATA_0edd;
    TMR0L = DAT_DATA_0edc;
    if (DAT_DATA_0ede == '\0') {
      FUN_CODE_00b482(0);
      puVar7 = puVar5;
    }
    else {
      DAT_DATA_0edf = DAT_DATA_0edf + '\x01';
      puVar7 = puVar3 + 1;
      if (DAT_DATA_0edf == 'd') {
        DAT_DATA_0edf = '\0';
        puVar7 = puVar3 + 1;
      }
    }
  }
  *puVar7 = *puVar7;
  cVar8 = '\x10';
  puVar7 = puVar7 + -1;
  puVar9 = &DAT_DATA_0023;
  while (bVar10 = cVar8 != '\0', cVar8 = cVar8 + -1, bVar10) {
    *puVar9 = *puVar7;
    puVar7 = puVar7 + -1;
    puVar9 = puVar9 + -1;
  }
  cVar8 = '\x14';
  puVar9 = &DAT_DATA_0013;
  while (bVar10 = cVar8 != '\0', cVar8 = cVar8 + -1, bVar10) {
    *puVar9 = *puVar7;
    puVar7 = puVar7 + -1;
    puVar9 = puVar9 + -1;
  }
  return puVar7[-8];
}


// ===== 0x001ae2 =====

/* WARNING: Restarted to delay deadcode elimination for space: DATA */

void FUN_CODE_001ae2(void)

{
  BADSPACEBASE *in_FSR2;
  BADSPACEBASE *in_FSR1;
  byte *pbVar1;
  byte *pbVar2;
  undefined1 uVar3;
  char cVar4;
  
  FUN_CODE_002af8();
  pbVar1 = (byte *)((short)in_FSR1 + 1);
  *(undefined1 *)in_FSR1 = 9;
  FUN_CODE_0025cc();
  uVar3 = FUN_CODE_009936();
  *pbVar1 = *pbVar1;
  pbVar1[-1] = pbVar1[-1];
  *(undefined1 *)in_FSR2 = uVar3;
  DAT_DATA_0e03 = 0;
  pbVar1[-2] = *(byte *)in_FSR2 < 0x79 | 0x8e;
  pbVar1[-1] = 0;
  FUN_CODE_0025cc();
  FUN_CODE_0028b4();
  pbVar2 = pbVar1 + -1;
  *pbVar1 = *pbVar1;
  cVar4 = DAT_DATA_0e04 - 3;
  if (2 < DAT_DATA_0e04) {
    DAT_DATA_0e04 = DAT_DATA_0e04 - 3;
    pbVar1[-1] = 0x98;
    FUN_CODE_0023f6(0x58);
    pbVar2 = pbVar1 + 1;
    *pbVar1 = DAT_DATA_0e04;
    FUN_CODE_00cfd8();
    *pbVar2 = *pbVar2;
    pbVar2[-1] = 0x93;
    cVar4 = FUN_CODE_0023f6(0x58);
  }
  *pbVar2 = *pbVar2;
  FUN_CODE_0021d8(cVar4);
  return;
}


// ===== 0x002166 =====

void FUN_CODE_002166(void)

{
  return;
}


// ===== 0x0021d8 =====

void FUN_CODE_0021d8(void)

{
  return;
}


// ===== 0x0023f6 =====

void FUN_CODE_0023f6(void)

{
  BADSPACEBASE *in_FSR1;
  undefined1 *puVar1;
  
  puVar1 = &FramePointer10x0001;
  FUN_CODE_00cf2e();
  *puVar1 = *puVar1;
  puVar1[-1] = puVar1[-1];
  return;
}


// ===== 0x0025cc =====

undefined1 FUN_CODE_0025cc(void)

{
  return 0xfd;
}


// ===== 0x0028b4 =====

void FUN_CODE_0028b4(void)

{
  BADSPACEBASE *in_FSR1;
  
  FUN_CODE_0098fc();
  *(undefined1 *)in_FSR1 = *(undefined1 *)in_FSR1;
  *(undefined1 *)((short)in_FSR1 + -1) = *(undefined1 *)((short)in_FSR1 + -1);
  return;
}


// ===== 0x002af8 =====

void FUN_CODE_002af8(void)

{
  BADSPACEBASE *in_FSR1;
  
  FUN_CODE_002166();
  *(undefined1 *)in_FSR1 = *(undefined1 *)in_FSR1;
  return;
}


// ===== 0x004264 =====

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
  PORTH = bVar21 & 0xbf;
  if ((DAT_DATA_015b & 8) == 0) {
    bVar21 = PORTH;
    PORTH = bVar21 & 0xbf;
  }
  else {
    bVar21 = PORTH;
    PORTH = bVar21 & 0xef;
  }
  bVar21 = PORTH;
  PORTH = bVar21 | 0x80;
  bVar21 = PORTB;
  PORTB = bVar21 | 1;
  bVar21 = PORTB;
  PORTB = bVar21 & 0xfd;
  bVar21 = PORTC;
  PORTC = bVar21 | 1;
  bVar21 = PORTC;
  PORTC = bVar21 & 0xfd;
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
    PORTB = bVar21 | 8;
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
    PORTB = bVar21 & 0xf7;
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


// ===== 0x0044d4 =====

undefined1 FUN_CODE_0044d4(void)

{
  BADSPACEBASE *in_FSR1;
  undefined1 *puVar1;
  
  puVar1 = &FramePointer10x0005;
  DAT_DATA_0014 = FUN_CODE_009af0();
  if ((byte)puVar1 < 5) {
    *(undefined1 *)((ushort)puVar1 & 0xff00) = *(undefined1 *)((ushort)puVar1 & 0xff00);
  }
  return 0;
}


// ===== 0x004850 =====

void FUN_CODE_004850(void)

{
  BADSPACEBASE *in_FSR2;
  
  FUN_CODE_004c90();
  DAT_DATA_010f = *(undefined1 *)((short)in_FSR2 + -2);
  FUN_CODE_004d6e();
  return;
}


// ===== 0x00485a =====

byte FUN_CODE_00485a(void)

{
  byte bVar1;
  
  DAT_DATA_0024 = 0;
  bVar1 = TRISB;
  TRISB = bVar1 & 0xef;
  bVar1 = PORTB;
  PORTB = bVar1 & 0xef;
  bVar1 = PORTB;
  if ((bVar1 & 0x80) == 0) {
    DAT_DATA_0024 = 2;
  }
  bVar1 = PORTB;
  if ((bVar1 & 0x20) == 0) {
    DAT_DATA_0024 = DAT_DATA_0024 | 1;
  }
  bVar1 = PORTB;
  if ((bVar1 & 0x40) == 0) {
    DAT_DATA_0024 = DAT_DATA_0024 | 4;
  }
  bVar1 = TRISB;
  TRISB = bVar1 | 0x10;
  bVar1 = PORTB;
  PORTB = bVar1 | 0x10;
  bVar1 = TRISE;
  TRISE = bVar1 & 0xbf;
  bVar1 = PORTE;
  PORTE = bVar1 & 0xbf;
  bVar1 = PORTB;
  if ((bVar1 & 0x40) == 0) {
    DAT_DATA_0024 = DAT_DATA_0024 | 0x40;
  }
  bVar1 = TRISE;
  TRISE = bVar1 | 0x40;
  bVar1 = PORTE;
  PORTE = bVar1 | 0x40;
  bVar1 = TRISE;
  TRISE = bVar1 & 0x7f;
  bVar1 = PORTE;
  PORTE = bVar1 & 0x7f;
  bVar1 = PORTB;
  if ((bVar1 & 0x40) == 0) {
    DAT_DATA_0024 = DAT_DATA_0024 | 0x20;
  }
  bVar1 = PORTB;
  if ((bVar1 & 0x80) == 0) {
    DAT_DATA_0024 = DAT_DATA_0024 | 8;
  }
  bVar1 = PORTB;
  if ((bVar1 & 0x20) == 0) {
    DAT_DATA_0024 = DAT_DATA_0024 | 0x10;
  }
  bVar1 = TRISE;
  TRISE = bVar1 | 0x80;
  bVar1 = PORTE;
  PORTE = bVar1 | 0x80;
  return DAT_DATA_0024;
}


// ===== 0x004bd8 =====

void FUN_CODE_004bd8(void)

{
  BADSPACEBASE *in_FSR2;
  
  FUN_CODE_004c90();
  DAT_DATA_0107 = *(undefined1 *)((short)in_FSR2 + -2);
  FUN_CODE_004d6e();
  return;
}


// ===== 0x004c90 =====

void FUN_CODE_004c90(void)

{
  FUN_CODE_004f80();
  return;
}


// ===== 0x004d6e =====

void FUN_CODE_004d6e(void)

{
  return;
}


// ===== 0x004f80 =====

void FUN_CODE_004f80(void)

{
  return;
}


// ===== 0x0075e2 =====

undefined1 FUN_CODE_0075e2(void)

{
  BADSPACEBASE *in_FSR1;
  undefined1 *puVar1;
  
  puVar1 = &FramePointer10x0001;
  FUN_CODE_0079ea();
  FUN_CODE_009f46();
  *puVar1 = *puVar1;
  puVar1[-1] = puVar1[-1];
  puVar1[-2] = puVar1[-2];
  DAT_DATA_0169 = 0;
  DAT_DATA_016c = 0;
  DAT_DATA_016b = 0;
  DAT_DATA_0168 = DAT_DATA_0168 | 3;
  return 0;
}


// ===== 0x0075fe =====

undefined1 FUN_CODE_0075fe(void)

{
  BADSPACEBASE *in_FSR1;
  undefined1 *puVar1;
  
  puVar1 = &FramePointer10x0005;
  DAT_DATA_0014 = FUN_CODE_009af0();
  if ((byte)puVar1 < 5) {
    *(undefined1 *)((ushort)puVar1 & 0xff00) = *(undefined1 *)((ushort)puVar1 & 0xff00);
  }
  return 0;
}


// ===== 0x007628 =====

/* WARNING: Restarted to delay deadcode elimination for space: DATA */

char FUN_CODE_007628(char param_1)

{
  byte bVar1;
  BADSPACEBASE *in_FSR1;
  undefined1 *puVar2;
  char cVar4;
  bool bVar5;
  undefined1 *puVar3;
  
  while (bVar1 = PIR3, (bVar1 & 0x20) != 0) {
    DAT_DATA_003f = RCREG2;
    param_1 = '\0';
    if (((DAT_DATA_0168 & 1) != 0) &&
       ((DAT_DATA_0169 < 0xb || (param_1 = RCREG2 - 0xd, param_1 == '\0')))) {
      do {
        bVar1 = PIR3;
      } while ((bVar1 & 0x10) == 0);
      TXREG2 = RCREG2;
      if (RCREG2 == 0xd) {
        DAT_DATA_0168 = DAT_DATA_0168 & 0xfe;
        FUN_CODE_0079ea(0);
        param_1 = FUN_CODE_009f7a();
        puVar2 = (undefined1 *)((short)in_FSR1 + -1);
        puVar3 = (undefined1 *)((short)in_FSR1 + -1);
        *(undefined1 *)in_FSR1 = *(undefined1 *)in_FSR1;
        in_FSR1 = (BADSPACEBASE *)((short)in_FSR1 + -2);
        *puVar2 = *puVar3;
      }
      else {
        if (RCREG2 == 0x20) {
          DAT_DATA_0168 = DAT_DATA_0168 & 0xfd;
        }
        if ((DAT_DATA_0168 & 2) != 0) {
          *(byte *)in_FSR1 = DAT_DATA_0169;
          cVar4 = *(char *)in_FSR1;
          *(char *)in_FSR1 = cVar4;
          bVar1 = RCREG2;
          while (cVar4 != '\0') {
            bVar1 = bVar1 << 1;
            cVar4 = *(char *)in_FSR1 + -1;
            *(char *)in_FSR1 = cVar4;
          }
          DAT_DATA_016b = bVar1 ^ DAT_DATA_016b;
        }
        bVar5 = 0x93 < DAT_DATA_0169;
        cVar4 = DAT_DATA_0169 + 0x6c;
        DAT_DATA_003f = TXREG2;
        DAT_DATA_0169 = DAT_DATA_0169 + 1;
        *(byte *)CONCAT11(bVar5 + '\x01',cVar4) = TXREG2;
        param_1 = '\x01';
        *(undefined1 *)CONCAT11((0x93 < DAT_DATA_0169) + '\x01',DAT_DATA_0169 + 0x6c) = 0;
      }
    }
  }
  return param_1;
}


// ===== 0x0079ea =====

undefined1 FUN_CODE_0079ea(void)

{
  return 0;
}


// ===== 0x009282 =====

void FUN_CODE_009282(void)

{
  char cVar1;
  undefined1 uVar2;
  byte unaff_Z;
  
  cVar1 = FUN_CODE_0099c0();
  if ((unaff_Z & 1) == 0) {
    if (cVar1 == '\x01') {
      FUN_CODE_00998e();
      uVar2 = 0xee;
    }
    else {
      if (cVar1 != '\x04') goto LAB_CODE_0092ac;
      FUN_CODE_00998e();
      uVar2 = 0xf1;
    }
  }
  else {
    FUN_CODE_00998e();
    uVar2 = 0xef;
  }
  FUN_CODE_0099ca(uVar2);
LAB_CODE_0092ac:
  FUN_CODE_009972();
  return;
}


// ===== 0x0092ac =====

void FUN_CODE_009282(void)

{
  char cVar1;
  undefined1 uVar2;
  byte unaff_Z;
  
  cVar1 = FUN_CODE_0099c0();
  if ((unaff_Z & 1) == 0) {
    if (cVar1 == '\x01') {
      FUN_CODE_00998e();
      uVar2 = 0xee;
    }
    else {
      if (cVar1 != '\x04') goto LAB_CODE_0092ac;
      FUN_CODE_00998e();
      uVar2 = 0xf1;
    }
  }
  else {
    FUN_CODE_00998e();
    uVar2 = 0xef;
  }
  FUN_CODE_0099ca(uVar2);
LAB_CODE_0092ac:
  FUN_CODE_009972();
  return;
}


// ===== 0x0092ae =====

void FUN_CODE_0092ae(void)

{
  char cVar1;
  undefined1 uVar2;
  byte unaff_Z;
  
  cVar1 = FUN_CODE_0099c0();
  if ((unaff_Z & 1) == 0) {
    if (cVar1 == '\x01') {
      FUN_CODE_00998e();
      uVar2 = 0xef;
    }
    else {
      if (cVar1 != '\x04') goto LAB_CODE_0092d8;
      FUN_CODE_00998e();
      uVar2 = 0xf2;
    }
  }
  else {
    FUN_CODE_00998e();
    uVar2 = 0xf0;
  }
  FUN_CODE_0099ca(uVar2);
LAB_CODE_0092d8:
  FUN_CODE_009972();
  return;
}


// ===== 0x0092d8 =====

void FUN_CODE_0092ae(void)

{
  char cVar1;
  undefined1 uVar2;
  byte unaff_Z;
  
  cVar1 = FUN_CODE_0099c0();
  if ((unaff_Z & 1) == 0) {
    if (cVar1 == '\x01') {
      FUN_CODE_00998e();
      uVar2 = 0xef;
    }
    else {
      if (cVar1 != '\x04') goto LAB_CODE_0092d8;
      FUN_CODE_00998e();
      uVar2 = 0xf2;
    }
  }
  else {
    FUN_CODE_00998e();
    uVar2 = 0xf0;
  }
  FUN_CODE_0099ca(uVar2);
LAB_CODE_0092d8:
  FUN_CODE_009972();
  return;
}


// ===== 0x009316 =====

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


// ===== 0x0093c6 =====

void FUN_CODE_0093c6(void)

{
  BADSPACEBASE *in_FSR2;
  BADSPACEBASE *in_FSR1;
  undefined1 *puVar1;
  char cVar2;
  undefined1 uVar3;
  
  cVar2 = FUN_CODE_0099e2();
  if (cVar2 == '\a') {
    *(undefined1 *)in_FSR1 = 0x5b;
    uVar3 = 0x12;
  }
  else {
    *(undefined1 *)in_FSR1 = 0x5f;
    uVar3 = 0x10;
  }
  *(undefined1 *)((short)in_FSR1 + 1) = uVar3;
  *(undefined1 *)((short)in_FSR1 + 2) = 1;
  puVar1 = (undefined1 *)((short)in_FSR1 + 4);
  *(undefined1 *)((short)in_FSR1 + 3) = *(undefined1 *)((short)in_FSR2 + -2);
  FUN_CODE_00d008();
  *puVar1 = *puVar1;
  FUN_CODE_009aa8();
  return;
}


// ===== 0x0093ee =====

/* WARNING: Restarted to delay deadcode elimination for space: DATA */

void FUN_CODE_0093ee(void)

{
  BADSPACEBASE *in_FSR1;
  byte *pbVar1;
  undefined1 *puVar2;
  undefined1 *puVar3;
  byte bVar4;
  undefined1 uVar5;
  
  FUN_CODE_009a5a();
  pbVar1 = (byte *)((short)in_FSR1 + 1);
  *(byte *)in_FSR1 = DAT_DATA_0e00 & 0xcf;
  FUN_CODE_0099a8();
  DAT_DATA_0e06 = FUN_CODE_00cc0c();
  *pbVar1 = *pbVar1;
  pbVar1[-1] = pbVar1[-1];
  pbVar1[-2] = pbVar1[-2];
  DAT_DATA_01ea = '\0';
  DAT_DATA_01eb = DAT_DATA_0e05;
  DAT_DATA_0e07 = DAT_DATA_0e04;
  bVar4 = DAT_DATA_0e00 & 0x60;
  if (bVar4 == 0) {
    bVar4 = DAT_DATA_0e00 & 6;
    if (bVar4 == 6) {
      DAT_DATA_0014 = 0x40;
      DAT_DATA_0e07 = 0x40 - (DAT_DATA_0e06 >> 1);
    }
    else if (bVar4 == 4) {
      DAT_DATA_0e07 = 0x82 - DAT_DATA_0e06;
    }
    else if (bVar4 == 2) {
      DAT_DATA_0e07 = 0;
    }
    goto LAB_CODE_00948a;
  }
  if (bVar4 == 0x60) {
    if (DAT_DATA_0e05 < 0xfe || DAT_DATA_0e06 < DAT_DATA_0e05 + 2) {
      DAT_DATA_0e07 = DAT_DATA_0e04 + (DAT_DATA_0e05 - DAT_DATA_0e06 >> 1);
      goto LAB_CODE_00948a;
    }
    bVar4 = DAT_DATA_0e06 - DAT_DATA_0e05 >> 1;
  }
  else {
    if (bVar4 != 0x40) goto LAB_CODE_00948a;
    if (DAT_DATA_0e05 < 0xfe || DAT_DATA_0e06 < DAT_DATA_0e05 + 2) {
      DAT_DATA_0e07 = ((DAT_DATA_0e05 + DAT_DATA_0e04) - DAT_DATA_0e06) + 2;
      goto LAB_CODE_00948a;
    }
    bVar4 = DAT_DATA_0e06 - DAT_DATA_0e05;
  }
  DAT_DATA_01ea = -bVar4;
LAB_CODE_00948a:
  bVar4 = DAT_DATA_0e00 & 0x60;
  if (bVar4 == 0) {
    pbVar1[-3] = DAT_DATA_0e07;
    FUN_CODE_009a30(0);
  }
  else {
    puVar2 = pbVar1 + -2;
    pbVar1[-3] = DAT_DATA_0e04;
    FUN_CODE_009a30(bVar4);
    for (DAT_DATA_0e08 = DAT_DATA_0e04; DAT_DATA_0e08 < DAT_DATA_0e07;
        DAT_DATA_0e08 = DAT_DATA_0e08 + 1) {
      if ((DAT_DATA_0e00 & 0x80) == 0) {
        uVar5 = 0;
      }
      else {
        uVar5 = 0xff;
      }
      puVar3 = puVar2 + 1;
      *puVar2 = uVar5;
      FUN_CODE_00cefe();
      puVar2 = puVar3 + -1;
      *puVar3 = *puVar3;
    }
    DAT_DATA_0e07 = DAT_DATA_0e07 - DAT_DATA_0e04;
  }
  DAT_DATA_0e07 = DAT_DATA_01ea + DAT_DATA_0e06 + DAT_DATA_0e07;
  FUN_CODE_009972();
  return;
}


// ===== 0x00948a =====

/* WARNING: Restarted to delay deadcode elimination for space: DATA */

void FUN_CODE_0093ee(void)

{
  BADSPACEBASE *in_FSR1;
  byte *pbVar1;
  undefined1 *puVar2;
  undefined1 *puVar3;
  byte bVar4;
  undefined1 uVar5;
  
  FUN_CODE_009a5a();
  pbVar1 = (byte *)((short)in_FSR1 + 1);
  *(byte *)in_FSR1 = DAT_DATA_0e00 & 0xcf;
  FUN_CODE_0099a8();
  DAT_DATA_0e06 = FUN_CODE_00cc0c();
  *pbVar1 = *pbVar1;
  pbVar1[-1] = pbVar1[-1];
  pbVar1[-2] = pbVar1[-2];
  DAT_DATA_01ea = '\0';
  DAT_DATA_01eb = DAT_DATA_0e05;
  DAT_DATA_0e07 = DAT_DATA_0e04;
  bVar4 = DAT_DATA_0e00 & 0x60;
  if (bVar4 == 0) {
    bVar4 = DAT_DATA_0e00 & 6;
    if (bVar4 == 6) {
      DAT_DATA_0014 = 0x40;
      DAT_DATA_0e07 = 0x40 - (DAT_DATA_0e06 >> 1);
    }
    else if (bVar4 == 4) {
      DAT_DATA_0e07 = 0x82 - DAT_DATA_0e06;
    }
    else if (bVar4 == 2) {
      DAT_DATA_0e07 = 0;
    }
    goto LAB_CODE_00948a;
  }
  if (bVar4 == 0x60) {
    if (DAT_DATA_0e05 < 0xfe || DAT_DATA_0e06 < DAT_DATA_0e05 + 2) {
      DAT_DATA_0e07 = DAT_DATA_0e04 + (DAT_DATA_0e05 - DAT_DATA_0e06 >> 1);
      goto LAB_CODE_00948a;
    }
    bVar4 = DAT_DATA_0e06 - DAT_DATA_0e05 >> 1;
  }
  else {
    if (bVar4 != 0x40) goto LAB_CODE_00948a;
    if (DAT_DATA_0e05 < 0xfe || DAT_DATA_0e06 < DAT_DATA_0e05 + 2) {
      DAT_DATA_0e07 = ((DAT_DATA_0e05 + DAT_DATA_0e04) - DAT_DATA_0e06) + 2;
      goto LAB_CODE_00948a;
    }
    bVar4 = DAT_DATA_0e06 - DAT_DATA_0e05;
  }
  DAT_DATA_01ea = -bVar4;
LAB_CODE_00948a:
  bVar4 = DAT_DATA_0e00 & 0x60;
  if (bVar4 == 0) {
    pbVar1[-3] = DAT_DATA_0e07;
    FUN_CODE_009a30(0);
  }
  else {
    puVar2 = pbVar1 + -2;
    pbVar1[-3] = DAT_DATA_0e04;
    FUN_CODE_009a30(bVar4);
    for (DAT_DATA_0e08 = DAT_DATA_0e04; DAT_DATA_0e08 < DAT_DATA_0e07;
        DAT_DATA_0e08 = DAT_DATA_0e08 + 1) {
      if ((DAT_DATA_0e00 & 0x80) == 0) {
        uVar5 = 0;
      }
      else {
        uVar5 = 0xff;
      }
      puVar3 = puVar2 + 1;
      *puVar2 = uVar5;
      FUN_CODE_00cefe();
      puVar2 = puVar3 + -1;
      *puVar3 = *puVar3;
    }
    DAT_DATA_0e07 = DAT_DATA_0e07 - DAT_DATA_0e04;
  }
  DAT_DATA_0e07 = DAT_DATA_01ea + DAT_DATA_0e06 + DAT_DATA_0e07;
  FUN_CODE_009972();
  return;
}


// ===== 0x0094d8 =====

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


// ===== 0x009546 =====

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


// ===== 0x0095bc =====

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


// ===== 0x0095ce =====

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


// ===== 0x0095f2 =====

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


// ===== 0x009626 =====

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


// ===== 0x0096c0 =====

/* WARNING: Restarted to delay deadcode elimination for space: DATA */

void FUN_CODE_0096c0(void)

{
  BADSPACEBASE *in_FSR2;
  BADSPACEBASE *in_FSR1;
  undefined1 *puVar1;
  byte bVar2;
  byte bVar3;
  char cVar4;
  undefined1 uVar5;
  byte bVar6;
  BADSPACEBASE *in_FSR0;
  short in_PROD;
  byte *in_TBLPTR;
  bool bVar7;
  bool bVar8;
  
  FUN_CODE_009a5a();
  DAT_DATA_0e0c = 0x12;
  DAT_DATA_0e0d = 0xe;
  *(undefined1 *)in_FSR1 = 0xff;
  DAT_DATA_0e00 = *(byte *)((short)in_FSR2 + -3) & *(byte *)in_FSR1;
  DAT_DATA_0014 = *(byte *)((short)in_FSR2 + -1);
  DAT_DATA_0015 = 0;
  DAT_DATA_0e01 = DAT_DATA_0014;
  if ((DAT_DATA_0014 & 1) != 0) {
    FUN_CODE_009a80();
    *(undefined1 *)in_FSR0 = 9;
  }
  bVar3 = DAT_DATA_0e00 & 8;
  if ((bVar3 == 0) && (bVar3 = DAT_DATA_0e09 - 0x3c, bVar3 == 0)) {
    bVar8 = 0xfe < DAT_DATA_0e0a;
    DAT_DATA_0e0a = DAT_DATA_0e0a + 1;
    DAT_DATA_0e0b = DAT_DATA_0e0b + bVar8;
    bVar3 = DAT_DATA_0e02;
LAB_CODE_009714:
    DAT_DATA_0e02 = bVar3;
    FUN_CODE_009ab0();
    DAT_DATA_0e09 = *in_TBLPTR;
    if (DAT_DATA_0e09 != 0x3e) {
      bVar8 = 0xfe < DAT_DATA_0e0a;
      DAT_DATA_0e0a = DAT_DATA_0e0a + 1;
      DAT_DATA_0e0b = DAT_DATA_0e0b + bVar8;
      bVar3 = DAT_DATA_0e02;
      if (DAT_DATA_0e09 == 0x42) {
        DAT_DATA_0e00 = DAT_DATA_0e00 & 0xfe;
      }
      else if (DAT_DATA_0e09 == 0x62) {
        DAT_DATA_0e00 = DAT_DATA_0e00 | 1;
      }
      else if (DAT_DATA_0e09 == 0x49) {
        DAT_DATA_0e00 = DAT_DATA_0e00 & 0x7f;
      }
      else {
        if (DAT_DATA_0e09 != 0x69) {
          if (DAT_DATA_0e09 == 0x4e) {
            bVar2 = 0x9f;
          }
          else {
            if (DAT_DATA_0e09 == 0x43) {
              DAT_DATA_0e00 = DAT_DATA_0e00 & 0x9f | 0x60;
              goto LAB_CODE_009714;
            }
            if (DAT_DATA_0e09 == 0x52) {
              DAT_DATA_0e00 = DAT_DATA_0e00 & 0x9f | 0x40;
              goto LAB_CODE_009714;
            }
            if (DAT_DATA_0e09 == 0x4c) {
              DAT_DATA_0e00 = DAT_DATA_0e00 & 0x9f | 0x20;
              goto LAB_CODE_009714;
            }
            if (DAT_DATA_0e09 != 0x6e) {
              if (DAT_DATA_0e09 == 99) {
                DAT_DATA_0e00 = DAT_DATA_0e00 & 0xf9 | 6;
              }
              else if (DAT_DATA_0e09 == 0x72) {
                DAT_DATA_0e00 = DAT_DATA_0e00 & 0xf9 | 4;
              }
              else {
                bVar3 = DAT_DATA_0e09;
                if (DAT_DATA_0e09 == 0x6c) {
                  DAT_DATA_0e00 = DAT_DATA_0e00 & 0xf9 | 2;
                  bVar3 = DAT_DATA_0e02;
                }
              }
              goto LAB_CODE_009714;
            }
            bVar2 = 0xf9;
          }
          DAT_DATA_0e00 = DAT_DATA_0e00 & bVar2;
          goto LAB_CODE_009714;
        }
        DAT_DATA_0e00 = DAT_DATA_0e00 | 0x80;
      }
      goto LAB_CODE_009714;
    }
    bVar8 = 0xfe < DAT_DATA_0e0a;
    DAT_DATA_0e0a = DAT_DATA_0e0a + 1;
    bVar3 = 0;
    DAT_DATA_0e0b = DAT_DATA_0e0b + bVar8;
    DAT_DATA_0e09 = 0x3e;
  }
  cVar4 = FUN_CODE_009aba(bVar3);
  bVar8 = false;
  bVar3 = 5U - cVar4;
  if (5U - cVar4 == 0) {
    if ((DAT_DATA_0e00 & 0x60) == 0x40) {
      DAT_DATA_0e00 = DAT_DATA_0e00 & 0x9f | 0x20;
    }
    else if ((DAT_DATA_0e00 & 0x60) == 0x20) {
      DAT_DATA_0e00 = DAT_DATA_0e00 & 0x9f | 0x40;
    }
    if ((DAT_DATA_0e00 & 6) == 4) {
      DAT_DATA_0e00 = DAT_DATA_0e00 & 0xf9 | 2;
    }
    else {
      bVar3 = DAT_DATA_0e00 & 6 ^ 2;
      bVar8 = bVar3 == 0;
      if (!bVar8) goto LAB_CODE_0097f0;
      DAT_DATA_0e00 = DAT_DATA_0e00 & 0xf9 | 4;
    }
    bVar8 = DAT_DATA_0e00 == 0;
    bVar3 = DAT_DATA_0e00;
  }
LAB_CODE_0097f0:
  do {
    FUN_CODE_009a08(bVar3);
    if (bVar8) {
LAB_CODE_0098d6:
      FUN_CODE_0099b6();
      *(undefined1 *)in_FSR0 = 0;
      FUN_CODE_009972();
      return;
    }
    bVar2 = DAT_DATA_0e0a + 1;
    DAT_DATA_0e0b = DAT_DATA_0e0b + (0xfe < DAT_DATA_0e0a);
    if (DAT_DATA_0e09 != 1) {
      if (DAT_DATA_0e09 - 0x25 != 0) {
        if ((DAT_DATA_0e00 & 8) == 0) {
          bVar8 = false;
          bVar6 = DAT_DATA_0e09 - 0x3c;
          if (DAT_DATA_0e09 - 0x3c == 0) {
            DAT_DATA_0e0b = DAT_DATA_0e0b - ~(bVar2 != 0);
            goto LAB_CODE_0098d6;
          }
        }
        else {
          bVar8 = false;
          bVar6 = DAT_DATA_0e09 - 0x25;
        }
LAB_CODE_0098ce:
        DAT_DATA_0e0a = bVar2;
        bVar3 = FUN_CODE_009a80(bVar6);
        *(byte *)in_FSR0 = DAT_DATA_0e09;
        goto LAB_CODE_0097f0;
      }
      DAT_DATA_0e0a = bVar2;
      FUN_CODE_00997e(0);
      DAT_DATA_0e08 = 0;
      if ((0x2f < DAT_DATA_0e09) && (DAT_DATA_0e09 < 0x3a)) {
        if (DAT_DATA_0e09 == 0x30) {
          FUN_CODE_00997e(0);
          DAT_DATA_0e08 = 2;
        }
        else {
          DAT_DATA_0e08 = 1;
        }
        DAT_DATA_0e07 = 0;
        while ((0x2f < DAT_DATA_0e09 && (DAT_DATA_0e09 < 0x3a))) {
          DAT_DATA_0014 = DAT_DATA_0e09 - 0x30;
          in_PROD = (ushort)DAT_DATA_0e07 * 10;
          DAT_DATA_0e07 = DAT_DATA_0014 + (char)in_PROD;
          FUN_CODE_00997e();
        }
      }
      if (DAT_DATA_0e09 == 0x3c) {
        FUN_CODE_009a80();
        bVar3 = 0x3c;
      }
      else {
        if (DAT_DATA_0e09 == 99) {
          DAT_DATA_0e0e = DAT_DATA_0e0e + -1;
          FUN_CODE_009a4c();
          DAT_DATA_0e09 = *(byte *)in_FSR0;
          bVar8 = DAT_DATA_0e09 == 0;
          bVar3 = 0;
          bVar6 = DAT_DATA_0e09;
          bVar2 = DAT_DATA_0e0a;
          if (!bVar8) goto LAB_CODE_0098ce;
          goto LAB_CODE_0097f0;
        }
        if (DAT_DATA_0e09 == 0x73) {
          DAT_DATA_0e0e = DAT_DATA_0e0e + -2;
          bVar7 = DAT_DATA_0e0e == '\0';
          FUN_CODE_009a4c();
          DAT_DATA_0e10 = *(undefined1 *)in_FSR0;
          DAT_DATA_0e11 = *(undefined1 *)((short)in_FSR0 + 1);
          while( true ) {
            bVar3 = FUN_CODE_009a14();
            bVar8 = true;
            if (bVar7) break;
            FUN_CODE_009a8a();
          }
          goto LAB_CODE_0097f0;
        }
        if (DAT_DATA_0e09 != 0x25) {
          bVar8 = DAT_DATA_0e09 == 0x62;
          if (!bVar8) {
            bVar3 = DAT_DATA_0e09 ^ 100;
            bVar8 = bVar3 == 0;
            if (!bVar8) goto LAB_CODE_0097f0;
          }
          bVar3 = FUN_CODE_0095f2();
          goto LAB_CODE_0097f0;
        }
        FUN_CODE_009a80();
        bVar3 = 0x25;
      }
      bVar8 = true;
      *(byte *)in_FSR0 = bVar3;
      goto LAB_CODE_0097f0;
    }
    DAT_DATA_0e0a = bVar2;
    FUN_CODE_00997e(0);
    uVar5 = FUN_CODE_009aba();
    *(undefined1 *)in_FSR1 = uVar5;
    puVar1 = (undefined1 *)((short)in_FSR1 + 2);
    *(byte *)((short)in_FSR1 + 1) = DAT_DATA_0e09 - 1;
    FUN_CODE_0092ae();
    *puVar1 = *puVar1;
    in_FSR1 = (BADSPACEBASE *)(puVar1 + -2);
    cVar4 = puVar1[-1];
    puVar1[-1] = cVar4;
    DAT_DATA_0e10 = (undefined1)in_PROD;
    DAT_DATA_0e11 = (undefined1)((ushort)in_PROD >> 8);
    while( true ) {
      bVar3 = FUN_CODE_009a14();
      bVar8 = true;
      if (cVar4 == '\0') break;
      FUN_CODE_009a8a();
    }
  } while( true );
}


// ===== 0x009714 =====

/* WARNING: Restarted to delay deadcode elimination for space: DATA */

void FUN_CODE_0096c0(void)

{
  BADSPACEBASE *in_FSR2;
  BADSPACEBASE *in_FSR1;
  undefined1 *puVar1;
  byte bVar2;
  byte bVar3;
  char cVar4;
  undefined1 uVar5;
  byte bVar6;
  BADSPACEBASE *in_FSR0;
  short in_PROD;
  byte *in_TBLPTR;
  bool bVar7;
  bool bVar8;
  
  FUN_CODE_009a5a();
  DAT_DATA_0e0c = 0x12;
  DAT_DATA_0e0d = 0xe;
  *(undefined1 *)in_FSR1 = 0xff;
  DAT_DATA_0e00 = *(byte *)((short)in_FSR2 + -3) & *(byte *)in_FSR1;
  DAT_DATA_0014 = *(byte *)((short)in_FSR2 + -1);
  DAT_DATA_0015 = 0;
  DAT_DATA_0e01 = DAT_DATA_0014;
  if ((DAT_DATA_0014 & 1) != 0) {
    FUN_CODE_009a80();
    *(undefined1 *)in_FSR0 = 9;
  }
  bVar3 = DAT_DATA_0e00 & 8;
  if ((bVar3 == 0) && (bVar3 = DAT_DATA_0e09 - 0x3c, bVar3 == 0)) {
    bVar8 = 0xfe < DAT_DATA_0e0a;
    DAT_DATA_0e0a = DAT_DATA_0e0a + 1;
    DAT_DATA_0e0b = DAT_DATA_0e0b + bVar8;
    bVar3 = DAT_DATA_0e02;
LAB_CODE_009714:
    DAT_DATA_0e02 = bVar3;
    FUN_CODE_009ab0();
    DAT_DATA_0e09 = *in_TBLPTR;
    if (DAT_DATA_0e09 != 0x3e) {
      bVar8 = 0xfe < DAT_DATA_0e0a;
      DAT_DATA_0e0a = DAT_DATA_0e0a + 1;
      DAT_DATA_0e0b = DAT_DATA_0e0b + bVar8;
      bVar3 = DAT_DATA_0e02;
      if (DAT_DATA_0e09 == 0x42) {
        DAT_DATA_0e00 = DAT_DATA_0e00 & 0xfe;
      }
      else if (DAT_DATA_0e09 == 0x62) {
        DAT_DATA_0e00 = DAT_DATA_0e00 | 1;
      }
      else if (DAT_DATA_0e09 == 0x49) {
        DAT_DATA_0e00 = DAT_DATA_0e00 & 0x7f;
      }
      else {
        if (DAT_DATA_0e09 != 0x69) {
          if (DAT_DATA_0e09 == 0x4e) {
            bVar2 = 0x9f;
          }
          else {
            if (DAT_DATA_0e09 == 0x43) {
              DAT_DATA_0e00 = DAT_DATA_0e00 & 0x9f | 0x60;
              goto LAB_CODE_009714;
            }
            if (DAT_DATA_0e09 == 0x52) {
              DAT_DATA_0e00 = DAT_DATA_0e00 & 0x9f | 0x40;
              goto LAB_CODE_009714;
            }
            if (DAT_DATA_0e09 == 0x4c) {
              DAT_DATA_0e00 = DAT_DATA_0e00 & 0x9f | 0x20;
              goto LAB_CODE_009714;
            }
            if (DAT_DATA_0e09 != 0x6e) {
              if (DAT_DATA_0e09 == 99) {
                DAT_DATA_0e00 = DAT_DATA_0e00 & 0xf9 | 6;
              }
              else if (DAT_DATA_0e09 == 0x72) {
                DAT_DATA_0e00 = DAT_DATA_0e00 & 0xf9 | 4;
              }
              else {
                bVar3 = DAT_DATA_0e09;
                if (DAT_DATA_0e09 == 0x6c) {
                  DAT_DATA_0e00 = DAT_DATA_0e00 & 0xf9 | 2;
                  bVar3 = DAT_DATA_0e02;
                }
              }
              goto LAB_CODE_009714;
            }
            bVar2 = 0xf9;
          }
          DAT_DATA_0e00 = DAT_DATA_0e00 & bVar2;
          goto LAB_CODE_009714;
        }
        DAT_DATA_0e00 = DAT_DATA_0e00 | 0x80;
      }
      goto LAB_CODE_009714;
    }
    bVar8 = 0xfe < DAT_DATA_0e0a;
    DAT_DATA_0e0a = DAT_DATA_0e0a + 1;
    bVar3 = 0;
    DAT_DATA_0e0b = DAT_DATA_0e0b + bVar8;
    DAT_DATA_0e09 = 0x3e;
  }
  cVar4 = FUN_CODE_009aba(bVar3);
  bVar8 = false;
  bVar3 = 5U - cVar4;
  if (5U - cVar4 == 0) {
    if ((DAT_DATA_0e00 & 0x60) == 0x40) {
      DAT_DATA_0e00 = DAT_DATA_0e00 & 0x9f | 0x20;
    }
    else if ((DAT_DATA_0e00 & 0x60) == 0x20) {
      DAT_DATA_0e00 = DAT_DATA_0e00 & 0x9f | 0x40;
    }
    if ((DAT_DATA_0e00 & 6) == 4) {
      DAT_DATA_0e00 = DAT_DATA_0e00 & 0xf9 | 2;
    }
    else {
      bVar3 = DAT_DATA_0e00 & 6 ^ 2;
      bVar8 = bVar3 == 0;
      if (!bVar8) goto LAB_CODE_0097f0;
      DAT_DATA_0e00 = DAT_DATA_0e00 & 0xf9 | 4;
    }
    bVar8 = DAT_DATA_0e00 == 0;
    bVar3 = DAT_DATA_0e00;
  }
LAB_CODE_0097f0:
  do {
    FUN_CODE_009a08(bVar3);
    if (bVar8) {
LAB_CODE_0098d6:
      FUN_CODE_0099b6();
      *(undefined1 *)in_FSR0 = 0;
      FUN_CODE_009972();
      return;
    }
    bVar2 = DAT_DATA_0e0a + 1;
    DAT_DATA_0e0b = DAT_DATA_0e0b + (0xfe < DAT_DATA_0e0a);
    if (DAT_DATA_0e09 != 1) {
      if (DAT_DATA_0e09 - 0x25 != 0) {
        if ((DAT_DATA_0e00 & 8) == 0) {
          bVar8 = false;
          bVar6 = DAT_DATA_0e09 - 0x3c;
          if (DAT_DATA_0e09 - 0x3c == 0) {
            DAT_DATA_0e0b = DAT_DATA_0e0b - ~(bVar2 != 0);
            goto LAB_CODE_0098d6;
          }
        }
        else {
          bVar8 = false;
          bVar6 = DAT_DATA_0e09 - 0x25;
        }
LAB_CODE_0098ce:
        DAT_DATA_0e0a = bVar2;
        bVar3 = FUN_CODE_009a80(bVar6);
        *(byte *)in_FSR0 = DAT_DATA_0e09;
        goto LAB_CODE_0097f0;
      }
      DAT_DATA_0e0a = bVar2;
      FUN_CODE_00997e(0);
      DAT_DATA_0e08 = 0;
      if ((0x2f < DAT_DATA_0e09) && (DAT_DATA_0e09 < 0x3a)) {
        if (DAT_DATA_0e09 == 0x30) {
          FUN_CODE_00997e(0);
          DAT_DATA_0e08 = 2;
        }
        else {
          DAT_DATA_0e08 = 1;
        }
        DAT_DATA_0e07 = 0;
        while ((0x2f < DAT_DATA_0e09 && (DAT_DATA_0e09 < 0x3a))) {
          DAT_DATA_0014 = DAT_DATA_0e09 - 0x30;
          in_PROD = (ushort)DAT_DATA_0e07 * 10;
          DAT_DATA_0e07 = DAT_DATA_0014 + (char)in_PROD;
          FUN_CODE_00997e();
        }
      }
      if (DAT_DATA_0e09 == 0x3c) {
        FUN_CODE_009a80();
        bVar3 = 0x3c;
      }
      else {
        if (DAT_DATA_0e09 == 99) {
          DAT_DATA_0e0e = DAT_DATA_0e0e + -1;
          FUN_CODE_009a4c();
          DAT_DATA_0e09 = *(byte *)in_FSR0;
          bVar8 = DAT_DATA_0e09 == 0;
          bVar3 = 0;
          bVar6 = DAT_DATA_0e09;
          bVar2 = DAT_DATA_0e0a;
          if (!bVar8) goto LAB_CODE_0098ce;
          goto LAB_CODE_0097f0;
        }
        if (DAT_DATA_0e09 == 0x73) {
          DAT_DATA_0e0e = DAT_DATA_0e0e + -2;
          bVar7 = DAT_DATA_0e0e == '\0';
          FUN_CODE_009a4c();
          DAT_DATA_0e10 = *(undefined1 *)in_FSR0;
          DAT_DATA_0e11 = *(undefined1 *)((short)in_FSR0 + 1);
          while( true ) {
            bVar3 = FUN_CODE_009a14();
            bVar8 = true;
            if (bVar7) break;
            FUN_CODE_009a8a();
          }
          goto LAB_CODE_0097f0;
        }
        if (DAT_DATA_0e09 != 0x25) {
          bVar8 = DAT_DATA_0e09 == 0x62;
          if (!bVar8) {
            bVar3 = DAT_DATA_0e09 ^ 100;
            bVar8 = bVar3 == 0;
            if (!bVar8) goto LAB_CODE_0097f0;
          }
          bVar3 = FUN_CODE_0095f2();
          goto LAB_CODE_0097f0;
        }
        FUN_CODE_009a80();
        bVar3 = 0x25;
      }
      bVar8 = true;
      *(byte *)in_FSR0 = bVar3;
      goto LAB_CODE_0097f0;
    }
    DAT_DATA_0e0a = bVar2;
    FUN_CODE_00997e(0);
    uVar5 = FUN_CODE_009aba();
    *(undefined1 *)in_FSR1 = uVar5;
    puVar1 = (undefined1 *)((short)in_FSR1 + 2);
    *(byte *)((short)in_FSR1 + 1) = DAT_DATA_0e09 - 1;
    FUN_CODE_0092ae();
    *puVar1 = *puVar1;
    in_FSR1 = (BADSPACEBASE *)(puVar1 + -2);
    cVar4 = puVar1[-1];
    puVar1[-1] = cVar4;
    DAT_DATA_0e10 = (undefined1)in_PROD;
    DAT_DATA_0e11 = (undefined1)((ushort)in_PROD >> 8);
    while( true ) {
      bVar3 = FUN_CODE_009a14();
      bVar8 = true;
      if (cVar4 == '\0') break;
      FUN_CODE_009a8a();
    }
  } while( true );
}


// ===== 0x0097f0 =====

/* WARNING: Restarted to delay deadcode elimination for space: DATA */

void FUN_CODE_0096c0(void)

{
  BADSPACEBASE *in_FSR2;
  BADSPACEBASE *in_FSR1;
  undefined1 *puVar1;
  byte bVar2;
  byte bVar3;
  char cVar4;
  undefined1 uVar5;
  byte bVar6;
  BADSPACEBASE *in_FSR0;
  short in_PROD;
  byte *in_TBLPTR;
  bool bVar7;
  bool bVar8;
  
  FUN_CODE_009a5a();
  DAT_DATA_0e0c = 0x12;
  DAT_DATA_0e0d = 0xe;
  *(undefined1 *)in_FSR1 = 0xff;
  DAT_DATA_0e00 = *(byte *)((short)in_FSR2 + -3) & *(byte *)in_FSR1;
  DAT_DATA_0014 = *(byte *)((short)in_FSR2 + -1);
  DAT_DATA_0015 = 0;
  DAT_DATA_0e01 = DAT_DATA_0014;
  if ((DAT_DATA_0014 & 1) != 0) {
    FUN_CODE_009a80();
    *(undefined1 *)in_FSR0 = 9;
  }
  bVar3 = DAT_DATA_0e00 & 8;
  if ((bVar3 == 0) && (bVar3 = DAT_DATA_0e09 - 0x3c, bVar3 == 0)) {
    bVar8 = 0xfe < DAT_DATA_0e0a;
    DAT_DATA_0e0a = DAT_DATA_0e0a + 1;
    DAT_DATA_0e0b = DAT_DATA_0e0b + bVar8;
    bVar3 = DAT_DATA_0e02;
LAB_CODE_009714:
    DAT_DATA_0e02 = bVar3;
    FUN_CODE_009ab0();
    DAT_DATA_0e09 = *in_TBLPTR;
    if (DAT_DATA_0e09 != 0x3e) {
      bVar8 = 0xfe < DAT_DATA_0e0a;
      DAT_DATA_0e0a = DAT_DATA_0e0a + 1;
      DAT_DATA_0e0b = DAT_DATA_0e0b + bVar8;
      bVar3 = DAT_DATA_0e02;
      if (DAT_DATA_0e09 == 0x42) {
        DAT_DATA_0e00 = DAT_DATA_0e00 & 0xfe;
      }
      else if (DAT_DATA_0e09 == 0x62) {
        DAT_DATA_0e00 = DAT_DATA_0e00 | 1;
      }
      else if (DAT_DATA_0e09 == 0x49) {
        DAT_DATA_0e00 = DAT_DATA_0e00 & 0x7f;
      }
      else {
        if (DAT_DATA_0e09 != 0x69) {
          if (DAT_DATA_0e09 == 0x4e) {
            bVar2 = 0x9f;
          }
          else {
            if (DAT_DATA_0e09 == 0x43) {
              DAT_DATA_0e00 = DAT_DATA_0e00 & 0x9f | 0x60;
              goto LAB_CODE_009714;
            }
            if (DAT_DATA_0e09 == 0x52) {
              DAT_DATA_0e00 = DAT_DATA_0e00 & 0x9f | 0x40;
              goto LAB_CODE_009714;
            }
            if (DAT_DATA_0e09 == 0x4c) {
              DAT_DATA_0e00 = DAT_DATA_0e00 & 0x9f | 0x20;
              goto LAB_CODE_009714;
            }
            if (DAT_DATA_0e09 != 0x6e) {
              if (DAT_DATA_0e09 == 99) {
                DAT_DATA_0e00 = DAT_DATA_0e00 & 0xf9 | 6;
              }
              else if (DAT_DATA_0e09 == 0x72) {
                DAT_DATA_0e00 = DAT_DATA_0e00 & 0xf9 | 4;
              }
              else {
                bVar3 = DAT_DATA_0e09;
                if (DAT_DATA_0e09 == 0x6c) {
                  DAT_DATA_0e00 = DAT_DATA_0e00 & 0xf9 | 2;
                  bVar3 = DAT_DATA_0e02;
                }
              }
              goto LAB_CODE_009714;
            }
            bVar2 = 0xf9;
          }
          DAT_DATA_0e00 = DAT_DATA_0e00 & bVar2;
          goto LAB_CODE_009714;
        }
        DAT_DATA_0e00 = DAT_DATA_0e00 | 0x80;
      }
      goto LAB_CODE_009714;
    }
    bVar8 = 0xfe < DAT_DATA_0e0a;
    DAT_DATA_0e0a = DAT_DATA_0e0a + 1;
    bVar3 = 0;
    DAT_DATA_0e0b = DAT_DATA_0e0b + bVar8;
    DAT_DATA_0e09 = 0x3e;
  }
  cVar4 = FUN_CODE_009aba(bVar3);
  bVar8 = false;
  bVar3 = 5U - cVar4;
  if (5U - cVar4 == 0) {
    if ((DAT_DATA_0e00 & 0x60) == 0x40) {
      DAT_DATA_0e00 = DAT_DATA_0e00 & 0x9f | 0x20;
    }
    else if ((DAT_DATA_0e00 & 0x60) == 0x20) {
      DAT_DATA_0e00 = DAT_DATA_0e00 & 0x9f | 0x40;
    }
    if ((DAT_DATA_0e00 & 6) == 4) {
      DAT_DATA_0e00 = DAT_DATA_0e00 & 0xf9 | 2;
    }
    else {
      bVar3 = DAT_DATA_0e00 & 6 ^ 2;
      bVar8 = bVar3 == 0;
      if (!bVar8) goto LAB_CODE_0097f0;
      DAT_DATA_0e00 = DAT_DATA_0e00 & 0xf9 | 4;
    }
    bVar8 = DAT_DATA_0e00 == 0;
    bVar3 = DAT_DATA_0e00;
  }
LAB_CODE_0097f0:
  do {
    FUN_CODE_009a08(bVar3);
    if (bVar8) {
LAB_CODE_0098d6:
      FUN_CODE_0099b6();
      *(undefined1 *)in_FSR0 = 0;
      FUN_CODE_009972();
      return;
    }
    bVar2 = DAT_DATA_0e0a + 1;
    DAT_DATA_0e0b = DAT_DATA_0e0b + (0xfe < DAT_DATA_0e0a);
    if (DAT_DATA_0e09 != 1) {
      if (DAT_DATA_0e09 - 0x25 != 0) {
        if ((DAT_DATA_0e00 & 8) == 0) {
          bVar8 = false;
          bVar6 = DAT_DATA_0e09 - 0x3c;
          if (DAT_DATA_0e09 - 0x3c == 0) {
            DAT_DATA_0e0b = DAT_DATA_0e0b - ~(bVar2 != 0);
            goto LAB_CODE_0098d6;
          }
        }
        else {
          bVar8 = false;
          bVar6 = DAT_DATA_0e09 - 0x25;
        }
LAB_CODE_0098ce:
        DAT_DATA_0e0a = bVar2;
        bVar3 = FUN_CODE_009a80(bVar6);
        *(byte *)in_FSR0 = DAT_DATA_0e09;
        goto LAB_CODE_0097f0;
      }
      DAT_DATA_0e0a = bVar2;
      FUN_CODE_00997e(0);
      DAT_DATA_0e08 = 0;
      if ((0x2f < DAT_DATA_0e09) && (DAT_DATA_0e09 < 0x3a)) {
        if (DAT_DATA_0e09 == 0x30) {
          FUN_CODE_00997e(0);
          DAT_DATA_0e08 = 2;
        }
        else {
          DAT_DATA_0e08 = 1;
        }
        DAT_DATA_0e07 = 0;
        while ((0x2f < DAT_DATA_0e09 && (DAT_DATA_0e09 < 0x3a))) {
          DAT_DATA_0014 = DAT_DATA_0e09 - 0x30;
          in_PROD = (ushort)DAT_DATA_0e07 * 10;
          DAT_DATA_0e07 = DAT_DATA_0014 + (char)in_PROD;
          FUN_CODE_00997e();
        }
      }
      if (DAT_DATA_0e09 == 0x3c) {
        FUN_CODE_009a80();
        bVar3 = 0x3c;
      }
      else {
        if (DAT_DATA_0e09 == 99) {
          DAT_DATA_0e0e = DAT_DATA_0e0e + -1;
          FUN_CODE_009a4c();
          DAT_DATA_0e09 = *(byte *)in_FSR0;
          bVar8 = DAT_DATA_0e09 == 0;
          bVar3 = 0;
          bVar6 = DAT_DATA_0e09;
          bVar2 = DAT_DATA_0e0a;
          if (!bVar8) goto LAB_CODE_0098ce;
          goto LAB_CODE_0097f0;
        }
        if (DAT_DATA_0e09 == 0x73) {
          DAT_DATA_0e0e = DAT_DATA_0e0e + -2;
          bVar7 = DAT_DATA_0e0e == '\0';
          FUN_CODE_009a4c();
          DAT_DATA_0e10 = *(undefined1 *)in_FSR0;
          DAT_DATA_0e11 = *(undefined1 *)((short)in_FSR0 + 1);
          while( true ) {
            bVar3 = FUN_CODE_009a14();
            bVar8 = true;
            if (bVar7) break;
            FUN_CODE_009a8a();
          }
          goto LAB_CODE_0097f0;
        }
        if (DAT_DATA_0e09 != 0x25) {
          bVar8 = DAT_DATA_0e09 == 0x62;
          if (!bVar8) {
            bVar3 = DAT_DATA_0e09 ^ 100;
            bVar8 = bVar3 == 0;
            if (!bVar8) goto LAB_CODE_0097f0;
          }
          bVar3 = FUN_CODE_0095f2();
          goto LAB_CODE_0097f0;
        }
        FUN_CODE_009a80();
        bVar3 = 0x25;
      }
      bVar8 = true;
      *(byte *)in_FSR0 = bVar3;
      goto LAB_CODE_0097f0;
    }
    DAT_DATA_0e0a = bVar2;
    FUN_CODE_00997e(0);
    uVar5 = FUN_CODE_009aba();
    *(undefined1 *)in_FSR1 = uVar5;
    puVar1 = (undefined1 *)((short)in_FSR1 + 2);
    *(byte *)((short)in_FSR1 + 1) = DAT_DATA_0e09 - 1;
    FUN_CODE_0092ae();
    *puVar1 = *puVar1;
    in_FSR1 = (BADSPACEBASE *)(puVar1 + -2);
    cVar4 = puVar1[-1];
    puVar1[-1] = cVar4;
    DAT_DATA_0e10 = (undefined1)in_PROD;
    DAT_DATA_0e11 = (undefined1)((ushort)in_PROD >> 8);
    while( true ) {
      bVar3 = FUN_CODE_009a14();
      bVar8 = true;
      if (cVar4 == '\0') break;
      FUN_CODE_009a8a();
    }
  } while( true );
}


// ===== 0x0098ce =====

/* WARNING: Restarted to delay deadcode elimination for space: DATA */

void FUN_CODE_0096c0(void)

{
  BADSPACEBASE *in_FSR2;
  BADSPACEBASE *in_FSR1;
  undefined1 *puVar1;
  byte bVar2;
  byte bVar3;
  char cVar4;
  undefined1 uVar5;
  byte bVar6;
  BADSPACEBASE *in_FSR0;
  short in_PROD;
  byte *in_TBLPTR;
  bool bVar7;
  bool bVar8;
  
  FUN_CODE_009a5a();
  DAT_DATA_0e0c = 0x12;
  DAT_DATA_0e0d = 0xe;
  *(undefined1 *)in_FSR1 = 0xff;
  DAT_DATA_0e00 = *(byte *)((short)in_FSR2 + -3) & *(byte *)in_FSR1;
  DAT_DATA_0014 = *(byte *)((short)in_FSR2 + -1);
  DAT_DATA_0015 = 0;
  DAT_DATA_0e01 = DAT_DATA_0014;
  if ((DAT_DATA_0014 & 1) != 0) {
    FUN_CODE_009a80();
    *(undefined1 *)in_FSR0 = 9;
  }
  bVar3 = DAT_DATA_0e00 & 8;
  if ((bVar3 == 0) && (bVar3 = DAT_DATA_0e09 - 0x3c, bVar3 == 0)) {
    bVar8 = 0xfe < DAT_DATA_0e0a;
    DAT_DATA_0e0a = DAT_DATA_0e0a + 1;
    DAT_DATA_0e0b = DAT_DATA_0e0b + bVar8;
    bVar3 = DAT_DATA_0e02;
LAB_CODE_009714:
    DAT_DATA_0e02 = bVar3;
    FUN_CODE_009ab0();
    DAT_DATA_0e09 = *in_TBLPTR;
    if (DAT_DATA_0e09 != 0x3e) {
      bVar8 = 0xfe < DAT_DATA_0e0a;
      DAT_DATA_0e0a = DAT_DATA_0e0a + 1;
      DAT_DATA_0e0b = DAT_DATA_0e0b + bVar8;
      bVar3 = DAT_DATA_0e02;
      if (DAT_DATA_0e09 == 0x42) {
        DAT_DATA_0e00 = DAT_DATA_0e00 & 0xfe;
      }
      else if (DAT_DATA_0e09 == 0x62) {
        DAT_DATA_0e00 = DAT_DATA_0e00 | 1;
      }
      else if (DAT_DATA_0e09 == 0x49) {
        DAT_DATA_0e00 = DAT_DATA_0e00 & 0x7f;
      }
      else {
        if (DAT_DATA_0e09 != 0x69) {
          if (DAT_DATA_0e09 == 0x4e) {
            bVar2 = 0x9f;
          }
          else {
            if (DAT_DATA_0e09 == 0x43) {
              DAT_DATA_0e00 = DAT_DATA_0e00 & 0x9f | 0x60;
              goto LAB_CODE_009714;
            }
            if (DAT_DATA_0e09 == 0x52) {
              DAT_DATA_0e00 = DAT_DATA_0e00 & 0x9f | 0x40;
              goto LAB_CODE_009714;
            }
            if (DAT_DATA_0e09 == 0x4c) {
              DAT_DATA_0e00 = DAT_DATA_0e00 & 0x9f | 0x20;
              goto LAB_CODE_009714;
            }
            if (DAT_DATA_0e09 != 0x6e) {
              if (DAT_DATA_0e09 == 99) {
                DAT_DATA_0e00 = DAT_DATA_0e00 & 0xf9 | 6;
              }
              else if (DAT_DATA_0e09 == 0x72) {
                DAT_DATA_0e00 = DAT_DATA_0e00 & 0xf9 | 4;
              }
              else {
                bVar3 = DAT_DATA_0e09;
                if (DAT_DATA_0e09 == 0x6c) {
                  DAT_DATA_0e00 = DAT_DATA_0e00 & 0xf9 | 2;
                  bVar3 = DAT_DATA_0e02;
                }
              }
              goto LAB_CODE_009714;
            }
            bVar2 = 0xf9;
          }
          DAT_DATA_0e00 = DAT_DATA_0e00 & bVar2;
          goto LAB_CODE_009714;
        }
        DAT_DATA_0e00 = DAT_DATA_0e00 | 0x80;
      }
      goto LAB_CODE_009714;
    }
    bVar8 = 0xfe < DAT_DATA_0e0a;
    DAT_DATA_0e0a = DAT_DATA_0e0a + 1;
    bVar3 = 0;
    DAT_DATA_0e0b = DAT_DATA_0e0b + bVar8;
    DAT_DATA_0e09 = 0x3e;
  }
  cVar4 = FUN_CODE_009aba(bVar3);
  bVar8 = false;
  bVar3 = 5U - cVar4;
  if (5U - cVar4 == 0) {
    if ((DAT_DATA_0e00 & 0x60) == 0x40) {
      DAT_DATA_0e00 = DAT_DATA_0e00 & 0x9f | 0x20;
    }
    else if ((DAT_DATA_0e00 & 0x60) == 0x20) {
      DAT_DATA_0e00 = DAT_DATA_0e00 & 0x9f | 0x40;
    }
    if ((DAT_DATA_0e00 & 6) == 4) {
      DAT_DATA_0e00 = DAT_DATA_0e00 & 0xf9 | 2;
    }
    else {
      bVar3 = DAT_DATA_0e00 & 6 ^ 2;
      bVar8 = bVar3 == 0;
      if (!bVar8) goto LAB_CODE_0097f0;
      DAT_DATA_0e00 = DAT_DATA_0e00 & 0xf9 | 4;
    }
    bVar8 = DAT_DATA_0e00 == 0;
    bVar3 = DAT_DATA_0e00;
  }
LAB_CODE_0097f0:
  do {
    FUN_CODE_009a08(bVar3);
    if (bVar8) {
LAB_CODE_0098d6:
      FUN_CODE_0099b6();
      *(undefined1 *)in_FSR0 = 0;
      FUN_CODE_009972();
      return;
    }
    bVar2 = DAT_DATA_0e0a + 1;
    DAT_DATA_0e0b = DAT_DATA_0e0b + (0xfe < DAT_DATA_0e0a);
    if (DAT_DATA_0e09 != 1) {
      if (DAT_DATA_0e09 - 0x25 != 0) {
        if ((DAT_DATA_0e00 & 8) == 0) {
          bVar8 = false;
          bVar6 = DAT_DATA_0e09 - 0x3c;
          if (DAT_DATA_0e09 - 0x3c == 0) {
            DAT_DATA_0e0b = DAT_DATA_0e0b - ~(bVar2 != 0);
            goto LAB_CODE_0098d6;
          }
        }
        else {
          bVar8 = false;
          bVar6 = DAT_DATA_0e09 - 0x25;
        }
LAB_CODE_0098ce:
        DAT_DATA_0e0a = bVar2;
        bVar3 = FUN_CODE_009a80(bVar6);
        *(byte *)in_FSR0 = DAT_DATA_0e09;
        goto LAB_CODE_0097f0;
      }
      DAT_DATA_0e0a = bVar2;
      FUN_CODE_00997e(0);
      DAT_DATA_0e08 = 0;
      if ((0x2f < DAT_DATA_0e09) && (DAT_DATA_0e09 < 0x3a)) {
        if (DAT_DATA_0e09 == 0x30) {
          FUN_CODE_00997e(0);
          DAT_DATA_0e08 = 2;
        }
        else {
          DAT_DATA_0e08 = 1;
        }
        DAT_DATA_0e07 = 0;
        while ((0x2f < DAT_DATA_0e09 && (DAT_DATA_0e09 < 0x3a))) {
          DAT_DATA_0014 = DAT_DATA_0e09 - 0x30;
          in_PROD = (ushort)DAT_DATA_0e07 * 10;
          DAT_DATA_0e07 = DAT_DATA_0014 + (char)in_PROD;
          FUN_CODE_00997e();
        }
      }
      if (DAT_DATA_0e09 == 0x3c) {
        FUN_CODE_009a80();
        bVar3 = 0x3c;
      }
      else {
        if (DAT_DATA_0e09 == 99) {
          DAT_DATA_0e0e = DAT_DATA_0e0e + -1;
          FUN_CODE_009a4c();
          DAT_DATA_0e09 = *(byte *)in_FSR0;
          bVar8 = DAT_DATA_0e09 == 0;
          bVar3 = 0;
          bVar6 = DAT_DATA_0e09;
          bVar2 = DAT_DATA_0e0a;
          if (!bVar8) goto LAB_CODE_0098ce;
          goto LAB_CODE_0097f0;
        }
        if (DAT_DATA_0e09 == 0x73) {
          DAT_DATA_0e0e = DAT_DATA_0e0e + -2;
          bVar7 = DAT_DATA_0e0e == '\0';
          FUN_CODE_009a4c();
          DAT_DATA_0e10 = *(undefined1 *)in_FSR0;
          DAT_DATA_0e11 = *(undefined1 *)((short)in_FSR0 + 1);
          while( true ) {
            bVar3 = FUN_CODE_009a14();
            bVar8 = true;
            if (bVar7) break;
            FUN_CODE_009a8a();
          }
          goto LAB_CODE_0097f0;
        }
        if (DAT_DATA_0e09 != 0x25) {
          bVar8 = DAT_DATA_0e09 == 0x62;
          if (!bVar8) {
            bVar3 = DAT_DATA_0e09 ^ 100;
            bVar8 = bVar3 == 0;
            if (!bVar8) goto LAB_CODE_0097f0;
          }
          bVar3 = FUN_CODE_0095f2();
          goto LAB_CODE_0097f0;
        }
        FUN_CODE_009a80();
        bVar3 = 0x25;
      }
      bVar8 = true;
      *(byte *)in_FSR0 = bVar3;
      goto LAB_CODE_0097f0;
    }
    DAT_DATA_0e0a = bVar2;
    FUN_CODE_00997e(0);
    uVar5 = FUN_CODE_009aba();
    *(undefined1 *)in_FSR1 = uVar5;
    puVar1 = (undefined1 *)((short)in_FSR1 + 2);
    *(byte *)((short)in_FSR1 + 1) = DAT_DATA_0e09 - 1;
    FUN_CODE_0092ae();
    *puVar1 = *puVar1;
    in_FSR1 = (BADSPACEBASE *)(puVar1 + -2);
    cVar4 = puVar1[-1];
    puVar1[-1] = cVar4;
    DAT_DATA_0e10 = (undefined1)in_PROD;
    DAT_DATA_0e11 = (undefined1)((ushort)in_PROD >> 8);
    while( true ) {
      bVar3 = FUN_CODE_009a14();
      bVar8 = true;
      if (cVar4 == '\0') break;
      FUN_CODE_009a8a();
    }
  } while( true );
}


// ===== 0x0098d6 =====

/* WARNING: Restarted to delay deadcode elimination for space: DATA */

void FUN_CODE_0096c0(void)

{
  BADSPACEBASE *in_FSR2;
  BADSPACEBASE *in_FSR1;
  undefined1 *puVar1;
  byte bVar2;
  byte bVar3;
  char cVar4;
  undefined1 uVar5;
  byte bVar6;
  BADSPACEBASE *in_FSR0;
  short in_PROD;
  byte *in_TBLPTR;
  bool bVar7;
  bool bVar8;
  
  FUN_CODE_009a5a();
  DAT_DATA_0e0c = 0x12;
  DAT_DATA_0e0d = 0xe;
  *(undefined1 *)in_FSR1 = 0xff;
  DAT_DATA_0e00 = *(byte *)((short)in_FSR2 + -3) & *(byte *)in_FSR1;
  DAT_DATA_0014 = *(byte *)((short)in_FSR2 + -1);
  DAT_DATA_0015 = 0;
  DAT_DATA_0e01 = DAT_DATA_0014;
  if ((DAT_DATA_0014 & 1) != 0) {
    FUN_CODE_009a80();
    *(undefined1 *)in_FSR0 = 9;
  }
  bVar3 = DAT_DATA_0e00 & 8;
  if ((bVar3 == 0) && (bVar3 = DAT_DATA_0e09 - 0x3c, bVar3 == 0)) {
    bVar8 = 0xfe < DAT_DATA_0e0a;
    DAT_DATA_0e0a = DAT_DATA_0e0a + 1;
    DAT_DATA_0e0b = DAT_DATA_0e0b + bVar8;
    bVar3 = DAT_DATA_0e02;
LAB_CODE_009714:
    DAT_DATA_0e02 = bVar3;
    FUN_CODE_009ab0();
    DAT_DATA_0e09 = *in_TBLPTR;
    if (DAT_DATA_0e09 != 0x3e) {
      bVar8 = 0xfe < DAT_DATA_0e0a;
      DAT_DATA_0e0a = DAT_DATA_0e0a + 1;
      DAT_DATA_0e0b = DAT_DATA_0e0b + bVar8;
      bVar3 = DAT_DATA_0e02;
      if (DAT_DATA_0e09 == 0x42) {
        DAT_DATA_0e00 = DAT_DATA_0e00 & 0xfe;
      }
      else if (DAT_DATA_0e09 == 0x62) {
        DAT_DATA_0e00 = DAT_DATA_0e00 | 1;
      }
      else if (DAT_DATA_0e09 == 0x49) {
        DAT_DATA_0e00 = DAT_DATA_0e00 & 0x7f;
      }
      else {
        if (DAT_DATA_0e09 != 0x69) {
          if (DAT_DATA_0e09 == 0x4e) {
            bVar2 = 0x9f;
          }
          else {
            if (DAT_DATA_0e09 == 0x43) {
              DAT_DATA_0e00 = DAT_DATA_0e00 & 0x9f | 0x60;
              goto LAB_CODE_009714;
            }
            if (DAT_DATA_0e09 == 0x52) {
              DAT_DATA_0e00 = DAT_DATA_0e00 & 0x9f | 0x40;
              goto LAB_CODE_009714;
            }
            if (DAT_DATA_0e09 == 0x4c) {
              DAT_DATA_0e00 = DAT_DATA_0e00 & 0x9f | 0x20;
              goto LAB_CODE_009714;
            }
            if (DAT_DATA_0e09 != 0x6e) {
              if (DAT_DATA_0e09 == 99) {
                DAT_DATA_0e00 = DAT_DATA_0e00 & 0xf9 | 6;
              }
              else if (DAT_DATA_0e09 == 0x72) {
                DAT_DATA_0e00 = DAT_DATA_0e00 & 0xf9 | 4;
              }
              else {
                bVar3 = DAT_DATA_0e09;
                if (DAT_DATA_0e09 == 0x6c) {
                  DAT_DATA_0e00 = DAT_DATA_0e00 & 0xf9 | 2;
                  bVar3 = DAT_DATA_0e02;
                }
              }
              goto LAB_CODE_009714;
            }
            bVar2 = 0xf9;
          }
          DAT_DATA_0e00 = DAT_DATA_0e00 & bVar2;
          goto LAB_CODE_009714;
        }
        DAT_DATA_0e00 = DAT_DATA_0e00 | 0x80;
      }
      goto LAB_CODE_009714;
    }
    bVar8 = 0xfe < DAT_DATA_0e0a;
    DAT_DATA_0e0a = DAT_DATA_0e0a + 1;
    bVar3 = 0;
    DAT_DATA_0e0b = DAT_DATA_0e0b + bVar8;
    DAT_DATA_0e09 = 0x3e;
  }
  cVar4 = FUN_CODE_009aba(bVar3);
  bVar8 = false;
  bVar3 = 5U - cVar4;
  if (5U - cVar4 == 0) {
    if ((DAT_DATA_0e00 & 0x60) == 0x40) {
      DAT_DATA_0e00 = DAT_DATA_0e00 & 0x9f | 0x20;
    }
    else if ((DAT_DATA_0e00 & 0x60) == 0x20) {
      DAT_DATA_0e00 = DAT_DATA_0e00 & 0x9f | 0x40;
    }
    if ((DAT_DATA_0e00 & 6) == 4) {
      DAT_DATA_0e00 = DAT_DATA_0e00 & 0xf9 | 2;
    }
    else {
      bVar3 = DAT_DATA_0e00 & 6 ^ 2;
      bVar8 = bVar3 == 0;
      if (!bVar8) goto LAB_CODE_0097f0;
      DAT_DATA_0e00 = DAT_DATA_0e00 & 0xf9 | 4;
    }
    bVar8 = DAT_DATA_0e00 == 0;
    bVar3 = DAT_DATA_0e00;
  }
LAB_CODE_0097f0:
  do {
    FUN_CODE_009a08(bVar3);
    if (bVar8) {
LAB_CODE_0098d6:
      FUN_CODE_0099b6();
      *(undefined1 *)in_FSR0 = 0;
      FUN_CODE_009972();
      return;
    }
    bVar2 = DAT_DATA_0e0a + 1;
    DAT_DATA_0e0b = DAT_DATA_0e0b + (0xfe < DAT_DATA_0e0a);
    if (DAT_DATA_0e09 != 1) {
      if (DAT_DATA_0e09 - 0x25 != 0) {
        if ((DAT_DATA_0e00 & 8) == 0) {
          bVar8 = false;
          bVar6 = DAT_DATA_0e09 - 0x3c;
          if (DAT_DATA_0e09 - 0x3c == 0) {
            DAT_DATA_0e0b = DAT_DATA_0e0b - ~(bVar2 != 0);
            goto LAB_CODE_0098d6;
          }
        }
        else {
          bVar8 = false;
          bVar6 = DAT_DATA_0e09 - 0x25;
        }
LAB_CODE_0098ce:
        DAT_DATA_0e0a = bVar2;
        bVar3 = FUN_CODE_009a80(bVar6);
        *(byte *)in_FSR0 = DAT_DATA_0e09;
        goto LAB_CODE_0097f0;
      }
      DAT_DATA_0e0a = bVar2;
      FUN_CODE_00997e(0);
      DAT_DATA_0e08 = 0;
      if ((0x2f < DAT_DATA_0e09) && (DAT_DATA_0e09 < 0x3a)) {
        if (DAT_DATA_0e09 == 0x30) {
          FUN_CODE_00997e(0);
          DAT_DATA_0e08 = 2;
        }
        else {
          DAT_DATA_0e08 = 1;
        }
        DAT_DATA_0e07 = 0;
        while ((0x2f < DAT_DATA_0e09 && (DAT_DATA_0e09 < 0x3a))) {
          DAT_DATA_0014 = DAT_DATA_0e09 - 0x30;
          in_PROD = (ushort)DAT_DATA_0e07 * 10;
          DAT_DATA_0e07 = DAT_DATA_0014 + (char)in_PROD;
          FUN_CODE_00997e();
        }
      }
      if (DAT_DATA_0e09 == 0x3c) {
        FUN_CODE_009a80();
        bVar3 = 0x3c;
      }
      else {
        if (DAT_DATA_0e09 == 99) {
          DAT_DATA_0e0e = DAT_DATA_0e0e + -1;
          FUN_CODE_009a4c();
          DAT_DATA_0e09 = *(byte *)in_FSR0;
          bVar8 = DAT_DATA_0e09 == 0;
          bVar3 = 0;
          bVar6 = DAT_DATA_0e09;
          bVar2 = DAT_DATA_0e0a;
          if (!bVar8) goto LAB_CODE_0098ce;
          goto LAB_CODE_0097f0;
        }
        if (DAT_DATA_0e09 == 0x73) {
          DAT_DATA_0e0e = DAT_DATA_0e0e + -2;
          bVar7 = DAT_DATA_0e0e == '\0';
          FUN_CODE_009a4c();
          DAT_DATA_0e10 = *(undefined1 *)in_FSR0;
          DAT_DATA_0e11 = *(undefined1 *)((short)in_FSR0 + 1);
          while( true ) {
            bVar3 = FUN_CODE_009a14();
            bVar8 = true;
            if (bVar7) break;
            FUN_CODE_009a8a();
          }
          goto LAB_CODE_0097f0;
        }
        if (DAT_DATA_0e09 != 0x25) {
          bVar8 = DAT_DATA_0e09 == 0x62;
          if (!bVar8) {
            bVar3 = DAT_DATA_0e09 ^ 100;
            bVar8 = bVar3 == 0;
            if (!bVar8) goto LAB_CODE_0097f0;
          }
          bVar3 = FUN_CODE_0095f2();
          goto LAB_CODE_0097f0;
        }
        FUN_CODE_009a80();
        bVar3 = 0x25;
      }
      bVar8 = true;
      *(byte *)in_FSR0 = bVar3;
      goto LAB_CODE_0097f0;
    }
    DAT_DATA_0e0a = bVar2;
    FUN_CODE_00997e(0);
    uVar5 = FUN_CODE_009aba();
    *(undefined1 *)in_FSR1 = uVar5;
    puVar1 = (undefined1 *)((short)in_FSR1 + 2);
    *(byte *)((short)in_FSR1 + 1) = DAT_DATA_0e09 - 1;
    FUN_CODE_0092ae();
    *puVar1 = *puVar1;
    in_FSR1 = (BADSPACEBASE *)(puVar1 + -2);
    cVar4 = puVar1[-1];
    puVar1[-1] = cVar4;
    DAT_DATA_0e10 = (undefined1)in_PROD;
    DAT_DATA_0e11 = (undefined1)((ushort)in_PROD >> 8);
    while( true ) {
      bVar3 = FUN_CODE_009a14();
      bVar8 = true;
      if (cVar4 == '\0') break;
      FUN_CODE_009a8a();
    }
  } while( true );
}


// ===== 0x0098dc =====

void FUN_CODE_0098dc(void)

{
  char cVar1;
  BADSPACEBASE *in_FSR1;
  undefined1 *puVar2;
  undefined1 *puVar3;
  undefined1 uVar4;
  byte unaff_Z;
  
  uVar4 = FUN_CODE_009a5a();
  puVar3 = (undefined1 *)in_FSR1;
  while( true ) {
    FUN_CODE_009a08(uVar4);
    if ((unaff_Z & 1) != 0) break;
    FUN_CODE_0099a8();
    FUN_CODE_0096c0();
    *puVar3 = *puVar3;
    puVar2 = puVar3 + -2;
    puVar3[-1] = puVar3[-1];
    unaff_Z = DAT_DATA_0e12 == '\0';
    uVar4 = 0;
    puVar3 = puVar3 + -2;
    if (!(bool)unaff_Z) {
      FUN_CODE_009a26();
      uVar4 = FUN_CODE_0094d8();
      *puVar2 = *puVar2;
      puVar3 = puVar2 + -2;
      cVar1 = puVar2[-1];
      puVar2[-1] = cVar1;
      unaff_Z = cVar1 == '\0';
    }
  }
  FUN_CODE_009972();
  return;
}


// ===== 0x0098fc =====

void FUN_CODE_0098fc(void)

{
  BADSPACEBASE *in_FSR2;
  byte unaff_BSR;
  BADSPACEBASE *in_FSR1;
  byte bVar1;
  
  bVar1 = FUN_CODE_009a00();
  *(byte *)((ushort)unaff_BSR * 0x100 + 0xe) = bVar1 - 5;
  *(char *)((ushort)unaff_BSR * 0x100 + 0xf) = (char)((ushort)in_FSR1 >> 8) + -1 + (4 < bVar1);
  FUN_CODE_00999c();
  *(undefined1 *)in_FSR1 = *(undefined1 *)((short)in_FSR2 + -4);
  FUN_CODE_009a9c(0xfc);
  return;
}


// ===== 0x009936 =====

void FUN_CODE_009936(void)

{
  BADSPACEBASE *in_FSR2;
  undefined1 *puVar1;
  BADSPACEBASE *in_FSR1;
  undefined1 *puVar2;
  
  FUN_CODE_009a5a();
  FUN_CODE_00999c();
  DAT_DATA_0e0e = (byte)in_FSR2 - 4;
  DAT_DATA_0e0f = (char)((ushort)in_FSR2 >> 8) + -1 + (3 < (byte)in_FSR2);
  puVar1 = (undefined1 *)((short)in_FSR2 + 1);
  *(undefined1 *)in_FSR1 = *(undefined1 *)((short)in_FSR2 + -3);
  puVar2 = (undefined1 *)((short)in_FSR1 + 2);
  *(undefined1 *)((short)in_FSR1 + 1) = 0;
  FUN_CODE_0096c0();
  *puVar2 = *puVar2;
  puVar2[-1] = puVar2[-1];
  puVar2[-2] = puVar1[-3];
  FUN_CODE_009a26();
  FUN_CODE_00cb86();
  FUN_CODE_009aa8();
  return;
}


// ===== 0x009972 =====

void FUN_CODE_009972(void)

{
  return;
}


// ===== 0x00997e =====

undefined1 FUN_CODE_00997e(void)

{
  byte bVar1;
  byte unaff_BSR;
  undefined1 *in_TBLPTR;
  
  FUN_CODE_009ab0();
  bVar1 = *(byte *)((ushort)unaff_BSR * 0x100 + 10);
  *(byte *)((ushort)unaff_BSR * 0x100 + 10) = bVar1 + 1;
  *(char *)((ushort)unaff_BSR * 0x100 + 0xb) =
       *(char *)((ushort)unaff_BSR * 0x100 + 0xb) + (0xfe < bVar1);
  DAT_DATA_0e09 = *in_TBLPTR;
  return 0;
}


// ===== 0x00998e =====

char FUN_CODE_00998e(void)

{
  char in_FramePointer2_0000fffe;
  
  return in_FramePointer2_0000fffe << 1;
}


// ===== 0x00999c =====

void FUN_CODE_00999c(void)

{
  undefined1 in_PRODL;
  undefined1 in_PRODH;
  
  FUN_CODE_009a6c();
  DAT_DATA_0e0a = in_PRODL;
  DAT_DATA_0e0b = in_PRODH;
  return;
}


// ===== 0x0099a8 =====

undefined1 FUN_CODE_0099a8(void)

{
  return 0xfd;
}


// ===== 0x0099b6 =====

void FUN_CODE_0099b6(void)

{
  return;
}


// ===== 0x0099c0 =====

byte FUN_CODE_0099c0(void)

{
  BADSPACEBASE *in_FSR2;
  
  FUN_CODE_009a5a();
  return *(byte *)((short)in_FSR2 + -3) ^ 4;
}


// ===== 0x0099ca =====

void FUN_CODE_0099ca(char param_1)

{
  undefined3 in_TBLPTR;
  undefined1 *puVar1;
  byte unaff_C;
  
  puVar1 = (undefined1 *)
           CONCAT12((char)((uint3)in_TBLPTR >> 0x10),
                    CONCAT11((char)((uint3)in_TBLPTR >> 8) + param_1 + (unaff_C & 1),(char)in_TBLPTR
                            ));
  DAT_DATA_0014 = *puVar1;
  DAT_DATA_0015 = puVar1[1];
  return;
}


// ===== 0x0099e2 =====

undefined1 FUN_CODE_0099e2(void)

{
  BADSPACEBASE *in_FSR2;
  
  FUN_CODE_009a5a();
  return *(undefined1 *)((short)in_FSR2 + -2);
}


// ===== 0x0099ea =====

undefined1 FUN_CODE_0099ea(void)

{
  byte unaff_BSR;
  byte unaff_C;
  
  *(byte *)((ushort)unaff_BSR * 0x100 + 0xf) =
       *(char *)((ushort)unaff_BSR * 0x100 + 0xf) - ~(unaff_C & 1);
  return 0;
}


// ===== 0x009a00 =====

undefined1 FUN_CODE_009a00(void)

{
  undefined1 in_FSR1L;
  
  FUN_CODE_009a5a();
  return in_FSR1L;
}


// ===== 0x009a08 =====

undefined1 FUN_CODE_009a08(void)

{
  undefined1 *in_TBLPTR;
  
  FUN_CODE_009ab0();
  DAT_DATA_0e09 = *in_TBLPTR;
  return *in_TBLPTR;
}


// ===== 0x009a14 =====

undefined1 FUN_CODE_009a14(void)

{
  undefined3 in_TBLPTR;
  
  DAT_DATA_0e09 =
       *(undefined1 *)
        CONCAT12((char)((uint3)in_TBLPTR >> 0x10),CONCAT11(DAT_DATA_0e11,DAT_DATA_0e10));
  return DAT_DATA_0e09;
}


// ===== 0x009a26 =====

undefined1 FUN_CODE_009a26(void)

{
  return 0xe;
}


// ===== 0x009a30 =====

void FUN_CODE_009a30(void)

{
  BADSPACEBASE *in_FSR1;
  undefined1 *puVar1;
  
  puVar1 = &FramePointer10x0001;
  FUN_CODE_00cfc6();
  *puVar1 = *puVar1;
  puVar1[-1] = puVar1[-1];
  return;
}


// ===== 0x009a3e =====

void FUN_CODE_009a3e(void)

{
  BADSPACEBASE *in_FSR1;
  undefined1 *puVar1;
  
  puVar1 = &FramePointer10x0001;
  FUN_CODE_00cefe();
  *puVar1 = *puVar1;
  DAT_DATA_0e07 = DAT_DATA_0e07 + '\x01';
  return;
}


// ===== 0x009a4c =====

undefined1 FUN_CODE_009a4c(void)

{
  byte unaff_BSR;
  byte unaff_C;
  
  *(byte *)((ushort)unaff_BSR * 0x100 + 0xf) =
       *(char *)((ushort)unaff_BSR * 0x100 + 0xf) - ~(unaff_C & 1);
  return 0;
}


// ===== 0x009a5a =====

void FUN_CODE_009a5a(void)

{
  return;
}


// ===== 0x009a6c =====

void FUN_CODE_009a6c(void)

{
  BADSPACEBASE *in_FSR2;
  BADSPACEBASE *in_FSR1;
  undefined1 *puVar1;
  undefined1 uVar2;
  
  uVar2 = FUN_CODE_009aba();
  *(undefined1 *)in_FSR1 = uVar2;
  puVar1 = (undefined1 *)((short)in_FSR1 + 2);
  *(undefined1 *)((short)in_FSR1 + 1) = *(undefined1 *)((short)in_FSR2 + -2);
  FUN_CODE_009282();
  *puVar1 = *puVar1;
  puVar1[-1] = puVar1[-1];
  return;
}


// ===== 0x009a80 =====

undefined1 FUN_CODE_009a80(void)

{
  byte bVar1;
  byte unaff_BSR;
  
  FUN_CODE_0099b6();
  bVar1 = *(byte *)((ushort)unaff_BSR * 0x100 + 0xc);
  *(byte *)((ushort)unaff_BSR * 0x100 + 0xc) = bVar1 + 1;
  *(char *)((ushort)unaff_BSR * 0x100 + 0xd) =
       *(char *)((ushort)unaff_BSR * 0x100 + 0xd) + (0xfe < bVar1);
  return 0;
}


// ===== 0x009a8a =====

void FUN_CODE_009a8a(void)

{
  byte bVar1;
  byte unaff_BSR;
  char cVar2;
  BADSPACEBASE *in_FSR0;
  
  bVar1 = *(byte *)((ushort)unaff_BSR * 0x100 + 0x10);
  *(byte *)((ushort)unaff_BSR * 0x100 + 0x10) = bVar1 + 1;
  *(char *)((ushort)unaff_BSR * 0x100 + 0x11) =
       *(char *)((ushort)unaff_BSR * 0x100 + 0x11) + (0xfe < bVar1);
  cVar2 = FUN_CODE_0099b6();
  bVar1 = *(byte *)((ushort)unaff_BSR * 0x100 + 0xc);
  *(byte *)((ushort)unaff_BSR * 0x100 + 0xc) = bVar1 + 1;
  *(char *)((ushort)unaff_BSR * 0x100 + 0xd) =
       *(char *)((ushort)unaff_BSR * 0x100 + 0xd) + cVar2 + (0xfe < bVar1);
  *(undefined1 *)in_FSR0 = DAT_DATA_0e09;
  return;
}


// ===== 0x009a9c =====

void FUN_CODE_009a9c(void)

{
  BADSPACEBASE *in_FSR1;
  undefined1 *puVar1;
  
  puVar1 = &FramePointer10x0001;
  FUN_CODE_0098dc();
  *puVar1 = *puVar1;
  puVar1[-1] = puVar1[-1];
  FUN_CODE_009972();
  return;
}


// ===== 0x009aa8 =====

void FUN_CODE_009aa8(void)

{
  FUN_CODE_009972();
  return;
}


// ===== 0x009ab0 =====

void FUN_CODE_009ab0(void)

{
  return;
}


// ===== 0x009aba =====

byte FUN_CODE_009aba(void)

{
  return (DAT_DATA_0158 & 0x38) >> 3;
}


// ===== 0x009ac8 =====

void FUN_CODE_009ac8(void)

{
  undefined1 in_PRODL;
  undefined1 in_PRODH;
  
  FUN_CODE_009a6c();
  DAT_DATA_0014 = in_PRODL;
  DAT_DATA_0015 = in_PRODH;
  return;
}


// ===== 0x009ad4 =====

void FUN_CODE_009ad4(void)

{
  DAT_DATA_0098 = 0;
  DAT_DATA_0099 = 0;
  DAT_DATA_0060 = 0;
  DAT_DATA_0061 = 0;
  DAT_DATA_00ae = 0;
  DAT_DATA_00af = 0;
  uDATA00b1 = 0;
  DAT_DATA_00b0 = 0;
  DAT_DATA_00aa = 0;
  DAT_DATA_00ab = 0;
  DAT_DATA_00ac = 0;
  DAT_DATA_00ad = 0;
  return;
}


// ===== 0x009af0 =====

void FUN_CODE_009af0(void)

{
  BADSPACEBASE *in_FSR2;
  undefined1 *puVar1;
  BADSPACEBASE *in_FSR1;
  BADSPACEBASE *in_FSR0;
  undefined1 *puVar2;
  
  FUN_CODE_00a16e();
  FUN_CODE_00a1aa();
  puVar1 = (undefined1 *)((short)in_FSR2 + 1);
  *(byte *)in_FSR1 = *(byte *)((short)in_FSR2 + -6) & 0x7f;
  FUN_CODE_00a244();
  FUN_CODE_009b2c();
  FUN_CODE_00a2e4();
  FUN_CODE_00a19c();
  FUN_CODE_00a260();
  FUN_CODE_00a19c();
  *(byte *)in_FSR0 = *(byte *)in_FSR0 & 0x7f;
  FUN_CODE_00a19c();
  puVar2 = (undefined1 *)((short)in_FSR0 + 1);
  *(undefined1 *)in_FSR0 = *(undefined1 *)in_FSR0;
  FUN_CODE_00a200();
  FUN_CODE_00a19c();
  FUN_CODE_00a1ca();
  *puVar2 = DAT_DATA_00b0;
  if ((puVar1[-6] & 0x80) == 0) {
    FUN_CODE_00a19c();
    FUN_CODE_00a220();
    FUN_CODE_00a244();
    FUN_CODE_00a1e6();
  }
  FUN_CODE_00a18c();
  FUN_CODE_00a180(0);
  return;
}


// ===== 0x009b2c =====

void FUN_CODE_009b2c(void)

{
  undefined1 uVar1;
  BADSPACEBASE *in_FSR2;
  undefined1 *puVar2;
  undefined1 *puVar3;
  BADSPACEBASE *in_FSR1;
  BADSPACEBASE *in_FSR0;
  
  FUN_CODE_00a28c();
  puVar2 = (undefined1 *)((short)in_FSR2 + 1);
  if (*(byte *)((short)in_FSR2 + -4) < 0x10) {
    *(undefined1 *)((short)in_FSR2 + 1) = 0;
  }
  else {
    puVar2 = (undefined1 *)((short)in_FSR2 + 2);
    *(undefined1 *)((short)in_FSR2 + -3) = 0xf;
    *(undefined1 *)((short)in_FSR2 + 2) = 1;
  }
  puVar3 = puVar2 + 1;
  DAT_DATA_0014 = puVar2[-4];
  FUN_CODE_00a160();
  *(byte *)in_FSR0 = DAT_DATA_0014 & 0xf | *(byte *)in_FSR0 & 0xf0;
  uVar1 = *puVar3;
  *(undefined1 *)in_FSR1 = *(undefined1 *)in_FSR1;
  FUN_CODE_00a180(uVar1);
  return;
}


// ===== 0x009b64 =====

void FUN_CODE_009b64(void)

{
  char cVar1;
  BADSPACEBASE *in_FSR2;
  undefined1 *puVar2;
  undefined1 *puVar3;
  undefined1 *puVar4;
  undefined1 *puVar5;
  undefined1 *puVar6;
  undefined1 *puVar7;
  undefined1 *puVar8;
  BADSPACEBASE *in_FSR1;
  byte *pbVar9;
  char cVar10;
  undefined1 uVar11;
  BADSPACEBASE *in_FSR0;
  
  FUN_CODE_00a28c();
  *(undefined1 *)in_FSR1 = *(undefined1 *)in_FSR1;
  *(undefined1 *)((short)in_FSR1 + 1) = *(undefined1 *)((short)in_FSR1 + 1);
  *(undefined1 *)((short)in_FSR1 + 2) = *(undefined1 *)((short)in_FSR1 + 2);
  pbVar9 = (byte *)((short)in_FSR1 + 4);
  cVar10 = *(char *)((short)in_FSR1 + 3);
  *(char *)((short)in_FSR1 + 3) = cVar10;
  FUN_CODE_00a19c();
  FUN_CODE_00a2fc();
  if (cVar10 == '\0') {
    FUN_CODE_00a19c();
    FUN_CODE_00a200();
    FUN_CODE_00a160();
    *(undefined1 *)((short)in_FSR0 + 4) = 0;
    *(undefined1 *)((short)in_FSR0 + 6) = 0;
    DAT_DATA_0014 = 0;
  }
  else {
    *(undefined1 *)((short)in_FSR2 + 3) = 0;
    puVar2 = (undefined1 *)((short)in_FSR2 + 2);
    *(undefined1 *)((short)in_FSR2 + 5) = 0;
    FUN_CODE_00a232();
    if (DAT_DATA_0015 == '\0') {
      cVar10 = FUN_CODE_00a2ec(0);
      puVar2[(short)cVar10 + 1] = *(undefined1 *)in_FSR0;
      while( true ) {
        puVar4 = puVar2 + 1;
        FUN_CODE_00a160();
        FUN_CODE_00a1ca();
        DAT_DATA_0014 = *(byte *)in_FSR0;
        puVar5 = puVar4 + 1;
        cVar10 = DAT_DATA_0014 - puVar4[5];
        puVar6 = puVar4 + 1;
        if ((DAT_DATA_0014 < (byte)puVar4[5]) ||
           (FUN_CODE_00a1ba(cVar10), puVar6 = puVar5, cVar10 == '\0')) break;
        cVar10 = FUN_CODE_00a2ec();
        puVar2 = puVar5 + 1;
        *pbVar9 = puVar5[(short)cVar10 + 1];
        *pbVar9 = *pbVar9 + *(char *)in_FSR0;
        puVar5[6] = *pbVar9;
      }
      FUN_CODE_00a26a();
      puVar7 = puVar6;
      if (cVar10 != '\0') {
        cVar10 = FUN_CODE_00a2ec();
        *pbVar9 = puVar6[(short)cVar10 + 1];
        *pbVar9 = *pbVar9 - *(char *)in_FSR0;
        puVar7 = puVar6 + 2;
        puVar6[6] = *pbVar9;
      }
      FUN_CODE_00a160();
      cVar10 = FUN_CODE_00a292();
      puVar8 = puVar7 + 1;
      cVar1 = puVar7[(short)cVar10 + 1];
      cVar10 = *(char *)in_FSR0;
      *(char *)in_FSR0 = cVar10 - cVar1;
      FUN_CODE_00a26a();
      puVar6 = puVar8;
      if (cVar10 - cVar1 != '\0') {
        FUN_CODE_00a2f2();
        cVar10 = FUN_CODE_00a2ec();
        *(char *)in_FSR0 = *(char *)in_FSR0 - puVar8[(short)cVar10 + 1];
        puVar6 = puVar8 + 1;
      }
    }
    else {
      FUN_CODE_00a160();
      *pbVar9 = *(byte *)in_FSR0 & 0xf;
      puVar2[5] = *pbVar9;
      puVar7 = puVar2 + 1;
      do {
        FUN_CODE_00a272();
        puVar3 = puVar7 + 1;
        cVar10 = puVar7[5] - (*(byte *)in_FSR0 & 0xf);
        puVar6 = puVar7 + 1;
        if ((byte)puVar7[5] < (*(byte *)in_FSR0 & 0xf)) break;
        FUN_CODE_00a1ba(cVar10);
        puVar6 = puVar3;
        puVar7 = puVar3;
      } while (cVar10 != '\0');
    }
    FUN_CODE_00a20e();
    if ((char)puVar6 == -2) {
      uVar11 = FUN_CODE_00a19c();
    }
    else {
      FUN_CODE_00a252();
      uVar11 = 0;
    }
    FUN_CODE_00a200(uVar11);
    FUN_CODE_00a160();
    DAT_DATA_0014 = FUN_CODE_00a298();
  }
  if ((byte)pbVar9 < 5) {
    *(undefined1 *)((ushort)pbVar9 & 0xff00) = *(undefined1 *)((ushort)pbVar9 & 0xff00);
  }
  FUN_CODE_00a180(DAT_DATA_0014);
  return;
}


// ===== 0x009ce6 =====

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


// ===== 0x009e94 =====

byte FUN_CODE_009e94(void)

{
  byte bVar1;
  byte bVar2;
  BADSPACEBASE *in_FSR1;
  byte *pbVar3;
  byte *pbVar4;
  
  FUN_CODE_009e94(DAT_DATA_0014);
  bVar1 = INTCON;
  pbVar4 = (byte *)((short)in_FSR1 + 1);
  *(byte *)in_FSR1 = bVar1 & 0xc0;
  bVar1 = INTCON;
  INTCON = bVar1 & 0x3f;
  if ((*(byte *)CONCAT11(DAT_DATA_0061,DAT_DATA_0060) & 0x70) == 0x50) {
    *(undefined1 *)((short)in_FSR1 + 1) = 0x98;
    *(undefined1 *)((short)in_FSR1 + 2) = 0;
    *(undefined1 *)((short)in_FSR1 + 3) = DAT_DATA_0060;
    pbVar3 = (byte *)((short)in_FSR1 + 5);
    *(undefined1 *)((short)in_FSR1 + 4) = DAT_DATA_0061;
    FUN_CODE_009b64();
    *pbVar3 = *pbVar3;
    pbVar3[-1] = pbVar3[-1];
    pbVar3[-2] = pbVar3[-2];
    pbVar4 = pbVar3 + -4;
    pbVar3[-3] = pbVar3[-3];
  }
  bVar1 = INTCON;
  INTCON = bVar1 & 0x3f;
  bVar1 = *(byte *)CONCAT11((char)((ushort)pbVar4 >> 8) - ~((char)pbVar4 != '\0'),(char)pbVar4 + -1)
  ;
  bVar2 = INTCON;
  INTCON = bVar2 | bVar1;
  return bVar1;
}


// ===== 0x009f10 =====

undefined1 FUN_CODE_009f10(void)

{
  DAT_DATA_00b0 = DAT_DATA_00b0 + '\x01';
  DAT_DATA_0014 = bDATA00b1;
  DAT_DATA_0015 = 0;
  if (0xfe < bDATA00b1 != true) {
    return 1;
  }
  bDATA00b1 = bDATA00b1 + 1;
  return 0;
}


// ===== 0x009f46 =====

void FUN_CODE_009f46(void)

{
  BADSPACEBASE *in_FSR2;
  BADSPACEBASE *in_FSR0;
  
  FUN_CODE_00a2b2();
  *(undefined1 *)in_FSR0 = 0;
  *(undefined1 *)((short)in_FSR0 + 1) = 0;
  FUN_CODE_00a286();
  *(undefined1 *)in_FSR0 = *(undefined1 *)((short)in_FSR2 + -4);
  FUN_CODE_00a18c();
  FUN_CODE_00a180(0);
  return;
}


// ===== 0x009f7a =====

/* WARNING: Restarted to delay deadcode elimination for space: DATA */

void FUN_CODE_009f7a(void)

{
  char cVar1;
  BADSPACEBASE *in_FSR2;
  BADSPACEBASE *in_FSR1;
  undefined1 *puVar2;
  BADSPACEBASE *in_FSR0;
  byte *pbVar3;
  
  FUN_CODE_00a28c();
  puVar2 = (undefined1 *)((short)in_FSR1 + 1);
  *(undefined1 *)in_FSR1 = *(undefined1 *)in_FSR1;
  FUN_CODE_00a1aa();
  FUN_CODE_00a286();
  DAT_DATA_0014 = *(byte *)in_FSR0;
  DAT_DATA_0015 = 0;
  if (0xfe < DAT_DATA_0014 == true) {
    FUN_CODE_00a286(0);
    cVar1 = *(char *)in_FSR0;
    *(char *)in_FSR0 = cVar1 + '\x01';
    FUN_CODE_00a160();
    FUN_CODE_00a2fc();
    if (cVar1 + '\x01' != '\0') {
      if ((DAT_DATA_00ad | DAT_DATA_00ac) == 0) {
        DAT_DATA_00ac = *(byte *)in_FSR2;
        DAT_DATA_00ad = *(byte *)((short)in_FSR2 + 1);
      }
      else {
        in_FSR0 = (BADSPACEBASE *)CONCAT11(DAT_DATA_00ab,DAT_DATA_00aa);
        FUN_CODE_00a298(DAT_DATA_00ad | DAT_DATA_00ac);
      }
      DAT_DATA_00aa = *(undefined1 *)in_FSR2;
      DAT_DATA_00ab = *(undefined1 *)((short)in_FSR2 + 1);
      FUN_CODE_00a272();
      FUN_CODE_00a1ee();
      pbVar3 = (byte *)((short)in_FSR0 + 1);
      DAT_DATA_0014 = *(byte *)in_FSR0;
      DAT_DATA_0015 = *(byte *)((short)in_FSR0 + 1);
      FUN_CODE_00a160();
      *pbVar3 = DAT_DATA_0014;
      pbVar3[1] = DAT_DATA_0015;
      FUN_CODE_00a272();
      pbVar3[4] = 0;
      pbVar3[6] = 0;
    }
    *(undefined1 *)in_FSR2 = 0;
  }
  else {
    *(undefined1 *)in_FSR2 = 4;
  }
  FUN_CODE_00a2d4();
  *puVar2 = *puVar2;
  FUN_CODE_00a180();
  return;
}


// ===== 0x00a160 =====

undefined1 FUN_CODE_00a160(void)

{
  return 0xfd;
}


// ===== 0x00a16e =====

void FUN_CODE_00a16e(void)

{
  return;
}


// ===== 0x00a180 =====

void FUN_CODE_00a180(void)

{
  return;
}


// ===== 0x00a18c =====

byte FUN_CODE_00a18c(void)

{
  byte bVar1;
  byte bVar2;
  BADSPACEBASE *in_FSR1;
  
  bVar1 = INTCON;
  INTCON = bVar1 & 0x3f;
  bVar1 = *(byte *)CONCAT11((char)((ushort)in_FSR1 >> 8) + '\x01',0xff);
  bVar2 = INTCON;
  INTCON = bVar2 | bVar1;
  return bVar1;
}


// ===== 0x00a19c =====

undefined1 FUN_CODE_00a19c(void)

{
  return 0xfb;
}


// ===== 0x00a1aa =====

undefined1 FUN_CODE_00a1aa(void)

{
  undefined1 uVar1;
  byte bVar2;
  
  uVar1 = INTCON;
  bVar2 = INTCON;
  INTCON = bVar2 & 0x3f;
  return 0x3f;
}


// ===== 0x00a1ba =====

void FUN_CODE_00a1ba(void)

{
  FUN_CODE_00a302();
  FUN_CODE_00a2a4();
  FUN_CODE_00a272();
  FUN_CODE_00a2fc(0);
  return;
}


// ===== 0x00a1ca =====

void FUN_CODE_00a1ca(void)

{
  FUN_CODE_00a2dc(5);
  return;
}


// ===== 0x00a1e6 =====

void FUN_CODE_00a1e6(void)

{
  BADSPACEBASE *in_FSR1;
  
  FUN_CODE_009b64();
  FUN_CODE_00a2e4();
  *(undefined1 *)in_FSR1 = *(undefined1 *)in_FSR1;
  return;
}


// ===== 0x00a1ee =====

void FUN_CODE_00a1ee(void)

{
  FUN_CODE_00a2dc(3);
  return;
}


// ===== 0x00a200 =====

undefined1 FUN_CODE_00a200(void)

{
  return 0xfd;
}


// ===== 0x00a20e =====

byte FUN_CODE_00a20e(undefined1 param_1)

{
  char in_FSR2H;
  byte *pbVar1;
  byte unaff_C;
  
  pbVar1 = (byte *)CONCAT11(in_FSR2H + (unaff_C & 1),param_1);
  return pbVar1[1] | *pbVar1;
}


// ===== 0x00a21c =====

void FUN_CODE_00a21c(void)

{
  FUN_CODE_00a2dc(2);
  return;
}


// ===== 0x00a220 =====

undefined1 FUN_CODE_00a220(void)

{
  return 0;
}


// ===== 0x00a232 =====

byte FUN_CODE_00a232(void)

{
  byte in_FramePointer2_0000fffb;
  undefined1 in_FramePointer2_0000fffd;
  
  DAT_DATA_0014 = in_FramePointer2_0000fffb;
  DAT_DATA_0015 = in_FramePointer2_0000fffd;
  return in_FramePointer2_0000fffb ^ 0xae;
}


// ===== 0x00a244 =====

undefined1 FUN_CODE_00a244(void)

{
  return 0xfb;
}


// ===== 0x00a252 =====

undefined1 FUN_CODE_00a252(void)

{
  return 3;
}


// ===== 0x00a260 =====

byte FUN_CODE_00a260(void)

{
  byte in_FramePointer0_00000000;
  
  return in_FramePointer0_00000000 & 0x8f | 0x10;
}


// ===== 0x00a26a =====

byte FUN_CODE_00a26a(void)

{
  BADSPACEBASE *in_FSR0;
  
  FUN_CODE_00a302();
  return *(byte *)((short)in_FSR0 + 1) | *(byte *)in_FSR0;
}


// ===== 0x00a272 =====

void FUN_CODE_00a272(void)

{
  return;
}


// ===== 0x00a27c =====

void FUN_CODE_00a27c(void)

{
  return;
}


// ===== 0x00a286 =====

void FUN_CODE_00a286(void)

{
  FUN_CODE_00a160();
  FUN_CODE_00a21c();
  return;
}


// ===== 0x00a28c =====

void FUN_CODE_00a28c(void)

{
  BADSPACEBASE *in_FSR1;
  
  FUN_CODE_00a16e();
  *(undefined1 *)in_FSR1 = *(undefined1 *)in_FSR1;
  return;
}


// ===== 0x00a292 =====

undefined1 FUN_CODE_00a292(void)

{
  FUN_CODE_00a1ca();
  return 4;
}


// ===== 0x00a298 =====

void FUN_CODE_00a298(void)

{
  BADSPACEBASE *in_FSR2;
  BADSPACEBASE *in_FSR0;
  
  FUN_CODE_00a1ee();
  *(undefined1 *)in_FSR0 = *(undefined1 *)in_FSR2;
  *(undefined1 *)((short)in_FSR0 + 1) = *(undefined1 *)((short)in_FSR2 + 1);
  return;
}


// ===== 0x00a2a4 =====

undefined1 FUN_CODE_00a2a4(void)

{
  return 3;
}


// ===== 0x00a2b2 =====

void FUN_CODE_00a2b2(void)

{
  FUN_CODE_00a16e();
  FUN_CODE_00a1aa();
  FUN_CODE_00a160();
  return;
}


// ===== 0x00a2d4 =====

undefined1 FUN_CODE_00a2d4(void)

{
  undefined1 uVar1;
  BADSPACEBASE *in_FSR2;
  BADSPACEBASE *in_FSR1;
  
  FUN_CODE_00a18c();
  uVar1 = *(undefined1 *)in_FSR2;
  *(undefined1 *)in_FSR1 = *(undefined1 *)in_FSR1;
  return uVar1;
}


// ===== 0x00a2dc =====

undefined1 FUN_CODE_00a2dc(void)

{
  return 0;
}


// ===== 0x00a2e4 =====

void FUN_CODE_00a2e4(void)

{
  return;
}


// ===== 0x00a2ec =====

void FUN_CODE_00a2ec(void)

{
  FUN_CODE_00a272();
  FUN_CODE_00a292();
  return;
}


// ===== 0x00a2f2 =====

void FUN_CODE_00a2f2(void)

{
  BADSPACEBASE *in_FSR2;
  char cVar1;
  BADSPACEBASE *in_FSR0;
  
  FUN_CODE_00a160();
  cVar1 = FUN_CODE_00a292();
  *(undefined1 *)((short)in_FSR2 + (short)cVar1 + 1) = *(undefined1 *)in_FSR0;
  return;
}


// ===== 0x00a2fc =====

void FUN_CODE_00a2fc(void)

{
  FUN_CODE_00a27c();
  FUN_CODE_00a26a();
  return;
}


// ===== 0x00a302 =====

void FUN_CODE_00a302(void)

{
  return;
}


// ===== 0x00ac34 =====

undefined1 FUN_CODE_00ac34(void)

{
  DAT_DATA_0178 = 0;
  DAT_DATA_0179 = 0;
  DAT_DATA_017b = 1;
  DAT_DATA_017a = 0;
  DAT_DATA_017c = 0;
  FUN_CODE_00b006();
  return 0;
}


// ===== 0x00ac46 =====

undefined1 FUN_CODE_00ac46(void)

{
  BADSPACEBASE *in_FSR1;
  undefined1 *puVar1;
  
  puVar1 = &FramePointer10x0005;
  DAT_DATA_0014 = FUN_CODE_009af0();
  if ((byte)puVar1 < 5) {
    *(undefined1 *)((ushort)puVar1 & 0xff00) = *(undefined1 *)((ushort)puVar1 & 0xff00);
  }
  return 0;
}


// ===== 0x00b006 =====

void FUN_CODE_00b006(void)

{
  byte unaff_BSR;
  
  *(undefined1 *)((ushort)unaff_BSR * 0x100 + 0x80) = 0xff;
  *(undefined1 *)((ushort)unaff_BSR * 0x100 + 0x81) = 0xff;
  *(undefined1 *)((ushort)unaff_BSR * 0x100 + 0x82) = 0xff;
  *(undefined1 *)((ushort)unaff_BSR * 0x100 + 0x83) = 0xff;
  *(undefined1 *)((ushort)unaff_BSR * 0x100 + 0x84) = 0xff;
  *(undefined1 *)((ushort)unaff_BSR * 0x100 + 0x85) = 0xff;
  *(undefined1 *)((ushort)unaff_BSR * 0x100 + 0x7f) = 0;
  return;
}


// ===== 0x00b068 =====

void FUN_CODE_00b068(void)

{
  byte bVar1;
  
  bVar1 = PORTH;
  PORTH = bVar1 & 0xdf;
  bVar1 = PORTG;
  PORTG = bVar1 & 0xf7;
  bVar1 = PORTG;
  PORTG = bVar1 & 0xfe;
  bVar1 = PORTH;
  PORTH = bVar1 & 0xfe;
  bVar1 = PORTH;
  PORTH = bVar1 & 0xfd;
  bVar1 = PORTH;
  PORTH = bVar1 & 0xfb;
  bVar1 = PORTH;
  PORTH = bVar1 & 0xf7;
  bVar1 = PORTH;
  PORTH = bVar1 & 0xef;
  bVar1 = PORTF;
  PORTF = bVar1 & 0xbf;
  DAT_DATA_0ee0 = 0;
  bVar1 = PORTF;
  PORTF = bVar1 & 0xdf;
  bVar1 = PORTB;
  PORTB = bVar1 & 0xf7;
  bVar1 = PORTH;
  PORTH = bVar1 & 0xbf;
  if ((DAT_DATA_015b & 8) == 0) {
    bVar1 = PORTH;
    PORTH = bVar1 & 0xbf;
  }
  else {
    bVar1 = PORTH;
    PORTH = bVar1 & 0xef;
  }
  bVar1 = PORTH;
  PORTH = bVar1 & 0x7f;
  bVar1 = PORTB;
  PORTB = bVar1 & 0xfe;
  bVar1 = PORTB;
  PORTB = bVar1 & 0xfd;
  bVar1 = PORTC;
  PORTC = bVar1 & 0xfe;
  bVar1 = PORTC;
  PORTC = bVar1 & 0xfd;
  return;
}


// ===== 0x00b256 =====

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


// ===== 0x00b482 =====

void FUN_CODE_00b482(void)

{
  BADSPACEBASE *in_FSR1;
  undefined1 *puVar1;
  
  FUN_CODE_009f10();
  *(undefined1 *)in_FSR1 = 0x9e;
  puVar1 = (undefined1 *)((short)in_FSR1 + 2);
  *(undefined1 *)((short)in_FSR1 + 1) = 0;
  FUN_CODE_009f7a();
  *puVar1 = *puVar1;
  puVar1[-1] = puVar1[-1];
  return;
}


// ===== 0x00b49c =====

void FUN_CODE_00b49c(void)

{
  return;
}


// ===== 0x00b49e =====

void FUN_CODE_00b49e(void)

{
  return;
}


// ===== 0x00b53c =====

undefined1 FUN_CODE_00b53c(void)

{
  return DAT_DATA_0165;
}


// ===== 0x00bc26 =====

/* WARNING: Instruction at (CODE,0x00bc86) overlaps instruction at (CODE,0x00bc84)
    */

undefined1 FUN_CODE_00bc26(void)

{
  byte bVar1;
  char cVar2;
  
  bVar1 = TRISG;
  TRISG = bVar1 | 4;
  bVar1 = TRISG;
  TRISG = bVar1 & 0xfd;
  TXSTA2 = 0x24;
  SPBRG2 = 0x19;
  RCSTA2 = 0x90;
  bVar1 = IPR1;
  IPR1 = bVar1 | 0x20;
  bVar1 = PIE3;
  PIE3 = bVar1 & 0xef;
  bVar1 = PIE3;
  PIE3 = bVar1 | 0x20;
  DAT_DATA_0eda = 0;
  DAT_DATA_0edb = 0xd9;
  bVar1 = T0CON;
  T0CON = bVar1 & 0xdf;
  bVar1 = T0CON;
  T0CON = bVar1 & 0xbf;
  TMR0H = 0xd9;
  TMR0L = 0;
  bVar1 = T0CON;
  T0CON = bVar1 | 8;
  bVar1 = T0CON;
  T0CON = bVar1 | 0x80;
  bVar1 = INTCON2;
  INTCON2 = bVar1 & 0xfb;
  bVar1 = INTCON;
  INTCON = bVar1 | 0x20;
  ADCON1 = 6;
  ADCON0 = 0;
  PORTA = 0;
  bVar1 = TRISA;
  TRISA = bVar1 | 0x33;
  TRISF = 0x3f;
  CMCON = 0xf;
  ADCON2 = 0x85;
  bVar1 = PIR1;
  PIR1 = bVar1 & 0xbf;
  bVar1 = PIE1;
  PIE1 = bVar1 & 0xbf;
  bVar1 = ADCON0;
  ADCON0 = bVar1 | 1;
  cVar2 = '<';
  do {
    cVar2 = cVar2 + -1;
  } while (cVar2 != '\0');
  TRISB = 0xe4;
  bVar1 = INTCON2;
  INTCON2 = bVar1 & 0x7f;
  TRISC = 0xfc;
  TRISE = 0x3f;
  TRISH = 0;
  TRISG = 0xe6;
  bVar1 = PORTF;
  PORTF = bVar1 & 0xbf;
  DAT_DATA_0ee0 = 0;
  bVar1 = TRISF;
  TRISF = bVar1 & 0xbf;
  bVar1 = TRISJ;
  TRISJ = bVar1 | 3;
  bVar1 = TRISC;
  TRISC = bVar1 | 8;
  bVar1 = TRISJ;
  TRISJ = bVar1 | 0xe0;
  bVar1 = TRISJ;
  TRISJ = bVar1 | 0x18;
  bVar1 = RCON;
  RCON = bVar1 | 0x80;
  DAT_DATA_0ee1 = 0xf;
  return 0;
}


// ===== 0x00bcc0 =====

undefined1 FUN_CODE_00bcc0(void)

{
  BADSPACEBASE *in_FSR1;
  undefined1 *puVar1;
  undefined1 *puVar2;
  undefined1 *puVar3;
  undefined1 *puVar4;
  undefined1 *puVar5;
  char cVar6;
  undefined1 *puVar7;
  bool bVar8;
  undefined1 in_WS;
  
  puVar2 = &FramePointer10x0008;
  cVar6 = '\x14';
  puVar5 = (undefined1 *)0x0;
  while (bVar8 = cVar6 != '\0', cVar6 = cVar6 + -1, bVar8) {
    puVar1 = puVar2 + 1;
    puVar2 = puVar2 + 1;
    *puVar1 = *puVar5;
    puVar5 = puVar5 + 1;
  }
  cVar6 = '\x10';
  puVar5 = &DAT_DATA_0014;
  while (bVar8 = cVar6 != '\0', cVar6 = cVar6 + -1, bVar8) {
    puVar3 = puVar2 + 1;
    puVar2 = puVar2 + 1;
    *puVar3 = *puVar5;
    puVar5 = puVar5 + 1;
  }
  puVar4 = puVar2 + 1;
  *puVar2 = *puVar2;
  thunk_FUN_CODE_007628();
  *puVar4 = *puVar4;
  cVar6 = '\x10';
  puVar5 = puVar4 + -1;
  puVar7 = &DAT_DATA_0023;
  while (bVar8 = cVar6 != '\0', cVar6 = cVar6 + -1, bVar8) {
    *puVar7 = *puVar5;
    puVar5 = puVar5 + -1;
    puVar7 = puVar7 + -1;
  }
  cVar6 = '\x14';
  puVar7 = &DAT_DATA_0013;
  while (bVar8 = cVar6 != '\0', cVar6 = cVar6 + -1, bVar8) {
    *puVar7 = *puVar5;
    puVar5 = puVar5 + -1;
    puVar7 = puVar7 + -1;
  }
  return in_WS;
}


// ===== 0x00bd4a =====

/* WARNING: Restarted to delay deadcode elimination for space: DATA */

undefined1 FUN_CODE_00bd4a(void)

{
  byte bVar1;
  BADSPACEBASE *in_FSR1;
  undefined1 *puVar2;
  undefined1 *puVar3;
  undefined1 *puVar4;
  undefined1 *puVar5;
  undefined1 *puVar6;
  undefined1 *puVar7;
  char cVar8;
  undefined1 *puVar9;
  bool bVar10;
  
  puVar3 = &FramePointer10x000b;
  cVar8 = '\x14';
  puVar7 = (undefined1 *)0x0;
  while (bVar10 = cVar8 != '\0', cVar8 = cVar8 + -1, bVar10) {
    puVar2 = puVar3 + 1;
    puVar3 = puVar3 + 1;
    *puVar2 = *puVar7;
    puVar7 = puVar7 + 1;
  }
  cVar8 = '\x10';
  puVar7 = &DAT_DATA_0014;
  while (bVar10 = cVar8 != '\0', cVar8 = cVar8 + -1, bVar10) {
    puVar4 = puVar3 + 1;
    puVar3 = puVar3 + 1;
    *puVar4 = *puVar7;
    puVar7 = puVar7 + 1;
  }
  puVar5 = puVar3 + 1;
  puVar6 = puVar3 + 1;
  *puVar3 = *puVar3;
  bVar1 = INTCON;
  if (((bVar1 & 0x20) == 0) || (bVar1 = INTCON, (bVar1 & 4) == 0)) {
    FUN_CODE_00b49c();
    puVar7 = puVar6;
  }
  else {
    bVar1 = INTCON;
    INTCON = bVar1 & 0xfb;
    bVar1 = TMR0L;
    cVar8 = TMR0H;
    DAT_DATA_0edc = bVar1 + DAT_DATA_0eda;
    DAT_DATA_0edd = cVar8 + DAT_DATA_0edb + CARRY1(bVar1,DAT_DATA_0eda);
    TMR0H = DAT_DATA_0edd;
    TMR0L = DAT_DATA_0edc;
    if (DAT_DATA_0ede == '\0') {
      FUN_CODE_00b482(0);
      puVar7 = puVar5;
    }
    else {
      DAT_DATA_0edf = DAT_DATA_0edf + '\x01';
      puVar7 = puVar3 + 1;
      if (DAT_DATA_0edf == 'd') {
        DAT_DATA_0edf = '\0';
        puVar7 = puVar3 + 1;
      }
    }
  }
  *puVar7 = *puVar7;
  cVar8 = '\x10';
  puVar7 = puVar7 + -1;
  puVar9 = &DAT_DATA_0023;
  while (bVar10 = cVar8 != '\0', cVar8 = cVar8 + -1, bVar10) {
    *puVar9 = *puVar7;
    puVar7 = puVar7 + -1;
    puVar9 = puVar9 + -1;
  }
  cVar8 = '\x14';
  puVar9 = &DAT_DATA_0013;
  while (bVar10 = cVar8 != '\0', cVar8 = cVar8 + -1, bVar10) {
    *puVar9 = *puVar7;
    puVar7 = puVar7 + -1;
    puVar9 = puVar9 + -1;
  }
  return puVar7[-8];
}


// ===== 0x00bff8 =====

/* WARNING: Instruction at (CODE,0x00c020) overlaps instruction at (CODE,0x00c01e)
    */
/* WARNING: Removing unreachable block (CODE,0x00c04c) */
/* WARNING: Removing unreachable block (CODE,0x00c054) */
/* WARNING: Removing unreachable block (CODE,0x00c058) */
/* WARNING: Removing unreachable block (CODE,0x00c062) */
/* WARNING: Removing unreachable block (CODE,0x00c066) */
/* WARNING: Removing unreachable block (CODE,0x00c070) */
/* WARNING: Removing unreachable block (CODE,0x00c07a) */
/* WARNING: Removing unreachable block (CODE,0x00c07e) */
/* WARNING: Removing unreachable block (CODE,0x00c088) */
/* WARNING: Removing unreachable block (CODE,0x00c08c) */
/* WARNING: Removing unreachable block (CODE,0x00c092) */
/* WARNING: Removing unreachable block (CODE,0x00c09c) */
/* WARNING: Removing unreachable block (CODE,0x00c0b6) */
/* WARNING: Removing unreachable block (CODE,0x00c0ba) */
/* WARNING: Removing unreachable block (CODE,0x00c0cc) */
/* WARNING: Removing unreachable block (CODE,0x00c0b8) */
/* WARNING: Removing unreachable block (CODE,0x00c0d0) */
/* WARNING: Removing unreachable block (CODE,0x00c0a6) */
/* WARNING: Removing unreachable block (CODE,0x00c0a8) */
/* WARNING: Removing unreachable block (CODE,0x00c0aa) */
/* WARNING: Removing unreachable block (CODE,0x00c0ae) */
/* WARNING: Removing unreachable block (CODE,0x00c090) */
/* WARNING: Removing unreachable block (CODE,0x00c0d6) */

void FUN_CODE_00bff8(void)

{
  byte bVar1;
  char cVar2;
  
  bVar1 = INTCON;
  INTCON = bVar1 | 0xc0;
  bVar1 = PORTB;
  PORTB = bVar1 | 8;
  DAT_DATA_0033 = 0;
  for (DAT_DATA_0032 = 0;
      (byte)~(0x99 < DAT_DATA_0032) <= DAT_DATA_0033 && DAT_DATA_0033 - ~(0x99 < DAT_DATA_0032) < 3;
      DAT_DATA_0032 = DAT_DATA_0032 + 1) {
    cVar2 = '<';
    do {
      cVar2 = cVar2 + -1;
    } while (cVar2 != '\0');
    DAT_DATA_0033 = DAT_DATA_0033 + (0xfe < DAT_DATA_0032);
  }
  bVar1 = PORTB;
  PORTB = bVar1 & 0xf7;
  do {
    cVar2 = '<';
    do {
      cVar2 = cVar2 + -1;
    } while (cVar2 != '\0');
  } while( true );
}


// ===== 0x00c226 =====

char FUN_CODE_00c226(void)

{
  char cVar1;
  ushort uVar2;
  undefined1 *puVar3;
  undefined1 *puVar4;
  byte bVar5;
  BADSPACEBASE *in_FSR1;
  undefined1 *puVar6;
  undefined1 *puVar7;
  short sVar8;
  char in_FramePointer1_00000003;
  byte in_FramePointer1_0000fffe;
  
  puVar3 = (undefined1 *)(ushort)in_FramePointer1_0000fffe;
  puVar6 = &FramePointer10x0006;
  puVar4 = puVar3;
  if (in_FramePointer1_00000003 < '\0') {
    puVar4 = puVar3 + 1;
    *puVar3 = 0x2d;
    puVar6 = &FramePointer10x000a;
  }
  *puVar6 = *puVar6;
  puVar6[1] = puVar6[1];
  puVar6[2] = (byte)(puVar6 + 2) - 2;
  puVar6[3] = (char)((ushort)(puVar6 + 2) >> 8) + -1 + (1 < (byte)(puVar6 + 2));
  puVar6[3] = puVar6[3];
  puVar7 = puVar6 + 6;
  puVar6[4] = puVar6[-1];
  FUN_CODE_00c2e2();
  bVar5 = (byte)puVar7;
  uVar2 = (ushort)puVar7 >> 8;
  FUN_CODE_00c2c2();
  if ((char)uVar2 + -1 + (4 < bVar5) == '\0') {
    FUN_CODE_00c2bc();
  }
  else {
    FUN_CODE_00c2d8();
    FUN_CODE_00c2ce();
  }
  FUN_CODE_00c2d8();
  *puVar4 = 0;
  bVar5 = (byte)puVar7 - 5;
  cVar1 = (char)((ushort)puVar7 >> 8) + -1 + (4 < (byte)puVar7);
  sVar8 = CONCAT11(cVar1,bVar5);
  *(undefined1 *)(sVar8 + 1) = *(undefined1 *)(sVar8 + 1);
  *(undefined1 *)(sVar8 + 1) = *(undefined1 *)(sVar8 + 1);
  return cVar1 + -1 + (2 < bVar5);
}


// ===== 0x00c2bc =====

byte FUN_CODE_00c2bc(void)

{
  byte in_FramePointer0_00000000;
  
  return in_FramePointer0_00000000 >> 4;
}


// ===== 0x00c2c2 =====

void FUN_CODE_00c2c2(void)

{
  return;
}


// ===== 0x00c2ce =====

char FUN_CODE_00c2ce(void)

{
  byte in_FramePointer0_00000000;
  
  return (in_FramePointer0_00000000 >> 4) + 0x30;
}


// ===== 0x00c2d8 =====

char FUN_CODE_00c2d8(void)

{
  byte in_FramePointer0_00000000;
  
  return (in_FramePointer0_00000000 & 0xf) + 0x30;
}


// ===== 0x00c2e2 =====

undefined1 FUN_CODE_00c2e2(void)

{
  char cVar1;
  BADSPACEBASE *in_FSR1;
  char *pcVar2;
  char *pcVar3;
  undefined1 *puVar4;
  byte *pbVar5;
  byte *pbVar6;
  bool bVar7;
  undefined1 in_FramePointer1_00000000;
  undefined1 in_FramePointer1_0000fffe;
  
  puVar4 = (undefined1 *)CONCAT11(in_FramePointer1_00000000,in_FramePointer1_0000fffe);
  pbVar6 = puVar4 + 1;
  *puVar4 = 0;
  puVar4[1] = 0;
  bVar7 = false;
  pcVar2 = &FramePointer10x0003;
  while( true ) {
    pcVar2[-1] = *pcVar2 << 1 | bVar7;
    pbVar5 = pbVar6 + -1;
    cVar1 = *pbVar6;
    *pbVar6 = cVar1 << 1 | *pcVar2 < '\0';
    pbVar6[-1] = pbVar6[-1] << 1 | cVar1 < '\0';
    pcVar3 = pcVar2 + 4;
    bVar7 = pcVar2[3] != '\0';
    cVar1 = pcVar2[3] + -1;
    pcVar2[2] = cVar1;
    if (cVar1 == '\0') break;
    FUN_CODE_00c316();
    pbVar6 = pbVar5 + 1;
    *pbVar5 = *pbVar5;
    FUN_CODE_00c316();
    pcVar2 = pcVar3;
  }
  pcVar2[4] = 0xff;
  return 0xff;
}


// ===== 0x00c316 =====

undefined1 FUN_CODE_00c316(void)

{
  return 0;
}


// ===== 0x00c328 =====

char FUN_CODE_00c328(void)

{
  char cVar1;
  ushort uVar2;
  undefined1 *puVar3;
  undefined1 *puVar4;
  byte bVar5;
  BADSPACEBASE *in_FSR1;
  undefined1 *puVar6;
  undefined1 *puVar7;
  undefined1 *puVar8;
  short sVar9;
  char in_FramePointer1_00000003;
  char in_FramePointer1_00000006;
  undefined1 in_FramePointer1_0000fffd;
  undefined1 in_FramePointer1_0000ffff;
  
  puVar3 = (undefined1 *)CONCAT11(in_FramePointer1_0000ffff,in_FramePointer1_0000fffd);
  puVar7 = &FramePointer10x0006;
  puVar4 = puVar3;
  if (in_FramePointer1_00000003 < '\0') {
    puVar4 = puVar3 + 1;
    *puVar3 = 0x2d;
    puVar6 = &FramePointer10x000a;
    if (in_FramePointer1_00000006 == -1) {
      puVar6 = &FramePointer10x000c;
    }
    puVar7 = puVar6 + 2;
    puVar6[-2] = ~puVar6[-1];
  }
  *puVar7 = *puVar7;
  puVar7[1] = puVar7[1];
  puVar7[2] = puVar7[2];
  puVar7[3] = (byte)(puVar7 + 3) - 3;
  puVar7[4] = (char)((ushort)(puVar7 + 3) >> 8) + -1 + (2 < (byte)(puVar7 + 3));
  puVar7[4] = puVar7[4];
  puVar7[5] = puVar7[-2];
  puVar8 = puVar7 + 9;
  puVar7[7] = *puVar7;
  FUN_CODE_00c408();
  bVar5 = (byte)puVar8;
  uVar2 = (ushort)puVar8 >> 8;
  FUN_CODE_00c3e8();
  if ((char)uVar2 + -1 + (6 < bVar5) == '\0') {
    FUN_CODE_00c3e2();
    FUN_CODE_00c3e8();
    FUN_CODE_00c3e2();
  }
  else {
    FUN_CODE_00c3fe();
    FUN_CODE_00c3f4();
    FUN_CODE_00c3fe();
    FUN_CODE_00c3f4();
  }
  FUN_CODE_00c3fe();
  *puVar4 = 0;
  bVar5 = (byte)puVar8 - 7;
  cVar1 = (char)((ushort)puVar8 >> 8) + -1 + (6 < (byte)puVar8);
  sVar9 = CONCAT11(cVar1,bVar5);
  *(undefined1 *)(sVar9 + 1) = *(undefined1 *)(sVar9 + 1);
  *(undefined1 *)(sVar9 + 1) = *(undefined1 *)(sVar9 + 1);
  return cVar1 + -1 + (3 < bVar5);
}


// ===== 0x00c3e2 =====

byte FUN_CODE_00c3e2(void)

{
  byte in_FramePointer0_00000000;
  
  return in_FramePointer0_00000000 >> 4;
}


// ===== 0x00c3e8 =====

void FUN_CODE_00c3e8(void)

{
  return;
}


// ===== 0x00c3f4 =====

char FUN_CODE_00c3f4(void)

{
  byte in_FramePointer0_00000000;
  
  return (in_FramePointer0_00000000 >> 4) + 0x30;
}


// ===== 0x00c3fe =====

char FUN_CODE_00c3fe(void)

{
  byte in_FramePointer0_00000000;
  
  return (in_FramePointer0_00000000 & 0xf) + 0x30;
}


// ===== 0x00c408 =====

undefined1 FUN_CODE_00c408(void)

{
  char cVar1;
  char cVar2;
  BADSPACEBASE *in_FSR1;
  undefined1 *puVar3;
  undefined1 *puVar4;
  undefined1 *puVar5;
  byte *pbVar6;
  undefined1 *puVar7;
  byte *pbVar8;
  bool bVar9;
  undefined1 in_FramePointer1_0000fffd;
  undefined1 in_FramePointer1_0000ffff;
  
  puVar5 = (undefined1 *)CONCAT11(in_FramePointer1_0000ffff,in_FramePointer1_0000fffd);
  *puVar5 = 0;
  pbVar8 = puVar5 + 2;
  puVar5[1] = 0;
  puVar5[2] = 0;
  bVar9 = false;
  puVar3 = &FramePointer10x0003;
  while( true ) {
    puVar3[-2] = puVar3[-1] << 1 | bVar9;
    puVar3[1] = puVar3[2] << 1 | (char)puVar3[-1] < '\0';
    cVar1 = *pbVar8;
    *pbVar8 = cVar1 << 1 | (char)puVar3[2] < '\0';
    pbVar6 = pbVar8 + -2;
    cVar2 = pbVar8[-1];
    pbVar8[-1] = cVar2 << 1 | cVar1 < '\0';
    pbVar8[-2] = pbVar8[-2] << 1 | cVar2 < '\0';
    puVar4 = puVar3 + 6;
    bVar9 = puVar3[5] != '\0';
    cVar1 = puVar3[5] + -1;
    puVar3[4] = cVar1;
    if (cVar1 == '\0') break;
    FUN_CODE_00c44a();
    puVar7 = pbVar6 + 1;
    *pbVar6 = *pbVar6;
    FUN_CODE_00c44a();
    pbVar8 = puVar7 + 1;
    *puVar7 = *puVar7;
    FUN_CODE_00c44a();
    puVar3 = puVar4;
  }
  puVar3[6] = 0xff;
  return 0xff;
}


// ===== 0x00c44a =====

undefined1 FUN_CODE_00c44a(void)

{
  return 0;
}


// ===== 0x00c8e4 =====

undefined1 FUN_CODE_00c8e4(void)

{
  DAT_DATA_01d3 = 8;
  DAT_DATA_01d9 = 0;
  DAT_DATA_01d7 = FUN_CODE_00c9e6(0x27);
  return 0;
}


// ===== 0x00c8f6 =====

undefined1 FUN_CODE_00c8f6(void)

{
  BADSPACEBASE *in_FSR1;
  undefined1 *puVar1;
  undefined1 *puVar2;
  
  puVar1 = &FramePointer10x0001;
  FUN_CODE_00ca12();
  *puVar1 = 6;
  puVar2 = puVar1 + 2;
  puVar1[1] = 0xc6;
  DAT_DATA_0014 = FUN_CODE_009af0();
  if ((byte)puVar2 < 5) {
    *(undefined1 *)((ushort)puVar2 & 0xff00) = *(undefined1 *)((ushort)puVar2 & 0xff00);
  }
  return 0;
}


// ===== 0x00c9e6 =====

void FUN_CODE_00c9e6(void)

{
  BADSPACEBASE *in_FSR1;
  undefined1 *puVar1;
  
  puVar1 = &FramePointer10x0001;
  FUN_CODE_00d67e();
  *puVar1 = *puVar1;
  return;
}


// ===== 0x00ca12 =====

undefined1 FUN_CODE_00ca12(void)

{
  return 0;
}


// ===== 0x00cb86 =====

/* WARNING: Restarted to delay deadcode elimination for space: DATA */

void FUN_CODE_00cb86(void)

{
  byte bVar1;
  byte bVar2;
  undefined1 uVar3;
  char cVar4;
  BADSPACEBASE *in_FSR2;
  undefined1 *puVar5;
  undefined1 *puVar6;
  undefined1 *puVar7;
  byte unaff_BSR;
  BADSPACEBASE *in_FSR1;
  byte bVar8;
  bool bVar9;
  
  bVar8 = FUN_CODE_00cd96();
  *(undefined1 *)((ushort)unaff_BSR * 0x100 + 0xe9) = 0;
  puVar6 = (undefined1 *)in_FSR2;
LAB_CODE_00cb8a:
  *(undefined1 *)((ushort)unaff_BSR * 0x100 + 0xe7) = 0;
  bVar9 = true;
  puVar5 = puVar6;
  do {
    while( true ) {
      FUN_CODE_00ce04(bVar8);
      if (bVar9) goto LAB_CODE_00cbe2;
      if ((puVar5[-4] & 8) == 0) break;
LAB_CODE_00cbc6:
      puVar6 = puVar5 + 2;
      puVar7 = puVar5 + 2;
      if ((puVar5[-3] & 1) == 0) {
        bVar8 = FUN_CODE_00cd48(puVar5[2]);
        bVar8 = bVar8 & 0xf;
        puVar6 = puVar7;
      }
      else {
        FUN_CODE_00cd48(puVar5[2]);
        bVar8 = FUN_CODE_00cda0();
      }
      unaff_BSR = 1;
      DAT_DATA_01e7 = DAT_DATA_01e7 + bVar8;
LAB_CODE_00cbde:
      cVar4 = *(char *)((ushort)unaff_BSR * 0x100 + 0xe7) + '\x01';
      *(char *)((ushort)unaff_BSR * 0x100 + 0xe7) = cVar4;
      bVar9 = cVar4 == '\0';
      puVar5 = puVar6;
    }
    if (puVar5[1] == '\n') break;
    if (puVar5[1] != '\b') {
      bVar8 = 0;
      puVar6 = puVar5 + 1;
      if ((puVar5[1] != '\r') && (bVar8 = 0, puVar6 = puVar5 + 1, puVar5[1] != '\t'))
      goto LAB_CODE_00cbc6;
      goto LAB_CODE_00cbde;
    }
    bVar8 = 0xfb;
    bVar1 = puVar5[-3];
    puVar5[-3] = ~(bVar1 & 1) | bVar1 & 0xfe;
    bVar9 = true;
    puVar5 = puVar5 + 2;
  } while( true );
  if ((puVar5[-3] & 0x10) != 0) {
LAB_CODE_00cbe2:
    if (*(byte *)((ushort)unaff_BSR * 0x100 + 0xe9) < *(byte *)((ushort)unaff_BSR * 0x100 + 0xe7)) {
      DAT_DATA_01e9 = DAT_DATA_01e7;
    }
    uVar3 = *(undefined1 *)((ushort)unaff_BSR * 0x100 + 0xe9);
    *(undefined1 *)in_FSR1 = *(undefined1 *)in_FSR1;
    FUN_CODE_00cd24(uVar3);
    return;
  }
  bVar1 = *(byte *)((ushort)unaff_BSR * 0x100 + 0xe7);
  bVar2 = *(byte *)((ushort)unaff_BSR * 0x100 + 0xe9);
  bVar8 = bVar2 - bVar1;
  puVar6 = puVar5 + 2;
  if (bVar2 < bVar1) {
    DAT_DATA_01e9 = DAT_DATA_01e7;
    puVar6 = puVar5 + 2;
  }
  goto LAB_CODE_00cb8a;
}


// ===== 0x00cb8a =====

/* WARNING: Restarted to delay deadcode elimination for space: DATA */

void FUN_CODE_00cb86(void)

{
  byte bVar1;
  byte bVar2;
  undefined1 uVar3;
  char cVar4;
  BADSPACEBASE *in_FSR2;
  undefined1 *puVar5;
  undefined1 *puVar6;
  undefined1 *puVar7;
  byte unaff_BSR;
  BADSPACEBASE *in_FSR1;
  byte bVar8;
  bool bVar9;
  
  bVar8 = FUN_CODE_00cd96();
  *(undefined1 *)((ushort)unaff_BSR * 0x100 + 0xe9) = 0;
  puVar6 = (undefined1 *)in_FSR2;
LAB_CODE_00cb8a:
  *(undefined1 *)((ushort)unaff_BSR * 0x100 + 0xe7) = 0;
  bVar9 = true;
  puVar5 = puVar6;
  do {
    while( true ) {
      FUN_CODE_00ce04(bVar8);
      if (bVar9) goto LAB_CODE_00cbe2;
      if ((puVar5[-4] & 8) == 0) break;
LAB_CODE_00cbc6:
      puVar6 = puVar5 + 2;
      puVar7 = puVar5 + 2;
      if ((puVar5[-3] & 1) == 0) {
        bVar8 = FUN_CODE_00cd48(puVar5[2]);
        bVar8 = bVar8 & 0xf;
        puVar6 = puVar7;
      }
      else {
        FUN_CODE_00cd48(puVar5[2]);
        bVar8 = FUN_CODE_00cda0();
      }
      unaff_BSR = 1;
      DAT_DATA_01e7 = DAT_DATA_01e7 + bVar8;
LAB_CODE_00cbde:
      cVar4 = *(char *)((ushort)unaff_BSR * 0x100 + 0xe7) + '\x01';
      *(char *)((ushort)unaff_BSR * 0x100 + 0xe7) = cVar4;
      bVar9 = cVar4 == '\0';
      puVar5 = puVar6;
    }
    if (puVar5[1] == '\n') break;
    if (puVar5[1] != '\b') {
      bVar8 = 0;
      puVar6 = puVar5 + 1;
      if ((puVar5[1] != '\r') && (bVar8 = 0, puVar6 = puVar5 + 1, puVar5[1] != '\t'))
      goto LAB_CODE_00cbc6;
      goto LAB_CODE_00cbde;
    }
    bVar8 = 0xfb;
    bVar1 = puVar5[-3];
    puVar5[-3] = ~(bVar1 & 1) | bVar1 & 0xfe;
    bVar9 = true;
    puVar5 = puVar5 + 2;
  } while( true );
  if ((puVar5[-3] & 0x10) != 0) {
LAB_CODE_00cbe2:
    if (*(byte *)((ushort)unaff_BSR * 0x100 + 0xe9) < *(byte *)((ushort)unaff_BSR * 0x100 + 0xe7)) {
      DAT_DATA_01e9 = DAT_DATA_01e7;
    }
    uVar3 = *(undefined1 *)((ushort)unaff_BSR * 0x100 + 0xe9);
    *(undefined1 *)in_FSR1 = *(undefined1 *)in_FSR1;
    FUN_CODE_00cd24(uVar3);
    return;
  }
  bVar1 = *(byte *)((ushort)unaff_BSR * 0x100 + 0xe7);
  bVar2 = *(byte *)((ushort)unaff_BSR * 0x100 + 0xe9);
  bVar8 = bVar2 - bVar1;
  puVar6 = puVar5 + 2;
  if (bVar2 < bVar1) {
    DAT_DATA_01e9 = DAT_DATA_01e7;
    puVar6 = puVar5 + 2;
  }
  goto LAB_CODE_00cb8a;
}


// ===== 0x00cbc6 =====

/* WARNING: Restarted to delay deadcode elimination for space: DATA */

void FUN_CODE_00cb86(void)

{
  byte bVar1;
  byte bVar2;
  undefined1 uVar3;
  char cVar4;
  BADSPACEBASE *in_FSR2;
  undefined1 *puVar5;
  undefined1 *puVar6;
  undefined1 *puVar7;
  byte unaff_BSR;
  BADSPACEBASE *in_FSR1;
  byte bVar8;
  bool bVar9;
  
  bVar8 = FUN_CODE_00cd96();
  *(undefined1 *)((ushort)unaff_BSR * 0x100 + 0xe9) = 0;
  puVar6 = (undefined1 *)in_FSR2;
LAB_CODE_00cb8a:
  *(undefined1 *)((ushort)unaff_BSR * 0x100 + 0xe7) = 0;
  bVar9 = true;
  puVar5 = puVar6;
  do {
    while( true ) {
      FUN_CODE_00ce04(bVar8);
      if (bVar9) goto LAB_CODE_00cbe2;
      if ((puVar5[-4] & 8) == 0) break;
LAB_CODE_00cbc6:
      puVar6 = puVar5 + 2;
      puVar7 = puVar5 + 2;
      if ((puVar5[-3] & 1) == 0) {
        bVar8 = FUN_CODE_00cd48(puVar5[2]);
        bVar8 = bVar8 & 0xf;
        puVar6 = puVar7;
      }
      else {
        FUN_CODE_00cd48(puVar5[2]);
        bVar8 = FUN_CODE_00cda0();
      }
      unaff_BSR = 1;
      DAT_DATA_01e7 = DAT_DATA_01e7 + bVar8;
LAB_CODE_00cbde:
      cVar4 = *(char *)((ushort)unaff_BSR * 0x100 + 0xe7) + '\x01';
      *(char *)((ushort)unaff_BSR * 0x100 + 0xe7) = cVar4;
      bVar9 = cVar4 == '\0';
      puVar5 = puVar6;
    }
    if (puVar5[1] == '\n') break;
    if (puVar5[1] != '\b') {
      bVar8 = 0;
      puVar6 = puVar5 + 1;
      if ((puVar5[1] != '\r') && (bVar8 = 0, puVar6 = puVar5 + 1, puVar5[1] != '\t'))
      goto LAB_CODE_00cbc6;
      goto LAB_CODE_00cbde;
    }
    bVar8 = 0xfb;
    bVar1 = puVar5[-3];
    puVar5[-3] = ~(bVar1 & 1) | bVar1 & 0xfe;
    bVar9 = true;
    puVar5 = puVar5 + 2;
  } while( true );
  if ((puVar5[-3] & 0x10) != 0) {
LAB_CODE_00cbe2:
    if (*(byte *)((ushort)unaff_BSR * 0x100 + 0xe9) < *(byte *)((ushort)unaff_BSR * 0x100 + 0xe7)) {
      DAT_DATA_01e9 = DAT_DATA_01e7;
    }
    uVar3 = *(undefined1 *)((ushort)unaff_BSR * 0x100 + 0xe9);
    *(undefined1 *)in_FSR1 = *(undefined1 *)in_FSR1;
    FUN_CODE_00cd24(uVar3);
    return;
  }
  bVar1 = *(byte *)((ushort)unaff_BSR * 0x100 + 0xe7);
  bVar2 = *(byte *)((ushort)unaff_BSR * 0x100 + 0xe9);
  bVar8 = bVar2 - bVar1;
  puVar6 = puVar5 + 2;
  if (bVar2 < bVar1) {
    DAT_DATA_01e9 = DAT_DATA_01e7;
    puVar6 = puVar5 + 2;
  }
  goto LAB_CODE_00cb8a;
}


// ===== 0x00cbde =====

/* WARNING: Restarted to delay deadcode elimination for space: DATA */

void FUN_CODE_00cb86(void)

{
  byte bVar1;
  byte bVar2;
  undefined1 uVar3;
  char cVar4;
  BADSPACEBASE *in_FSR2;
  undefined1 *puVar5;
  undefined1 *puVar6;
  undefined1 *puVar7;
  byte unaff_BSR;
  BADSPACEBASE *in_FSR1;
  byte bVar8;
  bool bVar9;
  
  bVar8 = FUN_CODE_00cd96();
  *(undefined1 *)((ushort)unaff_BSR * 0x100 + 0xe9) = 0;
  puVar6 = (undefined1 *)in_FSR2;
LAB_CODE_00cb8a:
  *(undefined1 *)((ushort)unaff_BSR * 0x100 + 0xe7) = 0;
  bVar9 = true;
  puVar5 = puVar6;
  do {
    while( true ) {
      FUN_CODE_00ce04(bVar8);
      if (bVar9) goto LAB_CODE_00cbe2;
      if ((puVar5[-4] & 8) == 0) break;
LAB_CODE_00cbc6:
      puVar6 = puVar5 + 2;
      puVar7 = puVar5 + 2;
      if ((puVar5[-3] & 1) == 0) {
        bVar8 = FUN_CODE_00cd48(puVar5[2]);
        bVar8 = bVar8 & 0xf;
        puVar6 = puVar7;
      }
      else {
        FUN_CODE_00cd48(puVar5[2]);
        bVar8 = FUN_CODE_00cda0();
      }
      unaff_BSR = 1;
      DAT_DATA_01e7 = DAT_DATA_01e7 + bVar8;
LAB_CODE_00cbde:
      cVar4 = *(char *)((ushort)unaff_BSR * 0x100 + 0xe7) + '\x01';
      *(char *)((ushort)unaff_BSR * 0x100 + 0xe7) = cVar4;
      bVar9 = cVar4 == '\0';
      puVar5 = puVar6;
    }
    if (puVar5[1] == '\n') break;
    if (puVar5[1] != '\b') {
      bVar8 = 0;
      puVar6 = puVar5 + 1;
      if ((puVar5[1] != '\r') && (bVar8 = 0, puVar6 = puVar5 + 1, puVar5[1] != '\t'))
      goto LAB_CODE_00cbc6;
      goto LAB_CODE_00cbde;
    }
    bVar8 = 0xfb;
    bVar1 = puVar5[-3];
    puVar5[-3] = ~(bVar1 & 1) | bVar1 & 0xfe;
    bVar9 = true;
    puVar5 = puVar5 + 2;
  } while( true );
  if ((puVar5[-3] & 0x10) != 0) {
LAB_CODE_00cbe2:
    if (*(byte *)((ushort)unaff_BSR * 0x100 + 0xe9) < *(byte *)((ushort)unaff_BSR * 0x100 + 0xe7)) {
      DAT_DATA_01e9 = DAT_DATA_01e7;
    }
    uVar3 = *(undefined1 *)((ushort)unaff_BSR * 0x100 + 0xe9);
    *(undefined1 *)in_FSR1 = *(undefined1 *)in_FSR1;
    FUN_CODE_00cd24(uVar3);
    return;
  }
  bVar1 = *(byte *)((ushort)unaff_BSR * 0x100 + 0xe7);
  bVar2 = *(byte *)((ushort)unaff_BSR * 0x100 + 0xe9);
  bVar8 = bVar2 - bVar1;
  puVar6 = puVar5 + 2;
  if (bVar2 < bVar1) {
    DAT_DATA_01e9 = DAT_DATA_01e7;
    puVar6 = puVar5 + 2;
  }
  goto LAB_CODE_00cb8a;
}


// ===== 0x00cbe2 =====

/* WARNING: Restarted to delay deadcode elimination for space: DATA */

void FUN_CODE_00cb86(void)

{
  byte bVar1;
  byte bVar2;
  undefined1 uVar3;
  char cVar4;
  BADSPACEBASE *in_FSR2;
  undefined1 *puVar5;
  undefined1 *puVar6;
  undefined1 *puVar7;
  byte unaff_BSR;
  BADSPACEBASE *in_FSR1;
  byte bVar8;
  bool bVar9;
  
  bVar8 = FUN_CODE_00cd96();
  *(undefined1 *)((ushort)unaff_BSR * 0x100 + 0xe9) = 0;
  puVar6 = (undefined1 *)in_FSR2;
LAB_CODE_00cb8a:
  *(undefined1 *)((ushort)unaff_BSR * 0x100 + 0xe7) = 0;
  bVar9 = true;
  puVar5 = puVar6;
  do {
    while( true ) {
      FUN_CODE_00ce04(bVar8);
      if (bVar9) goto LAB_CODE_00cbe2;
      if ((puVar5[-4] & 8) == 0) break;
LAB_CODE_00cbc6:
      puVar6 = puVar5 + 2;
      puVar7 = puVar5 + 2;
      if ((puVar5[-3] & 1) == 0) {
        bVar8 = FUN_CODE_00cd48(puVar5[2]);
        bVar8 = bVar8 & 0xf;
        puVar6 = puVar7;
      }
      else {
        FUN_CODE_00cd48(puVar5[2]);
        bVar8 = FUN_CODE_00cda0();
      }
      unaff_BSR = 1;
      DAT_DATA_01e7 = DAT_DATA_01e7 + bVar8;
LAB_CODE_00cbde:
      cVar4 = *(char *)((ushort)unaff_BSR * 0x100 + 0xe7) + '\x01';
      *(char *)((ushort)unaff_BSR * 0x100 + 0xe7) = cVar4;
      bVar9 = cVar4 == '\0';
      puVar5 = puVar6;
    }
    if (puVar5[1] == '\n') break;
    if (puVar5[1] != '\b') {
      bVar8 = 0;
      puVar6 = puVar5 + 1;
      if ((puVar5[1] != '\r') && (bVar8 = 0, puVar6 = puVar5 + 1, puVar5[1] != '\t'))
      goto LAB_CODE_00cbc6;
      goto LAB_CODE_00cbde;
    }
    bVar8 = 0xfb;
    bVar1 = puVar5[-3];
    puVar5[-3] = ~(bVar1 & 1) | bVar1 & 0xfe;
    bVar9 = true;
    puVar5 = puVar5 + 2;
  } while( true );
  if ((puVar5[-3] & 0x10) != 0) {
LAB_CODE_00cbe2:
    if (*(byte *)((ushort)unaff_BSR * 0x100 + 0xe9) < *(byte *)((ushort)unaff_BSR * 0x100 + 0xe7)) {
      DAT_DATA_01e9 = DAT_DATA_01e7;
    }
    uVar3 = *(undefined1 *)((ushort)unaff_BSR * 0x100 + 0xe9);
    *(undefined1 *)in_FSR1 = *(undefined1 *)in_FSR1;
    FUN_CODE_00cd24(uVar3);
    return;
  }
  bVar1 = *(byte *)((ushort)unaff_BSR * 0x100 + 0xe7);
  bVar2 = *(byte *)((ushort)unaff_BSR * 0x100 + 0xe9);
  bVar8 = bVar2 - bVar1;
  puVar6 = puVar5 + 2;
  if (bVar2 < bVar1) {
    DAT_DATA_01e9 = DAT_DATA_01e7;
    puVar6 = puVar5 + 2;
  }
  goto LAB_CODE_00cb8a;
}


// ===== 0x00cbf2 =====

void FUN_CODE_00cbf2(void)

{
  undefined1 uVar1;
  char cVar2;
  BADSPACEBASE *in_FSR2;
  byte unaff_BSR;
  BADSPACEBASE *in_FSR1;
  char cVar3;
  byte unaff_Z;
  
  FUN_CODE_00cd96();
  cVar3 = '\x01';
  *(undefined1 *)((ushort)unaff_BSR * 0x100 + 0xe9) = 1;
  while( true ) {
    FUN_CODE_00ce04(cVar3);
    if ((unaff_Z & 1) != 0) break;
    cVar3 = *(char *)in_FSR2 + -10;
    unaff_Z = 0;
    if (cVar3 == '\0') {
      cVar2 = *(char *)((ushort)unaff_BSR * 0x100 + 0xe9) + '\x01';
      *(char *)((ushort)unaff_BSR * 0x100 + 0xe9) = cVar2;
      unaff_Z = cVar2 == '\0';
    }
  }
  uVar1 = *(undefined1 *)((ushort)unaff_BSR * 0x100 + 0xe9);
  *(undefined1 *)in_FSR1 = *(undefined1 *)in_FSR1;
  FUN_CODE_00cd24(uVar1);
  return;
}


// ===== 0x00cc0c =====

void FUN_CODE_00cc0c(void)

{
  BADSPACEBASE *in_FSR2;
  BADSPACEBASE *in_FSR1;
  byte *pbVar1;
  
  FUN_CODE_00cdd2();
  *(byte *)in_FSR1 = *(byte *)((short)in_FSR2 + -4) | 0x10;
  *(undefined1 *)((short)in_FSR1 + 1) = *(undefined1 *)((short)in_FSR2 + -2);
  pbVar1 = (byte *)((short)in_FSR1 + 3);
  *(undefined1 *)((short)in_FSR1 + 2) = *(undefined1 *)in_FSR2;
  FUN_CODE_00cb86();
  *pbVar1 = *pbVar1;
  pbVar1[-1] = pbVar1[-1];
  pbVar1[-2] = pbVar1[-2];
  FUN_CODE_00cd24();
  return;
}


// ===== 0x00cc2c =====

void FUN_CODE_00cc2c(void)

{
  byte bVar1;
  BADSPACEBASE *in_FSR2;
  BADSPACEBASE *in_FSR1;
  undefined1 *puVar2;
  byte bVar3;
  bool bVar4;
  
  FUN_CODE_00cdd2();
  if ((*(byte *)((short)in_FSR2 + -2) & 0x20) != 0) {
    DAT_DATA_0014 = DAT_DATA_01ea;
    bVar1 = DAT_DATA_01ea + 1;
    bVar4 = (char)DAT_DATA_01ea < '\0';
    bVar3 = DAT_DATA_01ea << 1 | 0xfe < DAT_DATA_01ea;
    DAT_DATA_01ea = bVar1;
    if ((bVar4) || (bVar3 = bVar1 - DAT_DATA_01eb, DAT_DATA_01eb <= bVar1)) goto LAB_CODE_00cc58;
  }
  if ((*(byte *)((short)in_FSR2 + -1) & 0x80) == 0) {
    *(undefined1 *)in_FSR1 = 0;
  }
  else {
    *(undefined1 *)in_FSR1 = 0xff;
  }
  puVar2 = (undefined1 *)((short)in_FSR1 + 1);
  bVar3 = FUN_CODE_00cefe();
  *puVar2 = *puVar2;
LAB_CODE_00cc58:
  FUN_CODE_00cd24(bVar3);
  return;
}


// ===== 0x00cc58 =====

void FUN_CODE_00cc2c(void)

{
  byte bVar1;
  BADSPACEBASE *in_FSR2;
  BADSPACEBASE *in_FSR1;
  undefined1 *puVar2;
  byte bVar3;
  bool bVar4;
  
  FUN_CODE_00cdd2();
  if ((*(byte *)((short)in_FSR2 + -2) & 0x20) != 0) {
    DAT_DATA_0014 = DAT_DATA_01ea;
    bVar1 = DAT_DATA_01ea + 1;
    bVar4 = (char)DAT_DATA_01ea < '\0';
    bVar3 = DAT_DATA_01ea << 1 | 0xfe < DAT_DATA_01ea;
    DAT_DATA_01ea = bVar1;
    if ((bVar4) || (bVar3 = bVar1 - DAT_DATA_01eb, DAT_DATA_01eb <= bVar1)) goto LAB_CODE_00cc58;
  }
  if ((*(byte *)((short)in_FSR2 + -1) & 0x80) == 0) {
    *(undefined1 *)in_FSR1 = 0;
  }
  else {
    *(undefined1 *)in_FSR1 = 0xff;
  }
  puVar2 = (undefined1 *)((short)in_FSR1 + 1);
  bVar3 = FUN_CODE_00cefe();
  *puVar2 = *puVar2;
LAB_CODE_00cc58:
  FUN_CODE_00cd24(bVar3);
  return;
}


// ===== 0x00cc5a =====

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


// ===== 0x00cc90 =====

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


// ===== 0x00cd24 =====

void FUN_CODE_00cd24(void)

{
  return;
}


// ===== 0x00cd30 =====

undefined1 FUN_CODE_00cd30(void)

{
  return 0;
}


// ===== 0x00cd48 =====

undefined1 FUN_CODE_00cd48(byte param_1)

{
  undefined3 in_TBLPTR;
  
  return *(undefined1 *)
          CONCAT12((char)((uint3)in_TBLPTR >> 0x10),
                   CONCAT11((0x1f < param_1) + -0x7a,param_1 - 0x20));
}


// ===== 0x00cd7c =====

undefined1 FUN_CODE_00cd7c(void)

{
  byte unaff_BSR;
  byte bVar1;
  byte in_FramePointer2_0000fffe;
  
  bVar1 = (byte)((ushort)in_FramePointer2_0000fffe * 7);
  DAT_DATA_0014 = bVar1 - 0x20;
  DAT_DATA_0015 = (char)((ushort)in_FramePointer2_0000fffe * 7 >> 8) + '\x7f' + (0x1f < bVar1);
  return *(undefined1 *)((ushort)unaff_BSR * 0x100 + 0xe7);
}


// ===== 0x00cd96 =====

void FUN_CODE_00cd96(void)

{
  BADSPACEBASE *in_FSR1;
  
  FUN_CODE_00cdd2();
  *(undefined1 *)in_FSR1 = *(undefined1 *)in_FSR1;
  DAT_DATA_01e8 = 0;
  return;
}


// ===== 0x00cda0 =====

byte FUN_CODE_00cda0(byte param_1)

{
  return param_1 >> 4;
}


// ===== 0x00cdd2 =====

void FUN_CODE_00cdd2(void)

{
  return;
}


// ===== 0x00cdec =====

void FUN_CODE_00cdec(void)

{
  undefined1 in_FramePointer2_0000fffe;
  
  FUN_CODE_00cd48(in_FramePointer2_0000fffe);
  return;
}


// ===== 0x00ce04 =====

undefined1 FUN_CODE_00ce04(void)

{
  undefined1 uVar1;
  BADSPACEBASE *in_FSR2;
  byte unaff_BSR;
  BADSPACEBASE *in_FSR0;
  
  uVar1 = *(undefined1 *)((ushort)unaff_BSR * 0x100 + 0xe8);
  *(char *)((ushort)unaff_BSR * 0x100 + 0xe8) = *(char *)((ushort)unaff_BSR * 0x100 + 0xe8) + '\x01'
  ;
  FUN_CODE_00cd30(uVar1);
  *(undefined1 *)in_FSR2 = *(undefined1 *)in_FSR0;
  return *(undefined1 *)in_FSR2;
}


// ===== 0x00ce26 =====

/* WARNING: Instruction at (CODE,0x00ce3a) overlaps instruction at (CODE,0x00ce38)
    */

undefined1 FUN_CODE_00ce26(void)

{
  char cVar1;
  
  for (DAT_DATA_01f0 = 'F'; DAT_DATA_01f0 != '\0'; DAT_DATA_01f0 = DAT_DATA_01f0 + -1) {
    cVar1 = '<';
    do {
      cVar1 = cVar1 + -1;
    } while (cVar1 != '\0');
  }
  return 0;
}


// ===== 0x00ce44 =====

/* WARNING: Instruction at (CODE,0x00ce50) overlaps instruction at (CODE,0x00ce4e)
    */

undefined1 FUN_CODE_00ce44(void)

{
  byte bVar1;
  BADSPACEBASE *in_FSR1;
  undefined1 *puVar2;
  undefined1 *puVar3;
  undefined1 *puVar4;
  char cVar5;
  
  bVar1 = TRISE;
  TRISE = bVar1 & 0xc0;
  bVar1 = PORTE;
  PORTE = bVar1 & 0xef;
  cVar5 = '\x04';
  do {
    cVar5 = cVar5 + -1;
  } while (cVar5 != '\0');
  cVar5 = '\x04';
  do {
    cVar5 = cVar5 + -1;
  } while (cVar5 != '\0');
  bVar1 = PORTE;
  PORTE = bVar1 | 0x10;
  FUN_CODE_00ce26();
  bVar1 = TRISE;
  TRISE = bVar1 & 0xc0;
  TRISD = 0;
  bVar1 = PORTE;
  PORTE = bVar1 | 0x20;
  bVar1 = PORTE;
  PORTE = bVar1 & 0xfe;
  bVar1 = PORTE;
  PORTE = bVar1 | 2;
  bVar1 = PORTE;
  PORTE = bVar1 | 4;
  puVar2 = (undefined1 *)((short)in_FSR1 + 1);
  *(undefined1 *)in_FSR1 = 0xe2;
  FUN_CODE_00cece();
  *puVar2 = *puVar2;
  puVar2[-1] = 0xa3;
  FUN_CODE_00cece();
  *puVar2 = *puVar2;
  puVar2[-1] = 0x2f;
  FUN_CODE_00cece();
  *puVar2 = *puVar2;
  puVar2[-1] = 0x25;
  FUN_CODE_00cece();
  *puVar2 = *puVar2;
  puVar2[-1] = 0x81;
  FUN_CODE_00cece();
  *puVar2 = *puVar2;
  puVar2[-1] = 0x3f;
  FUN_CODE_00cece();
  *puVar2 = *puVar2;
  puVar2[-1] = 0xa0;
  FUN_CODE_00cece();
  *puVar2 = *puVar2;
  puVar2[-1] = 0xc0;
  FUN_CODE_00cece();
  *puVar2 = *puVar2;
  puVar2[-1] = 0x40;
  FUN_CODE_00cece();
  puVar3 = puVar2 + -1;
  *puVar2 = *puVar2;
  FUN_CODE_00ce26();
  FUN_CODE_00ce26();
  puVar4 = puVar3 + 1;
  *puVar3 = 0xa4;
  FUN_CODE_00cece();
  *puVar4 = *puVar4;
  puVar4[-1] = 0xaf;
  FUN_CODE_00cece();
  *puVar4 = *puVar4;
  return 0;
}


// ===== 0x00cece =====

undefined1 FUN_CODE_00cece(void)

{
  undefined1 uVar1;
  byte bVar2;
  BADSPACEBASE *in_FSR1;
  
  TRISD = 0;
  bVar2 = PORTE;
  PORTE = bVar2 & 0xf7;
  bVar2 = PORTE;
  PORTE = bVar2 & 0xdf;
  bVar2 = PORTE;
  PORTE = bVar2 & 0xfb;
  uVar1 = *(undefined1 *)
           (CONCAT11((char)((ushort)&FramePointer10x0002 >> 8),(char)&FramePointer10x0002) + -2);
  PORTD = uVar1;
  bVar2 = PORTE;
  PORTE = bVar2 | 4;
  bVar2 = PORTE;
  PORTE = bVar2 | 0x20;
  return uVar1;
}


// ===== 0x00cefe =====

undefined1 FUN_CODE_00cefe(void)

{
  undefined1 uVar1;
  byte bVar2;
  BADSPACEBASE *in_FSR1;
  
  TRISD = 0;
  bVar2 = PORTE;
  PORTE = bVar2 | 8;
  bVar2 = PORTE;
  PORTE = bVar2 & 0xdf;
  bVar2 = PORTE;
  PORTE = bVar2 & 0xfb;
  uVar1 = *(undefined1 *)
           (CONCAT11((char)((ushort)&FramePointer10x0002 >> 8),(char)&FramePointer10x0002) + -2);
  PORTD = uVar1;
  bVar2 = PORTE;
  PORTE = bVar2 | 4;
  bVar2 = PORTE;
  PORTE = bVar2 | 0x20;
  return uVar1;
}


// ===== 0x00cf2e =====

void FUN_CODE_00cf2e(void)

{
  BADSPACEBASE *in_FSR2;
  undefined1 *puVar1;
  BADSPACEBASE *in_FSR1;
  char *pcVar2;
  char cVar3;
  char *in_TBLPTR;
  undefined1 uVar4;
  
  FUN_CODE_00d11e();
  do {
    *(char *)((short)in_FSR2 + -2) = *(char *)((short)in_FSR2 + -1) + '\x01';
    puVar1 = (undefined1 *)((short)in_FSR2 + 4);
    uVar4 = (undefined1)((uint3)in_TBLPTR >> 0x10);
    in_TBLPTR = (char *)CONCAT12(uVar4,CONCAT11(*(undefined1 *)((short)in_FSR2 + 1),
                                                *(undefined1 *)((short)in_FSR2 + -3)));
    if (*(char *)((short)in_FSR2 + -1) == -1) {
      puVar1 = (undefined1 *)((short)in_FSR2 + 6);
      *(char *)((short)in_FSR2 + 2) = *(char *)((short)in_FSR2 + 3) + '\x01';
    }
    DAT_DATA_01f0 = *in_TBLPTR;
    if (DAT_DATA_01f0 == '\0') {
      in_FSR2 = (BADSPACEBASE *)(puVar1 + 2);
      in_TBLPTR = (char *)CONCAT12(uVar4,CONCAT11(puVar1[-1],puVar1[-3]));
      cVar3 = *in_TBLPTR;
      if (cVar3 == '\0') {
        FUN_CODE_00d130(0);
        return;
      }
      *(undefined1 *)in_FSR1 = 0;
    }
    else {
      *(char *)in_FSR1 = DAT_DATA_01f0;
      in_FSR2 = (BADSPACEBASE *)puVar1;
      cVar3 = DAT_DATA_01f0;
    }
    pcVar2 = (char *)((short)in_FSR1 + 1);
    FUN_CODE_00cefe(cVar3);
    in_FSR1 = (BADSPACEBASE *)(pcVar2 + -1);
    *pcVar2 = *pcVar2;
  } while( true );
}


// ===== 0x00cf6e =====

/* WARNING: Restarted to delay deadcode elimination for space: DATA */

void FUN_CODE_00cf6e(void)

{
  BADSPACEBASE *in_FSR2;
  undefined1 *puVar1;
  undefined1 *puVar2;
  BADSPACEBASE *in_FSR1;
  undefined1 *puVar3;
  
  FUN_CODE_00d11e();
  DAT_DATA_01f0 = *(char *)((short)in_FSR2 + -3);
  puVar1 = (undefined1 *)((short)in_FSR2 + 1);
  while( true ) {
    if (DAT_DATA_01f0 == '\0') break;
    puVar3 = (undefined1 *)((short)in_FSR1 + 1);
    puVar2 = puVar1 + 1;
    *(undefined1 *)in_FSR1 = puVar1[-2];
    DAT_DATA_01f0 = DAT_DATA_01f0 + -1;
    FUN_CODE_00cefe();
    in_FSR1 = (BADSPACEBASE *)(puVar3 + -1);
    *puVar3 = *puVar3;
    puVar1 = puVar2;
  }
  DAT_DATA_01f0 = DAT_DATA_01f0 + -1;
  FUN_CODE_00d130(0);
  return;
}


// ===== 0x00cfc6 =====

void FUN_CODE_00cfc6(void)

{
  BADSPACEBASE *in_FSR2;
  BADSPACEBASE *in_FSR1;
  undefined1 *puVar1;
  byte bVar2;
  
  bVar2 = FUN_CODE_00d16c();
  FUN_CODE_00d15c(bVar2 | 0xb0);
  puVar1 = (undefined1 *)((short)in_FSR1 + 1);
  *(undefined1 *)in_FSR1 = *(undefined1 *)((short)in_FSR2 + -3);
  FUN_CODE_00cfd8();
  *puVar1 = *puVar1;
  FUN_CODE_00d130();
  return;
}


// ===== 0x00cfd8 =====

void FUN_CODE_00cfd8(void)

{
  BADSPACEBASE *in_FSR2;
  byte bVar1;
  
  bVar1 = FUN_CODE_00d16c();
  FUN_CODE_00d15c(bVar1 >> 4 | 0x10);
  FUN_CODE_00d15c(*(byte *)((short)in_FSR2 + -2) & 0xf);
  FUN_CODE_00d130();
  return;
}


// ===== 0x00cfee =====

/* WARNING: Restarted to delay deadcode elimination for space: DATA */

void FUN_CODE_00cfee(void)

{
  BADSPACEBASE *in_FSR1;
  byte *pbVar1;
  
  DAT_DATA_01f2 = 0;
  while( true ) {
    if (7 < DAT_DATA_01f2) break;
    pbVar1 = (byte *)((short)in_FSR1 + 1);
    *(undefined1 *)in_FSR1 = 0;
    in_FSR1 = (BADSPACEBASE *)((short)in_FSR1 + 2);
    *pbVar1 = DAT_DATA_01f2;
    FUN_CODE_00d154('\a' - DAT_DATA_01f2);
    FUN_CODE_00d144(0x80);
  }
  return;
}


// ===== 0x00d008 =====

void FUN_CODE_00d008(void)

{
  BADSPACEBASE *in_FSR2;
  char *pcVar1;
  char *pcVar2;
  char *pcVar3;
  BADSPACEBASE *in_FSR1;
  char *pcVar4;
  byte bVar5;
  char cVar6;
  
  bVar5 = FUN_CODE_00d16c();
  cVar6 = '\a' - bVar5;
  if (bVar5 < 8) {
    cVar6 = '\x7f' - *(byte *)((short)in_FSR2 + -4);
    if (*(byte *)((short)in_FSR2 + -4) < 0x80) {
      *(char *)in_FSR1 = *(char *)((short)in_FSR2 + -2);
      pcVar1 = (char *)((short)in_FSR2 + 3);
      cVar6 = *(char *)in_FSR2;
      *(char *)((short)in_FSR1 + 1) = *(char *)((short)in_FSR1 + 1);
      if (8 < (byte)(*(char *)in_FSR1 + cVar6)) {
        *(char *)in_FSR1 = *(char *)((short)in_FSR2 + 1);
        *(char *)((short)in_FSR1 + 1) = *(char *)((short)in_FSR1 + 1);
        *(char *)in_FSR1 = '\t' - *(char *)in_FSR1;
        pcVar1 = (char *)((short)in_FSR2 + 5);
        *(char *)((short)in_FSR2 + 1) = *(char *)in_FSR1;
      }
      *(char *)in_FSR1 = pcVar1[-5];
      pcVar3 = pcVar1 + 2;
      cVar6 = pcVar1[-3];
      *(char *)((short)in_FSR1 + 1) = *(char *)((short)in_FSR1 + 1);
      if (0x7f < (byte)(*(char *)in_FSR1 + cVar6)) {
        *(char *)in_FSR1 = pcVar1[-2];
        *(char *)((short)in_FSR1 + 1) = *(char *)((short)in_FSR1 + 1);
        *(char *)in_FSR1 = -0x7f - *(char *)in_FSR1;
        pcVar3 = pcVar1 + 4;
        pcVar1[-2] = *(undefined1 *)in_FSR1;
      }
      DAT_DATA_01f2 = 0;
      while( true ) {
        cVar6 = DAT_DATA_01f2 - pcVar3[-3];
        if ((byte)pcVar3[-3] <= DAT_DATA_01f2) break;
        pcVar4 = (char *)((short)in_FSR1 + 1);
        *(char *)in_FSR1 = pcVar3[-3];
        pcVar2 = pcVar3 + 3;
        in_FSR1 = (BADSPACEBASE *)((short)in_FSR1 + 2);
        *pcVar4 = DAT_DATA_01f2 + *pcVar3;
        FUN_CODE_00d154();
        pcVar3 = pcVar2 + 1;
        FUN_CODE_00d144(pcVar2[-5] + '\x01');
      }
    }
  }
  FUN_CODE_00d130(cVar6);
  return;
}


// ===== 0x00d11e =====

void FUN_CODE_00d11e(void)

{
  return;
}


// ===== 0x00d130 =====

void FUN_CODE_00d130(void)

{
  return;
}


// ===== 0x00d144 =====

void FUN_CODE_00d144(void)

{
  BADSPACEBASE *in_FSR1;
  undefined1 *puVar1;
  
  puVar1 = &FramePointer10x0002;
  FUN_CODE_00cf6e();
  *puVar1 = *puVar1;
  puVar1[-1] = puVar1[-1];
  DAT_DATA_01f2 = DAT_DATA_01f2 + '\x01';
  return;
}


// ===== 0x00d154 =====

void FUN_CODE_00d154(void)

{
  BADSPACEBASE *in_FSR1;
  
  FUN_CODE_00cfc6();
  *(undefined1 *)in_FSR1 = *(undefined1 *)in_FSR1;
  *(undefined1 *)((short)in_FSR1 + -1) = *(undefined1 *)((short)in_FSR1 + -1);
  return;
}


// ===== 0x00d15c =====

void FUN_CODE_00d15c(void)

{
  BADSPACEBASE *in_FSR1;
  undefined1 *puVar1;
  
  puVar1 = &FramePointer10x0001;
  FUN_CODE_00cece();
  *puVar1 = *puVar1;
  return;
}


// ===== 0x00d16c =====

undefined1 FUN_CODE_00d16c(void)

{
  BADSPACEBASE *in_FSR2;
  
  FUN_CODE_00d11e();
  return *(undefined1 *)((short)in_FSR2 + -2);
}


// ===== 0x00d3a2 =====

undefined1 FUN_CODE_00d3a2(void)

{
  DAT_DATA_01c5 = 0;
  DAT_DATA_01c3 = 0;
  DAT_DATA_01c4 = 0;
  DAT_DATA_01c8 = 0;
  FUN_CODE_00d480();
  return 0;
}


// ===== 0x00d3b0 =====

undefined1 FUN_CODE_00d3b0(void)

{
  BADSPACEBASE *in_FSR1;
  undefined1 *puVar1;
  undefined1 *puVar2;
  
  puVar1 = &FramePointer10x0001;
  FUN_CODE_00d49a();
  *puVar1 = 0x74;
  puVar2 = puVar1 + 2;
  puVar1[1] = 0xd1;
  DAT_DATA_0014 = FUN_CODE_009af0();
  if ((byte)puVar2 < 5) {
    *(undefined1 *)((ushort)puVar2 & 0xff00) = *(undefined1 *)((ushort)puVar2 & 0xff00);
  }
  return 0;
}


// ===== 0x00d480 =====

undefined1 FUN_CODE_00d480(void)

{
  DAT_DATA_01cb = 0x78;
  DAT_DATA_01c6 = 0;
  DAT_DATA_01c7 = 0;
  DAT_DATA_01c5 = DAT_DATA_01c5 & 0xfc;
  return 0x78;
}


// ===== 0x00d49a =====

undefined1 FUN_CODE_00d49a(void)

{
  return 0;
}


// ===== 0x00d4a4 =====

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


// ===== 0x00d58c =====

void FUN_CODE_00d58c(void)

{
  undefined1 uVar1;
  undefined3 in_TBLPTR;
  byte unaff_Z;
  byte unaff_C;
  
  FUN_CODE_00d77c();
  if ((unaff_C & 1) == 0) {
    FUN_CODE_00d776();
    if ((unaff_Z & 1) != 0) {
      FUN_CODE_00d78c();
      uVar1 = *(undefined1 *)
               CONCAT12((char)((uint3)in_TBLPTR >> 0x10),
                        CONCAT11((char)((uint3)in_TBLPTR >> 8) + (0xfc < (byte)in_TBLPTR),
                                 (byte)in_TBLPTR + 3));
      goto LAB_CODE_00d5a6;
    }
  }
  uVar1 = 0;
LAB_CODE_00d5a6:
  FUN_CODE_00d6c6(uVar1);
  return;
}


// ===== 0x00d5a6 =====

void FUN_CODE_00d58c(void)

{
  undefined1 uVar1;
  undefined3 in_TBLPTR;
  byte unaff_Z;
  byte unaff_C;
  
  FUN_CODE_00d77c();
  if ((unaff_C & 1) == 0) {
    FUN_CODE_00d776();
    if ((unaff_Z & 1) != 0) {
      FUN_CODE_00d78c();
      uVar1 = *(undefined1 *)
               CONCAT12((char)((uint3)in_TBLPTR >> 0x10),
                        CONCAT11((char)((uint3)in_TBLPTR >> 8) + (0xfc < (byte)in_TBLPTR),
                                 (byte)in_TBLPTR + 3));
      goto LAB_CODE_00d5a6;
    }
  }
  uVar1 = 0;
LAB_CODE_00d5a6:
  FUN_CODE_00d6c6(uVar1);
  return;
}


// ===== 0x00d5a8 =====

void FUN_CODE_00d5a8(void)

{
  byte bVar1;
  BADSPACEBASE *in_FSR2;
  BADSPACEBASE *in_FSR1;
  byte bVar2;
  undefined1 uVar3;
  byte unaff_Z;
  byte unaff_C;
  
  FUN_CODE_00d77c();
  if ((unaff_C & 1) == 0) {
    FUN_CODE_00d776();
    if ((unaff_Z & 1) != 0) {
      FUN_CODE_00d700();
      bVar1 = *(byte *)((short)in_FSR2 + -2);
      bVar2 = (byte)((ushort)((short)in_FSR1 + 1) >> 8);
      *(byte *)in_FSR1 = bVar1 + 0x96;
      FUN_CODE_00d724();
      if (bVar1 < 0x6a) {
        *(undefined1 *)((ushort)bVar2 << 8) = *(undefined1 *)((ushort)bVar2 << 8);
      }
      uVar3 = FUN_CODE_00d76a();
      goto LAB_CODE_00d5c8;
    }
  }
  uVar3 = 0;
LAB_CODE_00d5c8:
  FUN_CODE_00d6c6(uVar3);
  return;
}


// ===== 0x00d5c8 =====

void FUN_CODE_00d5a8(void)

{
  byte bVar1;
  BADSPACEBASE *in_FSR2;
  BADSPACEBASE *in_FSR1;
  byte bVar2;
  undefined1 uVar3;
  byte unaff_Z;
  byte unaff_C;
  
  FUN_CODE_00d77c();
  if ((unaff_C & 1) == 0) {
    FUN_CODE_00d776();
    if ((unaff_Z & 1) != 0) {
      FUN_CODE_00d700();
      bVar1 = *(byte *)((short)in_FSR2 + -2);
      bVar2 = (byte)((ushort)((short)in_FSR1 + 1) >> 8);
      *(byte *)in_FSR1 = bVar1 + 0x96;
      FUN_CODE_00d724();
      if (bVar1 < 0x6a) {
        *(undefined1 *)((ushort)bVar2 << 8) = *(undefined1 *)((ushort)bVar2 << 8);
      }
      uVar3 = FUN_CODE_00d76a();
      goto LAB_CODE_00d5c8;
    }
  }
  uVar3 = 0;
LAB_CODE_00d5c8:
  FUN_CODE_00d6c6(uVar3);
  return;
}


// ===== 0x00d5ca =====

void FUN_CODE_00d5ca(void)

{
  byte bVar1;
  BADSPACEBASE *in_FSR2;
  BADSPACEBASE *in_FSR1;
  byte bVar2;
  undefined1 uVar3;
  byte unaff_Z;
  byte unaff_C;
  
  FUN_CODE_00d77c();
  if ((unaff_C & 1) == 0) {
    FUN_CODE_00d776();
    if ((unaff_Z & 1) != 0) {
      FUN_CODE_00d700();
      bVar1 = *(byte *)((short)in_FSR2 + -2);
      bVar2 = (byte)((ushort)((short)in_FSR1 + 1) >> 8);
      *(byte *)in_FSR1 = bVar1 + 0x4b;
      FUN_CODE_00d724();
      if (bVar1 < 0xb5) {
        *(undefined1 *)((ushort)bVar2 << 8) = *(undefined1 *)((ushort)bVar2 << 8);
      }
      uVar3 = FUN_CODE_00d76a();
      goto LAB_CODE_00d5ea;
    }
  }
  uVar3 = 0;
LAB_CODE_00d5ea:
  FUN_CODE_00d6c6(uVar3);
  return;
}


// ===== 0x00d5ea =====

void FUN_CODE_00d5ca(void)

{
  byte bVar1;
  BADSPACEBASE *in_FSR2;
  BADSPACEBASE *in_FSR1;
  byte bVar2;
  undefined1 uVar3;
  byte unaff_Z;
  byte unaff_C;
  
  FUN_CODE_00d77c();
  if ((unaff_C & 1) == 0) {
    FUN_CODE_00d776();
    if ((unaff_Z & 1) != 0) {
      FUN_CODE_00d700();
      bVar1 = *(byte *)((short)in_FSR2 + -2);
      bVar2 = (byte)((ushort)((short)in_FSR1 + 1) >> 8);
      *(byte *)in_FSR1 = bVar1 + 0x4b;
      FUN_CODE_00d724();
      if (bVar1 < 0xb5) {
        *(undefined1 *)((ushort)bVar2 << 8) = *(undefined1 *)((ushort)bVar2 << 8);
      }
      uVar3 = FUN_CODE_00d76a();
      goto LAB_CODE_00d5ea;
    }
  }
  uVar3 = 0;
LAB_CODE_00d5ea:
  FUN_CODE_00d6c6(uVar3);
  return;
}


// ===== 0x00d5ec =====

void FUN_CODE_00d5ec(void)

{
  BADSPACEBASE *in_FSR2;
  undefined1 *puVar1;
  BADSPACEBASE *in_FSR1;
  byte bVar2;
  char cVar3;
  undefined1 uVar4;
  byte unaff_Z;
  byte unaff_C;
  
  FUN_CODE_00d77c();
  if (((unaff_C & 1) == 0) && (FUN_CODE_00d776(), (unaff_Z & 1) != 0)) {
    puVar1 = (undefined1 *)((short)in_FSR2 + 1);
    cVar3 = *(char *)((short)in_FSR2 + -2);
    if (cVar3 == 'A') {
      puVar1 = (undefined1 *)((short)in_FSR2 + 2);
      DAT_DATA_015b = *(undefined1 *)((short)in_FSR2 + -2);
    }
    else if (cVar3 == ':') {
      puVar1 = (undefined1 *)((short)in_FSR2 + 2);
      DAT_DATA_015a = *(undefined1 *)((short)in_FSR2 + -2);
    }
    else if (cVar3 == ',') {
      puVar1 = (undefined1 *)((short)in_FSR2 + 2);
      DAT_DATA_0159 = *(undefined1 *)((short)in_FSR2 + -2);
    }
    else if (cVar3 == '+') {
      puVar1 = (undefined1 *)((short)in_FSR2 + 2);
      DAT_DATA_0158 = *(undefined1 *)((short)in_FSR2 + -2);
    }
    cVar3 = FUN_CODE_00d710((char)puVar1);
    bVar2 = (byte)((ushort)((short)in_FSR1 + 1) >> 8);
    *(undefined1 *)in_FSR1 = puVar1[(short)cVar3 + 1];
    FUN_CODE_00d750();
    uVar4 = DAT_DATA_0014;
    if ((unaff_C & 1) == 0) {
      *(undefined1 *)((ushort)bVar2 << 8) = *(undefined1 *)((ushort)bVar2 << 8);
      uVar4 = DAT_DATA_0014;
    }
  }
  else {
    uVar4 = 0x81;
  }
  FUN_CODE_00d6c6(uVar4);
  return;
}


// ===== 0x00d668 =====

void FUN_CODE_00d668(void)

{
  BADSPACEBASE *in_FSR2;
  BADSPACEBASE *in_FSR1;
  byte bVar1;
  byte unaff_C;
  
  FUN_CODE_00d6b4();
  FUN_CODE_00d700();
  bVar1 = (byte)((ushort)((short)in_FSR1 + 1) >> 8);
  *(undefined1 *)in_FSR1 = *(undefined1 *)((short)in_FSR2 + -2);
  FUN_CODE_00d724();
  if ((unaff_C & 1) == 0) {
    *(undefined1 *)((ushort)bVar1 << 8) = *(undefined1 *)((ushort)bVar1 << 8);
  }
  FUN_CODE_00d76a();
  FUN_CODE_00d6c6();
  return;
}


// ===== 0x00d67e =====

void FUN_CODE_00d67e(void)

{
  BADSPACEBASE *in_FSR2;
  undefined1 *puVar1;
  BADSPACEBASE *in_FSR1;
  undefined1 *puVar2;
  undefined1 uVar3;
  
  FUN_CODE_00d6b4();
  puVar2 = (undefined1 *)((short)in_FSR1 + 1);
  puVar1 = (undefined1 *)((short)in_FSR2 + 1);
  *(undefined1 *)in_FSR1 = *(undefined1 *)((short)in_FSR2 + -2);
  FUN_CODE_00d668();
  *puVar2 = *puVar2;
  uVar3 = DAT_DATA_0032;
  if (DAT_DATA_0201 < '\0') {
    puVar2[-1] = puVar1[-2];
    uVar3 = FUN_CODE_00d58c();
    *puVar2 = *puVar2;
  }
  FUN_CODE_00d6c6(uVar3);
  return;
}


// ===== 0x00d6a0 =====

undefined1 FUN_CODE_00d6a0(void)

{
  return 0xdd;
}


// ===== 0x00d6b4 =====

void FUN_CODE_00d6b4(void)

{
  return;
}


// ===== 0x00d6c6 =====

void FUN_CODE_00d6c6(void)

{
  return;
}


// ===== 0x00d6d2 =====

undefined1 FUN_CODE_00d6d2(byte param_1)

{
  byte in_TBLPTRL;
  char in_TBLPTRH;
  
  DAT_DATA_0014 = in_TBLPTRL + param_1;
  DAT_DATA_0015 = in_TBLPTRH + CARRY1(in_TBLPTRL,param_1);
  return 1;
}


// ===== 0x00d6f0 =====

char FUN_CODE_00d6f0(void)

{
  char in_FramePointer2_0000fffe;
  
  return in_FramePointer2_0000fffe + -0x4b;
}


// ===== 0x00d700 =====

undefined1 FUN_CODE_00d700(void)

{
  return 1;
}


// ===== 0x00d710 =====

undefined1 FUN_CODE_00d710(void)

{
  return 0xfd;
}


// ===== 0x00d724 =====

char FUN_CODE_00d724(void)

{
  char cVar1;
  
  cVar1 = '\x01';
  DAT_DATA_0014 = FUN_CODE_00dfd6();
  return cVar1 + -6;
}


// ===== 0x00d732 =====

char FUN_CODE_00d732(void)

{
  char *in_TBLPTR;
  char in_FramePointer2_0000fffe;
  
  DAT_DATA_0014 = *in_TBLPTR;
  return *in_TBLPTR - in_FramePointer2_0000fffe;
}


// ===== 0x00d740 =====

char FUN_CODE_00d740(void)

{
  char cVar1;
  
  cVar1 = '\x02';
  DAT_DATA_0016 = FUN_CODE_00e104();
  return cVar1 + -6;
}


// ===== 0x00d750 =====

char FUN_CODE_00d750(void)

{
  char cVar1;
  
  cVar1 = '\x01';
  DAT_DATA_0014 = FUN_CODE_00e060();
  return cVar1 + -6;
}


// ===== 0x00d75e =====

byte FUN_CODE_00d75e(void)

{
  byte unaff_C;
  
  DAT_DATA_0201 = DAT_DATA_0016;
  return DAT_DATA_0016 << 1 | unaff_C & 1;
}


// ===== 0x00d76a =====

undefined1 FUN_CODE_00d76a(void)

{
  DAT_DATA_0201 = DAT_DATA_0014;
  return DAT_DATA_0032;
}


// ===== 0x00d776 =====

void FUN_CODE_00d776(void)

{
  FUN_CODE_00d78c();
  FUN_CODE_00d732();
  return;
}


// ===== 0x00d77c =====

void FUN_CODE_00d77c(void)

{
  FUN_CODE_00d6b4();
  FUN_CODE_00d6f0();
  return;
}


// ===== 0x00d78c =====

void FUN_CODE_00d78c(void)

{
  undefined1 in_FramePointer2_0000fffe;
  
  FUN_CODE_00d6a0(in_FramePointer2_0000fffe);
  return;
}


// ===== 0x00d8ea =====

undefined1 FUN_CODE_00d8ea(void)

{
  DAT_DATA_01cc = 0xff;
  DAT_DATA_01cd = 0xff;
  DAT_DATA_01ce = 0xff;
  DAT_DATA_01cf = 0xff;
  DAT_DATA_01d0 = 0;
  DAT_DATA_01d1 = 0;
  DAT_DATA_01d2 = 0;
  return 0;
}


// ===== 0x00d8fc =====

undefined1 FUN_CODE_00d8fc(void)

{
  BADSPACEBASE *in_FSR1;
  undefined1 *puVar1;
  
  puVar1 = &FramePointer10x0005;
  DAT_DATA_0014 = FUN_CODE_009af0();
  if ((byte)puVar1 < 5) {
    *(undefined1 *)((ushort)puVar1 & 0xff00) = *(undefined1 *)((ushort)puVar1 & 0xff00);
  }
  return 0;
}


// ===== 0x00d926 =====

char FUN_CODE_00d926(void)

{
  char cVar1;
  
  cVar1 = FUN_CODE_00da78(0x3d);
  DAT_DATA_01cc = cVar1 * '<';
  DAT_DATA_01cd = 0;
  return cVar1 * '<';
}


// ===== 0x00da78 =====

void FUN_CODE_00da78(void)

{
  BADSPACEBASE *in_FSR1;
  undefined1 *puVar1;
  
  puVar1 = &FramePointer10x0001;
  FUN_CODE_00d668();
  *puVar1 = *puVar1;
  return;
}


// ===== 0x00dbe6 =====

undefined1 FUN_CODE_00dbe6(void)

{
  DAT_DATA_0186 = 0;
  DAT_DATA_0189 = FUN_CODE_00dd1a(0xf);
  DAT_DATA_018b = 0;
  DAT_DATA_018c = 0;
  DAT_DATA_018d = 0;
  DAT_DATA_018e = 0;
  DAT_DATA_0190 = 0;
  DAT_DATA_018f = 0;
  FUN_CODE_00dd3e();
  DAT_DATA_018a = 0;
  FUN_CODE_00fc40();
  return 0;
}


// ===== 0x00dc08 =====

undefined1 FUN_CODE_00dc08(void)

{
  BADSPACEBASE *in_FSR1;
  undefined1 *puVar1;
  
  puVar1 = &FramePointer10x0005;
  DAT_DATA_0014 = FUN_CODE_009af0();
  if ((byte)puVar1 < 5) {
    *(undefined1 *)((ushort)puVar1 & 0xff00) = *(undefined1 *)((ushort)puVar1 & 0xff00);
  }
  return 0;
}


// ===== 0x00dd1a =====

void FUN_CODE_00dd1a(void)

{
  BADSPACEBASE *in_FSR1;
  undefined1 *puVar1;
  
  puVar1 = &FramePointer10x0001;
  FUN_CODE_00d67e();
  *puVar1 = *puVar1;
  return;
}


// ===== 0x00dd34 =====

undefined1 FUN_CODE_00dd34(undefined1 param_1)

{
  DAT_DATA_0187 = param_1;
  DAT_DATA_0188 = 10;
  return 10;
}


// ===== 0x00dd3e =====

void FUN_CODE_00dd3e(void)

{
  FUN_CODE_00dd1a(0xe);
  FUN_CODE_00dd34();
  return;
}


// ===== 0x00dfd6 =====

/* WARNING: Removing unreachable block (CODE,0x00e004) */
/* WARNING: Removing unreachable block (CODE,0x00e02e) */
/* WARNING: Removing unreachable block (CODE,0x00e030) */
/* WARNING: Removing unreachable block (CODE,0x00e04a) */
/* WARNING: Removing unreachable block (CODE,0x00e04c) */

undefined1 FUN_CODE_00dfd6(void)

{
  char *pcVar1;
  BADSPACEBASE *in_FSR1;
  
  pcVar1 = (char *)CONCAT11((char)((ushort)&FramePointer10x0002 >> 8),(char)&FramePointer10x0002);
  DAT_DATA_0014 = pcVar1[-5];
  pcVar1[-4] = pcVar1[-3] + -1;
  DAT_DATA_0015 = pcVar1[-1];
  if (pcVar1[-3] == '\0') {
    *pcVar1 = pcVar1[1] + -1;
  }
  return 0;
}


// ===== 0x00e060 =====

/* WARNING: Removing unreachable block (CODE,0x00e08e) */
/* WARNING: Removing unreachable block (CODE,0x00e0a4) */
/* WARNING: Removing unreachable block (CODE,0x00e0a6) */
/* WARNING: Removing unreachable block (CODE,0x00e0da) */
/* WARNING: Removing unreachable block (CODE,0x00e0dc) */
/* WARNING: Removing unreachable block (CODE,0x00e0ec) */
/* WARNING: Removing unreachable block (CODE,0x00e0ee) */
/* WARNING: Removing unreachable block (CODE,0x00e0f0) */

undefined1 FUN_CODE_00e060(void)

{
  char *pcVar1;
  BADSPACEBASE *in_FSR1;
  
  pcVar1 = (char *)CONCAT11((char)((ushort)&FramePointer10x0002 >> 8),(char)&FramePointer10x0002);
  DAT_DATA_0014 = pcVar1[-5];
  pcVar1[-4] = pcVar1[-3] + -1;
  DAT_DATA_0015 = pcVar1[-1];
  if (pcVar1[-3] == '\0') {
    *pcVar1 = pcVar1[1] + -1;
  }
  return 0;
}


// ===== 0x00e104 =====

/* WARNING: Removing unreachable block (CODE,0x00e132) */
/* WARNING: Removing unreachable block (CODE,0x00e148) */
/* WARNING: Removing unreachable block (CODE,0x00e14a) */
/* WARNING: Removing unreachable block (CODE,0x00e180) */
/* WARNING: Removing unreachable block (CODE,0x00e182) */
/* WARNING: Removing unreachable block (CODE,0x00e192) */
/* WARNING: Removing unreachable block (CODE,0x00e194) */
/* WARNING: Removing unreachable block (CODE,0x00e196) */

undefined1 FUN_CODE_00e104(void)

{
  char *pcVar1;
  BADSPACEBASE *in_FSR1;
  
  pcVar1 = (char *)CONCAT11((char)((ushort)&FramePointer10x0002 >> 8),(char)&FramePointer10x0002);
  DAT_DATA_0014 = pcVar1[-5];
  pcVar1[-4] = pcVar1[-3] + -1;
  DAT_DATA_0015 = pcVar1[-1];
  if (pcVar1[-3] == '\0') {
    *pcVar1 = pcVar1[1] + -1;
  }
  return 0;
}


// ===== 0x00e1aa =====

/* WARNING: Removing unreachable block (CODE,0x00e1d8) */
/* WARNING: Removing unreachable block (CODE,0x00e210) */
/* WARNING: Removing unreachable block (CODE,0x00e212) */
/* WARNING: Removing unreachable block (CODE,0x00e222) */
/* WARNING: Removing unreachable block (CODE,0x00e224) */
/* WARNING: Removing unreachable block (CODE,0x00e226) */

undefined1 FUN_CODE_00e1aa(void)

{
  char *pcVar1;
  BADSPACEBASE *in_FSR1;
  
  pcVar1 = (char *)CONCAT11((char)((ushort)&FramePointer10x0002 >> 8),(char)&FramePointer10x0002);
  DAT_DATA_0014 = pcVar1[-5];
  pcVar1[-4] = pcVar1[-3] + -1;
  DAT_DATA_0015 = pcVar1[-1];
  if (pcVar1[-3] == '\0') {
    *pcVar1 = pcVar1[1] + -1;
  }
  return 0;
}


// ===== 0x00e6ba =====

undefined1 FUN_CODE_00e6ba(void)

{
  BADSPACEBASE *in_FSR1;
  undefined1 *puVar1;
  undefined1 *puVar2;
  undefined1 *puVar3;
  char cVar4;
  
  DAT_DATA_01bb = 0;
  DAT_DATA_01be = 0;
  DAT_DATA_01bd = 0;
  DAT_DATA_01c1 = 0;
  DAT_DATA_01c2 = 0;
  DAT_DATA_01bf = 0;
  puVar1 = &FramePointer10x0001;
  cVar4 = FUN_CODE_00d67e();
  puVar2 = puVar1 + -1;
  *puVar1 = *puVar1;
  if (cVar4 == '\0') {
    cVar4 = FUN_CODE_00b53c();
    if (cVar4 == '\0') {
      DAT_DATA_01c0 = 0x1e;
    }
    else {
      DAT_DATA_01c0 = 0;
    }
  }
  else {
    DAT_DATA_01c0 = 0x78;
    puVar2 = puVar1 + -1;
  }
  puVar3 = puVar2 + 1;
  *puVar2 = 0x22;
  DAT_DATA_01bc = FUN_CODE_00d67e();
  *puVar3 = *puVar3;
  DAT_DATA_01ba = 0;
  return 0;
}


// ===== 0x00e8ae =====

undefined1 FUN_CODE_00e8ae(void)

{
  byte unaff_BSR;
  char cVar1;
  byte bVar2;
  bool bVar3;
  
  FUN_CODE_00e926();
  cVar1 = FUN_CODE_00b53c();
  if (cVar1 == '\0') {
    FUN_CODE_00ea76(9);
    bVar2 = FUN_CODE_00ea80();
    if ((*(byte *)((ushort)unaff_BSR * 0x100 + 0xe3) & 0x80) == 0) {
      bVar3 = *(byte *)((ushort)unaff_BSR * 0x100 + 0xe3) !=
              ~(bVar2 <= *(byte *)((ushort)unaff_BSR * 0x100 + 0xe2));
    }
    else {
      bVar3 = false;
    }
    if (bVar3) goto LAB_CODE_00e8da;
    *(undefined1 *)((ushort)unaff_BSR * 0x100 + 0xe2) = 0xc;
  }
  else {
    unaff_BSR = 1;
    DAT_DATA_01e2 = 0;
  }
  *(undefined1 *)((ushort)unaff_BSR * 0x100 + 0xe3) = 0;
LAB_CODE_00e8da:
  *(undefined1 *)((ushort)unaff_BSR * 0x100 + 0xe4) = 0;
  *(undefined1 *)((ushort)unaff_BSR * 0x100 + 0xe5) = 0;
  *(undefined1 *)((ushort)unaff_BSR * 0x100 + 0xe6) = 0;
  *(undefined1 *)((ushort)unaff_BSR * 0x100 + 0xe1) = 0;
  return 0;
}


// ===== 0x00e8da =====

undefined1 FUN_CODE_00e8ae(void)

{
  byte unaff_BSR;
  char cVar1;
  byte bVar2;
  bool bVar3;
  
  FUN_CODE_00e926();
  cVar1 = FUN_CODE_00b53c();
  if (cVar1 == '\0') {
    FUN_CODE_00ea76(9);
    bVar2 = FUN_CODE_00ea80();
    if ((*(byte *)((ushort)unaff_BSR * 0x100 + 0xe3) & 0x80) == 0) {
      bVar3 = *(byte *)((ushort)unaff_BSR * 0x100 + 0xe3) !=
              ~(bVar2 <= *(byte *)((ushort)unaff_BSR * 0x100 + 0xe2));
    }
    else {
      bVar3 = false;
    }
    if (bVar3) goto LAB_CODE_00e8da;
    *(undefined1 *)((ushort)unaff_BSR * 0x100 + 0xe2) = 0xc;
  }
  else {
    unaff_BSR = 1;
    DAT_DATA_01e2 = 0;
  }
  *(undefined1 *)((ushort)unaff_BSR * 0x100 + 0xe3) = 0;
LAB_CODE_00e8da:
  *(undefined1 *)((ushort)unaff_BSR * 0x100 + 0xe4) = 0;
  *(undefined1 *)((ushort)unaff_BSR * 0x100 + 0xe5) = 0;
  *(undefined1 *)((ushort)unaff_BSR * 0x100 + 0xe6) = 0;
  *(undefined1 *)((ushort)unaff_BSR * 0x100 + 0xe1) = 0;
  return 0;
}


// ===== 0x00e926 =====

/* WARNING: Restarted to delay deadcode elimination for space: DATA */

undefined1 FUN_CODE_00e926(void)

{
  char cVar1;
  byte bVar2;
  BADSPACEBASE *in_FSR1;
  undefined1 *puVar3;
  byte bVar4;
  bool bVar5;
  
  bVar2 = 0xe;
  if ((DAT_DATA_0ee0 & 0x40) == 0) {
    return 1;
  }
  bVar4 = FUN_CODE_00b53c();
  if (bVar4 == 0) {
    FUN_CODE_00ea76(9);
    bVar4 = FUN_CODE_00ea80();
    if ((DAT_DATA_0ee3 & 0x80) == 0) {
      bVar5 = DAT_DATA_0ee3 != ~(bVar4 <= DAT_DATA_0ee2);
      bVar4 = DAT_DATA_0ee3 - ~(bVar4 <= DAT_DATA_0ee2);
    }
    else {
      bVar5 = false;
    }
    if (bVar5) goto LAB_CODE_00e956;
    bVar4 = 0xc;
    DAT_DATA_0ee2 = 0xc;
  }
  else {
    bVar2 = 1;
    DAT_DATA_01e2 = 0;
  }
  *(undefined1 *)((ushort)bVar2 * 0x100 + 0xe3) = 0;
LAB_CODE_00e956:
  bVar2 = PORTG;
  PORTG = bVar2 & 0xf7;
  DAT_DATA_0ee0 = DAT_DATA_0ee0 & 0xbf;
  FUN_CODE_00d926(bVar4);
  puVar3 = (undefined1 *)((short)in_FSR1 + 1);
  *(undefined1 *)in_FSR1 = 0;
  FUN_CODE_004bd8();
  *puVar3 = *puVar3;
  puVar3[-1] = 0xc;
  FUN_CODE_00ed58();
  *puVar3 = *puVar3;
  cVar1 = DAT_DATA_00f2 - DAT_DATA_01e6;
  if (DAT_DATA_00f2 < DAT_DATA_01e6) {
    DAT_DATA_00f2 = DAT_DATA_01e6;
    puVar3[-1] = 0;
    FUN_CODE_00ed94(cVar1);
    *puVar3 = *puVar3;
  }
  return 0;
}


// ===== 0x00e956 =====

/* WARNING: Restarted to delay deadcode elimination for space: DATA */

undefined1 FUN_CODE_00e926(void)

{
  char cVar1;
  byte bVar2;
  BADSPACEBASE *in_FSR1;
  undefined1 *puVar3;
  byte bVar4;
  bool bVar5;
  
  bVar2 = 0xe;
  if ((DAT_DATA_0ee0 & 0x40) == 0) {
    return 1;
  }
  bVar4 = FUN_CODE_00b53c();
  if (bVar4 == 0) {
    FUN_CODE_00ea76(9);
    bVar4 = FUN_CODE_00ea80();
    if ((DAT_DATA_0ee3 & 0x80) == 0) {
      bVar5 = DAT_DATA_0ee3 != ~(bVar4 <= DAT_DATA_0ee2);
      bVar4 = DAT_DATA_0ee3 - ~(bVar4 <= DAT_DATA_0ee2);
    }
    else {
      bVar5 = false;
    }
    if (bVar5) goto LAB_CODE_00e956;
    bVar4 = 0xc;
    DAT_DATA_0ee2 = 0xc;
  }
  else {
    bVar2 = 1;
    DAT_DATA_01e2 = 0;
  }
  *(undefined1 *)((ushort)bVar2 * 0x100 + 0xe3) = 0;
LAB_CODE_00e956:
  bVar2 = PORTG;
  PORTG = bVar2 & 0xf7;
  DAT_DATA_0ee0 = DAT_DATA_0ee0 & 0xbf;
  FUN_CODE_00d926(bVar4);
  puVar3 = (undefined1 *)((short)in_FSR1 + 1);
  *(undefined1 *)in_FSR1 = 0;
  FUN_CODE_004bd8();
  *puVar3 = *puVar3;
  puVar3[-1] = 0xc;
  FUN_CODE_00ed58();
  *puVar3 = *puVar3;
  cVar1 = DAT_DATA_00f2 - DAT_DATA_01e6;
  if (DAT_DATA_00f2 < DAT_DATA_01e6) {
    DAT_DATA_00f2 = DAT_DATA_01e6;
    puVar3[-1] = 0;
    FUN_CODE_00ed94(cVar1);
    *puVar3 = *puVar3;
  }
  return 0;
}


// ===== 0x00ea76 =====

void FUN_CODE_00ea76(void)

{
  BADSPACEBASE *in_FSR1;
  undefined1 *puVar1;
  
  puVar1 = &FramePointer10x0001;
  FUN_CODE_00d67e();
  *puVar1 = *puVar1;
  return;
}


// ===== 0x00ea80 =====

undefined1 FUN_CODE_00ea80(undefined1 param_1)

{
  DAT_DATA_01e2 = param_1;
  DAT_DATA_01e3 = 0;
  return 0xc;
}


// ===== 0x00ec76 =====

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


// ===== 0x00ed58 =====

void FUN_CODE_00ed58(void)

{
  BADSPACEBASE *in_FSR1;
  byte bVar1;
  byte bVar2;
  
  DAT_DATA_0032 = FUN_CODE_00edc4();
  bVar1 = (byte)((ushort)DAT_DATA_0032 * 4);
  DAT_DATA_0014 = bVar1 + 0xb2;
  DAT_DATA_0015 = (char)((ushort)DAT_DATA_0032 * 4 >> 8) + (0x4d < bVar1);
  FUN_CODE_00edfc();
  *(undefined1 *)in_FSR1 = 4;
  bVar1 = (byte)((ushort)((short)in_FSR1 + 2) >> 8);
  *(undefined1 *)((short)in_FSR1 + 1) = 0;
  bVar2 = DAT_DATA_0032 * '\x04';
  DAT_DATA_0017 = 0;
  DAT_DATA_0016 = bVar2 - 0x1c;
  FUN_CODE_00ede6(0);
  if (bVar2 < 0x1c) {
    *(undefined1 *)((ushort)bVar1 << 8) = *(undefined1 *)((ushort)bVar1 << 8);
  }
  FUN_CODE_00edda(DAT_DATA_0018);
  return;
}


// ===== 0x00ed94 =====

void FUN_CODE_00ed94(void)

{
  BADSPACEBASE *in_FSR1;
  byte bVar1;
  bool bVar2;
  
  DAT_DATA_0032 = FUN_CODE_00edc4();
  DAT_DATA_0015 = 0xd < DAT_DATA_0032;
  DAT_DATA_0014 = DAT_DATA_0032 - 0xe;
  FUN_CODE_00edfc();
  *(undefined1 *)in_FSR1 = 1;
  bVar1 = (byte)((ushort)((short)in_FSR1 + 2) >> 8);
  *(undefined1 *)((short)in_FSR1 + 1) = 0;
  DAT_DATA_0017 = 0;
  bVar2 = DAT_DATA_0032 < 0xdc;
  DAT_DATA_0016 = DAT_DATA_0032 + 0x24;
  FUN_CODE_00ede6(1);
  if (bVar2) {
    *(undefined1 *)((ushort)bVar1 << 8) = *(undefined1 *)((ushort)bVar1 << 8);
  }
  FUN_CODE_00edda(DAT_DATA_0018);
  return;
}


// ===== 0x00edc4 =====

undefined1 FUN_CODE_00edc4(void)

{
  BADSPACEBASE *in_FSR1;
  
  return *(undefined1 *)
          (CONCAT11((char)((ushort)&FramePointer10x0002 >> 8),(char)&FramePointer10x0002) + -2);
}


// ===== 0x00edda =====

void FUN_CODE_00edda(void)

{
  return;
}


// ===== 0x00ede6 =====

char FUN_CODE_00ede6(char param_1)

{
  char cVar1;
  byte unaff_C;
  
  DAT_DATA_0017 = DAT_DATA_0017 + param_1 + (unaff_C & 1);
  cVar1 = '\x02';
  DAT_DATA_0018 = FUN_CODE_00e060();
  return cVar1 + -6;
}


// ===== 0x00edfc =====

void FUN_CODE_00edfc(void)

{
  return;
}


// ===== 0x00f278 =====

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


// ===== 0x00f394 =====

void FUN_CODE_00f394(void)

{
  return;
}


// ===== 0x00f3a8 =====

void FUN_CODE_00f3a8(void)

{
  return;
}


// ===== 0x00f3c4 =====

void FUN_CODE_00f3c4(void)

{
  BADSPACEBASE *in_FSR1;
  undefined1 *puVar1;
  
  puVar1 = &FramePointer10x0001;
  FUN_CODE_00cefe();
  *puVar1 = *puVar1;
  return;
}


// ===== 0x00f3ce =====

/* WARNING: Instruction at (CODE,0x00f414) overlaps instruction at (CODE,0x00f412)
    */

undefined1 FUN_CODE_00f3ce(void)

{
  DAT_DATA_0000 = 0;
  if ((DAT_DATA_000e & 0x80) != 0) {
    DAT_DATA_000d = -DAT_DATA_000d;
    DAT_DATA_000e = ~DAT_DATA_000e + ('\0' < DAT_DATA_000d);
    DAT_DATA_0000 = 0xff;
  }
  if ((DAT_DATA_0009 & 0x80) != 0) {
    DAT_DATA_0008 = -DAT_DATA_0008;
    DAT_DATA_0009 = ~DAT_DATA_0009 + ('\0' < DAT_DATA_0008);
    DAT_DATA_0000 = ~DAT_DATA_0000;
  }
  FUN_CODE_00fbbc();
  if ((DAT_DATA_0009 & 0x80) == 0) {
    if ((DAT_DATA_0000 & 0x80) == 0) {
      return 0;
    }
  }
  else if ((DAT_DATA_0000 & 0x80) == 0) {
    DAT_DATA_0001 = DAT_DATA_0001 | 0x10;
    return 0xff;
  }
  DAT_DATA_0008 = -DAT_DATA_0008;
  DAT_DATA_0009 = ~DAT_DATA_0009 + ('\0' < DAT_DATA_0008);
  DAT_DATA_0004 = -DAT_DATA_0004;
  DAT_DATA_0005 = ~DAT_DATA_0005 + ('\0' < DAT_DATA_0004);
  return 0;
}


// ===== 0x00f592 =====

undefined1 FUN_CODE_00f592(void)

{
  char cVar1;
  char *pcVar2;
  undefined1 uVar3;
  undefined1 *puVar4;
  undefined1 in_FramePointer1_00000000;
  undefined1 in_FramePointer1_00000002;
  undefined1 in_FramePointer1_00000004;
  undefined1 in_FramePointer1_0000fffc;
  undefined1 in_FramePointer1_0000fffe;
  
  puVar4 = (undefined1 *)
           CONCAT12(in_FramePointer1_00000000,
                    CONCAT11(in_FramePointer1_0000fffe,in_FramePointer1_0000fffc));
  pcVar2 = (undefined1 *)CONCAT11(in_FramePointer1_00000004,in_FramePointer1_00000002);
  do {
    uVar3 = *puVar4;
    puVar4 = puVar4 + 1;
    *pcVar2 = uVar3;
    cVar1 = *pcVar2;
    pcVar2 = pcVar2 + 1;
  } while (cVar1 != '\0');
  return 0xff;
}


// ===== 0x00f5c4 =====

undefined1 FUN_CODE_00f5c4(void)

{
  char cVar1;
  char *pcVar2;
  undefined1 in_FramePointer1_00000001;
  undefined1 in_FramePointer1_0000ffff;
  
  pcVar2 = (undefined1 *)CONCAT11(in_FramePointer1_00000001,in_FramePointer1_0000ffff);
  do {
    cVar1 = *pcVar2;
    *pcVar2 = cVar1;
    pcVar2 = pcVar2 + 1;
  } while (cVar1 != '\0');
  return 0xff;
}


// ===== 0x00f760 =====

undefined1 FUN_CODE_00f760(void)

{
  DAT_DATA_01f8 = 0;
  DAT_DATA_01f7 = 0;
  return 0;
}


// ===== 0x00f80c =====

undefined1 FUN_CODE_00f80c(void)

{
  DAT_DATA_01fc = 0;
  DAT_DATA_01fb = 0;
  return 0;
}


// ===== 0x00f8b2 =====

undefined1 FUN_CODE_00f8b2(void)

{
  DAT_DATA_0ef3 = 0;
  DAT_DATA_0ef2 = 0;
  return 0;
}


// ===== 0x00f956 =====

undefined1 FUN_CODE_00f956(void)

{
  undefined1 *puVar1;
  undefined1 *puVar2;
  undefined1 uVar3;
  undefined1 *puVar4;
  int3 *piVar5;
  bool bVar6;
  
  piVar5 = (int3 *)&UNK_CODE_00002c;
  DAT_DATA_01b6 = '\0';
  for (DAT_DATA_01b5 = '\t'; (DAT_DATA_01b6 != '\0' || (DAT_DATA_01b5 != '\0'));
      DAT_DATA_01b5 = DAT_DATA_01b5 + -1) {
    DAT_DATA_01b0 = (undefined1)*piVar5;
    DAT_DATA_01b1 = *(undefined *)((int3)piVar5 + 1);
    DAT_DATA_01b2 = *(undefined *)((int3)piVar5 + 2);
    puVar4 = (undefined1 *)*piVar5;
    puVar1 = *(undefined1 **)(piVar5 + 1);
    DAT_DATA_01b3 = (char)piVar5[2];
    DAT_DATA_01b4 = *(char *)((int3)piVar5 + 9);
    piVar5 = piVar5 + 3;
    DAT_DATA_01b7 = SUB31(piVar5,0);
    DAT_DATA_01b8 = (undefined1)((uint3)piVar5 >> 8);
    DAT_DATA_01b9 = (undefined1)((uint3)piVar5 >> 0x10);
    while ((puVar2 = puVar1, DAT_DATA_01b3 != '\0' || (DAT_DATA_01b4 != '\0'))) {
      while( true ) {
        uVar3 = *puVar4;
        puVar4 = puVar4 + 1;
        puVar1 = puVar2 + 1;
        *puVar2 = uVar3;
        bVar6 = DAT_DATA_01b3 != '\0';
        DAT_DATA_01b3 = DAT_DATA_01b3 + -1;
        if (bVar6) break;
        DAT_DATA_01b4 = DAT_DATA_01b4 + -1;
        puVar2 = puVar2 + 1;
      }
    }
    piVar5 = (int3 *)CONCAT12(DAT_DATA_01b9,CONCAT11(DAT_DATA_01b8,DAT_DATA_01b7));
    DAT_DATA_01b6 = DAT_DATA_01b6 - ~(DAT_DATA_01b5 != '\0');
    DAT_DATA_01b3 = 0;
  }
  return 0;
}


// ===== 0x00f9f4 =====

undefined1 FUN_CODE_00f9f4(void)

{
  DAT_DATA_01fa = 0;
  DAT_DATA_01f9 = 0;
  return 0;
}


// ===== 0x00fbbc =====

byte FUN_CODE_00fbbc(void)

{
  byte bVar1;
  byte bVar2;
  bool bVar3;
  bool bVar4;
  char cVar5;
  
  DAT_DATA_0005 = 0;
  DAT_DATA_0004 = 0;
  cVar5 = '\x10';
  bVar3 = false;
  do {
    bVar4 = (char)DAT_DATA_0008 < '\0';
    DAT_DATA_0008 = DAT_DATA_0008 << 1 | bVar3;
    bVar3 = (char)DAT_DATA_0009 < '\0';
    DAT_DATA_0009 = DAT_DATA_0009 << 1 | bVar4;
    bVar4 = (char)DAT_DATA_0004 < '\0';
    DAT_DATA_0004 = DAT_DATA_0004 << 1 | bVar3;
    DAT_DATA_0005 = DAT_DATA_0005 << 1 | bVar4;
    bVar1 = ~(DAT_DATA_000d <= DAT_DATA_0004);
    bVar4 = DAT_DATA_000e < DAT_DATA_0005 - bVar1;
    bVar3 = DAT_DATA_0005 < bVar1 || bVar4;
    bVar2 = (DAT_DATA_0005 - DAT_DATA_000e) - ~(DAT_DATA_000d <= DAT_DATA_0004);
    if (DAT_DATA_0005 < bVar1 || bVar4) {
      bVar3 = DAT_DATA_000d <= DAT_DATA_0004;
      DAT_DATA_0004 = DAT_DATA_0004 - DAT_DATA_000d;
      DAT_DATA_0005 = (DAT_DATA_0005 - DAT_DATA_000e) - ~bVar3;
      bVar3 = 0xfe < DAT_DATA_0008;
      DAT_DATA_0008 = DAT_DATA_0008 + 1;
      bVar2 = DAT_DATA_000e;
    }
    cVar5 = cVar5 + -1;
  } while (cVar5 != '\0');
  return bVar2;
}


// ===== 0x00fc08 =====

void FUN_CODE_00fc08(void)

{
  DAT_DATA_0001 = DAT_DATA_0001 & 0xbf;
  FUN_CODE_00f956();
  do {
    FUN_CODE_00fcbc();
    FUN_CODE_00b256();
  } while( true );
}


// ===== 0x00fc40 =====

undefined1 FUN_CODE_00fc40(void)

{
  DAT_DATA_01ff = 0;
  return 0;
}


// ===== 0x00fc98 =====

undefined1 FUN_CODE_00fc98(void)

{
  uDATA00ff = 0;
  return 0;
}


// ===== 0x00fca2 =====

undefined1 FUN_CODE_00fca2(void)

{
  DAT_DATA_0202 = 0;
  return 0;
}


// ===== 0x00fcbc =====

void FUN_CODE_00fcbc(void)

{
  return;
}


