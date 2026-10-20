// address 0x002b00  size 8 bytes
// callers: 001974,00228c,000b9c,0004f6,

/* Auto: calls eeprom_read_raw; 3 instr */

void ui_to_eeprom_read_raw_2b00(void)

{
  BADSPACEBASE *in_FSR1;
  
  eeprom_read_raw();
  *(undefined1 *)in_FSR1 = *(undefined1 *)in_FSR1;
  return;
}

