// address 0x000838  size 14 bytes
// callers: (none: entry point, task, or reached via pointer)

/* Menu/screen handler (callback analysis) */

void screen_value_edit_setup_on_down(void)

{
  BADSPACEBASE *in_FSR1;
  undefined1 *puVar1;
  
  puVar1 = &FramePointer10x0001;
  mod_set_clock_edit_hour_a730();
  *puVar1 = *puVar1;
  ui_to_ui_draw_time_249e();
  return;
}

