// address 0x0008c4  size 32 bytes
// callers: (none: entry point, task, or reached via pointer)

/* Menu/screen handler (callback analysis) */

void menu_wakeup_1(void)

{
  byte bVar1;
  
  if ((cfg_systemconfig5 & 0x10) == 0) {
    return;
  }
  bVar1 = ui_to_ui_draw_on_off_22ea(0x36);
  ui_set_menu_edit_mode_2386((bVar1 & 0x10) != 0);
  menu_cb_enter = 0x9a;
  menu_set_cbs_back_default(8);
  return;
}

