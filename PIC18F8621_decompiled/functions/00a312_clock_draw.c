// address 0x00a312  size 258 bytes
// callers: 004828,002c22,00a588,004550,003b12,

/* Draw the clock (big digits or text style per SYSTEMCONFIG3 bit7) */

char clock_draw(void)

{
  byte bVar1;
  BADSPACEBASE *in_FSR1;
  byte *pbVar2;
  undefined1 *puVar3;
  undefined1 *puVar4;
  undefined1 *puVar5;
  undefined1 *puVar6;
  undefined1 *puVar7;
  char cVar8;
  char cVar9;
  undefined1 uVar10;
  undefined1 in_PRODL;
  undefined1 in_PRODH;
  
  mod_to_lcd_draw_glyph_a956();
  clock_display_on = 1;
  cVar8 = ui_draw_home_info();
  if (cVar8 == '\0') {
    cVar8 = replacement_days_left();
    if (cVar8 == '\0') {
      clock_display_blocked = '\0';
      goto LAB_CODE_00a330;
    }
  }
  clock_display_blocked = '\x01';
LAB_CODE_00a330:
  if ((cfg_systemconfig3 & 0x80) == 0) {
    lcd_draw_big_glyph();
    cVar8 = clock_display_blocked;
    if (clock_display_blocked == '\0') {
      cVar8 = clock_draw_text_style(0);
      return cVar8;
    }
  }
  else {
    text_row = 2;
    *(byte *)in_FSR1 = (cfg_systemconfig2 & 0x38) >> 3;
    pbVar2 = (byte *)((short)in_FSR1 + 2);
    *(undefined1 *)((short)in_FSR1 + 1) = clock_day;
    word_lookup_a();
    *pbVar2 = *pbVar2;
    puVar3 = pbVar2 + -2;
    pbVar2[-1] = pbVar2[-1];
    mod_get_c18_tmp0_aa44();
    *puVar3 = in_PRODL;
    puVar3[1] = in_PRODH;
    puVar3[2] = 6;
    puVar3[3] = 0;
    puVar4 = puVar3 + 5;
    puVar3[4] = 0x7e;
    c18_tmp2 = txt_set_ui_hold_counter_98fc();
    bVar1 = (byte)puVar4;
    if (bVar1 < 5) {
      puVar5 = (undefined1 *)((ushort)puVar4 & 0xff00);
      puVar4 = puVar5 + -1;
      *puVar5 = *puVar5;
    }
    puVar6 = (undefined1 *)CONCAT11((char)((ushort)puVar4 >> 8),bVar1 - 5);
    local0 = 0;
    while( true ) {
      cVar8 = local0 - 2;
      if (1 < local0) break;
      puVar7 = puVar6 + 1;
      *puVar6 = 0x20;
      mod_frag_a982(3);
      cVar9 = mod_get_clock_pm_a99c();
      if (cVar8 == '\0') {
LAB_CODE_00a3b4:
        mod_get_clock_hour_a9d4(cVar9);
        puVar6 = puVar7;
      }
      else {
        cVar9 = '\v' - clock_hour;
        if (clock_hour < 0xc) goto LAB_CODE_00a3b4;
        cVar8 = clock_pm + -1;
        if (cVar8 == '\0') {
          cVar8 = clock_hour - 0xc;
          cVar9 = '\0';
          if (cVar8 == '\0') goto LAB_CODE_00a3b4;
        }
        mod_to_mod_get_clock_hour_a91a(cVar8);
        puVar6 = puVar7;
      }
      mod_div_helper_a988();
      local1 = 0;
      while( true ) {
        if (0xd < local1) break;
        mod_get_c18_tmp2_a892(local2);
      }
      local1 = 0;
      while( true ) {
        if (0xd < local1) break;
        mod_get_c18_tmp2_a892(local3);
      }
      local1 = 0;
      while( true ) {
        if (5 < local1) break;
        if (clock_colon_blink == '\0') {
          uVar10 = 0;
        }
        else {
          uVar10 = mod_to_mod_get_c18_tmp0_a92e(clock_colon_blink);
        }
        mod_callw_lcd_write_data_a9f6(uVar10);
      }
      mod_get_clock_minute_a9b2(local1 - 6);
      local1 = 0;
      while( true ) {
        if (0xd < local1) break;
        mod_get_c18_tmp2_a892(local2);
      }
      local1 = 0;
      while( true ) {
        if (0xd < local1) break;
        mod_get_c18_tmp2_a892(local3);
      }
      local0 = local0 + 1;
    }
  }
  return cVar8;
}

