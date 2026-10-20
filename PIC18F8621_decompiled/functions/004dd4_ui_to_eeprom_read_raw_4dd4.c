// address 0x004dd4  size 10 bytes
// callers: 00509c,005040,004550,004b32,

/* Auto: calls eeprom_read_raw; 4 instr */

void ui_to_eeprom_read_raw_4dd4(void)

{
  BADSPACEBASE *in_FSR1;
  undefined1 *puVar1;
  
  puVar1 = &FramePointer10x0001;
  eeprom_read_raw();
  *puVar1 = *puVar1;
  return;
}

