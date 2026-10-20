// address 0x00a588  size 206 bytes
// callers: 00b104,

/* Per minute: advance clock, daily counters, check wake-up timers 1 and 2 */

char clock_minute_tick(void)

{
  BADSPACEBASE *in_FSR1;
  undefined1 *puVar1;
  byte *pbVar2;
  char cVar3;
  byte bVar4;
  char cVar5;
  
  if (clock_minute < 0x3b) {
    clock_minute = clock_minute + 1;
  }
  else {
    clock_minute = '\0';
    cVar5 = clock_hour - 0x17;
    if (clock_hour < 0x17) {
      bVar4 = clock_hour + 1;
      clock_hour = bVar4;
    }
    else {
      clock_hour = 0;
      if (clock_day < 6) {
        clock_day = clock_day + 1;
      }
      else {
        clock_day = 0;
      }
      if ((cfg_systemconfig & 8) != 0) {
        puVar1 = &FramePointer10x0001;
        stat_counter_inc();
        *puVar1 = *puVar1;
        puVar1[-1] = 0xd;
        stat_counter_save();
        in_FSR1 = (BADSPACEBASE *)(puVar1 + -1);
        *puVar1 = *puVar1;
      }
      pbVar2 = (byte *)((short)in_FSR1 + 1);
      *(undefined1 *)in_FSR1 = 0xe;
      stat_counter_inc();
      *pbVar2 = *pbVar2;
      pbVar2[-1] = 0xe;
      cVar5 = stat_counter_save();
      bVar4 = *pbVar2;
      *pbVar2 = bVar4;
    }
    mod_get_clock_pm_a99c(cVar5);
    if (bVar4 != 0) {
      if (clock_hour < 0xc) {
        clock_pm = 0;
      }
      else {
        clock_pm = 1;
      }
    }
  }
  if (clock_display_on != '\0') {
    if ((cfg_systemconfig3 & 0x80) == 0) {
      if (clock_display_blocked == '\0') {
        clock_draw_text_style(0);
      }
    }
    else {
      clock_draw(clock_display_on);
    }
  }
  cVar3 = system_get_mode();
  cVar5 = '\0';
  if (cVar3 != '\0') {
    if ((((cfg_systemconfig3 & 0x10) != 0) &&
        (bVar4 = mod_to_eeprom_read_raw_a94c(0x36), clock_hour == bVar4)) &&
       (cVar5 = mod_to_eeprom_read_raw_a94c(0x37), clock_minute == cVar5)) {
      system_wake(0);
      cVar5 = ui_to_heating_start_task_3470();
      return cVar5;
    }
    cVar5 = '\0';
    if ((cfg_systemconfig3 & 0x20) != 0) {
      cVar5 = mod_to_eeprom_read_raw_a94c(0x38);
      cVar5 = clock_hour - cVar5;
      if (cVar5 == '\0') {
        cVar5 = mod_to_eeprom_read_raw_a94c(0x39);
        cVar5 = clock_minute - cVar5;
        if (cVar5 == '\0') {
          system_wake(0);
          cVar5 = ui_to_heating_start_task_3470();
        }
      }
    }
  }
  return cVar5;
}

