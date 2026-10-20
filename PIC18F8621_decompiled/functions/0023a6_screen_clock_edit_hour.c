// address 0x0023a6  size 50 bytes
// callers: 0007fe,

/* Clock set: edit hours (then minutes) */

undefined1 screen_clock_edit_hour(void)

{
  BADSPACEBASE *in_FSR1;
  undefined1 *puVar1;
  undefined1 uVar2;
  
  uVar2 = ui_set_menu_value_lo_2bae(1);
  puVar1 = (undefined1 *)((short)in_FSR1 + 1);
  *(undefined1 *)in_FSR1 = uVar2;
  ui_draw_time();
  *puVar1 = *puVar1;
  menu_cb_up = 0xa8;
  menu_cb_up_hi = 7;
  menu_cb_down = 0xa0;
  menu_cb_down_hi = 7;
  menu_cb_back = 6;
  menu_cb_back_hi = 8;
  menu_cb_enter = 0xcc;
  menu_cb_enter_hi = 7;
  return 7;
}

