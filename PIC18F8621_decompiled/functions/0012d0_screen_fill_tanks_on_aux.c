// address 0x0012d0  size 40 bytes
// callers: (none: entry point, task, or reached via pointer)

/* Menu/screen handler (callback analysis) */

void screen_fill_tanks_on_aux(void)

{
  menu_cb_timeout = 0;
  menu_cb_timeout_hi = 0;
  menu_cb_aux = 0xf8;
  menu_cb_aux_hi = 0x12;
  menu_timer_lo = 3;
  menu_timer_hi = 0;
  dispense_stop_all();
  ui_word_filter_233c();
  ui_draw_done(4);
  ui_to_menu_set_cbs_noop_b_2a7e();
  return;
}

