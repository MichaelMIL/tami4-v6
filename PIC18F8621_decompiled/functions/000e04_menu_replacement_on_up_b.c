// address 0x000e04  size 280 bytes
// callers: 002a38,000df2,

/* Menu/screen handler (callback analysis) */

byte menu_replacement_on_up_b(void)

{
  bool bVar1;
  bool bVar2;
  BADSPACEBASE *in_FSR1;
  undefined1 *puVar3;
  undefined1 *puVar4;
  undefined1 *puVar5;
  undefined1 *puVar6;
  undefined1 uVar7;
  undefined1 uVar8;
  byte bVar9;
  bool bVar10;
  
  ui_callw_fn0450_2b5e(0x1e);
  text_row = 2;
  *(undefined1 *)in_FSR1 = 6;
  puVar3 = (undefined1 *)((short)in_FSR1 + 2);
  *(undefined1 *)((short)in_FSR1 + 1) = 0;
  ui_stack_adjust_21f4(0x74);
  ui_set_ui_wake_pending_244a(4);
  if (menu_edit_mode == '\0') {
    uVar7 = 0;
  }
  else {
    uVar7 = 0x80;
  }
  ui_to_ui_get_c18_tmp0_22cc(uVar7);
  ui_stack_adjust_21f4(0x4d);
  text_row = 4;
  ui_get_TBLPTRH_2606(0xfc);
  if ((c18_tmp5 & 0x80) != 0) {
    c18_tmp6 = 0xff;
    c18_tmp7 = 0xff;
  }
  c18_tmp0 = c18_tmp4 - stat_GFI;
  bVar9 = ~(stat_GFI <= c18_tmp4);
  bVar10 = c18_tmp5 < bVar9 || bDATA00eb < c18_tmp5 - bVar9;
  c18_tmp1 = (c18_tmp5 - bDATA00eb) - ~(stat_GFI <= c18_tmp4);
  bVar9 = ~bVar10;
  bVar1 = bVar9 <= c18_tmp6;
  bVar2 = c18_tmp6 - bVar9 <= bDATA00ec;
  c18_tmp2 = (c18_tmp6 - bDATA00ec) - ~bVar10;
  bVar10 = cDATA00ed == '\0';
  ui_get_menu_edit_mode_2652(cDATA00ed);
  if (bVar10) {
    uVar7 = 0;
  }
  else {
    uVar7 = 0x80;
  }
  uVar8 = ui_to_txt_set_ui_hold_counter_2594(uVar7);
  uVar7 = (undefined1)((ushort)puVar3 >> 8);
  if (bVar1 && bVar2) {
    puVar4 = (undefined1 *)((ushort)puVar3 & 0xff00);
    uVar7 = (undefined1)((ushort)(puVar4 + -1) >> 8);
    *puVar4 = *puVar4;
  }
  puVar5 = (undefined1 *)CONCAT11(uVar7,uVar8);
  if ((cfg_systemconfig & 8) != 0) {
    ui_set_ui_wake_pending_244a(5);
    if (menu_edit_mode == '\0') {
      uVar7 = 0x80;
    }
    else {
      uVar7 = 0;
    }
    ui_to_ui_get_c18_tmp0_22cc(uVar7);
    ui_stack_adjust_21f4(0x4e);
    text_row = 5;
    ui_get_TBLPTRH_2606(0xfc);
    if ((c18_tmp5 & 0x80) != 0) {
      c18_tmp6 = 0xff;
      c18_tmp7 = 0xff;
    }
    c18_tmp0 = c18_tmp4 - stat_GUV;
    bVar9 = ~(stat_GUV <= c18_tmp4);
    bVar10 = c18_tmp5 < bVar9 || bDATA00e7 < c18_tmp5 - bVar9;
    c18_tmp1 = (c18_tmp5 - bDATA00e7) - ~(stat_GUV <= c18_tmp4);
    bVar9 = ~bVar10;
    bVar1 = bVar9 <= c18_tmp6;
    bVar2 = c18_tmp6 - bVar9 <= bDATA00e8;
    c18_tmp2 = (c18_tmp6 - bDATA00e8) - ~bVar10;
    bVar10 = cDATA00e9 == '\0';
    ui_get_menu_edit_mode_2652(cDATA00e9);
    if (bVar10) {
      uVar7 = 0x80;
    }
    else {
      uVar7 = 0;
    }
    uVar8 = ui_to_txt_set_ui_hold_counter_2594(uVar7);
    uVar7 = (undefined1)((ushort)puVar5 >> 8);
    if (bVar1 && bVar2) {
      puVar6 = (undefined1 *)((ushort)puVar5 & 0xff00);
      uVar7 = (undefined1)((ushort)(puVar6 + -1) >> 8);
      *puVar6 = *puVar6;
    }
    puVar5 = (undefined1 *)CONCAT11(uVar7,uVar8);
  }
  if (((menu_edit_mode != '\0') && ((cfg_systemconfig4 & 4) == 0)) ||
     ((bVar9 = 0, menu_edit_mode != '\0' && (bVar9 = cfg_systemconfig4 & 0x20, bVar9 == 0)))) {
    text_row = 6;
    *puVar5 = 6;
    puVar5[1] = 0;
    bVar9 = ui_stack_adjust_21f4(0x67);
  }
  return bVar9;
}

