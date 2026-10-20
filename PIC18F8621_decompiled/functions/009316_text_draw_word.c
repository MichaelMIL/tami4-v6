// address 0x009316  size 164 bytes
// callers: 003ada,002996,004264,0027b0,005048,001582,003b12,

/* Draw a word from the word table (with language/screen header) */

void text_draw_word(void)

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
  
  txt_c18_prologue_9a5a();
  puVar4 = (undefined1 *)((short)in_FSR1 + 1);
  pcVar8 = (char *)((short)in_FSR1 + 1);
  *(undefined1 *)in_FSR1 = *(undefined1 *)in_FSR1;
  if (((((cfg_systemconfig4 & 1) == 0) && (ui_screen != '\x04')) && (ui_screen != '\x05')) &&
     ((ui_screen != '\x14' && (ui_screen + -0x1f != '\0')))) {
    txt_get_c18_tmp0_9ac8(ui_screen + -0x1f);
    c18_tmp2 = 0;
    *puVar4 = in_PRODL;
    puVar4[1] = in_PRODH;
    puVar5 = puVar4 + 3;
    puVar4[2] = c18_tmp2;
    txt_push_args_12_0e_9a26();
    c18_tmp3 = strcpy_rom2ram();
    bVar3 = (byte)puVar5;
    if (bVar3 < 5) {
      puVar6 = (undefined1 *)((ushort)puVar5 & 0xff00);
      puVar5 = puVar6 + -1;
      *puVar6 = *puVar6;
    }
    puVar7 = (undefined1 *)CONCAT11((char)((ushort)puVar5 >> 8),bVar3 - 5);
    txt_push_args_12_0e_9a26(c18_tmp3);
    uVar11 = mod_set_lcd_text_maxwidth_cbf2();
    *puVar7 = *puVar7;
    pcVar8 = puVar7 + -2;
    puVar7[-1] = puVar7[-1];
    *(undefined1 *)in_FSR2 = uVar11;
    while (*(char *)in_FSR2 != '\0') {
      pcVar2 = (char *)((short)in_FSR2 + 1);
      pcVar9 = pcVar8 + 1;
      *pcVar8 = *(char *)((short)in_FSR2 + 1) + *(char *)((short)in_FSR2 + -3) + -1;
      text_draw_char();
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
    text_row = *(undefined1 *)((short)in_FSR2 + -2);
    uVar11 = 0x16;
  }
  else {
    text_row = *(undefined1 *)((short)in_FSR2 + -2);
    uVar11 = 6;
  }
  *pcVar8 = uVar11;
  pcVar8[1] = 0;
  puVar10 = pcVar8 + 3;
  pcVar8[2] = *(undefined1 *)in_FSR2;
  txt_set_ui_hold_counter_98fc();
  *puVar10 = *puVar10;
  txt_stack_adjust_9aa8();
  return;
}

