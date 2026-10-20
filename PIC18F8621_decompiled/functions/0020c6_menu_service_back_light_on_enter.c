// address 0x0020c6  size 24 bytes
// callers: (none: entry point, task, or reached via pointer)

/* Menu/screen handler (callback analysis) */

void menu_service_back_light_on_enter(void)

{
  cfg_systemconfig5 = cfg_systemconfig5 & 0x7f;
  if (menu_edit_mode != '\0') {
    cfg_systemconfig5 = cfg_systemconfig5 | 0x80;
  }
  ui_get_cfg_systemconfig5_2c02();
  return;
}

