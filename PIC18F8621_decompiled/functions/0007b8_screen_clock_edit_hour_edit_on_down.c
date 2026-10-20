// address 0x0007b8  size 8 bytes
// callers: (none: entry point, task, or reached via pointer)

/* Menu/screen handler (callback analysis) */

void screen_clock_edit_hour_edit_on_down(void)

{
  mod_set_clock_edit_ampm_a78e();
  ui_to_ui_draw_time_23ea();
  return;
}

