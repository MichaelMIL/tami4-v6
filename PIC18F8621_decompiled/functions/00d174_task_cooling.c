// address 0x00d174  size 558 bytes
// callers: (none: entry point, task, or reached via pointer)

/* WARNING: Restarted to delay deadcode elimination for space: DATA */
/* Priority 4 task: cold tank thermostat driving the compressor, pull-down logging */

void task_cooling(void)

{
  BADSPACEBASE *in_FSR1;
  undefined1 *puVar1;
  byte *pbVar2;
  undefined1 *puVar3;
  byte *pbVar4;
  byte *pbVar5;
  undefined1 *puVar6;
  undefined1 *puVar7;
  undefined1 *puVar8;
  char cVar9;
  undefined1 uVar10;
  byte bVar11;
  bool bVar12;
  
code_c0x00d174:
  do {
    local1 = cooling_read_param(1);
    *(undefined1 *)in_FSR1 = 0;
    puVar1 = (undefined1 *)((short)in_FSR1 + 2);
    *(undefined1 *)((short)in_FSR1 + 1) = local1;
    OSDelay();
    *puVar1 = *puVar1;
    pbVar2 = puVar1 + -2;
    puVar1[-1] = puVar1[-1];
    adc_raw_lo = 0xb;
    OS_Yield();
    bVar11 = 0;
    if ((cfg_systemconfig5 & 0x60) == 0x20) goto LAB_CODE_00d22c;
    cold_temp_a = cold_temp_read_ch4();
    cold_temp_b = cold_temp_read_ch5();
    bVar11 = 0;
    if (cooling_fault == -0x73) goto LAB_CODE_00d22c;
    bVar11 = 0;
    if (cooling_fault + 'q' == '\0') goto LAB_CODE_00d22c;
    cVar9 = system_get_mode(cooling_fault + 'q');
    bVar11 = 0;
    if (cVar9 == '\x02') goto LAB_CODE_00d22c;
    cVar9 = mod_return_0x01_fcaa();
    in_FSR1 = (BADSPACEBASE *)pbVar2;
  } while (cVar9 == '\0');
  if (cold_temp_a == 0xff) {
LAB_CODE_00d1f8:
    cooling_fault = -0x73;
    compressor_stop();
    uVar10 = 0x8d;
  }
  else {
    if (cold_temp_a != 0xfe) {
      if (fault_code < '\0') {
joined_c0x00d226:
        bVar11 = cooling_fault << 1 | 1;
        if (-1 < cooling_fault) {
          cooling_fault = fault_code;
        }
LAB_CODE_00d22c:
        compressor_stop(bVar11);
        in_FSR1 = (BADSPACEBASE *)pbVar2;
        goto code_c0x00d174;
      }
      local0 = cold_temp_b;
      if (cold_temp_b == 0xff) goto LAB_CODE_00d1f8;
      if (cold_temp_b != 0xfe) {
        if (fault_code < '\0') goto joined_c0x00d226;
        OS_Yield(fault_code << 1 | 0xfd < cold_temp_b);
        *pbVar2 = cold_temp_b;
        pbVar4 = pbVar2 + 2;
        pbVar2[1] = cold_temp_a;
        uv_check_cold_abnormal();
        *pbVar4 = *pbVar4;
        in_FSR1 = (BADSPACEBASE *)(pbVar4 + -2);
        pbVar4[-1] = pbVar4[-1];
        cVar9 = system_get_mode();
        if (cVar9 == '\x01') {
          uVar10 = 2;
        }
        else {
          uVar10 = 3;
        }
        local0 = cooling_read_param(uVar10);
        *(byte *)in_FSR1 = local0;
        if (((local0 ^ cold_temp_a) & 0x80) == 0) {
          bVar12 = *(byte *)in_FSR1 < 0xfe || cold_temp_a < *(byte *)in_FSR1 + 2;
        }
        else {
          bVar12 = (char)cold_temp_a < '\0';
        }
        if (bVar12) {
          *(byte *)in_FSR1 = local0;
          if (((local0 ^ cold_temp_b) & 0x80) == 0) {
            bVar11 = *(byte *)in_FSR1;
            bVar12 = bVar11 < 0xfe || cold_temp_b < bVar11 + 2;
            bVar11 = (bVar11 - cold_temp_b) + 2;
          }
          else {
            bVar12 = (char)cold_temp_b < '\0';
            bVar11 = cold_temp_b << 1 | 1;
          }
          if (bVar12) goto LAB_CODE_00d2b2;
        }
        *(undefined1 *)in_FSR1 = 1;
        if ((cold_temp_a & 0x80) == 0) {
          bVar11 = *(byte *)in_FSR1;
          bVar12 = bVar11 < 0xfe || cold_temp_a < bVar11 + 2;
          bVar11 = (bVar11 - cold_temp_a) + 2;
        }
        else {
          bVar12 = (char)cold_temp_a < '\0';
          bVar11 = cold_temp_a << 1;
        }
        if (bVar12) {
LAB_CODE_00d2b2:
          compressor_stop(bVar11);
          if (((cooling_flags & 2) != 0) && ((cooling_flags & 1) != 0)) {
            *(byte *)in_FSR1 = local0;
            if (((local0 ^ cold_temp_a) & 0x80) == 0) {
              bVar12 = *(byte *)in_FSR1 < 0xfe || cold_temp_a < *(byte *)in_FSR1 + 2;
            }
            else {
              bVar12 = (char)cold_temp_a < '\0';
            }
            pulldown_end_temp = cold_temp_b;
            if (bVar12) {
              pulldown_end_temp = cold_temp_a;
            }
            stat_CG = pulldown_time_lo;
            DAT_DATA_00db = pulldown_time_hi;
            uDATA00dc = 0;
            uDATA00dd = 0;
            pbVar5 = (byte *)((short)in_FSR1 + 1);
            *(undefined1 *)in_FSR1 = 10;
            stat_counter_save();
            *pbVar5 = *pbVar5;
            stat_CGT = pulldown_start_temp - pulldown_end_temp;
            pbVar5[-1] = 1;
            stat_byte_save();
            puVar6 = pbVar5 + -1;
            *pbVar5 = *pbVar5;
            cooling_reset_pulldown();
            in_FSR1 = (BADSPACEBASE *)puVar6;
          }
          goto code_c0x00d174;
        }
        *(undefined1 *)in_FSR1 = 1;
        if ((cold_temp_b & 0x80) == 0) {
          bVar11 = *(byte *)in_FSR1;
          bVar12 = bVar11 < 0xfe || cold_temp_b < bVar11 + 2;
          bVar11 = (bVar11 - cold_temp_b) + 2;
        }
        else {
          bVar12 = (char)cold_temp_b < '\0';
          bVar11 = cold_temp_b << 1;
        }
        if (bVar12) goto LAB_CODE_00d2b2;
        local3 = cooling_read_param(4);
        *(byte *)in_FSR1 = local3 + local0;
        if (((local3 + local0 ^ cold_temp_a) & 0x80) == 0) {
          bVar12 = *(byte *)in_FSR1 <= cold_temp_a;
          bVar11 = cold_temp_a - *(byte *)in_FSR1;
        }
        else {
          bVar12 = *(char *)in_FSR1 < '\0';
          bVar11 = *(char *)in_FSR1 << 1 | CARRY1(local3,local0);
        }
        if (bVar12) {
          if ((outputs_shadow & 0x40) != 0) goto code_c0x00d174;
          cVar9 = compressor_start(bVar11);
          if (cVar9 != -0x7d) {
            puVar7 = (undefined1 *)((short)in_FSR1 + 1);
            *(undefined1 *)in_FSR1 = 0;
            cooling_set_demand();
            in_FSR1 = (BADSPACEBASE *)(puVar7 + -1);
            *puVar7 = *puVar7;
            if ((cooling_flags & 2) != 0) {
              cooling_flags = cooling_flags | 1;
              pulldown_start_temp = cold_temp_a;
              in_FSR1 = (BADSPACEBASE *)(puVar7 + -1);
            }
            goto code_c0x00d174;
          }
        }
        else {
          local3 = cooling_read_param(5);
          *(byte *)in_FSR1 = local3 + local0;
          if (((local3 + local0 ^ cold_temp_b) & 0x80) == 0) {
            bVar12 = *(byte *)in_FSR1 <= cold_temp_b;
            bVar11 = cold_temp_b - *(byte *)in_FSR1;
          }
          else {
            bVar12 = *(char *)in_FSR1 < '\0';
            bVar11 = *(char *)in_FSR1 << 1 | CARRY1(local3,local0);
          }
          if ((!bVar12) || ((outputs_shadow & 0x40) != 0)) goto code_c0x00d174;
          cVar9 = compressor_start(bVar11);
          if (cVar9 != -0x7d) {
            puVar8 = (undefined1 *)((short)in_FSR1 + 1);
            *(undefined1 *)in_FSR1 = 0;
            cooling_set_demand();
            in_FSR1 = (BADSPACEBASE *)(puVar8 + -1);
            *puVar8 = *puVar8;
            if ((cooling_flags & 2) != 0) {
              cooling_flags = cooling_flags | 1;
              pulldown_start_temp = cold_temp_b;
              in_FSR1 = (BADSPACEBASE *)(puVar8 + -1);
            }
            goto code_c0x00d174;
          }
        }
        puVar3 = (undefined1 *)((short)in_FSR1 + 1);
        *(undefined1 *)in_FSR1 = 1;
        cooling_set_demand();
        goto LAB_CODE_00d38a;
      }
    }
    cooling_fault = -0x71;
    compressor_stop();
    uVar10 = 0x8f;
  }
  puVar3 = pbVar2 + 1;
  *pbVar2 = uVar10;
  compressor_set_fault();
LAB_CODE_00d38a:
  *puVar3 = *puVar3;
  in_FSR1 = (BADSPACEBASE *)(puVar3 + -1);
  goto code_c0x00d174;
}

