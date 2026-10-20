// address 0x007628

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

