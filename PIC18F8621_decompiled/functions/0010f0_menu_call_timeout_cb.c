// address 0x0010f0  size 22 bytes
// callers: 0010f0,

/* Call menu_cb_timeout */

undefined1 menu_call_timeout_cb(void)

{
  bool bVar1;
  
  menu_call_timeout_cb(menu_cb_timeout);
  bVar1 = menu_timer_lo != '\0';
  menu_timer_lo = menu_timer_lo + -1;
  menu_timer_hi = menu_timer_hi - ~bVar1;
  return 0;
}

