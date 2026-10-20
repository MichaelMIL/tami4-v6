// address 0x000342  size 30 bytes
// callers: (none: entry point, task, or reached via pointer)

/* Menu/screen handler (callback analysis) */

void menu_reset_on_enter(void)

{
  if (menu_edit_mode == '\0') {
    menu_default_back();
    return;
  }
  lcd_clear(menu_edit_mode);
  ui_to_ui_draw_title_word_2874(0x8b);
  menu_cb_enter = 0x34;
  menu_set_cbs_enter_hi(3);
  return;
}

