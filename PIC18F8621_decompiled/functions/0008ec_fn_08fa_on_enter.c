// address 0x0008ec  size 14 bytes
// callers: (none: entry point, task, or reached via pointer)

/* Menu/screen handler (callback analysis) */

void fn_08fa_on_enter(void)

{
  mod_get_clock_edit_minute_a74a();
  ui_set_menu_timer_reload_lo_269c();
  ui_to_menu_default_back_279e(0x39);
  return;
}

