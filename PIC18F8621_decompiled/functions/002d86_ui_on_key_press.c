// address 0x002d86  size 1206 bytes
// callers: 002c22,

/* WARNING: Removing unreachable block (CODE,0x00307e) */
/* WARNING: Removing unreachable block (CODE,0x003084) */
/* WARNING: Removing unreachable block (CODE,0x00308a) */
/* WARNING: Removing unreachable block (CODE,0x003092) */
/* WARNING: Removing unreachable block (CODE,0x003098) */
/* WARNING: Removing unreachable block (CODE,0x0030a0) */
/* WARNING: Removing unreachable block (CODE,0x0030a4) */
/* WARNING: Removing unreachable block (CODE,0x0030aa) */
/* WARNING: Removing unreachable block (CODE,0x0030b2) */
/* WARNING: Removing unreachable block (CODE,0x0030ba) */
/* WARNING: Removing unreachable block (CODE,0x0030bc) */
/* WARNING: Removing unreachable block (CODE,0x0030c2) */
/* WARNING: Removing unreachable block (CODE,0x0030c8) */
/* WARNING: Removing unreachable block (CODE,0x0030ce) */
/* WARNING: Removing unreachable block (CODE,0x0030d6) */
/* WARNING: Removing unreachable block (CODE,0x0030dc) */
/* WARNING: Removing unreachable block (CODE,0x0030e2) */
/* WARNING: Removing unreachable block (CODE,0x00300e) */
/* WARNING: Removing unreachable block (CODE,0x00301a) */
/* WARNING: Removing unreachable block (CODE,0x00304a) */
/* WARNING: Removing unreachable block (CODE,0x003050) */
/* WARNING: Removing unreachable block (CODE,0x003056) */
/* WARNING: Removing unreachable block (CODE,0x00305c) */
/* WARNING: Removing unreachable block (CODE,0x00305e) */
/* WARNING: Removing unreachable block (CODE,0x00306a) */
/* WARNING: Removing unreachable block (CODE,0x003064) */
/* WARNING: Removing unreachable block (CODE,0x003022) */
/* WARNING: Removing unreachable block (CODE,0x00302c) */
/* WARNING: Removing unreachable block (CODE,0x00302e) */
/* WARNING: Removing unreachable block (CODE,0x003034) */
/* WARNING: Removing unreachable block (CODE,0x00303a) */
/* WARNING: Removing unreachable block (CODE,0x003040) */
/* WARNING: Removing unreachable block (CODE,0x003042) */
/* WARNING: Removing unreachable block (CODE,0x002f94) */
/* WARNING: Removing unreachable block (CODE,0x002f9c) */
/* WARNING: Removing unreachable block (CODE,0x002f9e) */
/* WARNING: Removing unreachable block (CODE,0x002fa4) */
/* WARNING: Removing unreachable block (CODE,0x002faa) */
/* WARNING: Removing unreachable block (CODE,0x002fb0) */
/* WARNING: Removing unreachable block (CODE,0x002fb2) */
/* WARNING: Removing unreachable block (CODE,0x002fd0) */
/* WARNING: Removing unreachable block (CODE,0x002fb8) */
/* WARNING: Removing unreachable block (CODE,0x002fc2) */
/* WARNING: Removing unreachable block (CODE,0x002fc0) */
/* WARNING: Removing unreachable block (CODE,0x0030fa) */
/* WARNING: Removing unreachable block (CODE,0x003106) */
/* WARNING: Removing unreachable block (CODE,0x00310e) */
/* WARNING: Removing unreachable block (CODE,0x003110) */
/* WARNING: Removing unreachable block (CODE,0x003116) */
/* WARNING: Removing unreachable block (CODE,0x003118) */
/* WARNING: Removing unreachable block (CODE,0x00311e) */
/* WARNING: Removing unreachable block (CODE,0x003120) */
/* WARNING: Removing unreachable block (CODE,0x003128) */
/* WARNING: Removing unreachable block (CODE,0x00312a) */
/* WARNING: Removing unreachable block (CODE,0x003132) */
/* WARNING: Removing unreachable block (CODE,0x003134) */
/* WARNING: Removing unreachable block (CODE,0x00315c) */
/* WARNING: Removing unreachable block (CODE,0x00316e) */
/* WARNING: Removing unreachable block (CODE,0x003162) */
/* WARNING: Removing unreachable block (CODE,0x002df4) */
/* WARNING: Removing unreachable block (CODE,0x002dfa) */
/* WARNING: Removing unreachable block (CODE,0x002e4a) */
/* WARNING: Removing unreachable block (CODE,0x002e50) */
/* WARNING: Removing unreachable block (CODE,0x002e56) */
/* WARNING: Removing unreachable block (CODE,0x002e5c) */
/* WARNING: Restarted to delay deadcode elimination for space: DATA */
/* Handle newly pressed keys: fault clearing, menu entry, cup/jug dispensing */

