// address 0x00ce1e  size 8 bytes
// callers: 00ca50,00ca3a,00ca24,

/* Auto: Small wrapper around lcd_write_data; 3 instr */

void mod_to_lcd_write_data_ce1e(void)

{
  BADSPACEBASE *in_FSR1;
  
  lcd_write_data();
  *(undefined1 *)in_FSR1 = *(undefined1 *)in_FSR1;
  mod_c18_epilogue_cd24();
  return;
}

