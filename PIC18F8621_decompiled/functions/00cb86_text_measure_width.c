// address 0x00cb86  size 108 bytes
// callers: 0094d8,009936,00cc0c,

/* WARNING: Restarted to delay deadcode elimination for space: DATA */
/* Measure pixel width of a text line */

void text_measure_width(void)

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
  
  bVar8 = mod_set_lcd_text_flag_cd96();
  *(undefined1 *)((ushort)unaff_BSR * 0x100 + 0xe9) = 0;
  puVar6 = (undefined1 *)in_FSR2;
LAB_CODE_00cb8a:
  *(undefined1 *)((ushort)unaff_BSR * 0x100 + 0xe7) = 0;
  bVar9 = true;
  puVar5 = puVar6;
  do {
    while( true ) {
      mod_set_lcd_text_flag_ce04(bVar8);
      if (bVar9) goto LAB_CODE_00cbe2;
      if ((puVar5[-4] & 8) == 0) break;
LAB_CODE_00cbc6:
      puVar6 = puVar5 + 2;
      puVar7 = puVar5 + 2;
      if ((puVar5[-3] & 1) == 0) {
        bVar8 = mod_get_TBLPTRH_cd48(puVar5[2]);
        bVar8 = bVar8 & 0xf;
        puVar6 = puVar7;
      }
      else {
        mod_get_TBLPTRH_cd48(puVar5[2]);
        bVar8 = mod_frag_cda0();
      }
      unaff_BSR = 1;
      lcd_text_width = lcd_text_width + bVar8;
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
      lcd_text_maxwidth = lcd_text_width;
    }
    uVar3 = *(undefined1 *)((ushort)unaff_BSR * 0x100 + 0xe9);
    *(undefined1 *)in_FSR1 = *(undefined1 *)in_FSR1;
    mod_c18_epilogue_cd24(uVar3);
    return;
  }
  bVar1 = *(byte *)((ushort)unaff_BSR * 0x100 + 0xe7);
  bVar2 = *(byte *)((ushort)unaff_BSR * 0x100 + 0xe9);
  bVar8 = bVar2 - bVar1;
  puVar6 = puVar5 + 2;
  if (bVar2 < bVar1) {
    lcd_text_maxwidth = lcd_text_width;
    puVar6 = puVar5 + 2;
  }
  goto LAB_CODE_00cb8a;
}

