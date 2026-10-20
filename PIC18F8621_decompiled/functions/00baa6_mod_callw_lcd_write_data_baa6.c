// address 0x00baa6  size 10 bytes
// callers: 00bbaa,00bbda,00b7e6,00b772,

/* Auto: Push W as argument and call lcd_write_data; 4 instr */

void mod_callw_lcd_write_data_baa6(void)

{
  BADSPACEBASE *in_FSR1;
  undefined1 *puVar1;
  
  puVar1 = &FramePointer10x0001;
  lcd_write_data();
  *puVar1 = *puVar1;
  return;
}

