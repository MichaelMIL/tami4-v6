// address 0x0029ac  size 18 bytes
// callers: 0003f6,000450,

/* Auto: calls lcd_clear,ui_draw_title; 6 instr */

void ui_to_lcd_clear_29ac(void)

{
  BADSPACEBASE *in_FSR1;
  
  ui_c18_prologue_2166();
  lcd_clear();
  ui_frame_push_args_25cc();
  ui_draw_title();
  *(undefined1 *)in_FSR1 = *(undefined1 *)in_FSR1;
  return;
}

