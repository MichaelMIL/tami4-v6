// address 0x001192  size 24 bytes
// callers: 00d998,

/* "FILTER IS REMOVED / INSERT FILTER" */

void screen_filter_removed(void)

{
  BADSPACEBASE *in_FSR1;
  
  menu_mode = 1;
  ui_word_filter_233c();
  *(undefined1 *)in_FSR1 = 3;
  ui_draw_word(0x7a);
  ui_to_menu_set_cbs_noop_b_281a();
  return;
}

