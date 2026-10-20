// address 0x004264  size 624 bytes
// callers: 00b256,

/* WARNING: Instruction at (CODE,0x004354) overlaps instruction at (CODE,0x004352)
    */
/* WARNING: Restarted to delay deadcode elimination for space: DATA */
/* Initialise UI state, LEDs and display */

undefined1 ui_init(void)

{
  undefined1 *puVar1;
  byte *pbVar2;
  byte *pbVar3;
  undefined1 *puVar4;
  undefined1 *puVar5;
  BADSPACEBASE *in_FSR1;
  undefined1 *puVar6;
  undefined1 *puVar7;
  undefined1 *puVar8;
  byte *pbVar9;
  byte *pbVar10;
  undefined1 *puVar11;
  undefined1 *puVar12;
  undefined1 *puVar13;
  byte *pbVar14;
  undefined1 *puVar15;
  undefined1 *puVar16;
  undefined1 *puVar17;
  undefined1 *puVar18;
  undefined1 *puVar19;
  undefined1 *puVar20;
  byte bVar21;
  char cVar22;
  bool bVar23;
  
  pbVar3 = (byte *)CONCAT11((char)((ushort)&FramePointer10x0002 >> 8),(char)&FramePointer10x0002);
  bVar21 = PORTH;
  PORTH = bVar21 & ~RH6;
  if ((cfg_systemconfig5 & 8) == 0) {
    bVar21 = PORTH;
    PORTH = bVar21 & ~RH6;
  }
  else {
    bVar21 = PORTH;
    PORTH = bVar21 & ~RH4;
  }
  bVar21 = PORTH;
  PORTH = bVar21 | RH7;
  bVar21 = PORTB;
  PORTB = bVar21 | RB0;
  bVar21 = PORTB;
  PORTB = bVar21 & ~RB1;
  bVar21 = PORTC;
  PORTC = bVar21 | RC0;
  bVar21 = PORTC;
  PORTC = bVar21 & ~RC1;
  keys_current = 0;
  buzzer_pattern = 0;
  ui_countdown_100ms = 0;
  ui_screen_timeout = 0xff;
  ui_backlight_timeout = 0;
  ui_menu_active = 0;
  ui_menu_param = 0;
  ui_header_text = 0;
  ui_message_timer = 0;
  ui_clock_suppressed = 0;
  puVar6 = &FramePointer10x0006;
  ui_refresh_timer = eeprom_read_param();
  puVar7 = puVar6 + -1;
  *puVar6 = *puVar6;
  c18_tmp0 = (cfg_systemconfig2 & 0x38) >> 3;
  if (7 < c18_tmp0) {
    cfg_systemconfig2 = cfg_systemconfig2 & 199;
  }
  lcd_init(c18_tmp0 - 8);
  lcd_clear();
  puVar8 = puVar7 + 1;
  *puVar7 = 0x5f;
  ui_draw_title();
  pbVar9 = puVar8 + -1;
  *puVar8 = *puVar8;
  bVar21 = keypad_scan();
  if ((bVar21 & 0x20) == 0) {
    cVar22 = is_factory_jumper();
    if (cVar22 == '\0') {
      if (((cfg_systemconfig4 & 1) == 0) || (bVar21 = keypad_scan(), (bVar21 & 0x40) == 0)) {
        if ((cfg_systemconfig4 & 1) == 0) {
          puVar17 = pbVar9 + 1;
          *pbVar9 = 0x88;
          ui_get_buzzer_pattern_4850();
          puVar13 = puVar17 + -1;
          *puVar17 = *puVar17;
        }
        else {
          puVar16 = pbVar9 + 1;
          *pbVar9 = 0x80;
          ui_get_buzzer_pattern_4850();
          puVar13 = puVar16 + -1;
          *puVar16 = *puVar16;
        }
        lcd_draw_big_glyph();
      }
      else {
        cfg_systemconfig4 = cfg_systemconfig4 & 0xfe;
        *pbVar9 = cfg_systemconfig4;
        pbVar14 = pbVar9 + 2;
        pbVar9[1] = 0x3a;
        param_write();
        *pbVar14 = *pbVar14;
        pbVar14[-1] = pbVar14[-1];
        pbVar14[-2] = 3;
        pbVar14[-1] = 0x6d;
        text_draw_word();
        *pbVar14 = *pbVar14;
        pbVar14[-1] = pbVar14[-1];
        puVar15 = pbVar14 + -1;
        pbVar14[-2] = 0xf0;
        ui_get_buzzer_pattern_4850();
        puVar13 = puVar15 + -1;
        *puVar15 = *puVar15;
      }
    }
    else {
      cfg_systemconfig4 = cfg_systemconfig4 & 0xfe;
      *pbVar9 = 3;
      puVar11 = pbVar9 + 2;
      pbVar9[1] = 0x6f;
      text_draw_word();
      *puVar11 = *puVar11;
      puVar11[-1] = puVar11[-1];
      puVar12 = puVar11 + -1;
      puVar11[-2] = 0xaa;
      ui_get_buzzer_pattern_4850();
      puVar13 = puVar12 + -1;
      *puVar12 = *puVar12;
    }
    ui_compressor_indicator = 0;
    ui_heater_indicator = 0;
    ui_layout_0 = 8;
    ui_layout_1 = 6;
    ui_layout_2 = 0x28;
    ui_layout_3 = 7;
    ui_layout_4 = 0x2f;
    ui_disp_hot_top = 0x32;
    puVar18 = puVar13 + 1;
    *puVar13 = 0x15;
    ui_disp_hot_bottom = eeprom_read_param();
    *puVar18 = *puVar18;
    ui_layout_5 = 8;
    ui_layout_6 = 0x73;
    ui_layout_7 = 0x28;
    ui_layout_8 = 7;
    ui_layout_9 = 0x2f;
    puVar18[-1] = 3;
    ui_disp_cold_a = param_read_min();
    *puVar18 = *puVar18;
    puVar18[-1] = 3;
    ui_disp_cold_b = param_read_max();
    *puVar18 = *puVar18;
    puVar18[-1] = 0;
    cVar22 = eeprom_read_param();
    puVar20 = puVar18 + -1;
    *puVar18 = *puVar18;
    if (cVar22 != '\0') {
      puVar18[-1] = 0;
      puVar19 = puVar18 + 1;
      *puVar18 = 0;
      param_write();
      *puVar19 = *puVar19;
      puVar20 = puVar19 + -2;
      puVar19[-1] = puVar19[-1];
    }
    *puVar20 = *puVar20;
    puVar20[-1] = puVar20[-1];
    puVar20[-2] = puVar20[-2];
    puVar20[-3] = puVar20[-3];
    return 0;
  }
  cfg_systemconfig4 = cfg_systemconfig4 | 1;
  *pbVar9 = cfg_systemconfig4;
  pbVar10 = pbVar9 + 2;
  pbVar9[1] = 0x3a;
  param_write();
  *pbVar10 = *pbVar10;
  pbVar10[-1] = pbVar10[-1];
  pbVar10[-2] = 3;
  pbVar10[-1] = 0x6c;
  text_draw_word();
  *pbVar10 = *pbVar10;
  pbVar10[-1] = pbVar10[-1];
  *pbVar3 = 0;
  while (*pbVar3 < 3) {
    bVar21 = PORTB;
    PORTB = bVar21 | RB3;
    pbVar3[2] = 0;
    pbVar3[4] = 0;
    pbVar2 = pbVar3 + 2;
    while( true ) {
      puVar4 = pbVar2;
      bVar21 = puVar4[4];
      bVar23 = false;
      if (-1 < (char)bVar21) {
        bVar23 = bVar21 < (byte)~(0x99 < (byte)puVar4[2]) || 2 < bVar21 - ~(0x99 < (byte)puVar4[2]);
      }
      if (bVar23) break;
      cVar22 = '<';
      do {
        cVar22 = cVar22 + -1;
      } while (cVar22 != '\0');
      puVar4[4] = puVar4[5] + '\x01';
      pbVar2 = puVar4 + 4;
      if (puVar4[5] == -1) {
        puVar4[7] = puVar4[8] + '\x01';
        pbVar2 = puVar4 + 6;
      }
    }
    bVar21 = PORTB;
    PORTB = bVar21 & ~RB3;
    puVar4[4] = 0;
    puVar4[6] = 0;
    puVar1 = puVar4 + 4;
    while( true ) {
      puVar5 = puVar1;
      pbVar3 = puVar5 + 2;
      bVar21 = puVar5[4];
      bVar23 = false;
      if (-1 < (char)bVar21) {
        bVar23 = bVar21 < (byte)~(0x99 < (byte)puVar5[2]) || 2 < bVar21 - ~(0x99 < (byte)puVar5[2]);
      }
      if (bVar23) break;
      cVar22 = '<';
      do {
        cVar22 = cVar22 + -1;
      } while (cVar22 != '\0');
      puVar5[4] = puVar5[5] + '\x01';
      puVar1 = puVar5 + 4;
      if (puVar5[5] == -1) {
        puVar5[7] = puVar5[8] + '\x01';
        puVar1 = puVar5 + 6;
      }
    }
    puVar5[2] = puVar5[2] + '\x01';
  }
  do {
                    /* WARNING: Do nothing block with infinite loop */
  } while( true );
}

