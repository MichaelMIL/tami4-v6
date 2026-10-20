// address 0x001644  size 64 bytes
// callers: 0026fc,

/* "STOPPED..." */

void screen_stopped(void)

{
  BADSPACEBASE *in_FSR2;
  BADSPACEBASE *in_FSR1;
  
  ui_c18_prologue_2166();
  menu_timer_enabled = 0;
  ui_word_installation_2370();
  *(undefined1 *)in_FSR1 = 3;
  ui_draw_word_push6(0xd);
  ui_draw_press_ok_to_continue();
  dispense_stop_all();
  menu_cb_aux = 0;
  menu_cb_aux_hi = 0;
  menu_cb_timeout = 0;
  menu_cb_timeout_hi = 0;
  menu_cb_enter = *(undefined1 *)((short)in_FSR2 + -3);
  menu_cb_enter_hi = *(undefined1 *)((short)in_FSR2 + -1);
  menu_set_cbs_noop();
  menu_cb_key = 0;
  menu_cb_key_hi = 0;
  ui_c18_epilogue_21d8();
  return;
}

