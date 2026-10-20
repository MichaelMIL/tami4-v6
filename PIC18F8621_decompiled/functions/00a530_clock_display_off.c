// address 0x00a530  size 8 bytes
// callers: 004e84,004d04,003b12,00331e,

/* Stop showing the clock */

void clock_display_off(void)

{
  clock_display_on = 0;
  mod_to_lcd_draw_glyph_a956();
  return;
}

