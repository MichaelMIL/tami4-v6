// address 0x000814  size 36 bytes
// callers: (none: entry point, task, or reached via pointer)

/* Menu/screen handler (callback analysis) */

void menu_clock_time(void)

{
  if ((cfg_systemconfig5 & 0x10) == 0) {
    return;
  }
  ui_get_TBLPTRL_22ba();
  ui_to_ui_set_text_row_245a();
  ui_chain_fn21f4_ui_set_menu_value__2ac6(0x39);
  clock_copy_to_edit();
  ui_to_ui_draw_time_23ea();
  menu_item = 0;
  ui_to_menu_set_cbs_down_hi_2882();
  return;
}

