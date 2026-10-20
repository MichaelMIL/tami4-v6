// address 0x00137a  size 24 bytes
// callers: (none: entry point, task, or reached via pointer)

/* "DROP COLLECTOR IS FULL / PLEASE EMPTY IT" */

void screen_drop_collector_full(void)

{
  BADSPACEBASE *in_FSR1;
  
  menu_mode = 5;
  lcd_clear();
  *(undefined1 *)in_FSR1 = 2;
  ui_draw_word(0x7b);
  ui_to_menu_set_cbs_noop_b_281a();
  return;
}

