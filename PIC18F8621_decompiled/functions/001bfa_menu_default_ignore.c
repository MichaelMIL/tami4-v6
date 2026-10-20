// address 0x001bfa  size 18 bytes
// callers: (none: entry point, task, or reached via pointer)

/* Menu/screen handler (callback analysis) */

void menu_default_ignore(void)

{
  menu_edit_mode = menu_edit_mode == '\0';
  screen_temp_sensor_values();
  return;
}

