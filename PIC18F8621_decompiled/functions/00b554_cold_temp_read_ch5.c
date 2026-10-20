// address 0x00b554  size 10 bytes
// callers: 003584,006e5c,00ace2,0034ae,00d174,

/* Cold tank sensor on AN5 */

void cold_temp_read_ch5(void)

{
  BADSPACEBASE *in_FSR1;
  undefined1 *puVar1;
  
  puVar1 = &FramePointer10x0001;
  cold_temp_read();
  *puVar1 = *puVar1;
  return;
}

