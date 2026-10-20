// address 0x0011e2  size 40 bytes
// callers: 0011aa,

/* Menu/screen handler (callback analysis) */

void fn_11e2_on_back_on_enter(void)

{
  if (menu_edit_mode != '\0') {
    ui_word_filter_233c();
    ui_word_put_2_liter_jug_x0aunder_the_2a72();
    menu_cb_enter = 10;
    menu_cb_enter_hi = 0x12;
    menu_cb_back = 0xaa;
    menu_set_cbs_back_hi(0x11);
    return;
  }
  ui_set_menu_mode_2a06(0);
  return;
}

