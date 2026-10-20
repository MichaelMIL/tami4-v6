// address 0x00b4a6  size 44 bytes
// callers: 006e5c,00b104,

/* Enter sleep mode (mode 1), reload sleep timers */

char system_enter_sleep(void)

{
  BADSPACEBASE *in_FSR1;
  undefined1 *puVar1;
  char cVar2;
  
  cVar2 = system_get_mode();
  if (cVar2 != '\0') {
    return cVar2;
  }
  system_mode = 1;
  sleep_check_period = 0x3c;
  cfg_sleep_delay = 0xff;
  puVar1 = (undefined1 *)((short)in_FSR1 + 1);
  *(undefined1 *)in_FSR1 = 0x31;
  cVar2 = eeprom_read_raw();
  *puVar1 = *puVar1;
  sleep_countdown = cVar2;
  if (cVar2 == '\0') {
    sleep_countdown = -1;
  }
  cVar2 = ui_set_ui_screen_3496(cVar2);
  return cVar2;
}

