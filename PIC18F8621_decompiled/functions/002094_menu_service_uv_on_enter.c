// address 0x002094  size 28 bytes
// callers: (none: entry point, task, or reached via pointer)

/* WARNING: Restarted to delay deadcode elimination for space: DATA */
/* Menu/screen handler (callback analysis) */

void menu_service_uv_on_enter(void)

{
  cfg_systemconfig = cfg_systemconfig & 0xf7;
  if (menu_edit_mode != '\0') {
    cfg_systemconfig = cfg_systemconfig | 8;
  }
  ui_to_menu_default_back_279e(0x25);
  return;
}

