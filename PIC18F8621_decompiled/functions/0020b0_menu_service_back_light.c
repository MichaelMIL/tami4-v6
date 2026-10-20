// address 0x0020b0  size 22 bytes
// callers: (none: entry point, task, or reached via pointer)

/* Menu/screen handler (callback analysis) */

void menu_service_back_light(void)

{
  ui_to_ui_draw_title_20de();
  ui_set_menu_edit_mode_2386((cfg_systemconfig5 & 0x80) != 0);
  menu_cb_enter = 0xc6;
  menu_set_cbs_back_default(0x20);
  return;
}

