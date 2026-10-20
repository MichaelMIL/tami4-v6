// address 0x00cd96  size 10 bytes
// callers: 00cb86,00cbf2,

/* Auto: writes lcd_text_flag; 5 instr */

void mod_set_lcd_text_flag_cd96(void)

{
  BADSPACEBASE *in_FSR1;
  
  mod_c18_prologue_cdd2();
  *(undefined1 *)in_FSR1 = *(undefined1 *)in_FSR1;
  lcd_text_flag = 0;
  return;
}

