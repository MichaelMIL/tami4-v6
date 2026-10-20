// address 0x002a06  size 10 bytes
// callers: 0011e2,001356,001374,

/* Auto: writes menu_mode; 4 instr */

void ui_set_menu_mode_2a06(void)

{
  ui_to_lcd_clear_21fc();
  menu_mode = 0;
  return;
}

