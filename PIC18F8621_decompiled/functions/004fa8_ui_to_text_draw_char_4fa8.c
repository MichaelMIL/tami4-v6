// address 0x004fa8  size 10 bytes
// callers: 003ada,0048b2,004d04,003b12,

/* Auto: calls text_draw_char; 4 instr */

void ui_to_text_draw_char_4fa8(void)

{
  BADSPACEBASE *in_FSR1;
  undefined1 *puVar1;
  
  puVar1 = &FramePointer10x0001;
  text_draw_char();
  *puVar1 = *puVar1;
  return;
}

