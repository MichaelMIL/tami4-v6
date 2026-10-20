// address 0x00aa20  size 12 bytes
// callers: 00a678,00a6a4,

/* Auto: writes clock_edit_hour; 6 instr */

char mod_set_clock_edit_hour_aa20(void)

{
  clock_edit_hour = mod_to_eeprom_read_raw_a94c();
  return '\x17' - clock_edit_hour;
}

