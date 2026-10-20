// address 0x0007a8  size 8 bytes
// callers: (none: entry point, task, or reached via pointer)

/* Menu/screen handler (callback analysis) */

void screen_clock_edit_hour_on_up(void)

{
  mod_set_clock_edit_minute_a760();
  ui_to_ui_draw_time_23ea();
  return;
}

