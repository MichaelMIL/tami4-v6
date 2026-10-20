// address 0x00cdba  size 12 bytes
// callers: 00ca90,00ca68,

/* Auto: writes lcd_text_flag; 6 instr */

void mod_set_lcd_text_flag_cdba(void)

{
  BADSPACEBASE *in_FSR1;
  undefined1 *puVar1;
  
  puVar1 = &FramePointer10x0001;
  mod_get_lcd_text_width_ca24();
  *puVar1 = *puVar1;
  lcd_text_flag = lcd_text_flag + '\x01';
  return;
}

