// address 0x00011e  size 28 bytes
// callers: (none: entry point, task, or reached via pointer)

/* Menu/screen handler (callback analysis) */

void menu_child_lock(void)

{
  if ((cfg_systemconfig5 & 0x10) == 0) {
    return;
  }
  ui_to_ui_draw_title_20de();
  child_protect_is_active();
  ui_set_menu_edit_mode_2386();
  menu_cb_enter = 10;
  menu_set_cbs_back_default(1);
  return;
}

