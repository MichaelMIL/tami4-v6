// address 0x0098d6

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

