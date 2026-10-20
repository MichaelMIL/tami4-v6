// address 0x00b104  size 338 bytes
// callers: (none: entry point, task, or reached via pointer)

/* Priority 4 task: once-per-second jobs, plus every 10 s and every 60 s jobs */

void task_second(void)

{
  BADSPACEBASE *in_FSR1;
  byte *pbVar1;
  byte bVar2;
  char cVar3;
  byte unaff_Z;
  byte unaff_C;
  bool bVar4;
  
  do {
    do {
      while( true ) {
        pbVar1 = (byte *)((short)in_FSR1 + 1);
        *(undefined1 *)in_FSR1 = 0xa2;
        os_wait_sem_helper(0);
        if ((unaff_Z & 1) != 0) break;
        OS_Yield();
        in_FSR1 = (BADSPACEBASE *)pbVar1;
      }
      inlet_valve_count_usage();
      OS_Yield();
      hot_valve_count_usage();
      OS_Yield();
      cold_valve_count_usage();
      OS_Yield();
      uv_count_usage();
      OS_Yield();
      heating_boil_timer_tick();
      OS_Yield();
      cooling_pulldown_tick();
      OS_Yield();
      heater_second_tick();
      OS_Yield();
      compressor_second_tick();
      OS_Yield();
      ui_second_tick();
      OS_Yield();
      uv_second_tick();
      OS_Yield();
      *pbVar1 = 0;
      if ((standby_countdown & 0x80) == 0) {
        bVar2 = *pbVar1;
        bVar4 = bVar2 < 0xfe || standby_countdown < bVar2 + 2;
        bVar2 = (bVar2 - standby_countdown) + 2;
      }
      else {
        bVar4 = (char)standby_countdown < '\0';
        bVar2 = standby_countdown << 1 | unaff_C & 1;
      }
      in_FSR1 = (BADSPACEBASE *)pbVar1;
      if (bVar4) {
        bVar2 = standby_countdown;
        if (standby_countdown == 0) {
          system_enter_standby(0);
          bVar2 = OS_Yield();
          in_FSR1 = (BADSPACEBASE *)pbVar1;
        }
      }
      else {
        standby_countdown = standby_countdown - 1;
      }
      fan_second_tick(bVar2);
      OS_Yield();
      sec_div_10s = sec_div_10s + '\x01';
      if (sec_div_10s == '\n') {
        heating_timers_10s(0);
        OS_Yield();
        compressor_offdelay_10s_tick();
        OS_Yield();
        inlet_valve_timeout_tick();
        cold_valve_timeout_tick();
        hot_valve_timeout_tick();
        OS_Yield();
        ui_10s_tick();
        OS_Yield();
        sec_div_10s = '\0';
      }
      unaff_C = 0x3b < sec_div_60s + 1;
      cVar3 = sec_div_60s - 0x3b;
      unaff_Z = cVar3 == '\0';
      sec_div_60s = sec_div_60s + 1;
    } while (!(bool)unaff_C);
    sec_div_60s = 0;
    clock_minute_tick(cVar3);
    OS_Yield();
    heating_minute_tick();
    OS_Yield();
    compressor_minute_tick();
    OS_Yield();
    heater_maxon_minute_tick();
    OS_Yield();
    uv_minute_tick();
    OS_Yield();
    cooling_idle_minute_tick();
    OS_Yield();
    bVar2 = cfg_application();
    unaff_C = bVar2 < 4;
    if (bVar2 == 3) {
      unaff_Z = 1;
    }
    else {
      cVar3 = cfg_application();
      unaff_Z = cVar3 == '\0';
      if ((!(bool)unaff_Z) && (unaff_Z = (cfg_systemconfig2 & 1) == 0, !(bool)unaff_Z)) {
        if (heater_fault == -0x7c) {
          unaff_C = 1;
          unaff_Z = 1;
        }
        else {
          *(undefined1 *)in_FSR1 = 0;
          if ((cfg_sleep_delay & 0x80) == 0) {
            unaff_C = *(byte *)in_FSR1 < 0xfe || cfg_sleep_delay < *(byte *)in_FSR1 + 2;
          }
          else {
            unaff_C = (char)cfg_sleep_delay < '\0';
          }
          if ((bool)unaff_C == false) {
            unaff_C = sleep_check_period != '\0';
            sleep_check_period = sleep_check_period + -1;
            if (sleep_check_period == '\0') {
              unaff_C = cfg_sleep_delay != 0;
              cfg_sleep_delay = cfg_sleep_delay - 1;
              unaff_Z = cfg_sleep_delay == 0;
              sleep_check_period = '\n';
            }
            else {
              unaff_Z = 0;
            }
          }
          else {
            unaff_Z = cfg_sleep_delay == 0;
            if ((bool)unaff_Z) {
              system_enter_sleep(0);
            }
          }
        }
      }
    }
  } while( true );
}

