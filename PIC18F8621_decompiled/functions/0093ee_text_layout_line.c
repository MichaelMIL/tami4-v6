// address 0x0093ee  size 234 bytes
// callers: 0094d8,

/* WARNING: Restarted to delay deadcode elimination for space: DATA */
/* Compute alignment and fill for a text line */

void text_layout_line(void)

{
  BADSPACEBASE *in_FSR1;
  byte *pbVar1;
  undefined1 *puVar2;
  undefined1 *puVar3;
  byte bVar4;
  undefined1 uVar5;
  
  txt_c18_prologue_9a5a();
  pbVar1 = (byte *)((short)in_FSR1 + 1);
  *(byte *)in_FSR1 = text_flags & 0xcf;
  txt_frame_push_args_99a8();
  text_width2 = mod_to_text_measure_width_cc0c();
  *pbVar1 = *pbVar1;
  pbVar1[-1] = pbVar1[-1];
  pbVar1[-2] = pbVar1[-2];
  text_x_adjust = '\0';
  text_width_saved = text_width;
  text_x_end = text_x;
  bVar4 = text_flags & 0x60;
  if (bVar4 == 0) {
    bVar4 = text_flags & 6;
    if (bVar4 == 6) {
      c18_tmp0 = 0x40;
      text_x_end = 0x40 - (text_width2 >> 1);
    }
    else if (bVar4 == 4) {
      text_x_end = 0x82 - text_width2;
    }
    else if (bVar4 == 2) {
      text_x_end = 0;
    }
    goto LAB_CODE_00948a;
  }
  if (bVar4 == 0x60) {
    if (text_width < 0xfe || text_width2 < text_width + 2) {
      text_x_end = text_x + (text_width - text_width2 >> 1);
      goto LAB_CODE_00948a;
    }
    bVar4 = text_width2 - text_width >> 1;
  }
  else {
    if (bVar4 != 0x40) goto LAB_CODE_00948a;
    if (text_width < 0xfe || text_width2 < text_width + 2) {
      text_x_end = ((text_width + text_x) - text_width2) + 2;
      goto LAB_CODE_00948a;
    }
    bVar4 = text_width2 - text_width;
  }
  text_x_adjust = -bVar4;
LAB_CODE_00948a:
  bVar4 = text_flags & 0x60;
  if (bVar4 == 0) {
    pbVar1[-3] = text_x_end;
    txt_get_text_row_9a30(0);
  }
  else {
    puVar2 = pbVar1 + -2;
    pbVar1[-3] = text_x;
    txt_get_text_row_9a30(bVar4);
    for (text_column = text_x; text_column < text_x_end; text_column = text_column + 1) {
      if ((text_flags & 0x80) == 0) {
        uVar5 = 0;
      }
      else {
        uVar5 = 0xff;
      }
      puVar3 = puVar2 + 1;
      *puVar2 = uVar5;
      lcd_write_data();
      puVar2 = puVar3 + -1;
      *puVar3 = *puVar3;
    }
    text_x_end = text_x_end - text_x;
  }
  text_x_end = text_x_adjust + text_width2 + text_x_end;
  txt_c18_epilogue_9972();
  return;
}

