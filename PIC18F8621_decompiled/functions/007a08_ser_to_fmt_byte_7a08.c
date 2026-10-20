// address 0x007a08  size 14 bytes
// callers: 007848,007ac8,006e5c,

/* Auto: calls fmt_byte; 6 instr */

void ser_to_fmt_byte_7a08(void)

{
  BADSPACEBASE *in_FSR1;
  undefined1 *puVar1;
  
  puVar1 = &FramePointer10x0001;
  fmt_byte();
  *puVar1 = *puVar1;
  puVar1[-1] = puVar1[-1];
  puVar1[-2] = puVar1[-2];
  return;
}

