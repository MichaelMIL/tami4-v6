// address 0x003584  size 1366 bytes
// callers: 003b12,

/* WARNING: Removing unreachable block (CODE,0x0037fc) */
/* WARNING: Removing unreachable block (CODE,0x003790) */
/* WARNING: Removing unreachable block (CODE,0x00372c) */
/* WARNING: Removing unreachable block (CODE,0x0036c6) */
/* WARNING: Removing unreachable block (CODE,0x00365a) */
/* WARNING: Removing unreachable block (CODE,0x0035f6) */
/* WARNING: Removing unreachable block (CODE,0x0035d4) */
/* WARNING: Removing unreachable block (CODE,0x003638) */
/* WARNING: Removing unreachable block (CODE,0x0036a0) */
/* WARNING: Removing unreachable block (CODE,0x00370a) */
/* WARNING: Removing unreachable block (CODE,0x00376e) */
/* WARNING: Removing unreachable block (CODE,0x0037d6) */
/* WARNING: Removing unreachable block (CODE,0x003abc) */
/* Service diagnostics screen: title "T6 3.47V" (firmware version), sensors, states */

void screen_diagnostics(void)

{
  BADSPACEBASE *in_FSR2;
  BADSPACEBASE *in_FSR1;
  undefined1 *puVar1;
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
  undefined1 *puVar33;
  byte bVar34;
  undefined1 uVar35;
  char cVar36;
  byte bVar37;
  BADSPACEBASE *in_FSR0;
  byte *pbVar38;
  byte *pbVar39;
  byte *pbVar40;
  byte *pbVar41;
  byte *pbVar42;
  byte *pbVar43;
  byte *pbVar44;
  byte *pbVar45;
  bool bVar46;
  bool bVar47;
  
  ui_frag_4c90();
  bVar37 = (byte)in_FSR1;
  bVar47 = 0xf8 < bVar37;
  if (bVar47) {
    puVar1 = (undefined1 *)CONCAT11((char)((ushort)in_FSR1 >> 8),0xff);
    in_FSR1 = (BADSPACEBASE *)(puVar1 + 1);
    *puVar1 = *puVar1;
  }
  puVar2 = (undefined1 *)CONCAT11((char)((ushort)in_FSR1 >> 8),bVar37 + 7);
  puVar3 = puVar2 + 1;
  *puVar2 = 0x5f;
  ui_draw_title();
  *puVar3 = *puVar3;
  puVar3[-1] = 0;
  ui_callw_fncfc6_4c62(1);
  puVar4 = puVar3 + 1;
  *puVar3 = 0xd4;
  ui_callw_mod_set_lcd_text_flag_4c48(0x53);
  c18_tmp0 = hot_temp_read_top();
  c18_tmp1 = 0;
  if ((c18_tmp0 & 0x80) != 0) {
    c18_tmp1 = 0xff;
  }
  ui_get_c18_tmp0_4d10();
  ser_test_value_50aa();
  pbVar39 = (byte *)((short)in_FSR0 + -1);
  pbVar38 = (byte *)((short)in_FSR0 + -1);
  bVar37 = *(byte *)in_FSR0 ^ 0xff;
  if (bVar37 == 0) {
    ui_to_fmt_byte_4c9c(0);
  }
  else {
    ui_test_value_4f78(bVar37);
    ui_to_temp_c_to_f_4ffc();
    pbVar39 = pbVar38;
  }
  bVar34 = ui_stack_adjust_4f5a();
  bVar46 = false;
  pbVar40 = pbVar39;
  if (bVar37 == 0) {
    pbVar40 = pbVar39 + -1;
    bVar34 = *pbVar39 ^ 0xff;
    bVar46 = bVar34 == 0;
  }
  if (bVar46) {
    uVar35 = 0x45;
    *(undefined1 *)in_FSR2 = 0x45;
  }
  else {
    uVar35 = ui_test_value_4f78(bVar34);
  }
  ser_stack_adjust_508e(uVar35);
  ui_callw_fncfc6_4c62(1);
  puVar5 = puVar4 + 1;
  *puVar4 = 0xd0;
  ui_callw_mod_set_lcd_text_flag_4c48(0x53);
  c18_tmp0 = temp_read_ch6();
  c18_tmp1 = 0;
  if ((c18_tmp0 & 0x80) != 0) {
    c18_tmp1 = 0xff;
  }
  ui_get_c18_tmp0_4d10();
  ser_test_value_50aa();
  pbVar39 = pbVar40 + -1;
  pbVar41 = pbVar40 + -1;
  bVar37 = *pbVar40 ^ 0xff;
  if (bVar37 == 0) {
    ui_to_fmt_byte_4c9c(0);
  }
  else {
    ui_test_value_4f78(bVar37);
    ui_to_temp_c_to_f_4ffc();
    pbVar39 = pbVar41;
  }
  bVar34 = ui_stack_adjust_4f5a();
  bVar46 = false;
  pbVar40 = pbVar39;
  if (bVar37 == 0) {
    pbVar40 = pbVar39 + -1;
    bVar34 = *pbVar39 ^ 0xff;
    bVar46 = bVar34 == 0;
  }
  if (bVar46) {
    uVar35 = 0x45;
    *(undefined1 *)in_FSR2 = 0x45;
  }
  else {
    uVar35 = ui_test_value_4f78(bVar34);
  }
  ui_to_mod_get_lcd_text_width_4c54(uVar35);
  puVar6 = puVar5 + 1;
  *puVar5 = 0x58;
  ui_callw_fncfc6_4c62(1);
  puVar7 = puVar6 + 1;
  *puVar6 = 0xcc;
  ui_callw_mod_set_lcd_text_flag_4c48(0x53);
  c18_tmp0 = cold_temp_read_ch4();
  c18_tmp1 = 0;
  if ((c18_tmp0 & 0x80) != 0) {
    c18_tmp1 = 0xff;
  }
  ui_get_c18_tmp0_4d10();
  ser_test_value_50aa();
  pbVar39 = pbVar40 + -1;
  pbVar42 = pbVar40 + -1;
  bVar37 = *pbVar40 ^ 0xff;
  if (bVar37 == 0) {
    ui_frame_access_4e3c(0);
  }
  else {
    ui_test_value_4f78(bVar37);
    temp_c_to_f();
    pbVar39 = pbVar42;
  }
  ui_to_fmt_int_4eaa();
  bVar34 = ui_stack_adjust_4f5a();
  bVar46 = false;
  pbVar40 = pbVar39;
  if (bVar37 == 0) {
    pbVar40 = pbVar39 + -1;
    bVar34 = *pbVar39 ^ 0xff;
    bVar46 = bVar34 == 0;
  }
  if (bVar46) {
    uVar35 = 0x45;
    *(undefined1 *)in_FSR2 = 0x45;
  }
  else {
    uVar35 = ui_test_value_4f78(bVar34);
  }
  ui_to_mod_get_lcd_text_width_4c54(uVar35);
  puVar8 = puVar7 + 1;
  *puVar7 = 0;
  ui_callw_fncfc6_4c62(2);
  puVar9 = puVar8 + 1;
  *puVar8 = 200;
  ui_callw_mod_set_lcd_text_flag_4c48(0x53);
  c18_tmp0 = hot_temp_read_bottom();
  c18_tmp1 = 0;
  if ((c18_tmp0 & 0x80) != 0) {
    c18_tmp1 = 0xff;
  }
  ui_get_c18_tmp0_4d10();
  ser_test_value_50aa();
  pbVar39 = pbVar40 + -1;
  pbVar43 = pbVar40 + -1;
  bVar37 = *pbVar40 ^ 0xff;
  if (bVar37 == 0) {
    ui_to_fmt_byte_4c9c(0);
  }
  else {
    ui_test_value_4f78(bVar37);
    ui_to_temp_c_to_f_4ffc();
    pbVar39 = pbVar43;
  }
  bVar34 = ui_stack_adjust_4f5a();
  bVar46 = false;
  pbVar40 = pbVar39;
  if (bVar37 == 0) {
    pbVar40 = pbVar39 + -1;
    bVar34 = *pbVar39 ^ 0xff;
    bVar46 = bVar34 == 0;
  }
  if (bVar46) {
    uVar35 = 0x45;
    *(undefined1 *)in_FSR2 = 0x45;
  }
  else {
    uVar35 = ui_test_value_4f78(bVar34);
  }
  ser_stack_adjust_508e(uVar35);
  ui_callw_fncfc6_4c62(2);
  puVar10 = puVar9 + 1;
  *puVar9 = 0xc4;
  ui_callw_mod_set_lcd_text_flag_4c48(0x53);
  c18_tmp0 = temp_read_ch7();
  c18_tmp1 = 0;
  if ((c18_tmp0 & 0x80) != 0) {
    c18_tmp1 = 0xff;
  }
  ui_get_c18_tmp0_4d10();
  ser_test_value_50aa();
  pbVar39 = pbVar40 + -1;
  pbVar44 = pbVar40 + -1;
  bVar37 = *pbVar40 ^ 0xff;
  if (bVar37 == 0) {
    ui_to_fmt_byte_4c9c(0);
  }
  else {
    ui_test_value_4f78(bVar37);
    ui_to_temp_c_to_f_4ffc();
    pbVar39 = pbVar44;
  }
  bVar34 = ui_stack_adjust_4f5a();
  bVar46 = false;
  pbVar40 = pbVar39;
  if (bVar37 == 0) {
    pbVar40 = pbVar39 + -1;
    bVar34 = *pbVar39 ^ 0xff;
    bVar46 = bVar34 == 0;
  }
  if (bVar46) {
    uVar35 = 0x45;
    *(undefined1 *)in_FSR2 = 0x45;
  }
  else {
    uVar35 = ui_test_value_4f78(bVar34);
  }
  ui_to_mod_get_lcd_text_width_4c54(uVar35);
  puVar11 = puVar10 + 1;
  *puVar10 = 0x58;
  ui_callw_fncfc6_4c62(2);
  puVar12 = puVar11 + 1;
  *puVar11 = 0xc0;
  ui_callw_mod_set_lcd_text_flag_4c48(0x53);
  c18_tmp0 = cold_temp_read_ch5();
  c18_tmp1 = 0;
  if ((c18_tmp0 & 0x80) != 0) {
    c18_tmp1 = 0xff;
  }
  ui_get_c18_tmp0_4d10();
  ser_test_value_50aa();
  pbVar39 = pbVar40 + -1;
  pbVar45 = pbVar40 + -1;
  bVar37 = *pbVar40 ^ 0xff;
  if (bVar37 == 0) {
    ui_frame_access_4e3c(0);
  }
  else {
    ui_test_value_4f78(bVar37);
    temp_c_to_f();
    pbVar39 = pbVar45;
  }
  ui_to_fmt_int_4eaa();
  bVar34 = ui_stack_adjust_4f5a();
  bVar46 = false;
  pbVar40 = pbVar39;
  if (bVar37 == 0) {
    pbVar40 = pbVar39 + -1;
    bVar34 = *pbVar39 ^ 0xff;
    bVar46 = bVar34 == 0;
  }
  if (bVar46) {
    uVar35 = 0x45;
    *(undefined1 *)in_FSR2 = 0x45;
  }
  else {
    uVar35 = ui_test_value_4f78(bVar34);
  }
  ui_to_mod_get_lcd_text_width_4c54(uVar35);
  puVar13 = puVar12 + 1;
  *puVar12 = 0;
  ui_callw_fncfc6_4c62(3);
  puVar14 = puVar13 + 1;
  *puVar13 = 0xbc;
  ui_callw_mod_set_lcd_text_flag_4c48(0x53);
  ui_to_ui_to_fmt_byte_4fbc(heater_power_level);
  ser_stack_adjust_508e();
  ui_callw_fncfc6_4c62(3);
  puVar15 = puVar14 + 1;
  *puVar14 = 0xb8;
  ui_callw_mod_set_lcd_text_flag_4c48(0x53);
  bVar37 = PORTH;
  if ((bVar37 & RH5) == 0) {
    *puVar15 = 0xb0;
    uVar35 = 0x53;
    puVar15 = puVar15 + 1;
  }
  else {
    uVar35 = ui_stack_adjust_4eec();
  }
  ser_stack_adjust_502e(uVar35);
  ui_callw_fncfc6_4c62(3);
  puVar16 = puVar15 + 1;
  *puVar15 = 0xac;
  ui_callw_mod_set_lcd_text_flag_4c48(0x53);
  if ((outputs_shadow & 0x40) == 0) {
    cVar36 = compressor_get_offdelay();
    if (cVar36 == '\0') {
      *puVar16 = 0xb0;
      uVar35 = 0x53;
      puVar16 = puVar16 + 1;
      goto LAB_CODE_00388c;
    }
    compressor_get_offdelay();
    ui_to_ui_to_fmt_byte_4fbc();
    ser_chain_fn4f80_fn5036_50b2();
    puVar17 = puVar16 + 1;
    *puVar16 = 0x30;
    mod_get_lcd_text_width_ca24();
  }
  else {
    uVar35 = ui_stack_adjust_4eec();
LAB_CODE_00388c:
    puVar18 = puVar16 + 1;
    *puVar16 = uVar35;
    mod_set_lcd_text_flag_ca68();
    puVar17 = puVar18 + -1;
    *puVar18 = *puVar18;
  }
  *puVar17 = *puVar17;
  puVar17[-1] = 0;
  ui_callw_fncfc6_4c62(4);
  puVar15 = puVar17 + 1;
  *puVar17 = 0xa8;
  ui_callw_mod_set_lcd_text_flag_4c48(0x53);
  if ((outputs_shadow & 2) == 0) {
    *puVar15 = 0xb0;
    uVar35 = 0x53;
    puVar15 = puVar15 + 1;
  }
  else {
    uVar35 = ui_stack_adjust_4eec();
  }
  ui_callw_mod_set_lcd_text_flag_4c48(uVar35);
  puVar19 = puVar15 + 1;
  *puVar15 = 0x2c;
  ui_callw_fncfc6_4c62(4);
  puVar15 = puVar19 + 1;
  *puVar19 = 0xa4;
  ui_callw_mod_set_lcd_text_flag_4c48(0x53);
  if ((outputs_shadow & 1) == 0) {
    *puVar15 = 0xb0;
    uVar35 = 0x53;
    puVar15 = puVar15 + 1;
  }
  else {
    uVar35 = ui_stack_adjust_4eec();
  }
  ser_stack_adjust_502e(uVar35);
  ui_callw_fncfc6_4c62(4);
  puVar16 = puVar15 + 1;
  *puVar15 = 0xa0;
  ui_callw_mod_set_lcd_text_flag_4c48(0x53);
  if ((outputs_shadow & 4) == 0) {
    *puVar16 = 0xb0;
    uVar35 = 0x53;
    puVar16 = puVar16 + 1;
  }
  else {
    uVar35 = ui_stack_adjust_4eec();
  }
  ui_callw_mod_set_lcd_text_flag_4c48(uVar35);
  puVar20 = puVar16 + 1;
  *puVar16 = 0;
  ui_callw_fncfc6_4c62(5);
  puVar15 = puVar20 + 1;
  *puVar20 = 0x9c;
  ui_callw_mod_set_lcd_text_flag_4c48(0x53);
  cVar36 = heating_is_extra_hot();
  if (cVar36 == '\0') {
    cVar36 = system_get_mode();
    if (cVar36 == '\0') {
      puVar21 = puVar15 + 1;
      *puVar15 = 0x96;
      goto LAB_CODE_00395e;
    }
    cVar36 = system_get_mode();
    if (cVar36 == '\x01') {
      puVar21 = puVar15 + 1;
      *puVar15 = 0x93;
      bVar47 = true;
      goto LAB_CODE_00395e;
    }
    bVar37 = system_get_mode();
    bVar47 = bVar37 < 3;
    if (bVar37 == 2) {
      puVar21 = puVar15 + 1;
      *puVar15 = 0x90;
      goto LAB_CODE_00395e;
    }
  }
  else {
    puVar21 = puVar15 + 1;
    *puVar15 = 0x99;
LAB_CODE_00395e:
    ui_callw_mod_set_lcd_text_flag_4c48(0x53);
    puVar15 = puVar21;
  }
  puVar22 = puVar15 + 1;
  *puVar15 = 0x2c;
  ui_callw_fncfc6_4c62(5);
  puVar23 = puVar22 + 1;
  *puVar22 = 0x8c;
  ui_callw_mod_set_lcd_text_flag_4c48(0x53);
  bVar37 = PORTJ;
  if ((bVar37 & RJ3) == 0) {
    *puVar23 = 0x88;
  }
  else {
    bVar37 = PORTJ;
    if ((bVar37 & RJ4) == 0) {
      *puVar23 = 0x84;
    }
    else {
      *puVar23 = 0x80;
    }
  }
  puVar24 = puVar23 + 1;
  ser_stack_adjust_502e(0x53);
  ser_stack_adjust_505a(5);
  bVar37 = PORTJ;
  if ((bVar37 & RJ0) == 0) {
    *puVar24 = 0x88;
  }
  else {
    *puVar24 = 0x80;
  }
  puVar25 = puVar24 + 1;
  ui_callw_mod_set_lcd_text_flag_4c48(0x53);
  puVar26 = puVar25 + 1;
  *puVar25 = 0;
  ui_callw_fncfc6_4c62(6);
  bVar37 = (byte)((ushort)(puVar26 + 1) >> 8);
  *puVar26 = 0x78;
  ui_callw_mod_set_lcd_text_flag_4c48(0x53);
  if ((cfg_systemconfig3 & 4) == 0) {
    filter_usage_calc();
    math_aarg_b3 = 6;
    math_barg_b0 = 0;
    ui_get_math_tmp2_4fc6();
    ui_get_math_res0_4fdc();
    math_res0 = c18_tmp0 + 0xf;
    bVar47 = CARRY1(c18_tmp1,0xf0 < c18_tmp0);
    math_res1 = c18_tmp1 + (0xf0 < c18_tmp0);
    bVar46 = CARRY1(c18_tmp2,bVar47);
    math_aarg_lo = c18_tmp2 + bVar47;
    bVar47 = CARRY1(c18_tmp3,bVar46);
    math_aarg_hi = c18_tmp3 + bVar46;
    math_aarg_b3 = 0x1e;
    math_barg_b0 = 0;
    math_barg_lo = 0;
    math_barg_hi = 0;
    c18_tmp0 = math_res0;
    c18_tmp1 = math_res1;
    c18_tmp2 = math_aarg_lo;
    c18_tmp3 = math_aarg_hi;
    uVar35 = ui_to_ltoa_4daa();
    if (bVar47) goto LAB_CODE_003a26;
  }
  else {
    filter_usage_calc();
    math_aarg_b3 = 0x58;
    math_barg_b0 = 2;
    ui_get_math_tmp2_4fc6();
    uVar35 = ui_to_ltoa_4daa();
    if (bVar47) goto LAB_CODE_003a26;
  }
  puVar27 = (undefined1 *)((ushort)bVar37 * 0x100);
  bVar37 = (byte)((ushort)(puVar27 + -1) >> 8);
  *puVar27 = *puVar27;
LAB_CODE_003a26:
  puVar28 = (undefined1 *)CONCAT11(bVar37,uVar35);
  bVar47 = c18_tmp8 == '\0';
  ser_chain_fn4f80_fn5036_50b2(c18_tmp8);
  puVar29 = puVar28 + 1;
  *puVar28 = 0x2c;
  ui_callw_fncfc6_4c62(6);
  puVar30 = puVar29 + 1;
  *puVar29 = 0x74;
  ui_callw_mod_set_lcd_text_flag_4c48(0x53);
  bVar37 = PORTC;
  if ((bVar37 & RC3) == 0) {
    *puVar30 = 0x88;
  }
  else {
    *puVar30 = 0x80;
  }
  puVar15 = puVar30 + 1;
  ser_stack_adjust_502e(0x53);
  ser_stack_adjust_505a(6);
  bVar37 = PORTJ;
  if ((bVar37 & RJ1) == 0) {
    uVar35 = ui_stack_adjust_4eec();
  }
  else {
    *puVar15 = 0xb0;
    uVar35 = 0x53;
    puVar15 = puVar15 + 1;
  }
  ui_callw_mod_set_lcd_text_flag_4c48(uVar35);
  ui_draw_home_info();
  puVar31 = puVar15 + 1;
  *puVar15 = 0x58;
  ui_callw_fncfc6_4c62(7);
  puVar32 = puVar31 + 1;
  *puVar31 = 0x70;
  ui_callw_mod_set_lcd_text_flag_4c48(0x53);
  uVar35 = ui_to_eeprom_read_param_4f64(0x15);
  puVar33 = puVar32 + 1;
  *puVar32 = uVar35;
  ui_calc_array_ptr_4c3a();
  ui_stack_adjust_4f26();
  if ((cfg_systemconfig3 & 4) == 0) {
    ui_to_temp_c_to_f_4ffc();
  }
  else {
    ui_to_fmt_byte_4c9c();
  }
  bVar37 = ui_stack_adjust_4f5a();
  bVar46 = false;
  if (bVar47) {
    bVar37 = *pbVar40 ^ 0xff;
    bVar46 = bVar37 == 0;
  }
  if (bVar46) {
    uVar35 = 0x45;
    *(undefined1 *)in_FSR2 = 0x45;
  }
  else {
    uVar35 = ui_test_value_4f78(bVar37);
  }
  ui_to_mod_get_lcd_text_width_4c54(uVar35);
  if ((byte)puVar33 < 7) {
    *(undefined1 *)((ushort)puVar33 & 0xff00) = *(undefined1 *)((ushort)puVar33 & 0xff00);
  }
  ui_c18_epilogue_4d6e((byte)puVar33 - 7);
  return;
}

