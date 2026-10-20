// address 0x0026be  size 16 bytes
// callers: 0016d2,001732,

/* Auto: writes menu_timer_lo,menu_timer_hi,menu_timer_reload_lo; reads menu_timer_hi; 7 instr */

undefined1 ui_set_menu_timer_lo_26be(void)

{
  menu_timer_lo = 0x78;
  menu_timer_hi = 0;
  menu_timer_reload_lo = 0x78;
  menu_timer_reload_hi = 0;
  return 0x78;
}

