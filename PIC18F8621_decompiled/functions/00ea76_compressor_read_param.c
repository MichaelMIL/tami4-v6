// address 0x00ea76  size 10 bytes
// callers: 00ea8a,00e9b2,00e8ae,00e926,

/* eeprom_read_param wrapper for compressor module */

void compressor_read_param(void)

{
  BADSPACEBASE *in_FSR1;
  undefined1 *puVar1;
  
  puVar1 = &FramePointer10x0001;
  eeprom_read_param();
  *puVar1 = *puVar1;
  return;
}

