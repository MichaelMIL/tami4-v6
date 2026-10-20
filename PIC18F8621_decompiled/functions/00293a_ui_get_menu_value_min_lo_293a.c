// address 0x00293a  size 24 bytes
// callers: 002208,

/* Auto: reads menu_value_min_lo; 9 instr */

void ui_get_menu_value_min_lo_293a(void)

{
  BADSPACEBASE *in_FSR1;
  undefined1 *puVar1;
  undefined1 *puVar2;
  
  puVar1 = &FramePointer10x0002;
  mod_to_mod_to_lcd_write_cmd_cfc6();
  *puVar1 = *puVar1;
  puVar1[-1] = puVar1[-1];
  puVar2 = puVar1 + -1;
  puVar1[-2] = 0xff;
  lcd_write_data();
  *puVar2 = *puVar2;
  return;
}

