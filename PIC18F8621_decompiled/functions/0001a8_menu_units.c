// address 0x0001a8  size 54 bytes
// callers: (none: entry point, task, or reached via pointer)

/* Menu/screen handler (callback analysis) */

void menu_units(void)

{
  if ((cfg_systemconfig5 & 0x10) == 0) {
    return;
  }
  ui_to_lcd_clear_2bf2();
  ui_draw_title();
  ui_stack_adjust_2800();
  ui_set_text_a(0x46);
  ui_set_text_b(0x47);
  ui_set_menu_edit_mode_2386((cfg_systemconfig3 & 4) != 0);
  menu_cb_enter = 0x9a;
  menu_set_cbs_back_default(1);
  return;
}

