// address 0x004550  size 728 bytes
// callers: 00b104,

/* WARNING: Removing unreachable block (CODE,0x0047cc) */
/* WARNING: Removing unreachable block (CODE,0x004730) */
/* WARNING: Restarted to delay deadcode elimination for space: DATA */
/* Per second: UI timeouts and screen updates */

byte ui_second_tick(void)

{
  BADSPACEBASE *in_FSR1;
  byte *pbVar1;
  undefined1 *puVar2;
  byte *pbVar3;
  undefined1 *puVar4;
  undefined1 *puVar5;
  undefined1 *puVar6;
  byte bVar7;
  char cVar8;
  byte bVar9;
  undefined1 uVar10;
  undefined1 in_PRODL;
  byte unaff_C;
  bool bVar11;
  
  bVar7 = ui_menu_active;
  if (ui_menu_active == 0) {
    unaff_C = 0x1d < ui_screen;
    bVar7 = 0;
    if (ui_screen != 0x1e) {
      unaff_C = 0x1e < ui_screen;
      bVar7 = 0;
      if (((ui_screen != 0x1f) && (bVar7 = 0, ui_backlight_timeout != '\0')) &&
         (bVar7 = cfg_systemconfig5 & 0x80, bVar7 == 0)) {
        unaff_C = ui_backlight_timeout != '\0';
        ui_backlight_timeout = ui_backlight_timeout + -1;
        if (ui_backlight_timeout == '\0') {
          bVar7 = ui_get_PORTH_4f12();
          bVar9 = PORTC;
          PORTC = bVar9 & ~RC1;
        }
      }
    }
  }
  if ((cfg_systemconfig5 & 0x80) != 0) {
    ui_get_PORTH_4f04(bVar7);
    ui_backlight_timeout = '\x03';
  }
  if ((ui_menu_active == 0) && (ui_menu_param != '\0')) {
    unaff_C = ui_menu_param != '\0';
    ui_menu_param = ui_menu_param + -1;
  }
  if ((ui_screen == 4) || (ui_screen == 5)) {
    if (ui_menu_active != 0) {
      return ui_menu_active;
    }
    bVar7 = clock_blink_update(0);
    return bVar7;
  }
  if ((((ui_screen == 0) || (ui_screen == 1)) || (ui_screen == 2)) || (ui_screen == 3)) {
    if (ui_menu_active != 0) {
      return ui_menu_active;
    }
    clock_blink_update(0);
    ui_clock_block_tmp = replacement_days_left();
    bVar9 = ui_clock_suppressed;
    bVar7 = ui_clock_block_tmp;
    if ((ui_clock_block_tmp == 0) && (bVar7 = 0, ui_clock_suppressed != 0)) {
      ui_clock_suppressed = 0;
      bVar7 = clock_draw(bVar9);
    }
    ui_clock_suppressed = ui_clock_block_tmp;
    return bVar7;
  }
  if (ui_screen == 0x1f) {
    bVar7 = 0;
    if (ui_menu_active != 0) {
      return ui_menu_active;
    }
LAB_CODE_0047f8:
    bVar7 = menu_timer_tick(bVar7);
    return bVar7;
  }
  if (ui_screen == 0x14) {
    *(undefined1 *)in_FSR1 = 0;
    if ((ui_screen_timeout & 0x80) == 0) {
      bVar7 = *(byte *)in_FSR1;
      bVar11 = bVar7 < 0xfe || ui_screen_timeout < bVar7 + 2;
      bVar7 = (bVar7 - ui_screen_timeout) + 2;
    }
    else {
      bVar11 = (char)ui_screen_timeout < '\0';
      bVar7 = ui_screen_timeout << 1 | unaff_C & 1;
    }
    if (!bVar11) {
      ui_screen_timeout = ui_screen_timeout - 1;
    }
    goto LAB_CODE_0047f8;
  }
  if (ui_screen == 0x11) {
    if (ui_menu_active != 0) {
      return ui_menu_active;
    }
    bVar7 = ui_to_gfx_anim_icon_b_4e66(0);
    if (bVar7 >= 5) {
      ui_dispense_state = 0;
    }
    bVar9 = ui_set_ui_blink_phase_4ef4('\x04' - bVar7);
    if (bVar7 < 5) {
      return bVar9;
    }
    if ((ui_blink_phase & 1) == 0) {
      ui_to_txt_to_text_draw_char_4fb2();
      ui_test_value_4f9a();
      *(undefined1 *)in_FSR1 = 7;
      puVar6 = (undefined1 *)((short)in_FSR1 + 1);
      bVar7 = ser_to_text_draw_word_5048(0xe);
      goto LAB_CODE_0047d6;
    }
    puVar6 = (undefined1 *)((short)in_FSR1 + 1);
    *(undefined1 *)in_FSR1 = 6;
    uVar10 = 0x16;
  }
  else {
    if (ui_screen != 0x13) {
      if (ui_screen == 0xd) {
        if (ui_menu_active != 0) {
          return ui_menu_active;
        }
        pbVar3 = (byte *)((short)in_FSR1 + 1);
        *(byte *)in_FSR1 = ui_dispense_state;
        ui_dispense_state = ui_dispense_state + 1;
        gfx_anim_icon_c();
        puVar4 = pbVar3 + -1;
        *pbVar3 = *pbVar3;
        bVar11 = ui_dispense_state < 3;
        cVar8 = '\x02' - ui_dispense_state;
        if (!bVar11) {
          ui_dispense_state = 0;
        }
        bVar7 = ui_set_ui_blink_phase_4ef4(cVar8);
        if (bVar11) {
          return bVar7;
        }
        if ((ui_blink_phase & 1) == 0) {
          ser_chain_ui_to_lcd_draw_gly_fn4ea0_5096();
          ui_to_eeprom_read_raw_4dd4(0x35);
          ui_to_ui_draw_temp_units_4d8e();
          *(undefined1 *)((ushort)puVar4 & 0xff00) = *(undefined1 *)((ushort)puVar4 & 0xff00);
          bVar7 = ser_set_ui_blink_phase_5074();
          return bVar7;
        }
        in_FSR1 = (BADSPACEBASE *)(puVar4 + 1);
        *puVar4 = 6;
        ui_to_ser_to_text_draw_word_4d7a(0xe);
        cVar8 = ui_get_cfg_systemconfig2_4e02();
        if (cVar8 == '\a') {
          return 0;
        }
      }
      else {
        if (((ui_screen == 0x19) || (ui_screen == 0x1d)) || (ui_screen == 0xb)) {
          bVar7 = -ui_hold_counter;
          if (ui_hold_counter == '\0') {
            return 0;
          }
          ui_hold_counter = ui_hold_counter + -1;
          return bVar7;
        }
        if (ui_screen == 0xf) {
          if (ui_menu_active != 0) {
            return ui_menu_active;
          }
          pbVar1 = (byte *)((short)in_FSR1 + 1);
          *(byte *)in_FSR1 = ui_dispense_state;
          ui_dispense_state = ui_dispense_state + 1;
          gfx_anim_icon_d();
          in_FSR1 = (BADSPACEBASE *)(pbVar1 + -1);
          *pbVar1 = *pbVar1;
          bVar11 = ui_dispense_state < 3;
          cVar8 = '\x02' - ui_dispense_state;
          if (!bVar11) {
            ui_dispense_state = 0;
          }
          bVar7 = ui_set_ui_blink_phase_4ef4(cVar8);
          if (bVar11) {
            return bVar7;
          }
          if ((ui_blink_phase & 1) == 0) {
            ser_chain_ui_to_lcd_draw_gly_fn4ea0_5096();
            ui_to_eeprom_read_raw_4dd4(0x43);
            ui_to_ui_draw_temp_units_4d8e();
LAB_CODE_0046a0:
            puVar2 = (undefined1 *)((ushort)in_FSR1 & 0xff00);
            in_FSR1 = (BADSPACEBASE *)(puVar2 + -1);
            *puVar2 = *puVar2;
            ui_stack_adjust_4e78();
LAB_CODE_0046a6:
            bVar7 = ser_to_text_draw_word_5048();
            goto LAB_CODE_0046f4;
          }
          if (1 < (ui_blink_phase & 3)) goto LAB_CODE_004680;
LAB_CODE_004688:
          *(undefined1 *)in_FSR1 = 6;
          uVar10 = 0xb;
          in_FSR1 = (BADSPACEBASE *)((short)in_FSR1 + 1);
        }
        else {
          if (ui_screen == 9) {
            if (ui_menu_active != 0) {
              return ui_menu_active;
            }
            bVar7 = ui_to_gfx_anim_icon_a_4e54(0);
            if (bVar7 >= 3) {
              ui_dispense_state = 0;
            }
            bVar9 = ui_set_ui_blink_phase_4ef4('\x02' - bVar7);
            if (bVar7 < 3) {
              return bVar9;
            }
            if ((ui_blink_phase & 1) == 0) {
              ser_chain_ui_to_lcd_draw_gly_fn4ea0_5096();
              ui_to_eeprom_read_raw_4dd4(0x3e);
              ui_to_ui_draw_temp_units_4d8e();
              goto LAB_CODE_0046a0;
            }
            if ((ui_blink_phase & 3) < 2) goto LAB_CODE_004688;
          }
          else {
            if ((ui_screen ^ 7) != 0) {
              return ui_screen ^ 7;
            }
            if (ui_menu_active != 0) {
              return ui_menu_active;
            }
            bVar7 = ui_to_gfx_anim_icon_a_4e54(0);
            if (4 < bVar7) {
              ui_dispense_state = 0;
            }
            bVar9 = ui_set_ui_blink_phase_4ef4('\x04' - bVar7);
            if (4 >= bVar7) {
              return bVar9;
            }
            if ((ui_blink_phase & 1) == 0) {
              ui_stack_adjust_4eca();
              goto LAB_CODE_0046a6;
            }
          }
LAB_CODE_004680:
          *(undefined1 *)in_FSR1 = 6;
          uVar10 = 0x16;
          in_FSR1 = (BADSPACEBASE *)((short)in_FSR1 + 1);
        }
        ui_to_ser_to_text_draw_word_4d7a(uVar10);
      }
      bVar7 = ser_push_args_01_txt_to_text_draw_char_5052();
LAB_CODE_0046f4:
      *(undefined1 *)in_FSR1 = *(undefined1 *)in_FSR1;
      return bVar7;
    }
    if (ui_menu_active != 0) {
      return ui_menu_active;
    }
    bVar7 = ui_to_gfx_anim_icon_b_4e66(0);
    if (2 < bVar7) {
      ui_dispense_state = 0;
    }
    bVar9 = ui_set_ui_blink_phase_4ef4('\x02' - bVar7);
    if (2 >= bVar7) {
      return bVar9;
    }
    if ((ui_blink_phase & 1) == 0) {
      ui_to_lcd_draw_glyph_4ca8();
      cVar8 = ser_to_ui_to_eeprom_read_raw_509c(0x42);
      if (local4 == '\0' && cVar8 == '\0') {
        ui_test_value_4f9a(0);
        ser_to_ui_to_eeprom_read_raw_509c(0x35);
      }
      if (local4 == '\0' && local3 == '\0') {
        ui_test_value_4f9a(0);
        ser_to_ui_to_eeprom_read_raw_509c(0x3e);
      }
      ui_stack_adjust_4ea0();
      c18_tmp0 = local3;
      c18_tmp1 = local4;
      ser_get_c18_tmp1_5010(10);
      *(undefined1 *)in_FSR1 = in_PRODL;
      puVar5 = (undefined1 *)((short)in_FSR1 + 2);
      *(char *)((short)in_FSR1 + 1) = c18_tmp1;
      c18_tmp2 = ui_draw_temp_units();
      if ((byte)puVar5 < 5) {
        *(undefined1 *)((ushort)puVar5 & 0xff00) = *(undefined1 *)((ushort)puVar5 & 0xff00);
      }
      bVar7 = ser_set_ui_blink_phase_5074((byte)puVar5 - 5);
      return bVar7;
    }
    ui_test_value_4f9a();
    puVar6 = (undefined1 *)((short)in_FSR1 + 1);
    *(undefined1 *)in_FSR1 = 6;
    uVar10 = 0xf;
  }
  ui_to_ser_to_text_draw_word_4d7a(uVar10);
  bVar7 = ser_push_args_01_txt_to_text_draw_char_5052();
LAB_CODE_0047d6:
  *puVar6 = *puVar6;
  return bVar7;
}

