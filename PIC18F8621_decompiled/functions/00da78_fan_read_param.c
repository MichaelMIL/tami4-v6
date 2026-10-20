// address 0x00da78  size 10 bytes
// callers: 00d926,00d794,

/* EEPROM read wrapper for fan module */

void fan_read_param(void)

{
  BADSPACEBASE *in_FSR1;
  undefined1 *puVar1;
  
  puVar1 = &FramePointer10x0001;
  eeprom_read_raw();
  *puVar1 = *puVar1;
  return;
}

