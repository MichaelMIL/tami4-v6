// address 0x0026fc  size 12 bytes
// callers: 001768,00170a,

/* Auto: calls screen_stopped; 5 instr */

void ui_to_screen_stopped_26fc(void)

{
  BADSPACEBASE *in_FSR1;
  undefined1 *puVar1;
  
  puVar1 = &FramePointer10x0001;
  screen_stopped();
  *puVar1 = *puVar1;
  puVar1[-1] = puVar1[-1];
  return;
}

