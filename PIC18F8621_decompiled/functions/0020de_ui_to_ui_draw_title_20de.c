// address 0x0020de  size 10 bytes
// callers: 001ff2,0000ca,000178,00011e,000148,00207e,0020b0,

/* Auto: calls ui_draw_title,ui_draw_on_off; 3 instr */

void ui_to_ui_draw_title_20de(void)

{
  ui_to_lcd_clear_2bf2();
  ui_draw_title();
  ui_draw_on_off();
  return;
}

