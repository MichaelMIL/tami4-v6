// address 0x002386  size 6 bytes
// callers: 0001a8,001ff2,0008c4,0000ca,000178,00011e,00094a,000148,00207e,0020b0,

/* Auto: writes menu_edit_mode; 3 instr */

void ui_set_menu_edit_mode_2386(undefined1 param_1)

{
  menu_edit_mode = param_1;
  ui_to_screen_temp_sensor_values_2af0();
  return;
}

