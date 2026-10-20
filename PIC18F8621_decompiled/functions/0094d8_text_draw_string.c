// address 0x0094d8  size 282 bytes
// callers: 0098dc,

/* WARNING: Restarted to delay deadcode elimination for space: DATA */
/* Render a string with alignment, newline, tab handling */

void text_draw_string(void)

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
  
  txt_c18_prologue_9a5a();
  if ((text_flags & 0x10) != 0) {
    txt_frame_push_args_99a8();
    text_width2 = mod_set_lcd_text_maxwidth_cbf2();
    puVar4 = (undefined1 *)((short)in_FSR1 + -1);
    puVar5 = (undefined1 *)((short)in_FSR1 + -1);
    *(undefined1 *)in_FSR1 = *(undefined1 *)in_FSR1;
    in_FSR1 = (BADSPACEBASE *)((short)in_FSR1 + -2);
    *puVar4 = *puVar5;
    text_row = text_row - (text_width2 + -1);
  }
  if ((text_flags & 0x60) == 0) {
    pbVar6 = (byte *)((short)in_FSR1 + 1);
    *(byte *)in_FSR1 = text_flags & 0xcf;
    txt_frame_push_args_99a8();
    text_width = text_measure_width();
    *pbVar6 = *pbVar6;
    pbVar6[-1] = pbVar6[-1];
    pbVar6[-2] = pbVar6[-2];
    pbVar9 = pbVar6 + -3;
    if (0x80 < text_width) {
      text_width = 0x80;
      pbVar9 = pbVar6 + -3;
    }
  }
  else {
    text_width = text_fill_width;
    pbVar9 = (byte *)in_FSR1;
  }
  bVar12 = text_flags & 6;
  if (bVar12 == 6) {
    c18_tmp0 = 0x40;
    bVar12 = 0x40 - (text_width >> 1);
    text_x = bVar12;
  }
  else if (bVar12 == 4) {
    bVar12 = 0x82 - text_width;
    text_x = bVar12;
  }
  else {
    bVar12 = bVar12 ^ 2;
    if (bVar12 == 0) {
      text_x = 0;
    }
  }
LAB_CODE_009546:
  txt_frame_push_args_99a8(bVar12);
  text_layout_line();
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
      text_char = *(char *)CONCAT11(*puVar2,*puVar1);
      if (*(char *)CONCAT11(*puVar2,*puVar1) == '\0') {
        cVar14 = '\0';
        if ((text_flags & 0x60) != 0) {
          while (cVar14 = text_x_end - text_width, text_x_end < text_width) {
            if ((text_flags & 0x80) == 0) {
              uVar13 = 0;
            }
            else {
              uVar13 = 0xff;
            }
            txt_set_text_x_end_9a3e(uVar13);
          }
        }
        txt_c18_epilogue_9972(cVar14);
        return;
      }
      if ((text_flags & 8) == 0) break;
LAB_CODE_0095bc:
      *pbVar9 = text_flags & 0xcf | 0x20;
      pbVar10 = pbVar9 + 2;
      pbVar9[1] = text_char;
      text_render_glyphs();
      pbVar11 = pbVar10 + -1;
      *pbVar10 = *pbVar10;
LAB_CODE_0095ce:
      pbVar9 = pbVar11 + -1;
      *pbVar11 = *pbVar11;
    }
    if (text_char == '\n') break;
    if (text_char != '\b') {
      if (text_char == '\r') {
        text_flags = ~(text_flags & 0x80) | text_flags & 0x7f;
      }
      else if (text_char != '\t') goto LAB_CODE_0095bc;
      pbVar11 = pbVar9 + 1;
      *pbVar9 = text_flags & 0xcf | 0x20;
      mod_set_text_x_adjust_cc2c();
      goto LAB_CODE_0095ce;
    }
    text_flags = ~(text_flags & 1) | text_flags & 0xfe;
  } while( true );
  bVar12 = 0;
  text_char = '\n';
  if ((text_flags & 0x60) != 0) {
    while (bVar12 = text_x_end - text_width, text_x_end < text_width) {
      if ((text_flags & 0x80) == 0) {
        uVar13 = 0;
      }
      else {
        uVar13 = 0xff;
      }
      txt_set_text_x_end_9a3e(uVar13);
    }
  }
  text_row = text_row + '\x01';
  goto LAB_CODE_009546;
}

