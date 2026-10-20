// address 0x00e700  size 10 bytes
// callers: 00c936,

/* Return 1 when heater power-up delay has elapsed */

undefined1 heater_is_ready(void)

{
  if (heater_powerup_delay != '\0') {
    return 0;
  }
  return 1;
}

