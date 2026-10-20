// address 0x0007fe  size 8 bytes
// callers: (none: entry point, task, or reached via pointer)

/* Menu/screen handler (callback analysis) */

void menu_clock_time_on_enter(void)

{
  mod_get_clock_edit_hour_a6f8();
  screen_clock_edit_hour();
  return;
}

