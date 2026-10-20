// address 0x003b12  size 1874 bytes
// callers: 002c22,

/* WARNING: Removing unreachable block (CODE,0x003c76) */
/* WARNING: Removing unreachable block (CODE,0x003c6c) */
/* WARNING: Removing unreachable block (CODE,0x003c18) */
/* WARNING: Removing unreachable block (CODE,0x003c22) */
/* WARNING: Removing unreachable block (CODE,0x003c8e) */
/* WARNING: Removing unreachable block (CODE,0x003c98) */
/* WARNING: Removing unreachable block (CODE,0x003fec) */
/* WARNING: Removing unreachable block (CODE,0x003ff6) */
/* WARNING: Removing unreachable block (CODE,0x003c00) */
/* WARNING: Removing unreachable block (CODE,0x003bf6) */
/* WARNING: Removing unreachable block (CODE,0x003c0e) */
/* WARNING: Removing unreachable block (CODE,0x003c84) */
/* WARNING: Removing unreachable block (CODE,0x00402a) */
/* WARNING: Removing unreachable block (CODE,0x00404c) */
/* WARNING: Removing unreachable block (CODE,0x004056) */
/* WARNING: Removing unreachable block (CODE,0x003fcc) */
/* WARNING: Removing unreachable block (CODE,0x003fd6) */
/* WARNING: Removing unreachable block (CODE,0x003fe4) */
/* WARNING: Removing unreachable block (CODE,0x004034) */
/* WARNING: Restarted to delay deadcode elimination for space: DATA */
/* Redraw current screen (called when refresh timer expires) */

void ui_refresh_screen(void)

