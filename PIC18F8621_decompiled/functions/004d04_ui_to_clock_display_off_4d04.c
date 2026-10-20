// address 0x004d04  size 12 bytes
// callers: 003b12,

/* Auto: calls clock_display_off; 4 instr */

void ui_to_clock_display_off_4d04(void)

{
  clock_display_off();
  ui_to_text_draw_char_4fa8(2);
  ui_to_txt_to_text_draw_char_4fb2();
  return;
}

