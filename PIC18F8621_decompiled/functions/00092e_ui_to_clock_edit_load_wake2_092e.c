// address 0x00092e  size 22 bytes
// callers: (none: entry point, task, or reached via pointer)

/* Auto: calls clock_edit_load_wake2,screen_wakeup2_edit_hour; 7 instr */

void ui_to_clock_edit_load_wake2_092e(void)

{
  ui_to_ui_set_text_row_245a();
  ui_chain_fn21f4_ui_set_menu_value__2ac6(0x4a);
  clock_edit_load_wake2();
  screen_wakeup2_edit_hour();
  return;
}

