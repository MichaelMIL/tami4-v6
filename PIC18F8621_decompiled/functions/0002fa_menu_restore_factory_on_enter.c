// address 0x0002fa  size 10 bytes
// callers: (none: entry point, task, or reached via pointer)

/* Menu/screen handler (callback analysis) */

void menu_restore_factory_on_enter(void)

{
  if (menu_edit_mode == '\0') {
    menu_default_back();
    return;
  }
  lcd_clear(menu_edit_mode);
  ui_to_ui_draw_title_word_2874(0x48);
  menu_cb_enter = 0xde;
  menu_set_cbs_enter_hi(1);
  return;
}

