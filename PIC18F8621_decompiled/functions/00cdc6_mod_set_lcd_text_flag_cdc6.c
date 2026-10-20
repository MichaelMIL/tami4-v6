// address 0x00cdc6  size 12 bytes
// callers: 00caa4,00ca7c,

/* Auto: writes lcd_text_flag; 6 instr */

void mod_set_lcd_text_flag_cdc6(void)

{
  BADSPACEBASE *in_FSR1;
  undefined1 *puVar1;
  
  puVar1 = &FramePointer10x0001;
  mod_get_lcd_text_width_ca3a();
  *puVar1 = *puVar1;
  lcd_text_flag = lcd_text_flag + '\x01';
  return;
}

