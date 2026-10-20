// address 0x000df2  size 18 bytes
// callers: (none: entry point, task, or reached via pointer)

/* Menu/screen handler (callback analysis) */

void menu_replacement_on_up(void)

{
  menu_edit_mode = menu_edit_mode == '\0';
  menu_replacement_on_up_b();
  return;
}

