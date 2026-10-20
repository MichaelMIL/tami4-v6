// address 0x0048b2  size 564 bytes
// callers: 00a312,003584,

/* Draw home-screen information (temperatures / clock area) */

void ui_draw_home_info(void)

{
  char *pcVar1;
  BADSPACEBASE *in_FSR2;
  undefined1 *puVar2;
  undefined1 *puVar3;
  undefined1 *puVar4;
  byte bVar5;
  byte bVar6;
  BADSPACEBASE *in_FSR1;
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
  char cVar18;
  undefined1 uVar19;
  BADSPACEBASE *in_FSR0;
  undefined1 in_PRODL;
  undefined1 in_PRODH;
  
  ui_frag_4c90();
  bVar5 = (byte)in_FSR1;
  if (0xea < bVar5) {
    puVar7 = (undefined1 *)CONCAT11((char)((ushort)in_FSR1 >> 8),0xff);
    in_FSR1 = (BADSPACEBASE *)(puVar7 + 1);
    *puVar7 = *puVar7;
  }
  puVar8 = (undefined1 *)CONCAT11((char)((ushort)in_FSR1 >> 8),bVar5 + 0x15);
  *puVar8 = 0x14;
  puVar8[1] = 0;
  puVar9 = puVar8 + 3;
  puVar8[2] = 0x20;
  ui_stack_adjust_4f80();
  c18_tmp0 = mod_frag_f55e();
  bVar5 = (byte)puVar9;
  if (bVar5 < 5) {
    puVar10 = (undefined1 *)((ushort)puVar9 & 0xff00);
    puVar9 = puVar10 + -1;
    *puVar10 = *puVar10;
  }
  puVar11 = (undefined1 *)CONCAT11((char)((ushort)puVar9 >> 8),bVar5 - 5);
  cVar18 = ui_get_cfg_systemconfig2_4e02(c18_tmp0);
  if (cVar18 == '\x05') {
    puVar2 = (undefined1 *)((short)in_FSR2 + 1);
    *(undefined1 *)((short)in_FSR2 + 0x15) = 0;
  }
  else {
    c18_tmp0 = 0x6c;
    c18_tmp1 = 0x53;
    c18_tmp2 = 0;
    *puVar11 = 0x6c;
    puVar11[1] = 0x53;
    puVar12 = puVar11 + 3;
    puVar11[2] = c18_tmp2;
    ui_stack_adjust_4f80();
    c18_tmp3 = strcpy_rom2ram();
    bVar5 = (byte)puVar12;
    if (bVar5 < 5) {
      puVar13 = (undefined1 *)((ushort)puVar12 & 0xff00);
      puVar12 = puVar13 + -1;
      *puVar13 = *puVar13;
    }
    puVar11 = (undefined1 *)CONCAT11((char)((ushort)puVar12 >> 8),bVar5 - 5);
    *(undefined1 *)((short)in_FSR2 + 0x15) = 4;
    in_PRODL = 0x20;
    puVar2 = (undefined1 *)((short)in_FSR2 + 2);
    *(undefined1 *)((short)in_FSR2 + 5) = 0x20;
  }
  if (cooling_fault == -0x76) {
    ui_frag_4ff2();
    uVar19 = 0x39;
LAB_CODE_00494a:
    ui_get_c18_tmp0_4f48(uVar19);
  }
  else {
    if (cooling_fault == -0x71) {
      ui_frame_access_4be8();
      uVar19 = 0x31;
      goto LAB_CODE_00494a;
    }
    if (cooling_fault == -0x73) {
      ui_frame_access_4be8();
      uVar19 = 0x32;
      goto LAB_CODE_00494a;
    }
  }
  if (heating_fault == -0x72) {
    ui_frame_access_4be8();
    uVar19 = 0x37;
LAB_CODE_004976:
    ui_get_c18_tmp0_4f48(uVar19);
  }
  else {
    if (heating_fault == -0x76) {
      ui_frag_4f6e();
      uVar19 = 0x30;
      goto LAB_CODE_004976;
    }
    if (heating_fault == -0x71) {
      ui_frame_access_4be8();
      uVar19 = 0x35;
      goto LAB_CODE_004976;
    }
    if (heating_fault == -0x73) {
      ui_frame_access_4be8();
      uVar19 = 0x36;
      goto LAB_CODE_004976;
    }
  }
  if (compressor_fault == -0x7c) {
    ui_frame_access_4be8(0);
    ui_get_c18_tmp0_4f48(0x34);
  }
  if (heater_fault == -0x7c) {
    ui_frame_access_4be8(0);
    ui_get_c18_tmp0_4f48(0x38);
  }
  if (uv_alarm_code == -0x75) {
    ui_frame_access_4be8(0);
    ui_get_c18_tmp0_4f48(0x33);
  }
  if (inlet_valve_fault == -0x7c) {
    ui_frag_4ff2(0);
    ui_get_c18_tmp0_4f48(0x31);
  }
  if (cold_valve_fault == -0x7c) {
    ui_frame_access_4be8(0);
    ui_get_c18_tmp0_4f48(0x39);
  }
  if (hot_valve_fault == -0x7c) {
    ui_frag_4ff2(0);
    ui_get_c18_tmp0_4f48(0x30);
  }
  if (uv_alarm_code == -0x7e) {
    ui_frag_4f6e(0);
    ui_get_c18_tmp0_4f48(0x31);
  }
  if (device_sensor_fault == -0x71) {
    ui_frag_4f6e(0);
    ui_get_c18_tmp0_4f48(0x32);
  }
  if (device_sensor_fault == -0x73) {
    ui_frag_4f6e(0);
    ui_get_c18_tmp0_4f48(0x33);
  }
  if (dryer_sensor_fault == -0x71) {
    ui_frag_4f6e(0);
    ui_get_c18_tmp0_4f48(0x34);
  }
  if (dryer_sensor_fault == -0x73) {
    ui_frag_4f6e(0);
    ui_get_c18_tmp0_4f48(0x35);
  }
  bVar5 = 0xe;
  if (uv_alarm_code == -0x70) {
    ui_frag_4f6e(0);
    ui_get_c18_tmp0_4f48(0x36);
  }
  cVar18 = ui_get_cfg_systemconfig2_4e02();
  if (cVar18 == '\x05') {
    puVar3 = puVar2 + 1;
    pcVar1 = puVar2 + 0x15;
    puVar2 = puVar2 + 1;
    uVar19 = 0;
    if (*pcVar1 != '\0') {
      ui_get_c18_tmp0_4ed4(*pcVar1);
      ser_ptr_add_5022();
      *(undefined1 *)in_FSR0 = 0x20;
      *puVar11 = 5;
      puVar14 = puVar11 + 2;
      puVar11[1] = 0x17;
      word_lookup_a();
      c18_tmp0 = in_PRODL;
      *puVar14 = *puVar14;
      puVar14[-1] = puVar14[-1];
      c18_tmp2 = 0;
      c18_tmp1 = in_PRODH;
      puVar14[-2] = c18_tmp0;
      puVar14[-1] = in_PRODH;
      *puVar14 = c18_tmp2;
      c18_tmp5 = SUB21(puVar3,0);
      c18_tmp6 = (undefined1)((ushort)puVar3 >> 8);
      puVar2 = puVar3 + 1;
      bVar5 = 0;
      bVar6 = (byte)(puVar3 + 1) + puVar3[0x15];
      c18_tmp3 = bVar6 + 1;
      c18_tmp4 = (char)((ushort)(puVar3 + 1) >> 8) + CARRY1((byte)(puVar3 + 1),puVar3[0x15]) +
                 (0xfe < bVar6);
      puVar14[1] = c18_tmp3;
      puVar15 = puVar14 + 3;
      puVar14[2] = c18_tmp4;
      c18_tmp7 = strcpy_rom2ram();
      bVar6 = (byte)puVar15;
      if (bVar6 < 5) {
        puVar16 = (undefined1 *)((ushort)puVar15 & 0xff00);
        puVar15 = puVar16 + -1;
        *puVar16 = *puVar16;
      }
      puVar11 = (undefined1 *)CONCAT11((char)((ushort)puVar15 >> 8),bVar6 - 5);
      uVar19 = c18_tmp7;
    }
  }
  else {
    ui_get_c18_tmp0_4ed4();
    uVar19 = ser_ptr_add_5022();
    *(undefined1 *)in_FSR0 = 0;
  }
  cVar18 = ui_get_cfg_systemconfig2_4e02(uVar19);
  puVar4 = puVar2;
  if (cVar18 == '\x05') {
LAB_CODE_004aaa:
    if ((*(byte *)((ushort)bVar5 * 0x100 + 0x58) & 0x38) == 0x28) {
      if (puVar4[0x15] != '\0') goto LAB_CODE_004ac0;
    }
    c18_tmp0 = 0;
  }
  else {
    puVar4 = puVar2 + 1;
    if ((byte)puVar2[0x15] < 5) goto LAB_CODE_004aaa;
LAB_CODE_004ac0:
    ui_to_text_draw_char_4fa8(7);
    puVar17 = puVar11 + 1;
    *puVar11 = 0x12;
    ui_callw_fncfc6_4c62(7);
    ser_chain_fn4f80_fn5036_50b2();
    c18_tmp0 = 1;
    puVar11 = puVar17;
  }
  if ((byte)puVar11 < 0x15) {
    *(undefined1 *)((ushort)puVar11 & 0xff00) = *(undefined1 *)((ushort)puVar11 & 0xff00);
  }
  ui_c18_epilogue_4d6e(c18_tmp0);
  return;
}

