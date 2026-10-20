// address 0x007a16  size 16 bytes
// callers: 007848,007910,

/* Auto: reads TBLPTRL; 8 instr */

void ser_get_TBLPTRL_7a16(void)

{
  BADSPACEBASE *in_FSR1;
  undefined1 *puVar1;
  
  puVar1 = &FramePointer10xfffe;
  ser_to_uart2_puts_rom_7ab2(0xfc);
  *puVar1 = *puVar1;
  return;
}

