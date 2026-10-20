// address 0x002ae8  size 8 bytes
// callers: 0013e8,001438,00148c,

/* Auto: writes menu_edit_mode; calls lcd_clear; 3 instr */

void ui_to_lcd_clear_2ae8(undefined1 param_1)

{
  menu_edit_mode = param_1;
  lcd_clear();
  return;
}

