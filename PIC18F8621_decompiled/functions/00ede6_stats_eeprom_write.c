// address 0x00ede6  size 22 bytes
// callers: 00ed58,00ed94,

/* EEPROM block write helper for statistics */

char stats_eeprom_write(char param_1)

{
  char cVar1;
  byte unaff_C;
  
  c18_tmp3 = c18_tmp3 + param_1 + (unaff_C & 1);
  cVar1 = '\x02';
  c18_tmp4 = eeprom_write_byte();
  return cVar1 + -6;
}

