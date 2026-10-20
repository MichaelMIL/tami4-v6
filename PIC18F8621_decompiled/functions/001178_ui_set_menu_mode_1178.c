// address 0x001178  size 26 bytes
// callers: 001140,

/* Auto: writes menu_mode; reads menu_edit_mode; 10 instr */

void ui_set_menu_mode_1178(void)

{
  if (menu_edit_mode != '\0') {
    ui_set_stat_GUV_22fa(menu_edit_mode);
  }
  ui_to_lcd_clear_21fc();
  ui_to_ui_select_home_screen_4af0();
  menu_mode = 0;
  return;
}

