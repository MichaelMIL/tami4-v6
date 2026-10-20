// address 0x00e860  size 10 bytes
// callers: 006e5c,

/* Return heater output state */

undefined1 heater_is_on(void)

{
  if (heater_power_level != '\0') {
    return 1;
  }
  return 0;
}

