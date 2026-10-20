// address 0x0007cc  size 50 bytes
// callers: (none: entry point, task, or reached via pointer)

/* Clock set: edit minutes */

undefined1 screen_clock_edit_minute(void)

{
  mod_get_clock_edit_minute_a76e();
  ui_set_menu_value_lo_2bae(2);
  ui_to_ui_draw_time_23ea();
  menu_cb_up = 0xc0;
  menu_cb_up_hi = 7;
  menu_cb_down = 0xb8;
  menu_cb_down_hi = 7;
  menu_cb_back = 200;
  menu_cb_back_hi = 7;
  menu_cb_enter = 0xb0;
  menu_cb_enter_hi = 7;
  return 7;
}

