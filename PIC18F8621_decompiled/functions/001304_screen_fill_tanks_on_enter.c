// address 0x001304  size 48 bytes
// callers: (none: entry point, task, or reached via pointer)

/* Menu/screen handler (callback analysis) */

void screen_fill_tanks_on_enter(void)

{
  BADSPACEBASE *in_FSR1;
  
  menu_cb_timeout = 0;
  menu_cb_timeout_hi = 0;
  ui_word_filter_233c();
  *(undefined1 *)in_FSR1 = 2;
  ui_to_text_draw_word_2996(0x57);
  menu_edit_mode = 1;
  screen_temp_sensor_values();
  menu_cb_enter = 0x34;
  menu_set_cbs_enter_hi_b(0x13);
  menu_cb_key = 0;
  menu_cb_key_hi = 0;
  return;
}

