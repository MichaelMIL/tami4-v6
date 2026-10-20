// address 0x0023f6  size 12 bytes
// callers: 001ae2,001c0c,001f6a,001e3e,

/* Auto: calls lcd_puts_rom; 5 instr */

void ui_to_lcd_puts_rom_23f6(void)

{
  BADSPACEBASE *in_FSR1;
  undefined1 *puVar1;
  
  puVar1 = &FramePointer10x0001;
  lcd_puts_rom();
  *puVar1 = *puVar1;
  puVar1[-1] = puVar1[-1];
  return;
}

