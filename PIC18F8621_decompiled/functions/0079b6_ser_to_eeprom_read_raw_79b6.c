// address 0x0079b6  size 12 bytes
// callers: 006d6a,006e5c,

/* Auto: reads serial_cmd_hash; calls eeprom_read_raw; 4 instr */

void ser_to_eeprom_read_raw_79b6(void)

{
  BADSPACEBASE *in_FSR1;
  undefined1 *puVar1;
  
  puVar1 = &FramePointer10x0001;
  eeprom_read_raw();
  *puVar1 = *puVar1;
  return;
}

