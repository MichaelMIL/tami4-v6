// address 0x00243e  size 12 bytes
// callers: 002a72,001550,

/* "PRESS OK WHEN READY" */

void ui_draw_press_ok_when_ready(void)

{
  BADSPACEBASE *in_FSR1;
  
  ui_draw_word();
  *(undefined1 *)in_FSR1 = 5;
  ui_draw_word(0x69);
  return;
}

