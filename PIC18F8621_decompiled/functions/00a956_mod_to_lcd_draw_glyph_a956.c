// address 0x00a956  size 30 bytes
// callers: 00a312,00a530,

/* Auto: calls lcd_draw_glyph; 14 instr */

void mod_to_lcd_draw_glyph_a956(void)

{
  BADSPACEBASE *in_FSR1;
  undefined1 *puVar1;
  
  puVar1 = &FramePointer10x0004;
  lcd_draw_glyph();
  *puVar1 = *puVar1;
  puVar1[-1] = puVar1[-1];
  puVar1[-2] = puVar1[-2];
  puVar1[-3] = puVar1[-3];
  return;
}

