// address 0x00ea8a  size 12 bytes
// callers: 00e8e6,

/* Load maximum run time from EEPROM (TCOMPMAXON) */

void compressor_load_maxon(void)

{
  compressor_maxon_lo = compressor_read_param(10);
  compressor_maxon_hi = 0;
  return;
}

