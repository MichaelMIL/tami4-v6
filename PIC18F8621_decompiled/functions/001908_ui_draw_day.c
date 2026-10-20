// address 0x001908  size 108 bytes
// callers: (none: entry point, task, or reached via pointer)

/* WARNING: Removing unreachable block (CODE,0x001960) */
/* Draw day of week */

void ui_draw_day(void)

{
  BADSPACEBASE *in_FSR2;
  undefined1 *puVar1;
  BADSPACEBASE *in_FSR1;
  undefined1 *puVar2;
  undefined1 *puVar3;
  undefined1 uVar4;
  byte unaff_Z;
  
  ui_chain_fn2b16_fn28aa_ui_get_menu_item_2bea();
  if ((unaff_Z & 1) == 0) {
    uVar4 = 0;
  }
  else {
    uVar4 = 0x80;
  }
  ui_to_ui_get_c18_tmp0_22cc(uVar4);
  puVar1 = (undefined1 *)((short)in_FSR2 + 1);
  if (*(char *)((short)in_FSR2 + -2) == '\0') {
    uVar4 = 0x39;
  }
  else {
    uVar4 = 0x38;
  }
  ui_stack_adjust_21f4(uVar4);
  ui_to_ui_set_ui_wake_pending_28aa(0xfd);
  if (puVar1[-2] == '\0') {
    *(undefined1 *)in_FSR1 = 0x9d;
    puVar2 = (undefined1 *)((short)in_FSR1 + 2);
    *(undefined1 *)((short)in_FSR1 + 1) = 1;
    mod_get_clock_pm_a7ee();
    *puVar2 = *puVar2;
    puVar3 = puVar2 + -2;
    puVar2[-1] = puVar2[-1];
    ui_frame_push_args_25cc();
    ui_draw_clock_text();
  }
  else {
    menu_day_edit = clock_get_day(puVar1[-2]);
    menu_day_edit_hi = 0;
    ui_get_menu_item_2554();
    ui_stack_adjust_2b26(0x80);
    puVar3 = (undefined1 *)((short)in_FSR1 + 1);
    *(undefined1 *)in_FSR1 = menu_day_edit;
    ui_to_txt_set_ui_hold_counter_28b4();
  }
  *puVar3 = *puVar3;
  ui_c18_epilogue_21d8();
  return;
}

