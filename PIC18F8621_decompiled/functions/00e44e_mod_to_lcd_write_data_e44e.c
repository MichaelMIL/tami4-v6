// address 0x00e44e  size 10 bytes
// callers: 00e290,00e23a,00e2d0,

/* Auto: Small wrapper around lcd_write_data; 4 instr */

void mod_to_lcd_write_data_e44e(void)

{
  BADSPACEBASE *in_FSR2;
  BADSPACEBASE *in_FSR1;
  
  lcd_write_data();
  *(undefined1 *)in_FSR1 = *(undefined1 *)in_FSR1;
  *(char *)in_FSR2 = *(char *)in_FSR2 + -1;
  return;
}

