// address 0x0027b0  size 12 bytes
// callers: 0026b6,001192,001392,0026f0,002220,00243e,0026ea,00137a,001684,001128,0013b0,00135c,0024ca,

/* Draw UI word (id in W) via text_draw_word */

void ui_draw_word(void)

{
  BADSPACEBASE *in_FSR1;
  undefined1 *puVar1;
  
  puVar1 = &FramePointer10x0001;
  text_draw_word();
  *puVar1 = *puVar1;
  puVar1[-1] = puVar1[-1];
  return;
}

