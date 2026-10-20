// address 0x00b4f8  size 24 bytes
// callers: 006e5c,00b104,

/* Enter standby mode (mode 2) */

undefined1 system_enter_standby(void)

{
  char cVar1;
  undefined1 uVar2;
  
  cVar1 = system_get_mode();
  if (cVar1 == '\x02') {
    return 0;
  }
  cfg_sleep_delay = 0xff;
  sleep_countdown = 0xff;
  standby_countdown = 0xff;
  system_mode = 2;
  uVar2 = ui_set_ui_screen_34a2();
  return uVar2;
}

