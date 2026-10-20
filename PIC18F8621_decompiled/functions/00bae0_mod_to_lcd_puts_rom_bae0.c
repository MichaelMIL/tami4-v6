// address 0x00bae0  size 18 bytes
// callers: 00b7e6,00b772,

/* Auto: calls lcd_puts_rom; 8 instr */

void mod_to_lcd_puts_rom_bae0(void)

{
  BADSPACEBASE *in_FSR1;
  undefined1 *puVar1;
  
  puVar1 = &FramePointer10x0002;
  lcd_puts_rom();
  *puVar1 = *puVar1;
  puVar1[-1] = puVar1[-1];
  return;
}

