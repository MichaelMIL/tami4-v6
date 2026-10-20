// address 0x000da0  size 24 bytes
// callers: (none: entry point, task, or reached via pointer)

/* Menu/screen handler (callback analysis) */

void menu_hot_water_qty_on_enter(void)

{
  byte unaff_Z;
  
  ui_get_menu_value_lo_2778();
  if ((unaff_Z & 1) != 0) {
    ui_get_menu_value_step_lo_25c2();
  }
  ui_get_math_aarg_lo_295a();
  ui_to_param_write_215a(0x42);
  ui_get_cfg_systemconfig5_2c02();
  return;
}

