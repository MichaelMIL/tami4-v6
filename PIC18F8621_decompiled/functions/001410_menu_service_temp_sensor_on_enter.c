// address 0x001410  size 40 bytes
// callers: (none: entry point, task, or reached via pointer)

/* WARNING: Restarted to delay deadcode elimination for space: DATA */
/* Menu/screen handler (callback analysis) */

void menu_service_temp_sensor_on_enter(void)

{
  if (menu_edit_mode != (cfg_systemconfig3 & 1)) {
    cfg_systemconfig3 = cfg_systemconfig3 & 0xfe;
    if ((menu_edit_mode & 1) != 0) {
      cfg_systemconfig3 = cfg_systemconfig3 | 1;
    }
    ui_to_param_write_215a(0x2c);
    screen_service_resetting();
    return;
  }
  menu_default_back(0);
  return;
}

