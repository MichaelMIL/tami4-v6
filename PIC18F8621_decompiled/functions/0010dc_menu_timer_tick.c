// address 0x0010dc  size 28 bytes
// callers: 004550,

/* Count down menu timer; on expiry call menu_cb_timeout */

undefined1 menu_timer_tick(void)

{
  undefined1 uVar1;
  bool bVar2;
  
  if ((menu_timer_hi != '\0' || menu_timer_lo != '\0') && (menu_timer_enabled != '\0')) {
    if ((menu_cb_timeout_hi | menu_cb_timeout) != 0) {
      menu_call_timeout_cb(menu_cb_timeout_hi | menu_cb_timeout);
    }
    bVar2 = menu_timer_lo != '\0';
    menu_timer_lo = menu_timer_lo + -1;
    menu_timer_hi = menu_timer_hi - ~bVar2;
    return 0;
  }
  uVar1 = 0;
  if ((menu_cb_aux_hi | menu_cb_aux) != 0) {
    uVar1 = menu_call_aux_cb(menu_cb_aux_hi | menu_cb_aux);
  }
  return uVar1;
}

