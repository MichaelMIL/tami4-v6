// address 0x000ccc  size 34 bytes
// callers: (none: entry point, task, or reached via pointer)

/* Menu/screen handler (callback analysis) */

void menu_cold_water_qty(void)

{
  if ((cfg_systemconfig5 & 0x10) == 0) {
    return;
  }
  ui_to_param_read_max_2360(0x3e);
  ui_chain_ui_set_menu_value__ui_get_menu_item_ui_to_ui_draw_set__(0x3e);
  ui_to_screen_mix_temp_bar_2bce(0x3e);
  menu_cb_enter = 0xee;
  menu_set_cbs_enter_hi_d(0xc);
  return;
}

