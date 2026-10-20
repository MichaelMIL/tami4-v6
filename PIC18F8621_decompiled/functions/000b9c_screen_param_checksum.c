// address 0x000b9c  size 150 bytes
// callers: (none: entry point, task, or reached via pointer)

/* WARNING: Removing unreachable block (CODE,0x000c06) */
/* Compute and show "PARAMETERS CS" (sum of 75 EEPROM parameters) */

void screen_param_checksum(void)

{
  byte bVar1;
  BADSPACEBASE *in_FSR2;
  byte *pbVar2;
  BADSPACEBASE *in_FSR1;
  undefined1 *puVar3;
  byte *pbVar4;
  byte *pbVar5;
  undefined1 uVar7;
  undefined1 *puVar6;
  undefined1 uVar8;
  
  ui_stack_adjust_2af8();
  puVar3 = (undefined1 *)((short)in_FSR1 + 1);
  puVar6 = (undefined1 *)((short)in_FSR1 + 1);
  *(undefined1 *)in_FSR1 = *(undefined1 *)in_FSR1;
  pbVar2 = (byte *)((short)in_FSR2 + 1);
  *(undefined1 *)((short)in_FSR2 + 2) = 0;
  if ((cfg_systemconfig5 & 0x10) != 0) {
    ui_callw_fn0450_2b5e(0x89);
    *pbVar2 = 0;
    pbVar4 = puVar3;
    for (; bVar1 = *pbVar2, bVar1 < 0x4b; pbVar2 = pbVar2 + 2) {
      pbVar5 = pbVar4 + 1;
      *pbVar4 = *pbVar2;
      c18_tmp0 = ui_to_eeprom_read_raw_2b00(bVar1 + 0xb5);
      *pbVar5 = pbVar2[2];
      *pbVar5 = *pbVar5 + c18_tmp0;
      pbVar2[3] = *pbVar5;
      pbVar2[2] = pbVar2[2] + '\x01';
      pbVar4 = pbVar5;
    }
    text_row = 4;
    text_x = 0x1e;
    text_fill_width = 0x23;
    *pbVar4 = pbVar2[2];
    pbVar4[1] = 6;
    pbVar4[2] = 0;
    uVar7 = (undefined1)((ushort)(pbVar4 + 4) >> 8);
    pbVar4[3] = 0xb3;
    ui_callw_txt_set_ui_hold_counter_2b10(0x58);
    uVar8 = ui_compare_multibyte_2b1e();
    puVar6 = (undefined1 *)CONCAT11(uVar7,uVar8);
    menu_cb_enter = 0xf2;
    menu_cb_enter_hi = 0x1b;
    menu_cb_up = 0xf2;
    menu_cb_up_hi = 0x1b;
    menu_cb_down = 0xf2;
    menu_set_cbs_down_hi(0x1b);
  }
  *puVar6 = *puVar6;
  puVar6[-1] = puVar6[-1];
  ui_c18_epilogue_21d8();
  return;
}

