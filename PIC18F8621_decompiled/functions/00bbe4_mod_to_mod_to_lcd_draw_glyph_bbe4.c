// address 0x00bbe4  size 10 bytes
// callers: 00b85a,00b898,00b944,

/* Auto: Small wrapper around mod_to_lcd_draw_glyph; 5 instr */

char mod_to_mod_to_lcd_draw_glyph_bbe4(void)

{
  BADSPACEBASE *in_FSR2;
  
  mod_to_lcd_draw_glyph_ba84();
  return '\x04' - *(char *)((short)in_FSR2 + -2);
}

