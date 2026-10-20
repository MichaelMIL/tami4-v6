// address 0x00aa56  size 478 bytes
// callers: (none: entry point, task, or reached via pointer)

/* WARNING: Restarted to delay deadcode elimination for space: DATA */
/* Priority 3 task: sequence cold/hot dispensing valves, inlet refill, hot dispense time limit */

void task_dispense(void)

{
  bool bVar1;
  BADSPACEBASE *in_FSR1;
  undefined1 *puVar2;
  char *pcVar3;
  undefined1 *puVar4;
  undefined1 *puVar5;
  undefined1 *puVar6;
  undefined1 *puVar7;
  byte bVar8;
  undefined1 uVar9;
  char cVar10;
  byte bVar11;
  bool bVar12;
  bool bVar13;
  
  do {
    while( true ) {
      bVar8 = dispense_request;
      if (dispense_request == 0) {
        dispense_task_state = 1;
        puVar2 = (undefined1 *)((short)in_FSR1 + 1);
        *(undefined1 *)in_FSR1 = 0;
        dispense_os_delay();
        adc_raw_lo = 0x11;
        bVar8 = OS_Yield();
        in_FSR1 = (BADSPACEBASE *)puVar2;
      }
      bVar8 = system_get_mode(bVar8);
      bVar13 = bVar8 < 3;
      bVar12 = bVar8 == 2;
      if (!bVar12) break;
      dispense_request = 0;
    }
    bVar8 = dispense_request;
    if (((dispense_request & 4) != 0) &&
       (bVar8 = dispense_request & 0xfb, (dispense_active & 1) != 0)) {
      bVar11 = dispense_request & 0x10;
      dispense_request = bVar8;
      if (bVar11 == 0) {
        uVar9 = dispense_close_inlet_after(8);
        if (bVar12) {
LAB_CODE_00aa96:
          ui_set_ui_alarm_index_4894(uVar9);
        }
        else {
          bVar13 = 1 < portion_mode;
          uVar9 = 0;
          if (portion_mode == 2) goto LAB_CODE_00aa96;
        }
        dispense_delay(2);
        adc_raw_lo = 5;
        OS_Yield();
      }
      cold_valve_close();
      uv_start_keep_cycle();
      pcVar3 = (char *)((short)in_FSR1 + 1);
      *(undefined1 *)in_FSR1 = 3;
      stat_counter_save();
      in_FSR1 = (BADSPACEBASE *)(pcVar3 + -1);
      cVar10 = *pcVar3;
      *pcVar3 = cVar10;
      bVar12 = cVar10 == '\0';
      dispense_active = dispense_active & 0xfe;
      bVar8 = dispense_request;
    }
    dispense_request = bVar8;
    bVar8 = dispense_request;
    if (((dispense_request & 8) != 0) &&
       (bVar8 = dispense_request & 0xf7, (dispense_active & 2) != 0)) {
      bVar11 = dispense_request & 0x10;
      dispense_request = bVar8;
      if (bVar11 == 0) {
        uVar9 = dispense_close_inlet_after(0x21);
        if (bVar12) {
LAB_CODE_00aad8:
          ui_set_ui_alarm_index_4894(uVar9);
        }
        else {
          bVar13 = 1 < portion_mode;
          uVar9 = 0;
          if (portion_mode == 2) goto LAB_CODE_00aad8;
        }
        dispense_delay(3);
        adc_raw_lo = 8;
        OS_Yield();
      }
      hot_valve_close();
      puVar4 = (undefined1 *)((short)in_FSR1 + 1);
      *(undefined1 *)in_FSR1 = 4;
      stat_counter_save();
      in_FSR1 = (BADSPACEBASE *)(puVar4 + -1);
      *puVar4 = *puVar4;
      dispense_active = dispense_active & 0xfd;
      bVar8 = dispense_request;
    }
    dispense_request = bVar8;
    bVar8 = dispense_request & 0xef;
    if (((dispense_request & 1) != 0) &&
       (dispense_request = dispense_request & 0xee, bVar8 = dispense_request,
       (dispense_active & 1) == 0)) {
      if ((dispense_active & 2) != 0) {
        dispense_request = dispense_request | 8;
      }
      cVar10 = uv_is_available();
      if (cVar10 == '\0') {
LAB_CODE_00ab1a:
        bVar11 = 0;
        bVar8 = dispense_request;
        if ((cfg_systemconfig & 8) != 0) goto LAB_CODE_00abac;
      }
      else {
        bVar12 = uv_alarm_code < '\0';
        bVar11 = uv_alarm_code << 1 | bVar13;
        bVar13 = bVar12;
        if (bVar12) goto LAB_CODE_00ab1a;
      }
      uv_start_keep_cycle(bVar11);
      dispense_uv_wait_lo = -0x18;
      dispense_uv_wait_hi = 3;
      while (((uv_status & 1) != 0 && (cVar10 = uv_is_available(uv_status & 1), cVar10 != '\0'))) {
        c18_tmp0 = dispense_uv_wait_lo;
        c18_tmp1 = dispense_uv_wait_hi;
        cVar10 = dispense_uv_wait_lo + -1;
        bVar13 = dispense_uv_wait_hi != ~(dispense_uv_wait_lo != '\0');
        bVar8 = dispense_uv_wait_hi - ~(dispense_uv_wait_lo != '\0');
        bVar12 = dispense_uv_wait_hi == 0;
        bVar1 = dispense_uv_wait_lo == '\0';
        dispense_uv_wait_lo = cVar10;
        dispense_uv_wait_hi = bVar8;
        if (bVar12 && bVar1) break;
        dispense_task_state = 4;
        puVar5 = (undefined1 *)((short)in_FSR1 + 1);
        *(undefined1 *)in_FSR1 = 0;
        dispense_os_delay(1);
        adc_raw_lo = 2;
        OS_Yield();
        in_FSR1 = (BADSPACEBASE *)puVar5;
      }
      if (((uv_status & 1) == 0) ||
         (cVar10 = uv_is_available(uv_status & 1), bVar8 = dispense_request, cVar10 == '\0')) {
        mod_to_dispense_read_param_afe2(7);
        cold_valve_open();
        if ((outputs_shadow & 1) == 0) {
          dispense_delay(5);
          adc_raw_lo = 3;
          OS_Yield();
          inlet_valve_open();
        }
        puVar6 = (undefined1 *)((short)in_FSR1 + 1);
        *(undefined1 *)in_FSR1 = 3;
        stat_counter_inc();
        in_FSR1 = (BADSPACEBASE *)(puVar6 + -1);
        *puVar6 = *puVar6;
        if ((dispense_active & 2) != 0) {
          dispense_request = dispense_request | 0x10;
        }
        dispense_active = dispense_active | 1;
        bVar8 = dispense_request;
      }
    }
LAB_CODE_00abac:
    do {
      do {
        dispense_request = bVar8;
        if ((dispense_request & 2) == 0) goto LAB_CODE_00abf8;
        dispense_request = dispense_request & 0xfd;
        bVar8 = dispense_request;
      } while ((dispense_active & 2) != 0);
      if ((dispense_active & 1) != 0) {
        dispense_request = dispense_request | 4;
      }
      bVar8 = dispense_request;
    } while (hot_dispense_allowed == '\0');
    mod_to_dispense_read_param_afe2(0x20);
    hot_valve_open();
    if ((outputs_shadow & 1) == 0) {
      dispense_delay(6);
      adc_raw_lo = 6;
      OS_Yield();
      inlet_valve_open();
    }
    puVar7 = (undefined1 *)((short)in_FSR1 + 1);
    *(undefined1 *)in_FSR1 = 4;
    stat_counter_inc();
    in_FSR1 = (BADSPACEBASE *)(puVar7 + -1);
    *puVar7 = *puVar7;
    hot_dispense_timer = dispense_read_param(0x1f);
    if ((dispense_active & 1) != 0) {
      dispense_request = dispense_request | 0x10;
    }
    dispense_active = dispense_active | 2;
LAB_CODE_00abf8:
    if ((dispense_active & 1) != 0) {
      bVar8 = inlet_valve_fault << 1 | bVar13;
      bVar13 = true;
      if (inlet_valve_fault < '\0') {
LAB_CODE_00ac08:
        dispense_request = dispense_request | 4;
      }
      else {
        bVar13 = cold_valve_fault < '\0';
        bVar8 = cold_valve_fault << 1;
        if (bVar13) goto LAB_CODE_00ac08;
      }
      mod_to_compressor_load_maxon_ea3a(bVar8);
      uv_start_keep_cycle();
    }
    if ((dispense_active & 2) != 0) {
      bVar8 = inlet_valve_fault << 1 | bVar13;
      if ((inlet_valve_fault < '\0') || (bVar8 = hot_valve_fault << 1, hot_valve_fault < '\0')) {
        dispense_request = dispense_request | 8;
      }
      mod_to_heater_load_maxon_e838(bVar8);
      heating_restart_extra_hot_timer();
    }
  } while( true );
}