{
  BADSPACEBASE *in_FSR2;
  byte bVar1;
  BADSPACEBASE *in_FSR1;
  undefined1 *puVar2;
  undefined1 *puVar3;
  undefined1 *puVar4;
  undefined1 *puVar5;
  undefined1 *puVar6;
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
  undefined1 *puVar18;
  undefined1 *puVar19;
  undefined1 *puVar20;
  undefined1 *puVar21;
  undefined1 *puVar22;
  undefined1 *puVar23;
  undefined1 *puVar24;
  undefined1 *puVar25;
  undefined1 *puVar26;
  undefined1 *puVar27;
  undefined1 *puVar28;
  undefined1 *puVar29;
  undefined1 *puVar30;
  undefined1 *puVar31;
  undefined1 *puVar32;
  char *pcVar33;
  char *pcVar34;
  undefined1 *puVar35;
  undefined1 *puVar36;
  byte *pbVar37;
  byte *pbVar38;
  char *pcVar39;
  undefined1 *puVar40;
  undefined1 *puVar41;
  undefined1 *puVar42;
  char *pcVar43;
  undefined1 *puVar44;
  char cVar45;
  byte bVar46;
  undefined1 uVar47;
  char cVar48;
  short sVar49;
  bool bVar50;
  
  ui_frag_4c90();
  puVar5 = (undefined1 *)((short)in_FSR1 + 1);
  puVar6 = (undefined1 *)((short)in_FSR1 + 1);
  puVar2 = (undefined1 *)((short)in_FSR1 + 1);
  puVar3 = (undefined1 *)((short)in_FSR1 + 1);
  puVar44 = (undefined1 *)((short)in_FSR1 + 1);
  puVar7 = (undefined1 *)((short)in_FSR1 + 1);
  puVar4 = (undefined1 *)((short)in_FSR1 + 1);
  puVar9 = (undefined1 *)((short)in_FSR1 + 1);
  puVar10 = (undefined1 *)((short)in_FSR1 + 1);
  puVar11 = (undefined1 *)((short)in_FSR1 + 1);
  puVar12 = (undefined1 *)((short)in_FSR1 + 1);
  puVar13 = (undefined1 *)((short)in_FSR1 + 1);
  puVar14 = (undefined1 *)((short)in_FSR1 + 1);
  puVar15 = (undefined1 *)((short)in_FSR1 + 1);
  puVar35 = (undefined1 *)((short)in_FSR1 + 1);
  puVar16 = (undefined1 *)((short)in_FSR1 + 1);
  puVar17 = (undefined1 *)((short)in_FSR1 + 1);
  puVar20 = (undefined1 *)((short)in_FSR1 + 1);
  puVar21 = (undefined1 *)((short)in_FSR1 + 1);
  puVar22 = (undefined1 *)((short)in_FSR1 + 1);
  puVar23 = (undefined1 *)((short)in_FSR1 + 1);
  puVar24 = (undefined1 *)((short)in_FSR1 + 1);
  puVar25 = (undefined1 *)((short)in_FSR1 + 1);
  puVar26 = (undefined1 *)((short)in_FSR1 + 1);
  puVar27 = (undefined1 *)((short)in_FSR1 + 1);
  puVar28 = (undefined1 *)((short)in_FSR1 + 1);
  puVar30 = (undefined1 *)((short)in_FSR1 + 1);
  puVar31 = (undefined1 *)((short)in_FSR1 + 1);
  pcVar33 = (char *)((short)in_FSR1 + 1);
  puVar41 = (undefined1 *)((short)in_FSR1 + 1);
  puVar42 = (undefined1 *)((short)in_FSR1 + 1);
  *(undefined1 *)in_FSR1 = *(undefined1 *)in_FSR1;
  cVar48 = ui_return_screen;
  bVar1 = 1;
  pcVar43 = (undefined1 *)((short)in_FSR1 + 1);
  if (ui_screen != '\x1f') {
    if (ui_screen == '\x1e') {
      compressor_stop();
      cooling_stop_task();
      heater_off();
      heater_output_enable = 0;
      heating_stop_task();
      cfg_systemconfig = cfg_systemconfig & 0xf7;
      clock_display_off();
      ui_to_screen_language_select_14d2();
      ui_screen = '\x1f';
      pcVar43 = puVar42;
    }
    else if (ui_screen == '\x14') {
      pcVar43 = (undefined1 *)((short)in_FSR1 + 1);
      if ((ui_screen_timeout == '\0') &&
         (cVar48 = ui_get_menu_mode_1122(0), pcVar43 = puVar41, cVar48 == '\0')) {
        ui_bank1_ui_to_lcd_clear_10d4();
        ui_select_home_screen();
        pcVar43 = puVar41;
      }
    }
    else {
      cVar45 = ui_hold_counter;
      if (ui_screen == '\x1d') goto joined_c0x003d34;
      if (ui_screen == '\x1c') {
        local3 = mod_to_hot_temp_read_top_c932();
        *(byte *)in_FSR2 = local3;
        local4 = 0;
        bVar1 = ui_param_tboil_4de4();
        if ((local4 & 0x80) == 0 && local4 != ~(bVar1 <= local3)) {
          c18_tmp1 = ui_to_eeprom_read_param_4f64(0x15);
          pcVar34 = pcVar33 + 1;
          *pcVar33 = c18_tmp1;
          cVar48 = ui_to_eeprom_read_param_4f64(0x16);
          pcVar33 = pcVar34 + -1;
          puVar4 = pcVar34 + -1;
          *pcVar34 = *pcVar34;
          if (ui_temp_change_timer == pcVar34[-1] - cVar48) goto LAB_CODE_0040c8;
          ui_substate = '\x01';
        }
        else {
LAB_CODE_0040c8:
          ui_substate = '\0';
          puVar4 = pcVar33;
        }
        c18_tmp1 = '\0';
        if ((ui_extra_hot_prev & 0x80) != 0) {
          c18_tmp1 = -1;
        }
        sVar49 = (ushort)(local3 - ui_extra_hot_prev) * 100;
        math_aarg_lo = (byte)sVar49;
        math_aarg_hi = ((local4 - c18_tmp1) - ~(ui_extra_hot_prev <= local3)) * 'd' +
                       (char)((ushort)sVar49 >> 8);
        math_barg_lo = ui_temp_change_timer - ui_extra_hot_prev;
        c18_tmp1 = '\0';
        if ((math_barg_lo & 0x80) != 0) {
          c18_tmp1 = -1;
        }
        math_barg_hi = c18_tmp1;
        c18_tmp0 = math_barg_lo;
        local3 = math_aarg_lo;
        local4 = math_aarg_hi;
        __divs16();
        local3 = math_aarg_lo;
        bVar50 = (char)math_aarg_hi < '\0';
        if (!bVar50) {
          bVar50 = ~(math_aarg_lo < 0x65) != 0 || math_aarg_hi < (byte)-~(math_aarg_lo < 0x65);
        }
        if ((bVar50) && ((math_aarg_hi & 0x80) == 0)) {
          bVar50 = false;
        }
        else {
          bVar50 = true;
        }
        if (bVar50) {
          local3 = 100;
          local4 = 0;
        }
        else {
          local4 = math_aarg_hi;
        }
        cVar48 = heating_is_extra_hot();
        pcVar43 = puVar4;
        if ((((cVar48 == '\0') && (ui_substate != '\0')) ||
            (((cfg_systemconfig5 & 1) == 0 && (heater_power_level < 3)))) ||
           (heater_power_level == 0)) {
          ui_return_screen = ui_screen;
          ui_screen = '\x1d';
          ui_hold_counter = '\x03';
          if (ui_menu_active == '\0') {
            mod_get_popup_index_e2d0(0);
            clock_draw();
            ui_to_txt_to_text_draw_char_4fb2();
            if ((cfg_systemconfig5 & 1) != 0) {
              ui_stack_adjust_4dde();
            }
            if (ui_substate == '\0') {
              puVar35 = puVar4 + 1;
              *puVar4 = 7;
              uVar47 = 0x13;
            }
            else {
              puVar35 = puVar4 + 1;
              *puVar4 = 7;
              uVar47 = 0x12;
            }
LAB_CODE_0041aa:
            puVar36 = puVar35 + 1;
            *puVar35 = uVar47;
            text_draw_word();
            goto LAB_CODE_004204;
          }
        }
        else if (ui_menu_active == '\0') {
          if (ui_substate == '\0') {
            *puVar4 = 2;
            uVar47 = 0x15;
          }
          else {
            *puVar4 = 2;
            uVar47 = 0x14;
          }
          pbVar37 = puVar4 + 1;
          ui_to_ser_to_text_draw_word_4d7a(uVar47);
          if ((cfg_systemconfig5 & 1) != 0) {
            ui_to_txt_to_text_draw_char_4fb2();
          }
          ui_stack_adjust_4dde();
          *pbVar37 = local3;
          pbVar38 = pbVar37 + 2;
          pbVar37[1] = local4;
          ui_draw_progress_popup();
          *pbVar38 = *pbVar38;
          pcVar43 = (char *)(pbVar38 + -2);
          pbVar38[-1] = pbVar38[-1];
          if ((cfg_systemconfig5 & 1) != 0) {
            pbVar38[-2] = 6;
            pbVar38[-1] = 0x20;
            pcVar39 = (char *)(pbVar38 + 1);
            *pbVar38 = *(char *)in_FSR2 + '\x01';
            draw_temperature_screen();
            puVar36 = pcVar39 + -1;
            *pcVar39 = *pcVar39;
            goto LAB_CODE_004204;
          }
        }
      }
      else {
        if (ui_screen == '\x1b') {
          ui_wake_pending = 1;
          ui_return_screen = ui_screen;
          ui_screen = '\x1c';
          ui_hold_counter = '\0';
          pcVar43 = (undefined1 *)((short)in_FSR1 + 1);
          if (ui_menu_active != '\0') goto LAB_CODE_00424e;
          clock_display_off(0);
          if ((cfg_systemconfig4 & 0x40) == 0) {
            ui_to_child_protect_is_active_4d80();
            ui_get_cfg_systemconfig3_4e96(0);
            puVar30 = puVar31;
            if ((cfg_systemconfig3 & 0x20) == 0) goto LAB_CODE_004064;
            uVar47 = 1;
          }
          else {
            ui_to_child_protect_is_active_4d80();
            ui_get_cfg_systemconfig2_4e8c(0);
            ser_param_tpowerdelay_5040();
            puVar30 = puVar31;
LAB_CODE_004064:
            uVar47 = 0;
          }
LAB_CODE_00406a:
          ui_to_ui_draw_label_value_4e4c(uVar47);
          ui_to_gfx_draw_frame_right_4c6e();
          puVar32 = puVar30 + 1;
          *puVar30 = 6;
          ui_to_ser_to_text_draw_word_4d7a(0x11);
          *puVar32 = 0x11;
          puVar36 = puVar32 + 2;
          puVar32[1] = 4;
          mod_to_ui_draw_progress_segment_e2ba();
LAB_CODE_004204:
          puVar40 = puVar36 + -1;
          *puVar36 = *puVar36;
        }
        else {
          if (ui_screen == '\x1a') {
            ui_return_screen = ui_screen;
            ui_screen = '\x1c';
            ui_hold_counter = '\0';
            ui_temp_change_timer = ui_param_tboil_4de4();
            ui_extra_hot_prev = mod_to_hot_temp_read_top_c932();
            ui_wake_pending = 1;
            pcVar43 = puVar30;
            if (ui_menu_active == '\0') {
              clock_display_off(0);
              if ((cfg_systemconfig4 & 0x40) == 0) {
                ui_to_child_protect_is_active_4d80();
                ui_get_cfg_systemconfig3_4e96(0);
                if ((cfg_systemconfig3 & 0x20) != 0) {
                  uVar47 = 1;
                  goto LAB_CODE_00406a;
                }
              }
              else {
                ui_to_child_protect_is_active_4d80();
                ui_get_cfg_systemconfig2_4e8c(0);
                ser_param_tpowerdelay_5040();
              }
              goto LAB_CODE_004064;
            }
            goto LAB_CODE_00424e;
          }
          if (ui_screen == '\x19') {
            ui_hold_counter = '\x02';
            ui_screen = '\x1a';
            ui_wake_pending = 1;
            pcVar43 = (undefined1 *)((short)in_FSR1 + 1);
            goto LAB_CODE_00424e;
          }
          if (ui_screen != '\x18') {
            pcVar43 = (undefined1 *)((short)in_FSR1 + 1);
            if (ui_screen == '\x17') goto LAB_CODE_00424e;
            if (ui_screen != '\x16') {
              if (ui_screen == '\x15') {
                ui_screen = '\x17';
                pcVar43 = (undefined1 *)((short)in_FSR1 + 1);
                if (ui_menu_active == '\0') {
                  puVar35 = (undefined1 *)((short)in_FSR1 + 1);
                  if (ui_return_screen == '\x1b') {
                    mod_to_mod_get_c18_tmp0_e290(0);
                    puVar35 = puVar26;
                  }
                  ui_to_clock_display_off_4d04();
                  if ((cfg_systemconfig5 & 1) != 0) {
                    ui_stack_adjust_4dde();
                  }
                  ser_word_child_protect_5066();
                  uVar47 = 0x62;
                  goto LAB_CODE_0041aa;
                }
              }
              else if (ui_screen == '\x11') {
                cVar48 = dispense_hot_is_active();
                pcVar43 = puVar25;
                if ((cVar48 == '\0') && (puVar20 = puVar25, ui_countdown_100ms == '\0')) {
LAB_CODE_003f10:
                  ui_screen = ui_return_screen;
                  pcVar43 = puVar20;
                }
              }
              else if (ui_screen == '\x10') {
                ui_screen = '\x11';
                ui_dispense_state = 0;
                pcVar43 = (undefined1 *)((short)in_FSR1 + 1);
                if (ui_menu_active == '\0') {
                  puVar4 = (undefined1 *)((short)in_FSR1 + 1);
                  if (ui_return_screen == '\x1b') {
                    mod_to_mod_get_c18_tmp0_e290(0);
                    puVar4 = puVar24;
                  }
                  ui_to_clock_display_off_4d04();
                  ui_test_value_4f9a();
joined_c0x003eca:
                  if (cVar48 == '\x1b') {
LAB_CODE_003eee:
                    puVar35 = puVar4 + 1;
                    *puVar4 = 7;
                    uVar47 = 0xe;
                  }
                  else {
                    puVar35 = puVar4 + 1;
                    *puVar4 = 7;
                    uVar47 = 0xf;
                  }
                  goto LAB_CODE_0041aa;
                }
              }
              else if (ui_screen == '\x12') {
                ui_dispense_state = 0;
                ui_screen = '\x13';
                pcVar43 = (undefined1 *)((short)in_FSR1 + 1);
                if (ui_menu_active == '\0') {
                  puVar4 = (undefined1 *)((short)in_FSR1 + 1);
                  if (ui_return_screen == '\x1b') {
                    mod_to_mod_get_c18_tmp0_e290(0);
                    puVar4 = puVar23;
                  }
                  ui_to_clock_display_off_4d04();
                  ui_test_value_4f9a();
                  goto joined_c0x003eca;
                }
              }
              else if (ui_screen == '\f') {
                ui_dispense_state = 0;
                ui_screen = '\r';
                pcVar43 = (undefined1 *)((short)in_FSR1 + 1);
                if (ui_menu_active == '\0') {
                  puVar4 = (undefined1 *)((short)in_FSR1 + 1);
                  if (ui_return_screen == '\x1b') {
                    mod_to_mod_get_c18_tmp0_e290(0);
                    puVar4 = puVar22;
                  }
                  ui_to_clock_display_off_4d04();
                  goto LAB_CODE_003eee;
                }
              }
              else if (ui_screen == '\n') {
                ui_screen = '\v';
                ui_hold_counter = '\x03';
                pcVar43 = (undefined1 *)((short)in_FSR1 + 1);
                if (ui_menu_active == '\0') {
                  clock_display_off(0);
                  puVar29 = puVar21 + 1;
                  *puVar21 = 6;
                  ser_to_text_draw_word_5048(0xd);
                  goto LAB_CODE_003f82;
                }
              }
              else if (ui_screen == '\v') {
                pcVar43 = (undefined1 *)((short)in_FSR1 + 1);
                if (ui_hold_counter == '\0') {
                  cVar48 = system_get_mode(0);
                  puVar12 = puVar20;
                  if (cVar48 == '\0') goto LAB_CODE_00420e;
                  cVar48 = system_get_mode();
                  puVar12 = puVar20;
                  if (cVar48 == '\x01') goto LAB_CODE_003e6c;
                  goto LAB_CODE_003f10;
                }
              }
              else if (ui_screen == '\x0f') {
                bVar46 = 0;
                if (ui_alarm_index != '\x01') {
                  bVar1 = 0xe;
                  bVar46 = uv_status & 1;
                  pcVar43 = (undefined1 *)((short)in_FSR1 + 1);
                  if (bVar46 == 0) goto LAB_CODE_00424e;
                }
                ui_to_ser_set_ui_screen_4dfa(bVar46);
                if ((*(byte *)((ushort)bVar1 * 0x100 + 0xf3) & 1) != 0) {
                  ui_to_dispense_stop_all_4f30();
                }
                pcVar43 = puVar17;
                if (ui_menu_active == '\0') {
                  puVar18 = puVar17 + 1;
                  *puVar17 = ui_dispense_state;
                  gfx_anim_icon_d(0);
LAB_CODE_003e44:
                  puVar19 = puVar18 + -1;
                  *puVar18 = *puVar18;
                  ui_stack_adjust_4dde();
                  puVar35 = puVar19 + 1;
                  *puVar19 = 6;
                  uVar47 = 0xc;
                  goto LAB_CODE_0041aa;
                }
              }
              else {
                if (ui_screen == '\x0e') {
                  ui_dispense_state = 0;
                  ui_screen = '\x0f';
                  pcVar43 = (undefined1 *)((short)in_FSR1 + 1);
                  if (ui_menu_active != '\0') goto LAB_CODE_00424e;
joined_c0x003d7c:
                  if (ui_return_screen == '\x1b') {
                    ui_dispense_state = 0;
                    mod_to_mod_get_c18_tmp0_e290();
                    puVar35 = puVar16;
                  }
                  else {
                    ui_dispense_state = 0;
                    clock_display_off(ui_return_screen + -0x1b);
                  }
                  ui_to_text_draw_char_4fa8(2);
                  uVar47 = ui_stack_adjust_4eca();
                  goto LAB_CODE_0041aa;
                }
                if (ui_screen == '\x13') {
                  pcVar43 = (undefined1 *)((short)in_FSR1 + 1);
                  if ((ui_alarm_index == '\x01') &&
                     (ser_set_ui_screen_5080(0), pcVar43 = puVar15, ui_menu_active == '\0')) {
                    puVar18 = puVar15 + 1;
                    *puVar15 = ui_dispense_state;
                    gfx_anim_icon_b(0);
                    goto LAB_CODE_003e44;
                  }
                }
                else if (ui_screen == '\r') {
                  bVar46 = 0;
                  if (ui_alarm_index != '\x01') {
                    bVar1 = 0xe;
                    bVar46 = uv_status & 1;
                    pcVar43 = (undefined1 *)((short)in_FSR1 + 1);
                    if (bVar46 == 0) goto LAB_CODE_00424e;
                  }
                  ui_to_ser_set_ui_screen_4dfa(bVar46);
                  if ((*(byte *)((ushort)bVar1 * 0x100 + 0xf3) & 1) != 0) {
                    ui_to_dispense_stop_all_4f30();
                  }
                  pcVar43 = puVar14;
                  if (ui_menu_active == '\0') {
                    puVar18 = puVar14 + 1;
                    *puVar14 = ui_dispense_state;
                    gfx_anim_icon_c(0);
                    goto LAB_CODE_003e44;
                  }
                }
                else if (ui_screen == '\t') {
                  bVar46 = 0;
                  if (ui_alarm_index != '\x01') {
                    bVar1 = 0xe;
                    bVar46 = uv_status & 1;
                    pcVar43 = (undefined1 *)((short)in_FSR1 + 1);
                    if (bVar46 == 0) goto LAB_CODE_00424e;
                  }
                  ui_to_ser_set_ui_screen_4dfa(bVar46);
                  if ((*(byte *)((ushort)bVar1 * 0x100 + 0xf3) & 1) != 0) {
                    ui_to_dispense_stop_all_4f30();
                  }
                  pcVar43 = puVar13;
                  if (ui_menu_active == '\0') {
                    puVar18 = puVar13 + 1;
                    *puVar13 = ui_dispense_state;
                    gfx_anim_icon_a(0);
                    goto LAB_CODE_003e44;
                  }
                }
                else if (ui_screen == '\b') {
                  ui_screen = '\t';
joined_c0x003d42:
                  ui_dispense_state = 0;
                  pcVar43 = (undefined1 *)((short)in_FSR1 + 1);
                  if (ui_menu_active == '\0') goto joined_c0x003d7c;
                }
                else if (ui_screen == '\a') {
                  cVar48 = dispense_cold_is_active();
                  pcVar43 = puVar12;
                  if ((cVar48 == '\0') && (ui_countdown_100ms == '\0')) {
                    cVar48 = system_get_mode(0);
                    if (cVar48 == '\x01') {
LAB_CODE_003e6c:
                      ui_screen = '\x02';
                      pcVar43 = puVar12;
                    }
                    else {
LAB_CODE_00420e:
                      ui_screen = '\0';
                      pcVar43 = puVar12;
                    }
                  }
                }
                else {
                  if (ui_screen == '\x06') {
                    ui_screen = '\a';
                    goto joined_c0x003d42;
                  }
                  if (ui_screen == '\x01') {
                    cVar48 = system_get_mode();
                    puVar12 = puVar11;
                    if (cVar48 == '\x01') goto LAB_CODE_003e6c;
                    pcVar43 = puVar11;
                    if (ui_message_timer != '\0') {
                      ui_message_timer = ui_message_timer + -1;
                      puVar4 = puVar11;
                      cVar45 = ui_message_timer;
joined_c0x003d34:
                      pcVar43 = puVar4;
                      puVar12 = puVar4;
                      if (cVar45 == '\0') goto LAB_CODE_00420e;
                    }
                  }
                  else {
                    if (ui_screen != '\x03') {
                      if (ui_screen == '\x05') {
                        cVar45 = system_get_mode();
                        puVar4 = puVar9;
                        goto joined_c0x003d34;
                      }
                      if (ui_screen == '\x04') {
                        ui_screen = '\x05';
                        pcVar43 = (undefined1 *)((short)in_FSR1 + 1);
                        if (ui_menu_active == '\0') {
                          lcd_clear(0);
                          clock_draw();
                          puVar8 = puVar7 + 1;
                          *puVar7 = 6;
                          ui_to_ser_to_text_draw_word_4d7a(10);
                          ui_get_PORTH_4f12();
                          bVar1 = PORTC;
                          PORTC = bVar1 & ~RC1;
                          ui_backlight_timeout = 0;
                          pcVar43 = puVar8;
                        }
                        goto LAB_CODE_00424e;
                      }
                      if (ui_screen != '\x02') {
                        if (ui_screen != '\0') goto LAB_CODE_00425e;
                        ui_wake_pending = 0;
                        ui_screen = '\x01';
                        pcVar43 = (undefined1 *)((short)in_FSR1 + 1);
                        if (ui_menu_active != '\0') goto LAB_CODE_00424e;
                        puVar4 = (undefined1 *)((short)in_FSR1 + 1);
                        if (ui_message_timer == '\0') {
                          if ((cfg_systemconfig4 & 0x40) == 0) {
                            ui_to_child_protect_is_active_4d80(0);
                            ui_get_cfg_systemconfig3_4e96(0);
                            puVar2 = puVar3;
                            if ((cfg_systemconfig3 & 0x20) == 0) goto LAB_CODE_003c30;
                            uVar47 = 1;
                          }
                          else {
                            ui_to_child_protect_is_active_4d80(0);
                            ui_get_cfg_systemconfig2_4e8c(0);
                            ser_param_tpowerdelay_5040();
LAB_CODE_003c30:
                            uVar47 = 0;
                            puVar3 = puVar2;
                          }
                          ui_to_ui_draw_label_value_4e4c(uVar47);
                          puVar4 = puVar3;
                        }
                        ui_to_gfx_draw_frame_right_4c6e();
                        ui_to_txt_to_text_draw_char_4fb2();
                        ui_stack_adjust_4dde();
                        if (ui_message_timer == '\0') {
                          clock_draw();
                          pcVar43 = puVar4;
                        }
                        else {
                          ui_word_tue_3ada(ui_message_timer);
                          pcVar43 = puVar4;
                        }
                        goto LAB_CODE_00424e;
                      }
                      ui_screen = '\x03';
                      pcVar43 = (undefined1 *)((short)in_FSR1 + 1);
                      if (ui_menu_active != '\0') goto LAB_CODE_00424e;
                      if ((cfg_systemconfig4 & 0x40) == 0) {
                        ui_to_child_protect_is_active_4d80(0);
                        ui_get_cfg_systemconfig3_4e96(0);
                        puVar5 = puVar6;
                        if ((cfg_systemconfig3 & 0x20) == 0) goto LAB_CODE_003ca6;
                        uVar47 = 1;
                      }
                      else {
                        ui_to_child_protect_is_active_4d80(0);
                        ui_get_cfg_systemconfig2_4e8c(0);
                        ser_param_tpowerdelay_5040();
LAB_CODE_003ca6:
                        uVar47 = 0;
                        puVar6 = puVar5;
                      }
                      ui_to_ui_draw_label_value_4e4c(uVar47);
                      ui_to_gfx_draw_frame_right_4c6e();
                      ui_stack_adjust_4dde();
                      clock_draw();
                      puVar35 = puVar6 + 1;
                      *puVar6 = 6;
                      uVar47 = 9;
                      goto LAB_CODE_0041aa;
                    }
                    cVar48 = system_get_mode();
                    pcVar43 = puVar10;
                    if (cVar48 == '\0') {
                      if (ui_substate == '\0') {
                        ui_screen = '\x19';
                      }
                      else {
                        cVar48 = heating_request_extra_hot(ui_substate);
                        puVar12 = puVar10;
                        if (cVar48 == '\0') goto LAB_CODE_00420e;
                        ui_screen = '\x1b';
                        pcVar43 = puVar10;
                      }
                    }
                  }
                }
              }
              goto LAB_CODE_00424e;
            }
            ui_screen = '\x17';
            pcVar43 = (undefined1 *)((short)in_FSR1 + 1);
            if (ui_menu_active != '\0') goto LAB_CODE_00424e;
            puVar35 = (undefined1 *)((short)in_FSR1 + 1);
            if (ui_return_screen == '\x1b') {
              mod_to_mod_get_c18_tmp0_e290(0);
              puVar35 = puVar27;
            }
            ui_to_clock_display_off_4d04();
            if ((cfg_systemconfig5 & 1) != 0) {
              ui_stack_adjust_4dde();
            }
            ser_word_child_protect_5066();
            uVar47 = 99;
            goto LAB_CODE_0041aa;
          }
          ui_screen = ui_return_screen;
          pcVar43 = (undefined1 *)((short)in_FSR1 + 1);
          if (ui_menu_active != '\0') goto LAB_CODE_00424e;
          ui_to_text_draw_char_4fa8(2);
          puVar29 = puVar28 + 1;
          *puVar28 = 4;
          text_draw_char();
LAB_CODE_003f82:
          puVar40 = puVar29 + -1;
          *puVar29 = *puVar29;
          ser_push_args_01_txt_to_text_draw_char_5052();
        }
        *puVar40 = *puVar40;
        pcVar43 = puVar40 + -1;
      }
    }
  }
LAB_CODE_00424e:
  if (ui_menu_active == '\0') {
    ui_draw_status_icons(0);
    puVar44 = pcVar43;
  }
  else {
    screen_diagnostics();
    puVar44 = pcVar43;
  }
LAB_CODE_00425e:
  *puVar44 = *puVar44;
  ui_c18_epilogue_4d6e();
  return;
}

