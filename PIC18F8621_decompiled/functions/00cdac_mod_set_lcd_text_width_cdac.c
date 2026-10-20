// address 0x00cdac  size 14 bytes
// callers: 00ca50,00ca3a,00ca24,

/* Auto: writes lcd_text_width; 6 instr */

void mod_set_lcd_text_width_cdac(void)

{
  BADSPACEBASE *in_FSR1;
  undefined1 *puVar1;
  
  puVar1 = &FramePointer10x0001;
  lcd_write_data();
  *puVar1 = *puVar1;
  lcd_text_width = lcd_text_width + '\x01';
  return;
}

