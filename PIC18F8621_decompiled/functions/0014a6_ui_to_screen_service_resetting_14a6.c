// address 0x0014a6  size 40 bytes
// callers: (none: entry point, task, or reached via pointer)

/* WARNING: Restarted to delay deadcode elimination for space: DATA */
/* Auto: writes cfg_systemconfig5; reads cfg_systemconfig5,menu_edit_mode; calls
   screen_service_resetting,menu_default_back; 16 instr */

void ui_to_screen_service_resetting_14a6(void)

{
  if (menu_edit_mode != (cfg_systemconfig5 & 1)) {
    cfg_systemconfig5 = cfg_systemconfig5 & 0xfe;
    if ((menu_edit_mode & 1) != 0) {
      cfg_systemconfig5 = cfg_systemconfig5 | 1;
    }
    ui_to_param_write_215a(0x41);
    screen_service_resetting();
    return;
  }
  menu_default_back(0);
  return;
}

