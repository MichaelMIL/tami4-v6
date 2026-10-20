// address 0x007ab2  size 10 bytes
// callers: 0079f4,007a16,

/* Auto: reads TBLPTRH; calls uart2_puts_rom; 5 instr */

void ser_to_uart2_puts_rom_7ab2(void)

{
  BADSPACEBASE *in_FSR1;
  
  ser_get_TABLAT_7ad2();
  uart2_puts_rom();
  *(undefined1 *)in_FSR1 = *(undefined1 *)in_FSR1;
  return;
}

