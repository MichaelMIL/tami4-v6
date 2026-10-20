// address 0x001438  size 32 bytes
// callers: (none: entry point, task, or reached via pointer)

/* Auto: writes menu_cb_enter; reads cfg_systemconfig4; calls menu_set_cbs_back_default; 13 instr */

void ui_to_menu_set_cbs_back_default_1438(void)

{
  ui_to_lcd_clear_2ae8((cfg_systemconfig4 & 0x40) != 0x40);
  ui_to_ui_draw_title_22dc(0x20);
  menu_cb_enter = 0x58;
  menu_set_cbs_back_default(0x14);
  return;
}