byte ui_on_key_press(void)

{
  BADSPACEBASE *in_FSR1;
  undefined1 *puVar1;
  undefined1 *puVar2;
  undefined1 *puVar3;
  undefined1 *puVar4;
  char cVar5;
  byte bVar6;
  undefined1 uVar7;
  
  if (((cfg_systemconfig & 0x80) != 0) || (keys_changed == '\0')) {
    puVar1 = &FramePointer10x0001;
    ui_get_buzzer_pattern_4850();
    in_FSR1 = (BADSPACEBASE *)(puVar1 + -1);
    *puVar1 = *puVar1;
  }
  if ((local1 & 0xe) != 0) {
    if (((((heating_fault == -0x74) || (heating_fault == -0x76)) || (heating_fault == -0x73)) ||
        ((heating_fault == -0x72 || (heating_fault == -0x71)))) || (heating_fault == -0x77)) {
      heating_fault = '\0';
      heater_fault = '\0';
      ui_set_heater_output_enable_4f1c(0);
    }
    if (heater_fault == -0x7c) {
      puVar2 = (undefined1 *)((short)in_FSR1 + 1);
      *(undefined1 *)in_FSR1 = 0;
      heater_set_fault(0);
      in_FSR1 = (BADSPACEBASE *)(puVar2 + -1);
      *puVar2 = *puVar2;
      ui_set_heater_output_enable_4f1c();
    }
    cVar5 = ui_hot_side_ok();
    if (cVar5 == '\0') {
      ui_get_ui_screen_4ee4();
    }
  }
  if ((local1 & 0x19) != 0) {
    if (((cooling_fault == -0x74) || (cooling_fault == -0x76)) ||
       ((cooling_fault == -0x73 || ((cooling_fault == -0x71 || (cooling_fault == -0x77)))))) {
      cooling_fault = '\0';
      puVar3 = (undefined1 *)((short)in_FSR1 + 1);
      *(undefined1 *)in_FSR1 = 0;
      compressor_set_fault(0);
      in_FSR1 = (BADSPACEBASE *)(puVar3 + -1);
      *puVar3 = *puVar3;
      compressor_output_enable = 1;
      bVar6 = TRISG;
      TRISG = bVar6 & ~TRISG3;
    }
    puVar4 = (undefined1 *)((short)in_FSR1 + 1);
    *(undefined1 *)in_FSR1 = 0;
    cVar5 = ui_cold_side_ok();
    *puVar4 = *puVar4;
    if (cVar5 == '\0') {
      ui_get_ui_screen_4ee4();
    }
    if ((compressor_fault != 0x84) && ((char)compressor_fault < '\0')) {
      ui_to_ui_get_buzzer_pattern_4e32(compressor_fault << 1 | 0x83 < compressor_fault);
      local1 = local1 & 0xe6;
    }
  }
  if ((ui_screen == '\v') && (ui_hold_counter != '\0')) {
    return -ui_hold_counter;
  }
  if (ui_screen == '\x11') {
    return 0;
  }
  if ((((ui_screen == '\t') || (ui_screen == '\r')) || (ui_screen == '\x13')) ||
     (ui_screen == '\x0f')) {
    ui_screen = '\n';
    bVar6 = dispense_stop_all();
    return bVar6;
  }
  if ((ui_menu_active == '\0') &&
     ((((((ui_screen == '\0' || (ui_screen == '\x01')) ||
         ((ui_screen == '\x1b' || ((ui_screen == '\x1c' || (ui_screen == '\x1d')))))) ||
        (ui_screen == '\x14')) ||
       (((ui_screen == '\x1f' || (ui_screen == '\x02')) || (ui_screen == '\x03')))) &&
      (local1 == 0x20)))) {
    uVar7 = 0;
    if (ui_screen != '\x1f') {
      if (ui_screen + -0x14 != '\0') {
        ui_return_screen = ui_screen;
        ui_to_clock_display_off_4e84(ui_screen + -0x14);
      }
      uVar7 = 0x3c;
      ui_screen_timeout = 0x3c;
    }
    cVar5 = menu_enter(uVar7);
    bVar6 = 0x80 - cVar5;
    if (bVar6 == 0) {
      cVar5 = system_get_mode();
      if (cVar5 == '\x02') {
        bVar6 = 0;
      }
      else {
        bVar6 = ui_screen - 0x1f;
        if (bVar6 != 0) {
          ui_screen = '\0';
          return bVar6;
        }
        bVar6 = 0;
      }
    }
  }
  else {
    if ((ui_screen == '\x14') || (ui_screen == '\x1f')) {
      if ((local1 & 1) != 0) {
        menu_key_up(0);
        ui_screen_timeout = 0x3c;
        return 0x3c;
      }
      if ((local1 & 0x10) != 0) {
        menu_key_down();
        ui_screen_timeout = 0x3c;
        return 0x3c;
      }
      if (local1 - 0x40 == '\0') {
        cVar5 = menu_key_back();
        if (cVar5 == '\0') {
          ui_select_home_screen();
        }
      }
      else {
        menu_key_other(local1 - 0x40);
      }
      ui_screen_timeout = 0x3c;
    }
    if ((((ui_screen == '\0') || (ui_screen == '\x01')) ||
        ((ui_screen == '\x1b' || ((ui_screen == '\x1c' || (ui_screen == '\x1d')))))) &&
       (local1 == 2)) {
      ser_test_value_50a4(0);
      bVar6 = ui_push_args_85_ui_set_ui_message_timer_4dc8();
      return bVar6;
    }
    if (((((((ui_screen == '\0') || (ui_screen == '\x01')) || (ui_screen == '\x02')) ||
          ((ui_screen == '\x03' || (ui_screen == '\x1b')))) || (ui_screen == '\x1c')) ||
        (ui_screen == '\x1d')) && (local1 == 8)) {
      ser_test_value_50a4(0);
      bVar6 = ui_push_args_85_ui_set_ui_message_timer_4dc8();
      return bVar6;
    }
    if (local1 == 1) {
      ui_get_ui_screen_4ee4(0);
    }
    if (local1 == 4) {
      ser_test_value_50a4(0);
      bVar6 = ui_push_args_85_ui_set_ui_message_timer_4dc8();
      return bVar6;
    }
    if (((((ui_screen == '\0') || (ui_screen == '\x01')) ||
         ((ui_screen == '\x02' ||
          (((ui_screen == '\x03' || (ui_screen == '\x1b')) || (ui_screen == '\x1c')))))) ||
        (ui_screen == '\x1d')) && (local1 == 0x10)) {
      bVar6 = ui_bank1_ui_get_cfg_systemconfig5_4c34(0);
      if (bVar6 == 1) {
        bVar6 = ui_push_args_85_ui_set_ui_message_timer_4dc8();
        return bVar6;
      }
      local0 = dispense_cold_cup();
      bVar6 = local0 << 1 | bVar6 < 2;
      if (local0 < '\0') {
        return bVar6;
      }
      ui_get_ui_screen_4f38(bVar6);
      if ((bVar6 == 0) || (ui_screen == '\x1c')) {
        ui_return_screen = '\x1b';
      }
      else {
        ui_return_screen = '\0';
      }
      ui_set_ui_screen_4e10(8);
    }
    bVar6 = 0;
    if ((((cfg_systemconfig5 & 2) != 0) && (bVar6 = ui_screen - 7, bVar6 == 0)) &&
       (bVar6 = local1 - 0x10, bVar6 == 0)) {
      bVar6 = ui_bank1_ui_get_cfg_systemconfig5_4c34(0);
      if (bVar6 == 1) {
        bVar6 = ui_push_args_85_ui_set_ui_message_timer_4dc8();
        return bVar6;
      }
      local0 = dispense_jug();
      bVar6 = local0 << 1 | bVar6 < 2;
      if (local0 < '\0') {
        return bVar6;
      }
      ui_get_ui_screen_4f38(bVar6);
      if ((bVar6 == 0) || (ui_screen == '\x1c')) {
        ui_return_screen = '\x1b';
      }
      else {
        ui_return_screen = '\0';
      }
      bVar6 = ui_set_ui_screen_4e10(0xe);
    }
    if (((local1 & 0x40) != 0) && (bVar6 = 0, ui_menu_active != '\0')) {
      ui_menu_active = '\0';
      ui_menu_param = 0;
      cfg_systemconfig4 = ui_to_eeprom_read_param_4f64(0x3a);
      lcd_clear();
      bVar6 = ui_select_home_screen();
    }
  }
  return bVar6;
}

