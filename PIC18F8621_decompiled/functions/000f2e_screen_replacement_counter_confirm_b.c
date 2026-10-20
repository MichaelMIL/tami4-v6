// address 0x000f2e  size 20 bytes
// callers: (none: entry point, task, or reached via pointer)

/* Menu/screen handler (callback analysis) */

void screen_replacement_counter_confirm_b(void)

{
  if (menu_edit_mode != '\0') {
    ui_set_stat_GFI_247a(menu_edit_mode);
  }
  menu_edit_mode = 1;
  ui_to_screen_replacement_counter_246a();
  return;
}

