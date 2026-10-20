// address 0x0027bc  size 22 bytes
// callers: 002bc2,002bb6,

/* Install up/down callbacks for time editing */

void screen_time_edit_setup(void)

{
  ui_to_ui_draw_time_249e();
  menu_cb_up = 0x46;
  menu_cb_up_hi = 8;
  menu_cb_down = 0x38;
  menu_set_cbs_down_hi(8);
  return;
}

