// address 0x00d740  size 16 bytes
// callers: 00d4a4,

/* Auto: calls eeprom_write_byte_b; 7 instr */

char mod_to_eeprom_write_byte_b_d740(void)

{
  char cVar1;
  
  cVar1 = '\x02';
  c18_tmp2 = eeprom_write_byte_b();
  return cVar1 + -6;
}

