// address 0x00d490  size 10 bytes
// callers: 00d174,

/* eeprom_read_param wrapper for cooling module */

void cooling_read_param(void)

{
  BADSPACEBASE *in_FSR1;
  undefined1 *puVar1;
  
  puVar1 = &FramePointer10x0001;
  eeprom_read_param();
  *puVar1 = *puVar1;
  return;
}

