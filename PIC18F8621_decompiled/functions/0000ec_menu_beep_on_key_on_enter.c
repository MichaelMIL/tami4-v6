// address 0x0000ec  size 10 bytes
// callers: (none: entry point, task, or reached via pointer)

/* WARNING: Restarted to delay deadcode elimination for space: DATA */
/* Menu/screen handler (callback analysis) */

void menu_beep_on_key_on_enter(void)

{
  cfg_systemconfig = cfg_systemconfig & 0x7f;
  if (menu_edit_mode != '\0') {
    cfg_systemconfig = cfg_systemconfig | 0x80;
  }
  ui_to_menu_default_back_279e(0x25);
  return;
}

