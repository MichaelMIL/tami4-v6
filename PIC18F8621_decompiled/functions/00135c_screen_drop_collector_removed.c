// address 0x00135c  size 24 bytes
// callers: (none: entry point, task, or reached via pointer)

/* "DROP COLLECTOR IS REMOVED / PLEASE REPLACE IT" */

void screen_drop_collector_removed(void)

{
  BADSPACEBASE *in_FSR1;
  
  menu_mode = 6;
  lcd_clear();
  *(undefined1 *)in_FSR1 = 2;
  ui_draw_word(0x78);
  ui_to_menu_set_cbs_noop_b_281a();
  return;
}

