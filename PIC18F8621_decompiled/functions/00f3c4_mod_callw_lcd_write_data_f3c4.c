// address 0x00f3c4  size 10 bytes
// callers: 00f334,00f278,00f364,

/* Auto: Push W as argument and call lcd_write_data; 4 instr */

void mod_callw_lcd_write_data_f3c4(void)

{
  BADSPACEBASE *in_FSR1;
  undefined1 *puVar1;
  
  puVar1 = &FramePointer10x0001;
  lcd_write_data();
  *puVar1 = *puVar1;
  return;
}

