// address 0x00d936  size 12 bytes
// callers: 00e70a,

/* Run fan 300 s after heater switches on */

undefined1 fan_start_heater_runon(void)

{
  fan_heater_runon_lo = 0x2c;
  fan_heater_runon_hi = 1;
  return 1;
}

