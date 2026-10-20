// address 0x00148c  size 26 bytes
// callers: (none: entry point, task, or reached via pointer)

/* Auto: writes menu_cb_enter; reads cfg_systemconfig5; calls menu_set_cbs_back_default; 10 instr */

void ui_to_menu_set_cbs_back_default_148c(void)

{
  ui_to_lcd_clear_2ae8(cfg_systemconfig5 & 1);
  ui_to_ui_draw_title_22dc(0x5a);
  menu_cb_enter = 0xa6;
  menu_set_cbs_back_default(0x14);
  return;
}

