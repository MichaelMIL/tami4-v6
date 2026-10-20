// address 0x003ada  size 34 bytes
// callers: 003b12,

/* Auto: shows "TUE"; reads ui_header_text; calls text_draw_word; 12 instr */

void ui_word_tue_3ada(void)

{
  BADSPACEBASE *in_FSR1;
  undefined1 *puVar1;
  
  ui_to_text_draw_char_4fa8(2);
  *(undefined1 *)in_FSR1 = 2;
  puVar1 = (undefined1 *)((short)in_FSR1 + 2);
  *(undefined1 *)((short)in_FSR1 + 1) = ui_header_text;
  text_draw_word();
  *puVar1 = *puVar1;
  puVar1[-1] = puVar1[-1];
  ui_to_text_draw_char_4fa8(4);
  ui_to_text_draw_char_4fa8(5);
  return;
}

