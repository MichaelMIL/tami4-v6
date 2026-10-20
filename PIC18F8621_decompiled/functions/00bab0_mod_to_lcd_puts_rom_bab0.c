// address 0x00bab0  size 24 bytes
// callers: 00b7e6,00b772,

/* Auto: writes anim_pos; calls lcd_puts_rom; 11 instr */

undefined1 mod_to_lcd_puts_rom_bab0(void)

{
  BADSPACEBASE *in_FSR1;
  undefined1 *puVar1;
  
  puVar1 = &FramePointer10x0002;
  lcd_puts_rom();
  *puVar1 = *puVar1;
  puVar1[-1] = puVar1[-1];
  anim_pos = 2;
  return 2;
}

