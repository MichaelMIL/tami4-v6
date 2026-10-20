// address 0x00e23a  size 86 bytes
// callers: 00e2ba,00e2fc,

/* Draw one segment of the progress popup */

void ui_draw_progress_segment(void)

{
  byte bVar1;
  BADSPACEBASE *in_FSR2;
  byte *pbVar2;
  BADSPACEBASE *in_FSR1;
  undefined1 *puVar3;
  undefined1 *puVar4;
  undefined1 *puVar5;
  undefined1 *puVar6;
  undefined1 *puVar7;
  bool bVar8;
  
  mod_stack_adjust_e496();
  mod_to_mod_get_c18_tmp0_e47e(popup_index * '\x05' + '\x01');
  puVar3 = (undefined1 *)((short)in_FSR1 + 1);
  *(undefined1 *)in_FSR1 = 0xff;
  lcd_write_data();
  puVar4 = puVar3 + -1;
  *puVar3 = *puVar3;
  popup_flag = 1;
  mod_get_popup_icon_e41a();
  bVar1 = *(byte *)in_FSR2;
  *(byte *)in_FSR2 = bVar1 - 6;
  bVar8 = *(byte *)((short)in_FSR2 + 1) != ~(5 < bVar1);
  *(byte *)((short)in_FSR2 + 1) = *(byte *)((short)in_FSR2 + 1) - ~(5 < bVar1);
  pbVar2 = (byte *)in_FSR2;
  puVar5 = puVar4;
  while( true ) {
    mod_get_c18_tmp0_e436();
    if ((c18_tmp1 & 0x80) != 0) break;
    puVar6 = puVar5 + 1;
    *puVar5 = 0x81;
    mod_to_lcd_write_data_e44e();
    puVar5 = puVar6;
    if (!bVar8) {
      bVar8 = pbVar2[3] != '\0';
      pbVar2[2] = pbVar2[3] + -1;
      pbVar2 = pbVar2 + 2;
    }
  }
  puVar7 = puVar5 + 1;
  *puVar5 = 0xff;
  lcd_write_data(c18_tmp1 & 0x80);
  *puVar7 = *puVar7;
  puVar7[-1] = puVar7[-1];
  puVar7[-2] = puVar7[-2];
  mod_c18_epilogue_e40e();
  return;
}

