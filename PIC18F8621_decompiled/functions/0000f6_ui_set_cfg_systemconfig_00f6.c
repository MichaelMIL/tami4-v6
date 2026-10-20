// address 0x0000f6  size 20 bytes
// callers: (none: entry point, task, or reached via pointer)

/* WARNING: Removing unreachable block (CODE,0x0000fe) */
/* WARNING: Restarted to delay deadcode elimination for space: DATA */
/* Auto: writes cfg_systemconfig; reads cfg_systemconfig; 8 instr */

void ui_set_cfg_systemconfig_00f6(void)

{
  cfg_systemconfig = cfg_systemconfig & 0x7f;
  ui_to_menu_default_back_279e(0x25);
  return;
}

