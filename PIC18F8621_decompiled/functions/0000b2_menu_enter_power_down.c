// address 0x0000b2  size 24 bytes
// callers: (none: entry point, task, or reached via pointer)

/* Menu/screen handler (callback analysis) */

void menu_enter_power_down(void)

{
  if ((cfg_systemconfig5 & 0x10) == 0) {
    return;
  }
  ui_to_lcd_clear_2bf2();
  ui_to_ui_draw_title_2986();
  menu_cb_enter = 0x9a;
  menu_set_cbs_back_default(0);
  return;
}

