// address 0x00cc5a  size 152 bytes
// callers: 0094d8,

/* WARNING: Restarted to delay deadcode elimination for space: DATA */
/* Render text glyphs to the LCD */

void text_render_glyphs(void)

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
  
  mod_c18_prologue_cdd2();
  puVar2 = (undefined1 *)((short)in_FSR2 + 1);
  puVar1 = (undefined1 *)((short)in_FSR2 + 1);
  if ((*(byte *)((short)in_FSR2 + -3) & 1) == 0) {
    bVar9 = mod_to_mod_get_TBLPTRH_cdec();
    lcd_text_maxwidth = bVar9 & 0xf;
  }
  else {
    mod_to_mod_get_TBLPTRH_cdec();
    lcd_text_maxwidth = mod_frag_cda0();
    puVar2 = puVar1;
  }
  lcd_text_width = 0;
  pbVar3 = puVar2;
  do {
    uVar12 = (undefined2)((uint3)in_TBLPTR >> 8);
    if (lcd_text_maxwidth <= lcd_text_width) {
      pbVar8 = (byte *)((short)in_FSR1 + 1);
      *(byte *)in_FSR1 = pbVar3[-3];
      mod_set_text_x_adjust_cc2c();
      *pbVar8 = *pbVar8;
      mod_c18_epilogue_cd24();
      return;
    }
    if ((pbVar3[-3] & 0x20) == 0) {
LAB_CODE_00cc90:
      pbVar4 = pbVar3 + 2;
      if ((pbVar3[-2] & 1) == 0) {
        pbVar4 = pbVar3 + 3;
        bVar9 = (byte)((ushort)*pbVar3 * 5);
        c18_tmp2 = bVar9 - 0x20;
        c18_tmp3 = (char)((ushort)*pbVar3 * 5 >> 8) + 'z' + (0x1f < bVar9);
        uVar11 = CONCAT21(uVar12,c18_tmp2 + lcd_text_width);
        cVar10 = c18_tmp3 + CARRY1(c18_tmp2,lcd_text_width);
      }
      else {
        bVar9 = mod_get_c18_tmp0_cd7c();
        uVar11 = CONCAT21(uVar12,c18_tmp0 + bVar9);
        cVar10 = c18_tmp1 + CARRY1(c18_tmp0,bVar9);
      }
      in_TBLPTR = (byte *)CONCAT12((char)((uint3)uVar11 >> 0x10),CONCAT11(cVar10,(char)uVar11));
      lcd_text_flag = *in_TBLPTR;
      puVar5 = pbVar4 + 1;
      if ((pbVar4[-3] & 0x80) != 0) {
        lcd_text_flag = ~lcd_text_flag;
      }
      pbVar7 = (byte *)((short)in_FSR1 + 1);
      *(byte *)in_FSR1 = lcd_text_flag;
      lcd_write_data();
      in_FSR1 = (BADSPACEBASE *)(pbVar7 + -1);
      *pbVar7 = *pbVar7;
      pbVar6 = puVar5;
    }
    else {
      c18_tmp0 = text_x_adjust;
      bVar9 = text_x_adjust + 1;
      bVar13 = -1 < (char)text_x_adjust;
      pbVar6 = pbVar3 + 1;
      text_x_adjust = bVar9;
      if ((bVar13) && (pbVar6 = pbVar3 + 1, bVar9 < text_width_saved)) goto LAB_CODE_00cc90;
    }
    lcd_text_width = lcd_text_width + 1;
    pbVar3 = pbVar6;
  } while( true );
}

