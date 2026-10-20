// address 0x00d794  size 342 bytes
// callers: (none: entry point, task, or reached via pointer)

/* Priority 4 task (500 ms): condenser fan (RH5), device sensor AN6, dryer over-temp AN7, fault
   inputs */

void task_fan_and_safety(void)

{
  BADSPACEBASE *in_FSR1;
  undefined1 *puVar1;
  undefined1 *puVar2;
  byte *pbVar3;
  byte *pbVar4;
  byte bVar5;
  char cVar6;
  byte bVar7;
  bool bVar8;
  
  do {
    *(undefined1 *)in_FSR1 = 0;
    puVar1 = (undefined1 *)((short)in_FSR1 + 2);
    *(undefined1 *)((short)in_FSR1 + 1) = 0x32;
    OSDelay();
    *puVar1 = *puVar1;
    in_FSR1 = (BADSPACEBASE *)(puVar1 + -2);
    puVar1[-1] = puVar1[-1];
    adc_raw_lo = 0x13;
    OS_Yield();
    if ((cfg_systemconfig4 & 0x10) != 0) {
      local2 = temp_read_ch6();
      if (local2 == 0xff) {
        device_sensor_fault = 0x8d;
      }
      else if (local2 == 0xfe) {
        device_sensor_fault = 0x8f;
      }
      else {
        device_sensor_fault = 0;
      }
      if (device_sensor_fault == 0) {
        if ((outputs_shadow & 0x40) == 0) {
          local0 = fan_read_param(0x3b);
          *(byte *)in_FSR1 = local0;
          if (((local0 ^ local2) & 0x80) == 0) {
            bVar8 = *(byte *)in_FSR1 < 0xfe || local2 < *(byte *)in_FSR1 + 2;
          }
          else {
            bVar8 = (char)local2 < '\0';
          }
          if (bVar8) {
            bVar8 = (char)fan_runon_hi < '\0';
            if (!bVar8) {
              bVar8 = ~(fan_runon_lo == 0) != 0 || fan_runon_hi < (byte)-~(fan_runon_lo == 0);
            }
            if (bVar8) {
              fan_runon_lo = 0xff;
              fan_runon_hi = 0xff;
              bVar7 = PORTH;
              PORTH = bVar7 & ~RH5;
            }
          }
          local1 = fan_read_param(0x3c);
          local0 = local0 + local1;
          *(byte *)in_FSR1 = local0;
          if (((local0 ^ local2) & 0x80) == 0) {
            bVar8 = *(byte *)in_FSR1 <= local2;
          }
          else {
            bVar8 = *(char *)in_FSR1 < '\0';
          }
          if (bVar8) {
            bVar7 = PORTH;
            PORTH = bVar7 | RH5;
          }
        }
        else {
          bVar7 = PORTH;
          PORTH = bVar7 | RH5;
        }
      }
    }
    bVar7 = 0;
    if (((cfg_systemconfig4 & 0x10) == 0) || (bVar7 = device_sensor_fault, device_sensor_fault != 0)
       ) {
      if ((outputs_shadow & 0x40) == 0) {
        if (fan_runon_hi == 0 && fan_runon_lo == 0) {
          fan_runon_lo = 0xff;
          fan_runon_hi = 0xff;
          bVar7 = PORTH;
          PORTH = bVar7 & ~RH5;
        }
        if (heater_power_level == '\0') {
          bVar7 = ~fan_runon_lo;
          if ((bVar7 == 0) && (bVar7 = ~fan_runon_hi, bVar7 == 0)) {
            bVar5 = PORTH;
            PORTH = bVar5 & ~RH5;
          }
        }
        else {
          bVar7 = fan_heater_runon_hi | fan_heater_runon_lo;
          if (bVar7 == 0) {
            fan_heater_runon_lo = 0xff;
            fan_heater_runon_hi = 0xff;
            goto LAB_CODE_00d868;
          }
        }
      }
      else {
LAB_CODE_00d868:
        bVar5 = PORTH;
        PORTH = bVar5 | RH5;
      }
    }
    if ((cfg_systemconfig4 & 8) != 0) {
      local2 = temp_read_ch7(bVar7);
      if (local2 == 0xff) {
        dryer_sensor_fault = 0x8d;
      }
      else if (local2 == 0xfe) {
        dryer_sensor_fault = 0x8f;
      }
      else {
        dryer_sensor_fault = 0;
      }
      bVar7 = dryer_sensor_fault;
      if (dryer_sensor_fault == 0) {
        puVar2 = (undefined1 *)((short)in_FSR1 + 1);
        *(undefined1 *)in_FSR1 = 0x3f;
        bVar5 = eeprom_read_param();
        in_FSR1 = (BADSPACEBASE *)(puVar2 + -1);
        *puVar2 = *puVar2;
        bVar7 = (bVar5 - local2) + 2;
        if (0xfd < bVar5 && bVar5 + 2 <= local2) {
          puVar2[-1] = 0x2d;
          local1 = eeprom_read_param();
          pbVar3 = puVar2 + -1;
          *puVar2 = *puVar2;
          puVar2[-1] = 0xc;
          if ((local1 & 0x80) == 0) {
            bVar8 = (byte)puVar2[-1] <= local1;
            cVar6 = local1 - puVar2[-1];
          }
          else {
            bVar8 = (char)puVar2[-1] < '\0';
            cVar6 = puVar2[-1] << 1;
          }
          if (!bVar8) {
            cVar6 = '\f';
            local1 = 0xc;
          }
          compressor_stop(cVar6);
          pbVar4 = pbVar3 + 1;
          *pbVar3 = local1;
          bVar7 = fan_set_runon_minutes();
          in_FSR1 = (BADSPACEBASE *)(pbVar4 + -1);
          *pbVar4 = *pbVar4;
        }
      }
    }
    lamp_filter_presence_check(bVar7);
  } while( true );
}

