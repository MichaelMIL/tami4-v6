// address 0x00b592  size 8 bytes
// callers: 003584,00ace2,0034ae,00bff8,00c606,

/* Hot tank top sensor (AN0) */

void hot_temp_read_top(void)

{
  BADSPACEBASE *in_FSR1;
  undefined1 *puVar1;
  
  puVar1 = &FramePointer10x0001;
  hot_temp_read();
  *puVar1 = *puVar1;
  return;
}

