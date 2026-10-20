// address 0x002684  size 12 bytes
// callers: 002826,000b2c,

/* Auto: calls screen_cold_temp_bar; 5 instr */

void ui_to_screen_cold_temp_bar_2684(void)

{
  BADSPACEBASE *in_FSR1;
  undefined1 *puVar1;
  
  puVar1 = &FramePointer10x0001;
  screen_cold_temp_bar();
  *puVar1 = *puVar1;
  return;
}

