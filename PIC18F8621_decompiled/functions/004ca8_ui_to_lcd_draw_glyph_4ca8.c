// address 0x004ca8  size 26 bytes
// callers: 004550,005096,

/* Auto: writes text_fill_width; calls lcd_draw_glyph; 12 instr */

void ui_to_lcd_draw_glyph_4ca8(void)

{
  BADSPACEBASE *in_FSR1;
  undefined1 *puVar1;
  
  text_fill_width = 0x5b;
  puVar1 = &FramePointer10x0004;
  lcd_draw_glyph();
  *puVar1 = *puVar1;
  ser_pop3_return_50b8();
  return;
}

