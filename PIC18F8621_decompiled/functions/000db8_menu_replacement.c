// address 0x000db8  size 58 bytes
// callers: (none: entry point, task, or reached via pointer)

/* Menu/screen handler (callback analysis) */

void menu_replacement(void)

{
  if ((cfg_systemconfig5 & 0x10) == 0) {
    return;
  }
  menu_edit_mode = 1;
  screen_replacement_counter();
  menu_cb_back = 0xf2;
  menu_cb_back_hi = 0x1b;
  if ((cfg_systemconfig & 8) == 0) {
    menu_cb_up = 4;
    menu_cb_up_hi = 0xe;
    menu_cb_down = 4;
    menu_cb_down_hi = 0xe;
  }
  else {
    menu_cb_down_hi = menu_set_cbs_updown_default();
  }
  return;
}

