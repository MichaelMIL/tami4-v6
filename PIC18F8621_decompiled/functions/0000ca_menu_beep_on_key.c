// address 0x0000ca  size 34 bytes
// callers: (none: entry point, task, or reached via pointer)

/* Menu/screen handler (callback analysis) */

void menu_beep_on_key(void)

{
  if ((cfg_systemconfig5 & 0x10) == 0) {
    return;
  }
  ui_to_ui_draw_title_20de();
  ui_set_menu_edit_mode_2386((cfg_systemconfig & 0x80) != 0);
  menu_cb_enter = 0xec;
  menu_set_cbs_back_default(0);
  return;
}

