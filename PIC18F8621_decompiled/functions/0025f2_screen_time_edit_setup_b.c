// address 0x0025f2  size 20 bytes
// callers: 002964,

/* Install up/down callbacks for time editing (variant) */

undefined1 screen_time_edit_setup_b(void)

{
  menu_cb_up = 0x5c;
  menu_cb_up_hi = 8;
  menu_cb_down = 0x54;
  menu_cb_down_hi = 8;
  return 8;
}

