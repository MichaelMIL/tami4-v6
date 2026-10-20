// address 0x004e32  size 10 bytes
// callers: 002d86,

/* Auto: Small wrapper around ui_get_buzzer_pattern; 5 instr */

void ui_to_ui_get_buzzer_pattern_4e32(void)

{
  BADSPACEBASE *in_FSR1;
  undefined1 *puVar1;
  
  puVar1 = &FramePointer10x0001;
  ui_get_buzzer_pattern_4850();
  *puVar1 = *puVar1;
  return;
}

