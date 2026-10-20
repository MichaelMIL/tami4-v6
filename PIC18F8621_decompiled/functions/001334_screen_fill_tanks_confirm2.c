// address 0x001334  size 34 bytes
// callers: (none: entry point, task, or reached via pointer)

/* Menu/screen handler (callback analysis) */

void screen_fill_tanks_confirm2(void)

{
  if (menu_edit_mode != '\0') {
    ui_draw_flushing();
    ui_push_args_14_04_mod_to_ui_draw_progress_segment_265e();
    ui_set_menu_cb_timeout_2402();
    return;
  }
  ui_set_menu_timer_lo_251e(0);
  dispense_stop_all();
  ui_bank1_ui_set_menu_mode_1356();
  ui_to_ui_select_home_screen_4af0();
  return;
}

