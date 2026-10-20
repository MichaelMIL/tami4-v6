// address 0x000b2c  size 102 bytes
// callers: (none: entry point, task, or reached via pointer)

/* Menu/screen handler (callback analysis) */

void menu_mix_water_temp(void)

{
  BADSPACEBASE *in_FSR1;
  undefined1 *puVar1;
  undefined1 uVar4;
  undefined1 *puVar2;
  undefined1 *puVar3;
  byte bVar5;
  undefined1 uVar6;
  byte unaff_C;
  
  if ((cfg_systemconfig5 & 0x10) == 0) {
    return;
  }
  ui_to_param_read_max_2360(0x33);
  ui_set_menu_value_step_lo_2344(0x33);
  ui_get_menu_value_max_lo_2574();
  puVar1 = (undefined1 *)((short)in_FSR1 + 1);
  *(undefined1 *)in_FSR1 = 0x50;
  uVar6 = ui_to_ui_draw_temp_value_2356(2);
  uVar4 = (undefined1)((ushort)puVar1 >> 8);
  if ((unaff_C & 1) == 0) {
    puVar2 = (undefined1 *)((ushort)puVar1 & 0xff00);
    uVar4 = (undefined1)((ushort)(puVar2 + -1) >> 8);
    *puVar2 = *puVar2;
  }
  puVar3 = (undefined1 *)CONCAT11(uVar4,uVar6);
  ui_get_menu_value_step_lo_2568(c18_tmp0);
  bVar5 = (byte)((ushort)(puVar3 + 1) >> 8);
  *puVar3 = 0x50;
  ui_to_ui_draw_temp_value_2356(6);
  if ((unaff_C & 1) == 0) {
    *(undefined1 *)((ushort)bVar5 << 8) = *(undefined1 *)((ushort)bVar5 << 8);
  }
  ui_callw_ui_to_eeprom_read_raw_228c(0x33);
  ui_to_screen_cold_temp_bar_2684();
  menu_cb_enter = 0x92;
  menu_cb_enter_hi = 0xb;
  menu_cb_up = 0x32;
  menu_cb_up_hi = 0x1c;
  menu_cb_down = 0x74;
  menu_set_cbs_down_hi(0x1c);
  return;
}

