// address 0x002ba4  size 10 bytes
// callers: 002874,002a1c,00261a,002220,

/* Draw title word (id in W) */

void ui_draw_title_word(void)

{
  BADSPACEBASE *in_FSR1;
  undefined1 *puVar1;
  
  puVar1 = &FramePointer10x0001;
  ui_draw_title();
  *puVar1 = *puVar1;
  return;
}

