// address 0x00c9bc  size 42 bytes
// callers: 006e5c,002d86,

/* Heating system state: 0 sleep, 1 normal, 2 extra-hot, 3 delay, 4 no heater */

undefined1 heating_get_state(void)

{
  char cVar1;
  byte unaff_Z;
  
  cfg_heater_type();
  if ((unaff_Z & 1) != 0) {
    return 4;
  }
  cVar1 = heater_get_powerup_delay();
  if (cVar1 != '\0') {
    return 3;
  }
  cVar1 = system_get_mode(0);
  if (cVar1 != '\x02') {
    cVar1 = system_get_mode();
    if (cVar1 != '\x01') {
      if ((heating_flags & 1) != 0) {
        return 2;
      }
      return 1;
    }
  }
  return 0;
}

