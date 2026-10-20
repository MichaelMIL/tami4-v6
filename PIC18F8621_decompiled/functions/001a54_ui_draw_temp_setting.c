// address 0x001a54  size 142 bytes
// callers: (none: entry point, task, or reached via pointer)

/* WARNING: Restarted to delay deadcode elimination for space: DATA */
/* Draw temperature setting value (C or F) */

void ui_draw_temp_setting(void)

{
  BADSPACEBASE *in_FSR2;
  undefined1 *puVar1;
  BADSPACEBASE *in_FSR1;
  undefined1 uVar2;
  byte bVar3;
  char cVar4;
  byte unaff_Z;
  bool bVar5;
  
  ui_chain_fn2b16_fn28aa_ui_get_menu_item_2bea();
  if ((unaff_Z & 1) == 0) {
    uVar2 = 0;
  }
  else {
    uVar2 = 0x80;
  }
  ui_to_ui_get_menu_table_ptr_lo_29cc(uVar2);
  puVar1 = (undefined1 *)((short)in_FSR2 + 1);
  ui_get_TBLPTRL_29e8(*(undefined1 *)((short)in_FSR2 + -2));
  ui_stack_adjust_21f4();
  cVar4 = puVar1[-2];
  if (puVar1[-2] == '\0') {
    ui_callw_ui_to_eeprom_read_raw_228c(0x15);
    if ((cfg_systemconfig3 & 4) == 0) {
      ui_to___mul16x16_32_24ea(9);
      menu_value_lo = math_res0;
      menu_value_hi = math_res1;
      math_barg_lo = 5;
      math_barg_hi = 0;
      math_aarg_lo = math_res0;
      math_aarg_hi = math_res1;
      ui_to___divs16_289c();
      bVar5 = 0xdf < menu_value_lo;
      menu_value_lo = menu_value_lo + 0x20;
      menu_value_hi = menu_value_hi + bVar5;
      bVar5 = menu_value_hi == '\0';
    }
    else {
      bVar5 = true;
    }
    ui_get_cfg_systemconfig3_258a();
    if (bVar5) {
      uVar2 = 0x4b;
    }
    else {
      uVar2 = 0x4c;
    }
    ui_to_ui_word_ptr_2536(uVar2);
    ui_get_menu_value_lo_2ace();
    ui_get_menu_item_2554();
    if (bVar5) {
      bVar3 = 0x80;
    }
    else {
      bVar3 = 0;
    }
    c18_tmp2 = ui_stack_adjust_2644(bVar3 | 4);
    cVar4 = c18_tmp2;
    if ((byte)in_FSR1 < 8) {
      *(undefined1 *)((ushort)in_FSR1 & 0xff00) = *(undefined1 *)((ushort)in_FSR1 & 0xff00);
      cVar4 = c18_tmp2;
    }
  }
  ui_c18_epilogue_21d8(cVar4);
  return;
}

