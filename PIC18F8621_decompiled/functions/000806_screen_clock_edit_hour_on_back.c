// address 0x000806  size 14 bytes
// callers: (none: entry point, task, or reached via pointer)

/* Menu/screen handler (callback analysis) */

void screen_clock_edit_hour_on_back(void)

{
  ui_set_menu_value_lo_26a6();
  ui_to_ui_draw_time_23ea();
  ui_to_menu_set_cbs_down_hi_2882();
  return;
}

