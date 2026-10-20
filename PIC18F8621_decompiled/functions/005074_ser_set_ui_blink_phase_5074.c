// address 0x005074  size 12 bytes
// callers: 004550,

/* Auto: writes ui_blink_phase; 6 instr */

undefined1 ser_set_ui_blink_phase_5074(void)

{
  ui_stack_adjust_4e78();
  ui_to_ser_to_text_draw_word_4d7a();
  ui_blink_phase = 2;
  return 2;
}

