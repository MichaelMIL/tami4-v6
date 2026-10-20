// address 0x00cbde

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

