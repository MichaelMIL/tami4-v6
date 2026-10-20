// address 0x00bb06  size 10 bytes
// callers: 00bb8e,

/* Auto: Small wrapper around lcd_write_data; 4 instr */

void mod_to_lcd_write_data_bb06(void)

{
  BADSPACEBASE *in_FSR1;
  undefined1 *puVar1;
  
  puVar1 = &FramePointer10x0001;
  lcd_write_data();
  *puVar1 = *puVar1;
  return;
}

