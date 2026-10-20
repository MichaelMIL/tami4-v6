// address 0x00d96e  size 42 bytes
// callers: 00e9b2,00d794,

/* Set fan run-on time in minutes */

char fan_set_runon_minutes(void)

{
  BADSPACEBASE *in_FSR1;
  
  fan_runon_lo = *(char *)(CONCAT11((char)((ushort)&FramePointer10x0002 >> 8),
                                    (char)&FramePointer10x0002) + -2) * '<';
  fan_runon_hi = 0;
  return fan_runon_lo;
}

