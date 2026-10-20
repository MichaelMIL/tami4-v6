// address 0x000596  size 16 bytes
// callers: (none: entry point, task, or reached via pointer)

/* Menu/screen handler (callback analysis) */

void menu_power_down_mode_on_enter(void)

{
  BADSPACEBASE *in_FSR1;
  
  ui_to___mul16x16_32_24ea(0x18);
  *(undefined1 *)in_FSR1 = math_res0;
  ui_to_menu_default_back_279e(0x31);
  return;
}

