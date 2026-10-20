// address 0x0029be  size 14 bytes
// callers: 00122e,001334,

/* "FLUSHING" */

void ui_draw_flushing(void)

{
  BADSPACEBASE *in_FSR1;
  
  ui_word_filter_233c();
  *(undefined1 *)in_FSR1 = 2;
  ui_draw_word_push6(0x55);
  ui_draw_press_any_key_to_stop();
  return;
}

