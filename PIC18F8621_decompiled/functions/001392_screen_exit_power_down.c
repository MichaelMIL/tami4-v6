// address 0x001392  size 30 bytes
// callers: 00331e,

/* "EXIT POWERDOWN MODE?" */

void screen_exit_power_down(void)

{
  ui_draw_power_down();
  ui_draw_word(0x58);
  text_row = 6;
  ui_stack_adjust_2bdc();
  DAT_DATA_0e34 = 0xce;
  menu_set_cbs_enter_hi_e(0x13);
  return;
}

