// address 0x001538  size 24 bytes
// callers: (none: entry point, task, or reached via pointer)

/* Menu/screen handler (callback analysis) */

void menu_install_fill_tanks(void)

{
  if ((cfg_systemconfig5 & 0x10) == 0) {
    return;
  }
  ui_word_installation_2370();
  ui_word_put_2_liter_jug_x0aunder_the_2a72();
  menu_cb_enter = 0xc2;
  menu_set_cbs_enter_hi_e(0x16);
  return;
}

