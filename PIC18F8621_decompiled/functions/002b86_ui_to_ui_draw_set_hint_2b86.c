// address 0x002b86  size 10 bytes
// callers: 002344,002992,002178,

/* Auto: calls ui_draw_set_hint; 4 instr */

void ui_to_ui_draw_set_hint_2b86(void)

{
  BADSPACEBASE *in_FSR1;
  
  ui_draw_set_hint();
  *(undefined1 *)in_FSR1 = *(undefined1 *)in_FSR1;
  *(undefined1 *)((short)in_FSR1 + -1) = *(undefined1 *)((short)in_FSR1 + -1);
  return;
}

