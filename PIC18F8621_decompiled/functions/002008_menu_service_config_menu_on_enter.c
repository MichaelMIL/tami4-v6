// address 0x002008  size 24 bytes
// callers: (none: entry point, task, or reached via pointer)

/* Menu/screen handler (callback analysis) */

void menu_service_config_menu_on_enter(void)

{
  cfg_systemconfig5 = cfg_systemconfig5 & 0xef;
  if (menu_edit_mode != '\0') {
    cfg_systemconfig5 = cfg_systemconfig5 | 0x10;
  }
  ui_get_cfg_systemconfig5_2c02();
  return;
}

