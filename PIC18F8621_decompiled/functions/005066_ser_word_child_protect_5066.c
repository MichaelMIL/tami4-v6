// address 0x005066  size 14 bytes
// callers: 003b12,

/* Auto: shows "CHILD PROTECT!"; 7 instr */

undefined1 ser_word_child_protect_5066(void)

{
  BADSPACEBASE *in_FSR1;
  undefined1 *puVar1;
  
  puVar1 = &FramePointer10x0001;
  ui_to_ser_to_text_draw_word_4d7a(0x10);
  *puVar1 = 4;
  return 4;
}

