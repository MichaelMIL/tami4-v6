// address 0x005048  size 10 bytes
// callers: 004d7a,004550,003b12,

/* Auto: calls text_draw_word; 4 instr */

void ser_to_text_draw_word_5048(void)

{
  BADSPACEBASE *in_FSR1;
  undefined1 *puVar1;
  
  puVar1 = &FramePointer10x0001;
  text_draw_word();
  *puVar1 = *puVar1;
  return;
}

