// address 0x000d58  size 72 bytes
// callers: (none: entry point, task, or reached via pointer)

/* Menu/screen handler (callback analysis) */

void menu_hot_water_qty(void)

{
  if ((cfg_systemconfig5 & 0x10) != 0) {
    ui_to_param_read_max_2360(0x42);
    ui_chain_ui_set_menu_value__ui_get_menu_item_ui_to_ui_draw_set__(0x42);
    ui_to_ui_get_menu_value_hi_2952(0x42);
    if ((cfg_systemconfig5 & 4) == 0) {
      menu_value_lo = 0;
      menu_value_hi = 0;
    }
    screen_qty_bar();
    ui_to_ui_to_ui_draw_temp_units_1df4();
    menu_cb_enter = 0xa0;
    menu_cb_enter_hi = 0xd;
    menu_cb_up = 0xe8;
    menu_cb_up_hi = 0x1d;
    menu_cb_down = 0xee;
    menu_set_cbs_down_hi(0x1d);
    return;
  }
  return;
}

