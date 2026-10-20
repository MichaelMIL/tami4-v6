// address 0x002058  size 2 bytes
// callers: (none: entry point, task, or reached via pointer)

/* Menu/screen handler (callback analysis) */

void menu_service_application_on_back(void)

{
  ui_set_menu_cb_enter_2c0a();
  menu_key_back();
  return;
}

