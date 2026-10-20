// address 0x00d15c  size 8 bytes
// callers: 00cfd8,00cfc6,

/* Auto: calls lcd_write_cmd; 4 instr */

void mod_to_lcd_write_cmd_d15c(void)

{
  BADSPACEBASE *in_FSR1;
  undefined1 *puVar1;
  
  puVar1 = &FramePointer10x0001;
  lcd_write_cmd();
  *puVar1 = *puVar1;
  return;
}

