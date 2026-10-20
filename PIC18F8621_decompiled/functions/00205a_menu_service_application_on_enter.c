// address 0x00205a  size 36 bytes
// callers: (none: entry point, task, or reached via pointer)

/* Menu/screen handler (callback analysis) */

void menu_service_application_on_enter(void)

{
  cfg_systemconfig5 = (menu_item & 3) << 5 | cfg_systemconfig5 & 0x9f;
  ui_to_param_write_215a(0x41);
  ui_to_menu_key_back_2670();
  return;
}

