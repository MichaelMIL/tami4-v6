// address 0x00261a  size 14 bytes
// callers: 001392,0013b0,

/* "POWER DOWN" */

undefined1 ui_draw_power_down(void)

{
  BADSPACEBASE *in_FSR1;
  
  lcd_clear();
  ui_draw_title_word(10);
  *(undefined1 *)in_FSR1 = 2;
  return 2;
}

