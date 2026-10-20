// address 0x00da82  size 356 bytes
// callers: (none: entry point, task, or reached via pointer)

/* WARNING: Restarted to delay deadcode elimination for space: DATA */
/* Priority 2 task: UV sterilising lamp cycles, filament warm-up, lamp verification (RJ1) */

void task_uv_lamp(void)

{
  byte bVar1;
  BADSPACEBASE *in_FSR1;
  undefined1 *puVar2;
  char cVar3;
  
code_c0x00da82:
  do {
    while( true ) {
      while( true ) {
        local0 = uv_read_param(1);
        *(undefined1 *)in_FSR1 = 0;
        puVar2 = (undefined1 *)((short)in_FSR1 + 2);
        *(char *)((short)in_FSR1 + 1) = local0;
        OSDelay();
        *puVar2 = *puVar2;
        in_FSR1 = (BADSPACEBASE *)(puVar2 + -2);
        puVar2[-1] = puVar2[-1];
        adc_raw_lo = 10;
        OS_Yield();
        if ((((cfg_systemconfig & 8) != 0) && (cVar3 = uv_cfg_application(), cVar3 != '\x03')) &&
           (cVar3 = uv_cfg_application(), cVar3 != '\x01')) break;
        uv_status = 0;
      }
      local0 = system_get_mode();
      cVar3 = uv_is_available();
      if ((cVar3 != '\0') && (local0 != '\x02')) break;
      uv_status = uv_status & 0xfd;
      dispense_stop_all_c(0);
      cold_valve_close();
      uv_lamp_off();
      uv_status = uv_status | 1;
      uv_service_off();
      uv_flags = uv_flags | 1;
      cVar3 = system_get_mode();
      if (cVar3 == '\x02') {
        uv_load_on_time(0x12);
      }
    }
    bVar1 = PORTJ;
    if ((bVar1 & RJ1) != 0) {
      uv_status = uv_status | 1;
    }
    if (uv_service_override != '\0') {
      uv_status = uv_status | 1;
    }
    if ((((uv_flags & 1) != 0) || ((uv_flags & 8) != 0)) || (uv_verify_retries == '\0'))
    goto LAB_CODE_00db4e;
    bVar1 = PORTJ;
    if ((bVar1 & RJ1) != 0) {
      uv_verify_retries = '\0';
      if (uv_alarm_code == -0x70) {
        uv_alarm_code = '\0';
      }
      goto LAB_CODE_00db4e;
    }
    if (uv_verify_period_timer == '\0') {
      uv_verify_retries = uv_verify_retries + -1;
      uv_verify_period_timer = uv_read_param(0x48);
    }
  } while (uv_verify_retries != '\0');
  if (-1 < uv_alarm_code) {
    uv_alarm_code = -0x70;
  }
LAB_CODE_00db4e:
  if (uv_alarm_code != -0x70) {
    if ((uv_flags & 1) == 0) {
      if ((uv_period_counter != '\0') || ((cfg_systemconfig6 & 1) == 0)) goto code_c0x00da82;
      uv_reload_period();
    }
    uv_flags = uv_flags | 1;
    if (uv_service_override != '\0') {
      uv_service_on(uv_service_override);
      uv_filament_timer = uv_read_param(0xf);
    }
    if (uv_filament_timer != '\0') goto code_c0x00da82;
    if ((outputs_shadow & 0x20) == 0) {
      uv_lamp_on(0);
      uv_reload_verify_delay();
      uv_on_timer = uv_on_time;
      uv_verify_off_timer = uv_read_param(0x47);
    }
    bVar1 = PORTJ;
    if ((bVar1 & RJ1) == 0) {
      uv_status = 0;
      uv_reload_verify_delay();
    }
    else if (uv_verify_delay == '\0') {
      bVar1 = PORTJ;
      if ((bVar1 & RJ1) != 0) {
        uv_lamp_off(bVar1 & RJ1);
        uv_status = uv_status | 2;
        if (-1 < uv_alarm_code) {
          uv_alarm_code = -0x75;
        }
        uv_on_timer = '\0';
      }
    }
    if (uv_on_timer != '\0') goto code_c0x00da82;
  }
  uv_lamp_off(0);
  uv_flags = uv_flags & 0xfe;
  uv_load_on_time(0x12);
  uv_reload_period();
  goto code_c0x00da82;
}

