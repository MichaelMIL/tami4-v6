// address 0x00331e  size 338 bytes
// callers: 002c22,

/* WARNING: Restarted to delay deadcode elimination for space: DATA */
/* Periodic screen/LED update from the UI task loop */

byte ui_update(void)

{
  byte bVar1;
  byte unaff_BSR;
  byte bVar2;
  char cVar3;
  byte unaff_Z;
  
  bVar2 = ui_get_ui_screen_4ee4();
  if ((unaff_Z & 1) == 0) {
    if (*(char *)((ushort)unaff_BSR * 0x100) == '\x1f') {
      return 0;
    }
    if (((*(char *)((ushort)unaff_BSR * 0x100 + 0xc) == '\0') ||
        (*(char *)((ushort)unaff_BSR * 0x100 + 3) != '\0')) ||
       (cVar3 = system_get_mode(0), cVar3 != '\x02')) {
      if (((keys_current & 0xe) != 0) && (ui_wake_pending == '\0')) {
        system_wake(0);
        if ((keys_current & 4) == 0) {
          ui_substate = 0;
        }
        else {
          ui_substate = 1;
        }
      }
    }
    else {
      ui_return_screen = ui_screen;
      ui_to_clock_display_off_4e84();
      ui_screen_timeout = 0x3c;
      screen_exit_power_down();
    }
    if ((((ui_screen == '\x01') || (ui_screen == '\x1b')) ||
        ((ui_screen == '\x1c' ||
         (((ui_screen == '\x1d' || (ui_screen == '\x02')) || (ui_screen == '\x03')))))) &&
       (((keys_current & 1) != 0 && (key_cold_hold_hi == '\0' && key_cold_hold_lo == '\0')))) {
      key_cold_hold_lo = -1;
      key_cold_hold_hi = -1;
      if ((ui_screen == '\x1b') || (ui_screen == '\x1c')) {
        ui_return_screen = '\x1b';
      }
      else {
        ui_return_screen = ui_screen;
      }
      ui_screen = '\x06';
      ui_countdown_100ms = 10;
      dispense_cold_request();
    }
    if ((keys_current & 0x60) == 0x60) {
      if ((ui_menu_param == 0) || (5 < ui_menu_param)) {
        ui_menu_param = 5;
      }
      else if (ui_menu_param == 1) {
        ui_menu_param = 0;
        ui_return_screen = ui_screen;
        ui_to_clock_display_off_4e84(0);
        ui_screen_timeout = 0x3c;
        ui_to_menu_draw_13d8();
      }
    }
    bVar2 = keys_current - 0x40;
    if ((keys_current - 0x40 == 0) && (bVar2 = ui_menu_active, ui_menu_active == 0)) {
      if (ui_menu_param == 0) {
        bVar2 = 10;
        ui_menu_param = 10;
      }
      else {
        bVar2 = ui_menu_param - 1;
        if (bVar2 == 0) {
          clock_display_off(0);
          lcd_clear();
          ui_menu_param = 0;
          bVar2 = 1;
          ui_menu_active = 1;
          cfg_systemconfig4 = cfg_systemconfig4 & 0xd9;
        }
      }
    }
    if ((cfg_systemconfig3 & 0x40) != 0) {
      if ((cfg_systemconfig5 & 8) != 0) {
        bVar2 = PORTH;
        if ((bVar2 & RH1) == 0) {
          bVar2 = PORTH;
          PORTH = bVar2 & ~RH4;
        }
        else {
          bVar2 = PORTH;
          PORTH = bVar2 | RH4;
        }
        bVar2 = PORTH;
        if ((bVar2 & RH2) == 0) {
          bVar2 = PORTH;
          PORTH = bVar2 & ~RH6;
          return 0;
        }
        bVar1 = PORTH;
        PORTH = bVar1 | RH6;
        return bVar2 & RH2;
      }
      bVar2 = PORTH;
      c18_tmp0 = (bVar2 & RH1) != 0;
      bVar2 = PORTH;
      bVar2 = (bool)c18_tmp0 || (bVar2 & 4) != 0;
      if ((bool)bVar2) {
        bVar1 = PORTH;
        PORTH = bVar1 | RH6;
      }
      else {
        bVar1 = PORTH;
        PORTH = bVar1 & ~RH6;
      }
    }
  }
  return bVar2;
}

