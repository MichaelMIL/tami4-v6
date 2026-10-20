// address 0x000944  size 6 bytes
// callers: (none: entry point, task, or reached via pointer)

/* Menu/screen handler (callback analysis) */

void menu_wakeup_2(void)

{
  byte bVar1;
  
  if ((cfg_systemconfig5 & 0x10) == 0) {
    return;
  }
  bVar1 = ui_to_ui_draw_on_off_22ea(0x37);
  ui_set_menu_edit_mode_2386((bVar1 & 0x20) != 0);
  menu_cb_enter = 0x1a;
  menu_set_cbs_back_default(9);
  return;
}

