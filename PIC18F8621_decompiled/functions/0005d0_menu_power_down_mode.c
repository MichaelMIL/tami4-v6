// address 0x0005d0  size 54 bytes
// callers: (none: entry point, task, or reached via pointer)

/* Menu/screen handler (callback analysis) */

void menu_power_down_mode(void)

{
  if ((cfg_systemconfig5 & 0x10) == 0) {
    return;
  }
  ui_callw_fn0450_2b5e(10);
  ui_callw_ui_to_eeprom_read_raw_228c(0x31);
  ui_get_menu_value_lo_22aa(0x18);
  screen_power_down_draw();
  menu_cb_enter = 0x96;
  menu_cb_enter_hi = 5;
  menu_cb_up = 0xa6;
  menu_cb_up_hi = 5;
  menu_cb_down = 0xbc;
  menu_set_cbs_down_hi(5);
  return;
}

