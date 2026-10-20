// address 0x00a94c  size 10 bytes
// callers: 00a588,00aa20,00aa2c,

/* Auto: calls eeprom_read_raw; 4 instr */

void mod_to_eeprom_read_raw_a94c(void)

{
  BADSPACEBASE *in_FSR1;
  undefined1 *puVar1;
  
  puVar1 = &FramePointer10x0001;
  eeprom_read_raw();
  *puVar1 = *puVar1;
  return;
}

