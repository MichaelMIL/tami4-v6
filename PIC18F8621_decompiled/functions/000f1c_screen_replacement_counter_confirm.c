// address 0x000f1c  size 18 bytes
// callers: (none: entry point, task, or reached via pointer)

/* Menu/screen handler (callback analysis) */

void screen_replacement_counter_confirm(void)

{
  if (menu_edit_mode != '\0') {
    ui_set_stat_GUV_22fa(menu_edit_mode);
  }
  menu_edit_mode = 0;
  ui_to_screen_replacement_counter_246a();
  return;
}

