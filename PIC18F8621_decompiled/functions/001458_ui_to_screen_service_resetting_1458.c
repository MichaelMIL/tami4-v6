// address 0x001458  size 52 bytes
// callers: (none: entry point, task, or reached via pointer)

/* WARNING: Restarted to delay deadcode elimination for space: DATA */
/* Auto: writes cfg_systemconfig4; reads cfg_systemconfig4,menu_edit_mode; calls
   screen_service_resetting,menu_default_back; 22 instr */

void ui_to_screen_service_resetting_1458(void)

{
  char cVar1;
  
  cVar1 = menu_edit_mode - ((cfg_systemconfig4 & 0x40) != 0);
  if (cVar1 == '\0') {
    cfg_systemconfig4 = cfg_systemconfig4 & 0xbf;
    if (menu_edit_mode == '\0') {
      cfg_systemconfig4 = cfg_systemconfig4 | 0x40;
    }
    ui_to_param_write_215a(0x3a);
    screen_service_resetting();
    return;
  }
  menu_default_back(cVar1);
  return;
}

