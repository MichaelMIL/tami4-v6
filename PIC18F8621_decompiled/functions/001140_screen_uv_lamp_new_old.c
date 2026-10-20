// address 0x001140  size 56 bytes
// callers: 00d998,

/* Ask NEW/OLD UV LAMP after refit (new resets GUV counter) */

void screen_uv_lamp_new_old(void)

{
  menu_mode = 4;
  if ((cfg_systemconfig4 & 1) == 0) {
    ui_word_uv_lamp_26ae();
    ui_to_ui_get_cfg_systemconfig2_2c1c();
    ui_set_text_a(0x51);
    ui_set_text_b(0x52);
    ui_set_menu_edit_mode_2498();
    menu_cb_enter = 0x78;
    menu_set_cbs_enter_hi_b(0x11);
    return;
  }
  menu_edit_mode = 0;
  ui_set_menu_mode_1178();
  ui_to_ui_select_home_screen_4af0();
  return;
}

