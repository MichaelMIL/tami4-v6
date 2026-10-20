// address 0x00d144  size 16 bytes
// callers: 00cfee,00d008,

/* Auto: writes lcd_page_counter; 8 instr */

void mod_set_lcd_page_counter_d144(void)

{
  BADSPACEBASE *in_FSR1;
  undefined1 *puVar1;
  
  puVar1 = &FramePointer10x0002;
  mod_set_lcd_delay_counter_cf6e();
  *puVar1 = *puVar1;
  puVar1[-1] = puVar1[-1];
  lcd_page_counter = lcd_page_counter + '\x01';
  return;
}

