// address 0x009a3e  size 14 bytes
// callers: 0094d8,

/* Auto: writes text_x_end; 6 instr */

void txt_set_text_x_end_9a3e(void)

{
  BADSPACEBASE *in_FSR1;
  undefined1 *puVar1;
  
  puVar1 = &FramePointer10x0001;
  lcd_write_data();
  *puVar1 = *puVar1;
  text_x_end = text_x_end + '\x01';
  return;
}

