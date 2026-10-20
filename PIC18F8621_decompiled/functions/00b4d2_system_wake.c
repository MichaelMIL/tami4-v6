// address 0x00b4d2  size 38 bytes
// callers: 006e5c,002a58,00a588,002d86,00331e,

/* Leave sleep/standby: mode 0, reload sleep delay from EEPROM */

char system_wake(void)

{
  BADSPACEBASE *in_FSR1;
  undefined1 *puVar1;
  char cVar2;
  
  puVar1 = &FramePointer10x0001;
  cfg_sleep_delay = eeprom_read_param();
  *puVar1 = *puVar1;
  sleep_check_period = 10;
  sleep_countdown = 0xff;
  cVar2 = system_get_mode();
  if (cVar2 == '\0') {
    return cVar2;
  }
  heating_flags = heating_flags | 0x10;
  system_mode = 0;
  return cVar2;
}

