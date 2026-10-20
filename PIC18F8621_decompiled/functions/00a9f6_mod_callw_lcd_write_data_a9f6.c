// address 0x00a9f6  size 12 bytes
// callers: 00a312,00a892,00a538,

/* Auto: Push W as argument and call lcd_write_data; 5 instr */

void mod_callw_lcd_write_data_a9f6(void)

{
  BADSPACEBASE *in_FSR1;
  undefined1 *puVar1;
  
  puVar1 = &FramePointer10x0001;
  lcd_write_data();
  *puVar1 = *puVar1;
  local1 = local1 + '\x01';
  return;
}

