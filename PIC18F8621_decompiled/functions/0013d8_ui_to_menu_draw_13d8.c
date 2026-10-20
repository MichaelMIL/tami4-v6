// address 0x0013d8  size 16 bytes
// callers: 00331e,

/* Auto: writes menu_table_ptr_lo,menu_table_ptr_hi; calls menu_draw; 7 instr */

void ui_to_menu_draw_13d8(void)

{
  menu_table_ptr_lo = 0x1a;
  menu_table_ptr_hi = 0xe6;
  menu_draw();
  ui_bank1_ui_set_menu_cb_up_2454();
  return;
}

