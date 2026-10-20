// address 0x0028be  size 10 bytes
// callers: 001f12,001e3e,0024a8,

/* Auto: Push W as argument and call lcd_write_data; 4 instr */

void ui_callw_lcd_write_data_28be(void)

{
  BADSPACEBASE *in_FSR1;
  undefined1 *puVar1;
  
  puVar1 = &FramePointer10x0001;
  lcd_write_data();
  *puVar1 = *puVar1;
  return;
}

