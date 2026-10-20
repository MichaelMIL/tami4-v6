// address 0x000a90  size 136 bytes
// callers: (none: entry point, task, or reached via pointer)

/* Menu/screen handler (callback analysis) */

void menu_cold_water_temp(void)

{
  bool bVar1;
  BADSPACEBASE *in_FSR1;
  undefined1 *puVar2;
  undefined1 uVar9;
  undefined1 *puVar3;
  undefined1 *puVar4;
  undefined1 *puVar5;
  undefined1 *puVar6;
  undefined1 *puVar7;
  undefined1 *puVar8;
  char cVar10;
  undefined1 uVar11;
  
  if ((cfg_systemconfig5 & 0x10) == 0) {
    return;
  }
  ui_to_param_read_max_2360(3);
  ui_set_menu_value_step_lo_2344(3);
  cVar10 = '\x05';
  if ((menu_value_step_hi & 0x80) == 0) {
    bVar1 = menu_value_step_hi != ~(4 < menu_value_step_lo);
    cVar10 = menu_value_step_hi - ~(4 < menu_value_step_lo);
  }
  else {
    bVar1 = false;
  }
  if (!bVar1) {
    cVar10 = '\x05';
    menu_value_step_lo = 5;
    menu_value_step_hi = 0;
  }
  ui_get_menu_value_step_lo_2568(cVar10);
  puVar2 = (undefined1 *)((short)in_FSR1 + 1);
  *(undefined1 *)in_FSR1 = 0x50;
  uVar11 = ui_to_ui_draw_temp_value_2356(2);
  uVar9 = (undefined1)((ushort)puVar2 >> 8);
  if (!bVar1) {
    puVar3 = (undefined1 *)((ushort)puVar2 & 0xff00);
    uVar9 = (undefined1)((ushort)(puVar3 + -1) >> 8);
    *puVar3 = *puVar3;
  }
  puVar4 = (undefined1 *)CONCAT11(uVar9,uVar11);
  ui_get_menu_value_max_lo_2574(c18_tmp0);
  puVar5 = puVar4 + 1;
  *puVar4 = 0x50;
  uVar11 = ui_to_ui_draw_temp_value_2356(6);
  uVar9 = (undefined1)((ushort)puVar5 >> 8);
  if (!bVar1) {
    puVar6 = (undefined1 *)((ushort)puVar5 & 0xff00);
    uVar9 = (undefined1)((ushort)(puVar6 + -1) >> 8);
    *puVar6 = *puVar6;
  }
  puVar7 = (undefined1 *)CONCAT11(uVar9,uVar11);
  ui_callw_ui_to_eeprom_read_raw_228c(3);
  puVar8 = puVar7 + 1;
  *puVar7 = 1;
  screen_cold_temp_bar();
  *puVar8 = *puVar8;
  menu_cb_enter = 0x18;
  menu_cb_enter_hi = 0xb;
  menu_cb_up = 0x9e;
  menu_cb_up_hi = 0x1d;
  menu_cb_down = 0x5e;
  menu_set_cbs_down_hi(0x1d);
  return;
}

