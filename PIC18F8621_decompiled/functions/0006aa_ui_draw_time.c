// address 0x0006aa  size 222 bytes
// callers: 0023ea,0023a6,00249e,

/* Draw time "%02b:%02b AM/PM" for clock/wake-up editing */

void ui_draw_time(void)

{
  BADSPACEBASE *in_FSR2;
  BADSPACEBASE *in_FSR1;
  undefined1 *puVar1;
  undefined1 *puVar2;
  undefined1 *puVar3;
  undefined1 *puVar4;
  undefined1 *puVar5;
  undefined1 uVar6;
  char cVar7;
  bool bVar8;
  
  ui_c18_prologue_2166();
  ui_set_text_row_2b08();
  if ((menu_value_lo == '\x02') && (menu_value_hi == '\0')) {
    uVar6 = 0xd;
  }
  else {
    uVar6 = 0;
  }
  puVar1 = (undefined1 *)((short)in_FSR1 + 1);
  *(undefined1 *)in_FSR1 = uVar6;
  cVar7 = mod_get_clock_edit_ampm_a774();
  if (cVar7 == '\0') {
    c18_tmp0 = 0xc4;
  }
  else {
    cVar7 = mod_get_clock_edit_ampm_a774();
    if (cVar7 == '\x01') {
      c18_tmp0 = 0xc1;
    }
    else if (*(char *)((short)in_FSR2 + -2) == '\0') {
      c18_tmp0 = 0xbb;
    }
    else {
      c18_tmp0 = 0xbe;
    }
  }
  c18_tmp1 = 0x58;
  *puVar1 = c18_tmp0;
  puVar1[1] = 0x58;
  if ((menu_value_lo == '\x02') && (menu_value_hi == '\0')) {
    uVar6 = 0xd;
  }
  else {
    uVar6 = 0;
  }
  puVar1[2] = uVar6;
  if ((menu_value_lo == '\x01') && (menu_value_hi == '\0')) {
    uVar6 = 0xd;
  }
  else {
    uVar6 = 0;
  }
  puVar2 = puVar1 + 4;
  puVar1[3] = uVar6;
  uVar6 = mod_get_clock_edit_minute_a74a();
  *puVar2 = uVar6;
  if ((menu_value_lo == '\x01') && (menu_value_hi == '\0')) {
    uVar6 = 0xd;
  }
  else {
    uVar6 = 0;
  }
  puVar2[1] = uVar6;
  bVar8 = menu_value_hi != '\0' || menu_value_lo != '\0';
  if (bVar8) {
    uVar6 = 0;
  }
  else {
    uVar6 = 0xd;
  }
  puVar3 = puVar2 + 3;
  puVar2[2] = uVar6;
  uVar6 = clock_edit_hour12();
  puVar4 = puVar3 + 1;
  *puVar3 = uVar6;
  ui_get_menu_value_lo_2778();
  if (bVar8) {
    uVar6 = 0;
  }
  else {
    uVar6 = 0xd;
  }
  *puVar4 = uVar6;
  puVar4[1] = 4;
  puVar4[2] = 0;
  puVar5 = puVar4 + 4;
  puVar4[3] = 199;
  c18_tmp2 = ui_callw_txt_set_ui_hold_counter_2b10(0x58);
  if ((byte)puVar5 < 0xe) {
    *(undefined1 *)((ushort)puVar5 & 0xff00) = *(undefined1 *)((ushort)puVar5 & 0xff00);
  }
  ui_c18_epilogue_21d8(c18_tmp2);
  return;
}

