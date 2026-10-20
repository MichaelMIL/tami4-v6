// address 0x00323c  size 226 bytes
// callers: 002c22,

/* Handle released keys */

byte ui_on_key_release(void)

{
  char cVar1;
  char cVar2;
  byte bVar3;
  
  cVar1 = ui_get_menu_flag_033c();
  if ((cVar1 != '\0') && ((local2 & 0x20) != 0)) {
    fn_2220_on_aux();
  }
  if ((ui_screen == '\v') && (ui_hold_counter != '\0')) {
    return -ui_hold_counter;
  }
  if (ui_screen == '\x14') {
    return 0;
  }
  if (ui_screen == '\x1f') {
    return 0;
  }
  bVar3 = ui_screen - 0x11;
  if ((bVar3 == 0) && (bVar3 = local2 & 2, bVar3 == 0)) {
    return 0;
  }
  if (((((local2 & 1) != 0) && (bVar3 = ~key_cold_hold_lo, bVar3 == 0)) &&
      (bVar3 = ~key_cold_hold_hi, bVar3 == 0)) &&
     (((bVar3 = 0, ui_screen != '\r' && (bVar3 = 0, ui_screen != '\f')) &&
      (bVar3 = 0, ui_screen != '\x0f')))) {
    bVar3 = 0;
    if (ui_screen + -0xe != '\0') {
      bVar3 = dispense_stop_all(ui_screen + -0xe);
    }
  }
  if ((local2 & 2) != 0) {
    if ((ui_screen == '\x11') || (ui_screen == '\x10')) {
      cVar1 = '\0';
      if ((cfg_systemconfig5 & 4) != 0) {
        cVar2 = ui_to_eeprom_read_param_4f64(0x42);
        cVar1 = -cVar2;
        if ((cVar2 != '\0') && (cVar1 = '\0', key_hot_hold_hi != '\0' || key_hot_hold_lo != '\0')) {
          key_hot_hold_lo = '\0';
          key_hot_hold_hi = '\0';
          dispense_hot_cup();
          bVar3 = ui_set_ui_screen_4e10(0x12);
          goto LAB_CODE_0032f4;
        }
      }
      bVar3 = dispense_stop_all(cVar1);
    }
    else if ((ui_screen == '\x15') || (bVar3 = ui_screen - 0x17, bVar3 == 0)) {
      bVar3 = 0x18;
      ui_screen = '\x18';
    }
  }
LAB_CODE_0032f4:
  if (((local2 & 8) != 0) && ((ui_screen == '\x16' || (bVar3 = ui_screen - 0x17, bVar3 == 0)))) {
    bVar3 = 0x18;
    ui_screen = '\x18';
  }
  if ((((local2 & 0x40) != 0) && (bVar3 = 0, ui_menu_param != '\0')) &&
     (bVar3 = -ui_menu_param, ui_menu_param != '\0')) {
    ui_menu_param = '\0';
  }
  return bVar3;
}

