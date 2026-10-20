// address 0x0013e8  size 40 bytes
// callers: (none: entry point, task, or reached via pointer)

/* Menu/screen handler (callback analysis) */

void menu_service_temp_sensor(void)

{
  BADSPACEBASE *in_FSR1;
  
  if ((cfg_systemconfig5 & 0x10) == 0) {
    return;
  }
  ui_to_lcd_clear_2ae8(cfg_systemconfig3 & 1);
  *(undefined1 *)in_FSR1 = 0x35;
  ui_draw_title();
  ui_draw_yes_no();
  screen_temp_sensor_values();
  menu_cb_enter = 0x10;
  menu_set_cbs_back_default(0x14);
  return;
}

