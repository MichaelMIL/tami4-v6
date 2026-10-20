// address 0x002874  size 14 bytes
// callers: 000342,000304,

/* Auto: writes text_row; calls ui_draw_title_word; 6 instr */

void ui_to_ui_draw_title_word_2874(void)

{
  ui_draw_title_word();
  text_row = 4;
  ui_stack_adjust_2bdc(0x16);
  return;
}

