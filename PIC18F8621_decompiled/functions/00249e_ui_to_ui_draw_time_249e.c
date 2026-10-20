// address 0x00249e  size 10 bytes
// callers: 000854,002964,000846,00085c,0027bc,000838,

/* Auto: calls ui_draw_time; 4 instr */

void ui_to_ui_draw_time_249e(void)

{
  BADSPACEBASE *in_FSR1;
  undefined1 *puVar1;
  
  puVar1 = &FramePointer10x0001;
  ui_draw_time();
  *puVar1 = *puVar1;
  return;
}

