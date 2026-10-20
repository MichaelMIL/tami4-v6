// address 0x007a3a  size 14 bytes
// callers: 007860,006e5c,

/* Auto: calls atol; 6 instr */

void ser_to_atol_7a3a(void)

{
  BADSPACEBASE *in_FSR1;
  undefined1 *puVar1;
  
  puVar1 = &FramePointer10x0001;
  atol();
  *puVar1 = *puVar1;
  puVar1[-1] = puVar1[-1];
  return;
}

