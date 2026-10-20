// address 0x00d750  size 14 bytes
// callers: 00d5ec,00d640,00d654,

/* Auto: calls eeprom_write_byte; 6 instr */

char mod_to_eeprom_write_byte_d750(void)

{
  char cVar1;
  
  cVar1 = '\x01';
  c18_tmp0 = eeprom_write_byte();
  return cVar1 + -6;
}

