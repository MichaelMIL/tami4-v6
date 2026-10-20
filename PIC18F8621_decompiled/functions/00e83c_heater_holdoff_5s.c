// address 0x00e83c  size 10 bytes
// callers: 00e8e6,

/* Hold heater off for 5 s (used when compressor starts) */

void heater_holdoff_5s(void)

{
  heater_holdoff = 5;
  heater_output_off();
  return;
}

