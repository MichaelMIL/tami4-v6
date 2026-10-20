// address 0x00c606  size 734 bytes
// callers: (none: entry point, task, or reached via pointer)

/* WARNING: Restarted to delay deadcode elimination for space: DATA */
/* Priority 4 task: hot tank thermostat (normal/sleep/extra-hot), boil and fault detection */

void task_heating(void)

{
  BADSPACEBASE *in_FSR1;
  undefined1 *puVar1;
  char *pcVar2;
  byte *pbVar3;
  char cVar4;
  byte bVar5;
  undefined1 uVar6;
  bool bVar7;
  bool bVar8;
  
code_c0x00c606:
  do {
    while( true ) {
      local1 = heating_read_param(1);
      *(undefined1 *)in_FSR1 = 0;
      puVar1 = (undefined1 *)((short)in_FSR1 + 2);
      *(undefined1 *)((short)in_FSR1 + 1) = local1;
      OSDelay();
      *puVar1 = *puVar1;
      in_FSR1 = (BADSPACEBASE *)(puVar1 + -2);
      puVar1[-1] = puVar1[-1];
      adc_raw_lo = 9;
      OS_Yield();
      cVar4 = cfg_application_b();
      if (cVar4 == '\0') {
        bVar5 = 0;
        goto LAB_CODE_00c878;
      }
      cVar4 = cfg_application_b();
      if (cVar4 != '\x03') break;
      hot_temp_top = 0x32;
      hot_temp_bottom = 0x32;
    }
    hot_temp_bottom = hot_temp_read_bottom();
    hot_temp_top = hot_temp_read_top();
    if (heating_fault == -0x73) {
      bVar5 = 0;
      goto LAB_CODE_00c878;
    }
    if (heating_fault == -0x72) {
      bVar5 = 0;
      goto LAB_CODE_00c878;
    }
    if (heating_fault + 'q' == '\0') {
      bVar5 = 0;
      goto LAB_CODE_00c878;
    }
    cVar4 = system_get_mode(heating_fault + 'q');
    if (cVar4 == '\x02') {
      bVar5 = 0x32;
      hot_temp_bottom = 0x32;
      hot_temp_top = 0x32;
      goto LAB_CODE_00c878;
    }
    cfg_heater_type();
    cVar4 = mod_return_0x01_fca0();
  } while (cVar4 == '\0');
  local0 = hot_temp_top;
  if (fault_code < '\0') {
joined_c0x00c694:
    bVar5 = heating_fault << 1 | 1;
    if (-1 < heating_fault) {
      heating_fault = fault_code;
    }
    goto LAB_CODE_00c878;
  }
  if (hot_temp_top == 0xff) {
LAB_CODE_00c6d8:
    heating_fault = -0x73;
    heater_off();
    uVar6 = 0x8d;
LAB_CODE_00c6f4:
    pcVar2 = (char *)((short)in_FSR1 + 1);
    *(undefined1 *)in_FSR1 = uVar6;
  }
  else {
    if (hot_temp_top == 0xfe) {
LAB_CODE_00c6ea:
      heating_fault = -0x71;
      heater_off();
      uVar6 = 0x8f;
      goto LAB_CODE_00c6f4;
    }
    cVar4 = heating_read_param(0x15);
    if (local0 < cVar4 + 2U) {
      if (fault_code < '\0') goto joined_c0x00c694;
      if (hot_temp_bottom == 0xff) goto LAB_CODE_00c6d8;
      if (hot_temp_bottom == 0xfe) goto LAB_CODE_00c6ea;
      cVar4 = heating_read_param(0x15);
      if (cVar4 + 2U <= hot_temp_bottom) goto LAB_CODE_00c704;
      local3 = heating_read_param(0x13);
      if (local3 + hot_temp_top <= hot_temp_bottom) {
        heater_off();
        if (-1 < heating_fault) {
          heating_fault = -0x76;
        }
        goto code_c0x00c606;
      }
      OS_Yield(hot_temp_bottom - (local3 + hot_temp_top));
      if ((extra_hot_timer == '\0') && ((heating_flags & 1) != 0)) {
        heating_cancel_extra_hot(0);
      }
      local0 = system_get_mode();
      local4 = heating_read_param(0x1d);
      bVar7 = local0 != 0;
      if (local0 != 1) {
        bVar5 = mod_get_hot_temp_top_ca00(local4);
        if ((bVar5 & 0x80) == 0) {
          bVar8 = *(byte *)in_FSR1 <= hot_temp_top;
          bVar5 = hot_temp_top - *(byte *)in_FSR1;
        }
        else {
          bVar8 = *(char *)in_FSR1 < '\0';
          bVar5 = *(char *)in_FSR1 << 1 | bVar7;
        }
        if ((bVar8) || (cVar4 = cfg_application_b(bVar5), cVar4 == '\x03')) {
          dispense_hot_allow();
        }
        if (heater_power_level != '\0') {
          bVar5 = mod_get_hot_temp_top_ca00(0x46);
          if ((bVar5 & 0x80) == 0) {
            bVar7 = *(byte *)in_FSR1 <= hot_temp_top;
          }
          else {
            bVar7 = *(char *)in_FSR1 < '\0';
          }
          if (((bVar7) && ((heating_flags & 0x10) != 0)) && ((heating_flags & 2) == 0)) {
            boil_timer = 0;
            heating_flags = heating_flags | 2;
          }
        }
        bVar5 = mod_get_hot_temp_top_ca00(0x50);
        if ((bVar5 & 0x80) == 0) {
          bVar7 = *(byte *)in_FSR1 <= hot_temp_top;
        }
        else {
          bVar7 = *(char *)in_FSR1 < '\0';
        }
        if ((bVar7) && ((heating_flags & 2) != 0)) {
          stat_H78 = boil_timer;
          uDATA00d7 = 0;
          uDATA00d8 = 0;
          uDATA00d9 = 0;
          pbVar3 = (byte *)((short)in_FSR1 + 1);
          *(undefined1 *)in_FSR1 = 9;
          stat_counter_save();
          in_FSR1 = (BADSPACEBASE *)(pbVar3 + -1);
          *pbVar3 = *pbVar3;
          heating_flags = heating_flags & 0xed;
        }
        local4 = heating_read_param(0x15);
        bVar7 = local4 != 0;
        portion_flow_lo = local4;
        bVar5 = mod_get_hot_temp_top_ca00(local4 - 1);
        if ((bVar5 & 0x80) == 0) {
          bVar8 = *(byte *)in_FSR1 <= hot_temp_top;
          bVar5 = hot_temp_top - *(byte *)in_FSR1;
        }
        else {
          bVar8 = *(char *)in_FSR1 < '\0';
          bVar5 = *(char *)in_FSR1 << 1 | bVar7;
        }
        if (!bVar8) {
          *(byte *)in_FSR1 = portion_flow_lo - 1;
          if (((portion_flow_lo - 1 ^ hot_temp_bottom) & 0x80) == 0) {
            bVar7 = *(byte *)in_FSR1 <= hot_temp_bottom;
            bVar5 = hot_temp_bottom - *(byte *)in_FSR1;
          }
          else {
            bVar7 = *(char *)in_FSR1 < '\0';
            bVar5 = *(char *)in_FSR1 << 1 | portion_flow_lo != 0;
          }
          if (!bVar7) {
            if ((heating_flags & 1) == 0) {
              uVar6 = 0x16;
            }
            else {
              uVar6 = 0x1b;
            }
            cVar4 = heating_read_param_tmp(uVar6);
            local4 = local4 - cVar4;
            if ((heating_flags & 1) == 0) {
              uVar6 = 0x2f;
            }
            else {
              uVar6 = 0x2e;
            }
            cVar4 = heating_read_param_tmp(uVar6);
            portion_flow_lo = portion_flow_lo - cVar4;
            goto LAB_CODE_00c84a;
          }
        }
joined_c0x00c822:
        if ((heating_flags & 1) != 0) {
          bVar5 = heating_cancel_extra_hot(bVar5);
        }
        heating_flags = heating_flags & 0xf7;
LAB_CODE_00c878:
        heater_off(bVar5);
        goto code_c0x00c606;
      }
      bVar5 = mod_get_hot_temp_top_ca00(local4);
      if ((bVar5 & 0x80) == 0) {
        bVar7 = *(byte *)in_FSR1 <= hot_temp_top;
        bVar5 = hot_temp_top - *(byte *)in_FSR1;
      }
      else {
        bVar7 = *(char *)in_FSR1 < '\0';
        bVar5 = *(char *)in_FSR1 << 1 | 1;
      }
      if (!bVar7) {
        dispense_hot_block(bVar5);
      }
      local4 = heating_read_param(0x14);
      portion_flow_lo = local4;
LAB_CODE_00c84a:
      bVar5 = mod_get_hot_temp_top_ca00(local4);
      if ((bVar5 & 0x80) == 0) {
        bVar7 = *(byte *)in_FSR1 <= hot_temp_top;
      }
      else {
        bVar7 = *(char *)in_FSR1 < '\0';
      }
      if (bVar7) {
        *(byte *)in_FSR1 = portion_flow_lo;
        if (((portion_flow_lo ^ hot_temp_bottom) & 0x80) == 0) {
          bVar7 = *(byte *)in_FSR1 <= hot_temp_bottom;
          bVar5 = hot_temp_bottom - *(byte *)in_FSR1;
        }
        else {
          bVar7 = *(char *)in_FSR1 < '\0';
          bVar5 = *(char *)in_FSR1 << 1 | 1;
        }
        if (bVar7) goto joined_c0x00c822;
      }
      local3 = heating_read_param(0x1c);
      local2 = 10;
      if (((heating_flags & 9) == 0) && (heater_power_level == '\0')) {
        if (local0 == 1) {
          uVar6 = 0x17;
        }
        else {
          uVar6 = 0x18;
        }
        cVar4 = heating_read_param_tmp(uVar6);
        bVar5 = mod_get_hot_temp_top_ca00(local4 - cVar4);
        if ((bVar5 & 0x80) == 0) {
          bVar7 = *(byte *)in_FSR1 <= hot_temp_top;
        }
        else {
          bVar7 = *(char *)in_FSR1 < '\0';
        }
        if (bVar7) {
          if (local0 == 1) {
            uVar6 = 0x19;
          }
          else {
            uVar6 = 0x1a;
          }
          cVar4 = heating_read_param_tmp(uVar6);
          *(byte *)in_FSR1 = portion_flow_lo - cVar4;
          if (((portion_flow_lo - cVar4 ^ hot_temp_bottom) & 0x80) == 0) {
            bVar7 = *(byte *)in_FSR1 <= hot_temp_bottom;
          }
          else {
            bVar7 = *(char *)in_FSR1 < '\0';
          }
          if (bVar7) goto code_c0x00c606;
        }
      }
      pcVar2 = (char *)((short)in_FSR1 + 1);
      *(undefined1 *)in_FSR1 = local2;
      heater_set_power();
      goto LAB_CODE_00c8e0;
    }
LAB_CODE_00c704:
    heating_fault = -0x72;
    heater_off();
    pcVar2 = (char *)((short)in_FSR1 + 1);
    *(char *)in_FSR1 = heating_fault;
  }
  heater_set_fault();
LAB_CODE_00c8e0:
  in_FSR1 = (BADSPACEBASE *)(pcVar2 + -1);
  *pcVar2 = *pcVar2;
  goto code_c0x00c606;
}

