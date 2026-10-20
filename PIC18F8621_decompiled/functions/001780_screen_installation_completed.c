// address 0x001780  size 34 bytes
// callers: (none: entry point, task, or reached via pointer)

/* "INSTALLATION COMPLETED" */

undefined1 screen_installation_completed(void)

{
  BADSPACEBASE *in_FSR1;
  
  ui_word_installation_2370();
  *(undefined1 *)in_FSR1 = 2;
  ui_draw_word_push6(0x7d);
  ui_draw_press_ok_to_continue();
  ui_set_menu_timer_lo_251e();
  menu_cb_enter = 0xa2;
  menu_cb_enter_hi = 0x17;
  return 0x17;
}

