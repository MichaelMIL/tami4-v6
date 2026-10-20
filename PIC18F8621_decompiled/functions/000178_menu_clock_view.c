// address 0x000178  size 34 bytes
// callers: (none: entry point, task, or reached via pointer)

/* Menu/screen handler (callback analysis) */

void menu_clock_view(void)

{
  if ((cfg_systemconfig5 & 0x10) == 0) {
    return;
  }
  ui_to_ui_draw_title_20de();
  ui_set_menu_edit_mode_2386((cfg_systemconfig3 & 0x80) != 0);
  menu_cb_enter = 0x6a;
  menu_set_cbs_back_default(1);
  return;
}

