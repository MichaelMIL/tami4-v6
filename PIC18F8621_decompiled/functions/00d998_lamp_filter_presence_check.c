// address 0x00d998  size 204 bytes
// callers: 00d794,

/* UV lamp switch (RJ0) / filter switch (RC3): on removal stop loads, show INSERT screen; on refit
   ask NEW/OLD */

void lamp_filter_presence_check(void)

{
  byte bVar1;
  char cVar2;
  
  if ((cfg_systemconfig4 & 0x20) != 0) {
    bVar1 = PORTJ;
    if ((bVar1 & RJ0) != 0) {
      presence_flags = presence_flags | 2;
      cVar2 = ui_get_menu_mode_1122(bVar1 & RJ0);
      if ((cVar2 == '\0') || (cVar2 = ui_get_menu_mode_1122(), cVar2 == '\x04')) {
        uv_alarm_code = 0x82;
        ui_get_ui_screen_4ae6();
        screen_uv_lamp_removed();
      }
      loads_stop_and_restart();
    }
  }
  if ((cfg_systemconfig4 & 4) != 0) {
    bVar1 = PORTC;
    if ((bVar1 & RC3) != 0) {
      presence_flags = presence_flags | 1;
      cVar2 = ui_get_menu_mode_1122(bVar1 & RC3);
      if ((cVar2 == '\0') || (cVar2 = ui_get_menu_mode_1122(), cVar2 == '\x02')) {
        ui_get_ui_screen_4ae6();
        screen_filter_removed();
      }
      loads_stop_and_restart();
    }
  }
  if ((((presence_flags & 2) != 0) &&
      (((cfg_systemconfig4 & 0x20) == 0 || (bVar1 = PORTJ, (bVar1 & RJ0) == 0)))) &&
     ((cVar2 = ui_get_menu_mode_1122(0), cVar2 == '\x03' ||
      (cVar2 = ui_get_menu_mode_1122(), cVar2 == '\0')))) {
    presence_flags = presence_flags & 0xfd;
    uv_alarm_code = 0;
    screen_uv_lamp_new_old();
    heating_start_task();
    cooling_start_task();
  }
  if ((((presence_flags & 1) != 0) &&
      (((cfg_systemconfig4 & 4) == 0 || (bVar1 = PORTC, (bVar1 & RC3) == 0)))) &&
     ((cVar2 = ui_get_menu_mode_1122(0), cVar2 == '\x01' ||
      (cVar2 = ui_get_menu_mode_1122(), cVar2 == '\0')))) {
    presence_flags = presence_flags & 0xfe;
    screen_filter_new_old();
    heating_start_task();
    cooling_start_task();
  }
  return;
}

