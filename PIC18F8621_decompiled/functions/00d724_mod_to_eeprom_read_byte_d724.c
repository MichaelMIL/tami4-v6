// address 0x00d724  size 14 bytes
// callers: 00d5ca,00d5a8,00d4a4,00d668,

/* Auto: calls eeprom_read_byte; 6 instr */

char mod_to_eeprom_read_byte_d724(void)

{
  char cVar1;
  
  cVar1 = '\x01';
  c18_tmp0 = eeprom_read_byte();
  return cVar1 + -6;
}

