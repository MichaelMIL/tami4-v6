// address 0x00120a  size 36 bytes
// callers: (none: entry point, task, or reached via pointer)

/* Menu/screen handler (callback analysis) */

void fn_11e2_on_enter(void)

{
  BADSPACEBASE *in_FSR1;
  
  ui_set_stat_GFI_247a();
  ui_word_filter_233c();
  ui_set_text_row_2b08();
  *(undefined1 *)in_FSR1 = 6;
  *(undefined1 *)((short)in_FSR1 + 1) = 0;
  ui_stack_adjust_21f4(0x6a);
  menu_cb_enter = 0x2e;
  menu_set_cbs_enter_hi_e(0x12);
  return;
}

