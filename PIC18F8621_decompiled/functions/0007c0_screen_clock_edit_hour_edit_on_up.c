// address 0x0007c0  size 8 bytes
// callers: (none: entry point, task, or reached via pointer)

/* Menu/screen handler (callback analysis) */

void screen_clock_edit_hour_edit_on_up(void)

{
  mod_set_clock_edit_ampm_a780();
  ui_to_ui_draw_time_23ea();
  return;
}

