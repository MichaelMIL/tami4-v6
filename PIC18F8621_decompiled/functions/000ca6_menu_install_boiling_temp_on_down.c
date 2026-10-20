// address 0x000ca6  size 8 bytes
// callers: (none: entry point, task, or reached via pointer)

/* Menu/screen handler (callback analysis) */

void menu_install_boiling_temp_on_down(void)

{
  menu_mix_water_temp_on_down();
  ui_push_args_01_46_03_ui_to_ui_draw_temp_value_0cae();
  return;
}

