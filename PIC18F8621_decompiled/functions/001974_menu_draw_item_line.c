// address 0x001974  size 140 bytes
// callers: 00270e,

/* Draw one menu line (highlighted when selected) */

void menu_draw_item_line(void)

{
  BADSPACEBASE *in_FSR2;
  undefined1 *puVar1;
  undefined1 *puVar2;
  undefined1 *puVar3;
  BADSPACEBASE *in_FSR1;
  undefined1 *puVar4;
  undefined1 *puVar5;
  undefined1 *puVar6;
  undefined1 *puVar7;
  undefined1 *puVar8;
  undefined1 uVar9;
  
  ui_c18_prologue_2166();
  ui_to_ui_set_ui_wake_pending_28aa(0xfc);
  puVar1 = (undefined1 *)((short)in_FSR2 + 1);
  if (menu_item == *(char *)((short)in_FSR2 + -3)) {
    uVar9 = 0x80;
  }
  else {
    uVar9 = 0;
  }
  ui_to_ui_get_c18_tmp0_22cc(uVar9);
  ui_frame_push_args_25cc();
  ui_to_txt_set_ui_hold_counter_28b4();
  puVar4 = (undefined1 *)((short)in_FSR1 + -1);
  *(undefined1 *)in_FSR1 = *(undefined1 *)in_FSR1;
  ui_to_ui_set_ui_wake_pending_28aa(0xfc);
  if (puVar1[-6] == '\0') {
    if (menu_item == puVar1[-2]) {
      uVar9 = 0x80;
    }
    else {
      uVar9 = 0;
    }
    ui_stack_adjust_2b26(uVar9);
    puVar5 = puVar4 + 1;
    *puVar4 = 0x45;
    ui_to_txt_set_ui_hold_counter_28b4();
  }
  else {
    puVar6 = puVar4 + 1;
    puVar2 = puVar1 + 2;
    *puVar4 = puVar1[-3];
    menu_tmp_a = ui_to_eeprom_read_raw_2b00();
    puVar7 = puVar6 + 1;
    puVar3 = puVar2 + 1;
    *puVar6 = puVar2[-5];
    menu_tmp_a_hi = ui_to_eeprom_read_raw_2b00();
    *puVar7 = 0x9d;
    puVar8 = puVar7 + 2;
    puVar7[1] = 1;
    clock_edit_compute_ampm();
    *puVar8 = *puVar8;
    puVar8[-1] = puVar8[-1];
    puVar5 = puVar8 + -1;
    puVar8[-2] = puVar3[-3];
    ui_draw_clock_text();
  }
  *puVar5 = *puVar5;
  ui_c18_epilogue_21d8();
  return;
}

