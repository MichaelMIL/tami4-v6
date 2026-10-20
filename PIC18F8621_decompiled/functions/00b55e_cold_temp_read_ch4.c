// address 0x00b55e  size 20 bytes
// callers: 003584,006e5c,00bff8,00d174,

/* Cold tank sensor on AN4 (AN5 if SYSTEMCONFIG3 bit0 clear) */

void cold_temp_read_ch4(void)

{
  BADSPACEBASE *in_FSR1;
  undefined1 *puVar1;
  
  puVar1 = &FramePointer10x0001;
  cold_temp_read();
  *puVar1 = *puVar1;
  return;
}

