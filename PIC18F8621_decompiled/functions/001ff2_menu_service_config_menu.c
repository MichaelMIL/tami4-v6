// address 0x001ff2  size 22 bytes
// callers: (none: entry point, task, or reached via pointer)

/* Menu/screen handler (callback analysis) */

void menu_service_config_menu(void)

{
  ui_to_ui_draw_title_20de();
  ui_set_menu_edit_mode_2386((cfg_systemconfig5 & 0x10) != 0);
  menu_cb_enter = 8;
  menu_set_cbs_back_default(0x20);
  return;
}

