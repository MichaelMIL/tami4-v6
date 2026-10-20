// address 0x000b18  size 20 bytes
// callers: (none: entry point, task, or reached via pointer)

/* Menu/screen handler (callback analysis) */

void menu_cold_water_temp_on_enter(void)

{
  BADSPACEBASE *in_FSR1;
  undefined1 *puVar1;
  
  puVar1 = &FramePointer10x0001;
  ui_to_param_write_215a(3);
  *puVar1 = menu_value_lo;
  ui_to_menu_default_back_279e(2);
  return;
}

