// address 0x002996  size 12 bytes
// callers: 001304,000f42,

/* Auto: calls text_draw_word,ui_draw_yes_no; 4 instr */

void ui_to_text_draw_word_2996(void)

{
  BADSPACEBASE *in_FSR1;
  undefined1 *puVar1;
  
  puVar1 = &FramePointer10x0001;
  text_draw_word();
  *puVar1 = *puVar1;
  ui_draw_yes_no();
  return;
}

