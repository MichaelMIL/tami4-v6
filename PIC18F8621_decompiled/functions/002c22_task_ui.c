// address 0x002c22  size 282 bytes
// callers: (none: entry point, task, or reached via pointer)

/* WARNING: Restarted to delay deadcode elimination for space: DATA */
/* Priority 2 task: keypad debounce, key press/release dispatch, buzzer, screen refresh */

void task_ui(void)

{
  BADSPACEBASE *in_FSR1;
  undefined1 *puVar1;
  undefined1 *puVar2;
  byte bVar3;
  
  lcd_clear();
  if ((cfg_systemconfig4 & 1) == 0) {
    clock_draw();
    ui_screen = 0;
    if ((cfg_systemconfig5 & 0x80) == 0) {
      ui_get_PORTH_4f12();
    }
    else {
      bVar3 = PORTH;
      PORTH = bVar3 | RH7;
      bVar3 = PORTB;
      PORTB = bVar3 | RB0;
      bVar3 = PORTB;
      PORTB = bVar3 & ~RB1;
      bVar3 = PORTC;
      PORTC = bVar3 | RC0;
    }
    bVar3 = PORTC;
    PORTC = bVar3 & ~RC1;
  }
  else {
    ui_screen = 0x1e;
  }
  ui_return_screen = ui_screen;
  key_cold_hold_lo = 0xff;
  key_cold_hold_hi = 0xff;
  key_hot_hold_lo = 0;
  key_hot_hold_hi = 0;
  if ((cfg_systemconfig4 & 0x40) != 0) {
    cfg_systemconfig3 = cfg_systemconfig3 & 0x4f;
  }
  do {
    bVar3 = ui_to_ui_to_eeprom_read_param_4efc(1);
    if (ui_refresh_timer < bVar3) {
      ui_refresh_timer = 0;
    }
    else {
      ui_refresh_timer = ui_refresh_timer - local0;
    }
    *(undefined1 *)in_FSR1 = 0;
    puVar1 = (undefined1 *)((short)in_FSR1 + 2);
    *(byte *)((short)in_FSR1 + 1) = local0;
    OSDelay();
    *puVar1 = *puVar1;
    in_FSR1 = (BADSPACEBASE *)(puVar1 + -2);
    puVar1[-1] = puVar1[-1];
    adc_raw_lo = 1;
    OS_Yield();
    bVar3 = keypad_scan();
    local0 = bVar3 & 0x7f;
    if ((keys_current ^ local0) != 0) {
      ui_param_dbnccntr_4eb2(keys_current ^ local0);
      while (keys_changed != 0) {
        bVar3 = keypad_scan(keys_changed);
        bVar3 = bVar3 & 0x7f ^ local0;
        if (bVar3 == 0) {
          keys_changed = keys_changed - 1;
        }
        else {
          ui_param_dbnccntr_4eb2(bVar3);
        }
        bVar3 = keypad_scan();
        keys_sample = bVar3 & 0x7f;
        *(undefined1 *)in_FSR1 = 0;
        puVar2 = (undefined1 *)((short)in_FSR1 + 2);
        *(undefined1 *)((short)in_FSR1 + 1) = 1;
        OSDelay();
        *puVar2 = *puVar2;
        in_FSR1 = (BADSPACEBASE *)(puVar2 + -2);
        puVar2[-1] = puVar2[-1];
        adc_raw_lo = 0x12;
        OS_Yield();
        local0 = keys_sample;
      }
      keys_changed = keys_current ^ local0;
      keys_current = local0;
      local1 = local0 & keys_changed;
      local2 = keys_changed & ~local0;
      if (local1 != 0) {
        ui_on_key_press(local1);
        ui_get_PORTH_4f04();
        ui_backlight_timeout = 0x78;
      }
      if (local2 != 0) {
        ui_on_key_release(local2);
      }
    }
    if ((buzzer_pattern & 0x80) == 0) {
      bVar3 = PORTB;
      PORTB = bVar3 & ~RB3;
    }
    else {
      bVar3 = PORTB;
      PORTB = bVar3 | RB3;
    }
    bVar3 = ui_refresh_timer;
    if (ui_refresh_timer == 0) {
      ui_refresh_timer = ui_to_eeprom_read_param_4f64(0x24);
      buzzer_pattern = buzzer_pattern << 1;
      bVar3 = ui_refresh_screen();
    }
    ui_update(bVar3);
  } while( true );
}

