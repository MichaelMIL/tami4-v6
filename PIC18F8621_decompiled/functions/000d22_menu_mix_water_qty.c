// address 0x000d22  size 44 bytes
// callers: (none: entry point, task, or reached via pointer)

/* Menu/screen handler (callback analysis) */

void menu_mix_water_qty(void)

{
  if ((cfg_systemconfig5 & 0x10) == 0) {
    return;
  }
  ui_to_param_read_max_2360(0x35);
  ui_chain_ui_set_menu_value__ui_get_menu_item_ui_to_ui_draw_set__(0x35);
  ui_to_ui_get_menu_value_hi_2952(0x35);
  screen_qty_bar();
  ui_to_ui_to_ui_draw_temp_units_1df4();
  menu_cb_enter = 0x4e;
  menu_set_cbs_enter_hi_d(0xd);
  return;
}

