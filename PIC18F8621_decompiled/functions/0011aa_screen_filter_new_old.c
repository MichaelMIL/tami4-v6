// address 0x0011aa  size 56 bytes
// callers: 00d998,

/* Ask NEW/OLD FILTER after refit (new resets GFI counter) */

void screen_filter_new_old(void)

{
  menu_mode = 2;
  if ((cfg_systemconfig4 & 1) == 0) {
    ui_word_filter_233c();
    ui_to_ui_get_cfg_systemconfig2_2c1c();
    ui_set_text_a(0x53);
    ui_set_text_b(0x54);
    ui_set_menu_edit_mode_2498();
    menu_cb_enter = 0xe2;
    menu_set_cbs_enter_hi_b(0x11);
    return;
  }
  menu_edit_mode = 0;
  fn_11e2_on_back_on_enter();
  ui_to_ui_select_home_screen_4af0();
  return;
}

