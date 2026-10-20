// address 0x00b59a  size 20 bytes
// callers: 003584,00bff8,00c606,

/* Hot tank bottom sensor (AN1 if SYSTEMCONFIG bit6, else AN0) */

void hot_temp_read_bottom(void)

{
  BADSPACEBASE *in_FSR1;
  undefined1 *puVar1;
  
  puVar1 = &FramePointer10x0001;
  hot_temp_read();
  *puVar1 = *puVar1;
  return;
}

