// address 0x00b022  size 10 bytes
// callers: 00aeec,00aefa,00aa56,00af68,00b060,00afe2,

/* eeprom_read_param wrapper for dispensing module */

void dispense_read_param(void)

{
  BADSPACEBASE *in_FSR1;
  undefined1 *puVar1;
  
  puVar1 = &FramePointer10x0001;
  eeprom_read_param();
  *puVar1 = *puVar1;
  return;
}

