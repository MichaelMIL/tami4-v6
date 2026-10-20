// address 0x002964  size 14 bytes
// callers: 00087a,0008fa,

/* Auto: calls screen_time_edit_setup_b; 5 instr */

void ui_to_screen_time_edit_setup_b_2964(void)

{
  ui_to_param_write_215a();
  ui_set_menu_value_lo_2bae(1);
  ui_to_ui_draw_time_249e();
  screen_time_edit_setup_b();
  return;
}

