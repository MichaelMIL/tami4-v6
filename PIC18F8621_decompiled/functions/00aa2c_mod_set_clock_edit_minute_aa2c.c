// address 0x00aa2c  size 12 bytes
// callers: 00a678,00a6a4,

/* Auto: writes clock_edit_minute; 6 instr */

char mod_set_clock_edit_minute_aa2c(void)

{
  clock_edit_minute = mod_to_eeprom_read_raw_a94c();
  return ';' - clock_edit_minute;
}

