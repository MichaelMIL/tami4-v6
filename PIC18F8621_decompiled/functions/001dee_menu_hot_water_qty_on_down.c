// address 0x001dee  size 6 bytes
// callers: (none: entry point, task, or reached via pointer)

/* Menu/screen handler (callback analysis) */

void menu_hot_water_qty_on_down(void)

{
  menu_value_decrement();
  ui_set_menu_value_lo_1e14();
  return;
}

