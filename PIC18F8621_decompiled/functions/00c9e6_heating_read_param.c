// address 0x00c9e6  size 10 bytes
// callers: 00c9ac,00ca1c,00c936,00c606,00c8e4,

/* eeprom_read_param wrapper for heating module */

void heating_read_param(void)

{
  BADSPACEBASE *in_FSR1;
  undefined1 *puVar1;
  
  puVar1 = &FramePointer10x0001;
  eeprom_read_param();
  *puVar1 = *puVar1;
  return;
}

