// address 0x006e5c  size 1926 bytes
// callers: (none: entry point, task, or reached via pointer)

/* WARNING: Removing unreachable block (CODE,0x007294) */
/* WARNING: Restarted to delay deadcode elimination for space: DATA */
/* Priority 5 task: serial console. Commands: RS NM SM ST PD GHT GCT GDT COT DCW DHW STP CP0 CP1 EH1
   EH0 GCS GHS HTS UVS IVS CVS HVS CWC GCH TC AC g, hidden GP SP RP GPL RPL SMN SMX GC RC GCL RCL
   VER XC LCL */

void task_serial_protocol(void)

{
  BADSPACEBASE *in_FSR1;
  undefined1 *puVar1;
  undefined1 *puVar3;
  undefined1 *puVar4;
  undefined1 *puVar5;
  byte *pbVar6;
  undefined1 *puVar7;
  undefined1 *puVar8;
  undefined1 *puVar9;
  undefined1 *puVar10;
  undefined1 *puVar11;
  undefined1 *puVar12;
  undefined1 *puVar13;
  undefined1 *puVar14;
  undefined1 *puVar15;
  undefined1 *puVar16;
  undefined1 *puVar17;
  byte *pbVar18;
  byte *pbVar19;
  byte *pbVar20;
  byte *pbVar21;
  byte *pbVar22;
  byte *pbVar23;
  byte *pbVar24;
  undefined1 *puVar25;
  undefined1 *puVar26;
  undefined1 *puVar27;
  undefined1 *puVar29;
  undefined1 *puVar30;
  byte *pbVar31;
  char *pcVar32;
  undefined1 *puVar33;
  byte bVar34;
  char cVar35;
  undefined1 uVar36;
  byte bVar37;
  char cVar38;
  undefined1 uVar39;
  BADSPACEBASE *in_FSR0;
  undefined1 *puVar40;
  byte *in_TBLPTR;
  undefined2 *puVar41;
  bool bVar42;
  bool bVar43;
  undefined1 *puVar2;
  undefined1 *puVar28;
  
  uart2_rx_flags = uart2_rx_flags | 1;
  do {
    while( true ) {
      serial_push_sem();
      bVar34 = OSWaitSem();
      puVar1 = (undefined1 *)((short)in_FSR1 + -1);
      puVar2 = (undefined1 *)((short)in_FSR1 + -1);
      *(undefined1 *)in_FSR1 = *(undefined1 *)in_FSR1;
      puVar3 = (undefined1 *)((short)in_FSR1 + -2);
      in_FSR1 = (BADSPACEBASE *)((short)in_FSR1 + -2);
      *puVar1 = *puVar2;
      if ((bVar34 & 2) == 0) break;
      OS_Yield();
    }
    ser_get_TBLPTRL_79f4();
    *puVar3 = *puVar3;
    fault_code = -0x7f;
    if ((serial_cmd_hash == 0xd4) && (uart2_rx_buffer != 'R')) {
      serial_cmd_hash = 0xd3;
    }
    if ((serial_cmd_hash == 0xfb) && (uart2_rx_buffer != 'S')) {
      serial_cmd_hash = 0xfa;
    }
    if ((serial_cmd_hash == 0xf1) && (uart2_rx_buffer != 'G')) {
      serial_cmd_hash = 0xf0;
    }
    if ((serial_cmd_hash == 0xa9) && (uart2_rx_buffer != 'S')) {
      serial_cmd_hash = 0xa7;
    }
    if ((serial_cmd_hash == 0xe1) && (uart2_rx_buffer != 'G')) {
      serial_cmd_hash = 0xe0;
    }
    if ((serial_cmd_hash == 0x8d) && (uart2_rx_buffer != 'G')) {
      serial_cmd_hash = 0x8c;
    }
    if (uart2_rx_buffer == 'g') {
      serial_cmd_hash = 0x67;
    }
    bVar42 = 0xdd < serial_cmd_hash;
    pbVar31 = puVar3 + -1;
    if (serial_cmd_hash == 0xde) {
      if ((uart2_rx_buffer_3 == '\0') || (uart2_rx_buffer_2 == '\0')) {
        serial_cmd_hash = 0;
        pbVar31 = puVar3 + -1;
      }
      else {
        puVar3[-1] = 0x6f;
        uVar39 = ser_to_atol_7a3a(1);
        ser_get_TBLPTRL_799c(uVar39);
        serial_cmd_hash = *in_TBLPTR;
        pbVar31 = puVar3;
      }
    }
    if (serial_cmd_hash == 0xa8) {
      cVar38 = hot_valve_is_open();
      if (cVar38 == '\0') {
        puVar30 = pbVar31 + 1;
        *pbVar31 = 0xcc;
        uVar39 = 0x50;
LAB_CODE_007588:
        pbVar31 = puVar30 + 1;
        *puVar30 = uVar39;
        uart2_puts_rom();
LAB_CODE_00758c:
        *pbVar31 = *pbVar31;
        pbVar31[-1] = pbVar31[-1];
        puVar29 = pbVar31 + -2;
      }
      else {
        puVar29 = pbVar31;
        if (cVar38 == '\x01') {
          puVar30 = pbVar31 + 1;
          *pbVar31 = 0xdb;
          uVar39 = 0x50;
          goto LAB_CODE_007588;
        }
      }
LAB_CODE_007590:
      ser_get_TBLPTRL_79f4();
LAB_CODE_007592:
      pbVar31 = puVar29 + -1;
      *puVar29 = *puVar29;
LAB_CODE_007594:
      fault_code = '\0';
    }
    else {
      if (serial_cmd_hash == 0xa3) {
        cVar38 = cold_valve_is_open();
        if (cVar38 == '\0') {
          puVar30 = pbVar31 + 1;
          *pbVar31 = 0xe9;
          uVar39 = 0x50;
        }
        else {
          puVar29 = pbVar31;
          if (cVar38 != '\x01') goto LAB_CODE_007590;
          puVar30 = pbVar31 + 1;
          *pbVar31 = 0xf8;
          uVar39 = 0x50;
        }
        goto LAB_CODE_007588;
      }
      if (serial_cmd_hash == 0xa7) {
        cVar38 = inlet_valve_is_open();
        if (cVar38 == '\0') {
          puVar30 = pbVar31 + 1;
          *pbVar31 = 6;
          uVar39 = 0x51;
        }
        else {
          puVar29 = pbVar31;
          if (cVar38 != '\x01') goto LAB_CODE_007590;
          puVar30 = pbVar31 + 1;
          *pbVar31 = 0x18;
          uVar39 = 0x51;
        }
        goto LAB_CODE_007588;
      }
      if (serial_cmd_hash == 0xb5) {
        bVar34 = PORTJ;
        if ((bVar34 & RJ1) == 0) {
          puVar30 = pbVar31 + 1;
          *pbVar31 = 0x37;
          uVar39 = 0x51;
        }
        else {
          puVar30 = pbVar31 + 1;
          *pbVar31 = 0x29;
          uVar39 = 0x51;
        }
        goto LAB_CODE_007588;
      }
      if (serial_cmd_hash == 0xac) {
        cVar38 = heater_is_on();
        if (cVar38 == '\0') {
          puVar30 = pbVar31 + 1;
          *pbVar31 = 0x44;
          uVar39 = 0x51;
        }
        else {
          puVar29 = pbVar31;
          if (cVar38 != '\x01') goto LAB_CODE_007590;
          puVar30 = pbVar31 + 1;
          *pbVar31 = 0x4f;
          uVar39 = 0x51;
        }
        goto LAB_CODE_007588;
      }
      if (serial_cmd_hash == 0xe1) {
LAB_CODE_007500:
        fault_code = -0x7e;
        goto LAB_CODE_0075a0;
      }
      if (serial_cmd_hash == 0x9b) {
        cVar38 = heating_get_state();
        if (cVar38 == '\x04') {
          puVar30 = pbVar31 + 1;
          *pbVar31 = 0x74;
          uVar39 = 0x51;
        }
        else if (cVar38 == '\x03') {
          puVar30 = pbVar31 + 1;
          *pbVar31 = 0x8f;
          uVar39 = 0x51;
        }
        else if (cVar38 == '\x02') {
          puVar30 = pbVar31 + 1;
          *pbVar31 = 0xa6;
          uVar39 = 0x51;
        }
        else if (cVar38 == '\x01') {
          puVar30 = pbVar31 + 1;
          *pbVar31 = 0xc0;
          uVar39 = 0x51;
        }
        else if (cVar38 == '\0') {
          puVar30 = pbVar31 + 1;
          *pbVar31 = 0xd8;
          uVar39 = 0x51;
        }
        else {
          puVar30 = pbVar31 + 1;
          *pbVar31 = 0x59;
          uVar39 = 0x51;
        }
        goto LAB_CODE_007588;
      }
      if (serial_cmd_hash == 0x8d) {
        cVar38 = cooling_get_state();
        if (cVar38 == '\x02') {
          puVar30 = pbVar31 + 1;
          *pbVar31 = 0xb;
          uVar39 = 0x52;
        }
        else if (cVar38 == '\0') {
          puVar30 = pbVar31 + 1;
          *pbVar31 = 0x22;
          uVar39 = 0x52;
        }
        else if (cVar38 == '\x01') {
          puVar30 = pbVar31 + 1;
          *pbVar31 = 0x37;
          uVar39 = 0x52;
        }
        else {
          puVar30 = pbVar31 + 1;
          *pbVar31 = 0xef;
          uVar39 = 0x51;
        }
        goto LAB_CODE_007588;
      }
      if (serial_cmd_hash == 0xe0) {
        cVar38 = child_protect_is_active();
        if (cVar38 == '\0') {
          puVar30 = pbVar31 + 1;
          *pbVar31 = 0x4b;
          uVar39 = 0x52;
        }
        else {
          puVar30 = pbVar31 + 1;
          *pbVar31 = 0x6e;
          uVar39 = 0x52;
        }
        goto LAB_CODE_007588;
      }
      if (serial_cmd_hash == 0x11) {
        system_wake();
        heating_request_extra_hot();
        goto LAB_CODE_007594;
      }
      if (serial_cmd_hash == 0x15) {
        heating_cancel_extra_hot();
        goto LAB_CODE_007594;
      }
      if (serial_cmd_hash == 0x27) {
        *pbVar31 = 1;
LAB_CODE_00745a:
        puVar29 = pbVar31 + 1;
        mod_to_mod_to_param_write_b52a();
        goto LAB_CODE_007592;
      }
      if (serial_cmd_hash == 0x23) {
        *pbVar31 = 0;
        goto LAB_CODE_00745a;
      }
      if (serial_cmd_hash != 0xbb) {
        if (serial_cmd_hash == 0x88) {
          fault_code = dispense_hot_request();
          goto LAB_CODE_0075a0;
        }
        if (serial_cmd_hash == 0x9e) {
          fault_code = dispense_cold_request();
          goto LAB_CODE_0075a0;
        }
        if (serial_cmd_hash == 0x91) {
          local0 = cold_temp_read_ch4();
          ser_chain_fn7ac8_fn7aa8_7842();
          local0 = cold_temp_read_ch5();
        }
        else {
          if (serial_cmd_hash != 0x87) {
            if ((serial_cmd_hash == 199) || (serial_cmd_hash == 0xd2)) goto LAB_CODE_007500;
            if (serial_cmd_hash == 0xfb) {
              serial_cmd_hash = 0;
              while( true ) {
                c18_tmp0 = serial_cmd_hash;
                c18_tmp1 = 0;
                bVar42 = 7 < serial_cmd_hash != true;
                if (7 < serial_cmd_hash != true) break;
                OS_Yield(0);
                ser_get_serial_cmd_hash_7962();
                puVar41 = (undefined2 *)
                          CONCAT21((short)((uint3)in_TBLPTR >> 8),(char)in_TBLPTR + '\x02');
                ser_get_TBLPTRH_7a50();
                uart2_puts_rom();
                puVar27 = pbVar31 + -1;
                puVar28 = pbVar31 + -1;
                *pbVar31 = *pbVar31;
                pbVar31 = pbVar31 + -2;
                *puVar27 = *puVar28;
                ser_get_serial_cmd_hash_7962();
                in_TBLPTR = (byte *)((int3)puVar41 + 1);
                in_FSR0 = (BADSPACEBASE *)*puVar41;
                ser_frag_7a48(*(undefined1 *)in_FSR0);
                serial_cmd_hash = serial_cmd_hash + 1;
              }
            }
            else if (serial_cmd_hash == 0xc9) {
              system_enter_sleep();
            }
            else if (serial_cmd_hash == 0xd3) {
              system_wake();
            }
            else {
              if (serial_cmd_hash == 0xf4) {
                *pbVar31 = 0x8d;
                puVar25 = pbVar31 + 2;
                pbVar31[1] = 0x52;
                ser_to_uart2_puts_rom_7914();
                *puVar25 = 0;
                puVar26 = puVar25 + 2;
                puVar25[1] = 200;
                OSDelay();
                *puVar26 = *puVar26;
                pbVar31 = puVar26 + -2;
                puVar26[-1] = puVar26[-1];
                adc_raw_lo = 0x10;
                OS_Yield();
                serial_cmd_reset();
                goto LAB_CODE_0075a0;
              }
              if (serial_cmd_hash == 0xd8) {
                fault_code = -0x7e;
                system_enter_standby();
              }
              else {
                if (serial_cmd_hash != 0xe4) {
                  if (serial_cmd_hash == 0xd4) {
                    if (((uart2_rx_buffer_3 != '\0') && (uart2_rx_buffer_2 != '\0')) &&
                       (serial_parse_index_arg(uart2_rx_buffer_2), bVar42)) {
                      bVar42 = 0x11 < serial_cmd_hash;
                      bVar34 = serial_cmd_hash - 0x12;
                      if (!bVar42) {
                        bVar37 = ser_to_serial_read_counter_desc_7a80(bVar34);
                        if ((bVar37 & 0x80) == 0) {
                          bVar37 = ser_compare_multibyte_78ec();
                          bVar43 = bVar42;
                        }
                        else {
                          bVar43 = c18_tmp7 < '\0';
                          bVar34 = c18_tmp7 << 1 | bVar42;
                          bVar37 = bVar34;
                        }
                        if (bVar43) {
                          ser_to_ser_get_serial_ptr_lo_7a26();
                          *(undefined1 *)in_FSR0 = 0;
                          pbVar21 = pbVar31 + 1;
                          *pbVar31 = local0;
                          stat_byte_save();
                        }
                        else {
                          ser_to_ser_get_serial_ptr_lo_7a58(bVar37);
                          do {
                            ser_shift_multibyte_79dc();
                          } while (bVar34 != 0);
                          local0 = c18_tmp0;
                          ser_frag_7a66(c18_tmp0);
                          pbVar21 = pbVar31 + 1;
                          *pbVar31 = local0;
                          stat_counter_save();
                        }
                        pbVar20 = pbVar21 + -1;
                        pbVar31 = pbVar21 + -1;
                        *pbVar21 = *pbVar21;
                        bVar42 = 0xfe < serial_param_index;
                        if (serial_param_index != 0xff) {
                          ser_calc_array_ptr_7956(serial_param_index);
                          *(undefined1 *)in_FSR0 = 0;
LAB_CODE_007354:
                          pbVar22 = pbVar20 + 1;
                          *pbVar20 = serial_param_index;
                          stat_byte_save();
LAB_CODE_00735c:
                          pbVar31 = pbVar22 + -1;
                          *pbVar22 = *pbVar22;
                        }
                        goto LAB_CODE_007594;
                      }
                    }
                  }
                  else if (serial_cmd_hash == 0x67) {
                    if ((uart2_rx_buffer_3 != '\0') && (uart2_rx_buffer_2 != '\0')) {
                      *pbVar31 = 2;
                      pbVar31[1] = 0;
                      puVar11 = pbVar31 + 3;
                      pbVar31[2] = 0x6d;
                      uVar36 = ser_to_memcpy_7986(1);
                      uVar39 = (undefined1)((ushort)puVar11 >> 8);
                      if (!bVar42) {
                        puVar12 = (undefined1 *)((ushort)puVar11 & 0xff00);
                        uVar39 = (undefined1)((ushort)(puVar12 + -1) >> 8);
                        *puVar12 = *puVar12;
                      }
                      serial_buf_a4 = 0;
                      puVar13 = (undefined1 *)CONCAT11(uVar39,uVar36) + 1;
                      *(undefined1 *)CONCAT11(uVar39,uVar36) = 0xa2;
                      serial_cmd_hash = ser_to_atol_7a3a(1);
                      *puVar13 = 8;
                      puVar13[1] = 0;
                      puVar14 = puVar13 + 3;
                      puVar13[2] = 0x6f;
                      uVar36 = ser_to_memcpy_7986(1);
                      uVar39 = (undefined1)((ushort)puVar14 >> 8);
                      if (!bVar42) {
                        puVar15 = (undefined1 *)((ushort)puVar14 & 0xff00);
                        uVar39 = (undefined1)((ushort)(puVar15 + -1) >> 8);
                        *puVar15 = *puVar15;
                      }
                      puVar16 = (undefined1 *)CONCAT11(uVar39,uVar36);
                      serial_buf_aa = 0;
                      *puVar16 = 0xa2;
                      puVar17 = puVar16 + 2;
                      puVar16[1] = 1;
                      serial_print_number();
                      *puVar17 = *puVar17;
                      pbVar18 = puVar17 + -2;
                      pbVar31 = puVar17 + -2;
                      puVar17[-1] = puVar17[-1];
                      serial_value32 = math_res0;
                      DAT_DATA_01ad = math_res1;
                      DAT_DATA_01ae = math_aarg_lo;
                      DAT_DATA_01af = math_aarg_hi;
                      bVar42 = 0x11 < serial_cmd_hash;
                      bVar34 = serial_cmd_hash - 0x12;
                      if (!bVar42) {
                        bVar37 = ser_to_serial_read_counter_desc_7a80(bVar34);
                        if ((bVar37 & 0x80) == 0) {
                          bVar37 = ser_compare_multibyte_78ec();
                          bVar43 = bVar42;
                        }
                        else {
                          bVar43 = c18_tmp7 < '\0';
                          bVar34 = c18_tmp7 << 1 | bVar42;
                          bVar37 = bVar34;
                        }
                        if (bVar43) {
                          ser_to_ser_get_serial_ptr_lo_7a26();
                          *(undefined1 *)in_FSR0 = serial_value32;
                          pbVar19 = pbVar18 + 1;
                          *pbVar18 = local0;
                          stat_byte_save();
                        }
                        else {
                          ser_to_ser_get_serial_ptr_lo_7a58(bVar37);
                          do {
                            ser_shift_multibyte_79dc();
                          } while (bVar34 != 0);
                          local0 = c18_tmp0;
                          ser_ptr_add_7928(c18_tmp0);
                          *(undefined1 *)in_FSR0 = serial_value32;
                          *(undefined1 *)((short)in_FSR0 + 1) = DAT_DATA_01ad;
                          puVar40 = (undefined1 *)((short)in_FSR0 + 3);
                          *(undefined1 *)((short)in_FSR0 + 2) = DAT_DATA_01ae;
                          in_FSR0 = (BADSPACEBASE *)((short)in_FSR0 + 4);
                          *puVar40 = DAT_DATA_01af;
                          pbVar19 = pbVar18 + 1;
                          *pbVar18 = local0;
                          stat_counter_save();
                        }
                        pbVar20 = pbVar19 + -1;
                        pbVar31 = pbVar19 + -1;
                        *pbVar19 = *pbVar19;
                        bVar42 = 0xfe < serial_param_index;
                        if (serial_param_index != 0xff) {
                          ser_calc_array_ptr_7956(serial_param_index);
                          *(undefined1 *)in_FSR0 = serial_value32;
                          goto LAB_CODE_007354;
                        }
                        goto LAB_CODE_007594;
                      }
                    }
                  }
                  else {
                    if (serial_cmd_hash != 0xc1) {
                      if (serial_cmd_hash == 0xf1) {
                        ser_frag_7a48(0x12);
                        for (serial_cmd_hash = 0; serial_cmd_hash < 0x12;
                            serial_cmd_hash = serial_cmd_hash + 1) {
                          OS_Yield(serial_cmd_hash - 0x12);
                          serial_read_counter_desc();
                          ser_get_serial_cmd_hash_7a96();
                          puVar8 = pbVar31 + 1;
                          *pbVar31 = serial_counter_ptr_lo;
                          pbVar31 = pbVar31 + 2;
                          *puVar8 = serial_counter_ptr_hi;
                          ser_to_uart2_puts_rom_7910();
                          bVar34 = ser_get_serial_ptr_lo_7890();
                          cVar38 = c18_tmp7;
                          bVar42 = (bVar34 & 0x80) != 0;
                          if (bVar42) {
                            cVar35 = c18_tmp7 << 1;
                          }
                          else {
                            cVar35 = ser_compare_multibyte_78ec();
                          }
                          if (!bVar42 || -1 < cVar38) {
                            uVar36 = ser_to_ltoa_78ce(cVar35);
                            uVar39 = (undefined1)((ushort)pbVar31 >> 8);
                            if (!bVar42 || -1 < cVar38) {
                              puVar9 = (undefined1 *)((ushort)pbVar31 & 0xff00);
                              uVar39 = (undefined1)((ushort)(puVar9 + -1) >> 8);
                              *puVar9 = *puVar9;
                            }
                            pbVar31 = (byte *)CONCAT11(uVar39,uVar36);
                            bVar34 = c18_tmp0;
                          }
                          else {
                            ser_to_ser_get_serial_ptr_lo_79b0();
                            bVar34 = ser_to_fmt_byte_7a08();
                          }
                          ser_to_uart2_puts_ram_7aa2(bVar34);
                          ser_to_ser_get_TBLPTRL_7aa8();
                        }
                        bVar42 = true;
                      }
                      else {
                        if (serial_cmd_hash != 0xc2) {
                          if (serial_cmd_hash == 0xf2) {
                            if (((uart2_rx_buffer_3 != '\0') && (uart2_rx_buffer_2 != '\0')) &&
                               (serial_parse_index_arg(uart2_rx_buffer_2), bVar42)) {
                              bVar42 = 0x4a < serial_cmd_hash;
                              if (!bVar42) {
                                bVar34 = ser_to_param_table_lookup_79c2(serial_cmd_hash + 0xb5);
LAB_CODE_007138:
                                *pbVar31 = bVar34;
                                pbVar6 = pbVar31 + 2;
                                pbVar31[1] = serial_cmd_hash;
                                fault_code = param_write();
                                goto LAB_CODE_007142;
                              }
                            }
                          }
                          else if (serial_cmd_hash == 0xf0) {
                            cVar38 = serial_parse_index_value_args();
                            if (cVar38 != '\0') {
                              *pbVar31 = local0;
                              pbVar6 = pbVar31 + 2;
                              pbVar31[1] = serial_cmd_hash;
                              fault_code = param_write_min();
LAB_CODE_007142:
                              *pbVar6 = *pbVar6;
                              pbVar31 = pbVar6 + -2;
                              pbVar6[-1] = pbVar6[-1];
                            }
                          }
                          else if (serial_cmd_hash == 0xa9) {
                            cVar38 = serial_parse_index_value_args();
                            if (cVar38 != '\0') {
                              *pbVar31 = local0;
                              pbVar6 = pbVar31 + 2;
                              pbVar31[1] = serial_cmd_hash;
                              fault_code = param_write_max();
                              goto LAB_CODE_007142;
                            }
                          }
                          else {
                            if (serial_cmd_hash != 0xf3) {
                              if (serial_cmd_hash == 0xfa) {
                                ser_frag_7a48(0x1c);
                                serial_cmd_hash = 0;
                                while( true ) {
                                  c18_tmp0 = serial_cmd_hash;
                                  c18_tmp1 = 0;
                                  bVar42 = 0x1b < serial_cmd_hash != true;
                                  if (0x1b < serial_cmd_hash != true) break;
                                  OS_Yield(0);
                                  ser_get_serial_cmd_hash_7a96();
                                  ser_get_TBLPTRL_799c(serial_cmd_hash);
                                  in_TBLPTR = (byte *)CONCAT21((short)((uint3)in_TBLPTR >> 8),
                                                               (char)in_TBLPTR + '\x01');
                                  ser_get_TBLPTRH_7a50();
                                  ser_to_uart2_puts_rom_7914();
                                  serial_cmd_hash = serial_cmd_hash + 1;
                                }
                              }
                              else {
                                if (serial_cmd_hash == 0xe7) {
                                  if (((uart2_rx_buffer_3 != '\0') && (uart2_rx_buffer_2 != '\0'))
                                     && (serial_parse_index_arg(uart2_rx_buffer_2), bVar42)) {
                                    bVar42 = 0x4a < serial_cmd_hash;
                                    if (!bVar42) {
                                      ser_push_args_6c_01_79fe(serial_cmd_hash + 0xb5);
                                      bVar34 = ser_to_eeprom_read_raw_79b6();
                                      goto LAB_CODE_0071fe;
                                    }
                                  }
                                  goto LAB_CODE_0075a0;
                                }
                                if (serial_cmd_hash != 0xd7) {
                                  if (serial_cmd_hash != 0x94) {
                                    if (serial_cmd_hash == 0x8c) {
                                      local0 = temp_read_ch7();
                                    }
                                    else {
                                      if (serial_cmd_hash != 0x9f) {
                                        fault_code = -0x7b;
                                        goto LAB_CODE_0075a0;
                                      }
                                      local0 = temp_read_ch6();
                                    }
                                    ser_push_args_6c_01_79fe();
                                    bVar34 = local0;
                                    goto LAB_CODE_0071fe;
                                  }
                                  puVar4 = pbVar31 + 1;
                                  *pbVar31 = 0x90;
                                  pbVar31 = pbVar31 + 2;
                                  *puVar4 = 0x52;
                                  uart2_puts_rom();
                                  goto LAB_CODE_007214;
                                }
                                ser_frag_7a48(0x4b);
                                for (serial_cmd_hash = 0; serial_cmd_hash < 0x4b;
                                    serial_cmd_hash = serial_cmd_hash + 1) {
                                  OS_Yield(serial_cmd_hash + 0xb5);
                                  serial_report_param();
                                  ser_get_serial_cmd_hash_7a96();
                                  puVar5 = pbVar31 + 1;
                                  *pbVar31 = adc_raw_hi;
                                  pbVar31 = pbVar31 + 2;
                                  *puVar5 = ntc_table_ptr_lo;
                                  ser_to_uart2_puts_rom_7910();
                                  local0 = temp_new_reading;
                                  ser_push_args_6c_01_79fe();
                                  ser_chain_ser_to_fmt_byte_ser_to_uart2_puts__ser_get_TBLPTRL_784
                                            (temp_new_reading);
                                  local0 = temp_channel;
                                  ser_push_args_6c_01_79fe();
                                  ser_chain_ser_to_fmt_byte_ser_to_uart2_puts__ser_get_TBLPTRL_784
                                            (temp_channel);
                                  local0 = ser_to_eeprom_read_raw_79b6();
                                  ser_push_args_6c_01_79fe();
                                  ser_chain_ser_to_fmt_byte_ser_to_uart2_puts__ser_get_TBLPTRL_784
                                            (local0);
                                  ser_to_param_table_lookup_79c2();
                                  ser_frag_7a48();
                                }
                                bVar42 = true;
                              }
                              goto LAB_CODE_007594;
                            }
                            cVar38 = serial_parse_index_value_args();
                            bVar34 = local0;
                            if (cVar38 != '\0') goto LAB_CODE_007138;
                          }
                          goto LAB_CODE_0075a0;
                        }
                        for (serial_cmd_hash = 0; serial_cmd_hash < 0x4b;
                            serial_cmd_hash = serial_cmd_hash + 1) {
                          OS_Yield(serial_cmd_hash + 0xb5);
                          uVar39 = ser_to_param_table_lookup_79c2();
                          *pbVar31 = uVar39;
                          puVar7 = pbVar31 + 2;
                          pbVar31[1] = serial_cmd_hash;
                          fault_code = param_write();
                          *puVar7 = *puVar7;
                          pbVar31 = puVar7 + -2;
                          puVar7[-1] = puVar7[-1];
                          if (fault_code < '\0') {
                            bVar42 = true;
                            goto LAB_CODE_007594;
                          }
                          pbVar31 = puVar7 + -2;
                        }
                        bVar42 = true;
                      }
                      goto LAB_CODE_007594;
                    }
                    if (((uart2_rx_buffer_3 != '\0') && (uart2_rx_buffer_2 != '\0')) &&
                       (serial_parse_index_arg(uart2_rx_buffer_2), bVar42)) {
                      bVar43 = 0x11 < serial_cmd_hash;
                      bVar42 = bVar43;
                      if (!bVar43) {
                        bVar34 = ser_to_serial_read_counter_desc_7a80(serial_cmd_hash - 0x12);
                        if ((bVar34 & 0x80) == 0) {
                          bVar34 = ser_compare_multibyte_78ec();
                        }
                        else {
                          bVar42 = c18_tmp7 < '\0';
                          bVar34 = c18_tmp7 << 1 | bVar43;
                        }
                        if (bVar42) {
                          bVar34 = ser_to_ser_get_serial_ptr_lo_79b0();
LAB_CODE_0071fe:
                          bVar34 = ser_to_fmt_byte_7a08(bVar34);
                        }
                        else {
                          uVar36 = ser_to_ltoa_78ce(bVar34);
                          uVar39 = (undefined1)((ushort)pbVar31 >> 8);
                          if (bVar42 == false) {
                            puVar10 = (undefined1 *)((ushort)pbVar31 & 0xff00);
                            uVar39 = (undefined1)((ushort)(puVar10 + -1) >> 8);
                            *puVar10 = *puVar10;
                          }
                          pbVar31 = (byte *)CONCAT11(uVar39,uVar36);
                          bVar34 = c18_tmp0;
                        }
                        ser_to_uart2_puts_ram_7aa2(bVar34);
LAB_CODE_007214:
                        *pbVar31 = *pbVar31;
                        pbVar22 = pbVar31 + -2;
                        pbVar31[-1] = pbVar31[-1];
                        ser_get_TBLPTRL_79f4();
                        goto LAB_CODE_00735c;
                      }
                    }
                  }
                  goto LAB_CODE_0075a0;
                }
                for (serial_cmd_hash = 0; serial_cmd_hash < 0x10;
                    serial_cmd_hash = serial_cmd_hash + 1) {
                  OS_Yield(serial_cmd_hash - 0x10);
                  ser_frag_7a66(serial_cmd_hash);
                  pbVar23 = pbVar31 + 1;
                  *pbVar31 = serial_cmd_hash;
                  stat_counter_save();
                  pbVar31 = pbVar23 + -1;
                  *pbVar23 = *pbVar23;
                }
                for (serial_cmd_hash = 0; serial_cmd_hash < 2; serial_cmd_hash = serial_cmd_hash + 1
                    ) {
                  OS_Yield(serial_cmd_hash - 2);
                  ser_calc_array_ptr_7956(serial_cmd_hash);
                  *(undefined1 *)in_FSR0 = 0;
                  pbVar24 = pbVar31 + 1;
                  *pbVar31 = serial_cmd_hash;
                  stat_byte_save();
                  pbVar31 = pbVar24 + -1;
                  *pbVar24 = *pbVar24;
                }
                bVar42 = true;
              }
            }
            goto LAB_CODE_007594;
          }
          local0 = hot_temp_top;
          ser_chain_fn7ac8_fn7aa8_7842();
          local0 = hot_temp_bottom;
        }
        ser_to_ser_to_fmt_byte_7ac8();
        goto LAB_CODE_00758c;
      }
      fault_code = dispense_stop_all();
    }
LAB_CODE_0075a0:
    if (fault_code < '\0') {
      ser_push_args_6c_01_79fe(fault_code << 1 | bVar42);
      pcVar32 = (char *)(pbVar31 + 1);
      *pbVar31 = fault_code;
      fmt_byte();
      *pcVar32 = *pcVar32;
      pcVar32[-1] = pcVar32[-1];
      pcVar32[-2] = pcVar32[-2];
      pcVar32[-3] = 0xc5;
      puVar33 = pcVar32 + -1;
      pcVar32[-2] = 0x50;
      uart2_puts_rom();
      *puVar33 = *puVar33;
      in_FSR1 = (BADSPACEBASE *)(puVar33 + -2);
      puVar33[-1] = puVar33[-1];
      ser_to_uart2_puts_ram_7aa2();
    }
    else {
      *pbVar31 = 0x8d;
      in_FSR1 = (BADSPACEBASE *)(pbVar31 + 2);
      pbVar31[1] = 0x52;
      uart2_puts_rom();
    }
    ser_to_ser_get_TBLPTRL_7aa8();
    uart2_rx_count = 0;
    serial_cmd_hash = 0;
    uart2_rx_flags = uart2_rx_flags | 3;
  } while( true );
}

