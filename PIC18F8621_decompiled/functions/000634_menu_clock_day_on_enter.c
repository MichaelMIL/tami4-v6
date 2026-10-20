// address 0x000634  size 14 bytes
// callers: (none: entry point, task, or reached via pointer)

/* Menu/screen handler (callback analysis) */

void menu_clock_day_on_enter(void)

{
  BADSPACEBASE *in_FSR1;
  undefined1 *puVar1;
  
  puVar1 = &FramePointer10x0001;
  clock_set_day();
  *puVar1 = *puVar1;
  menu_default_back();
  return;
}

