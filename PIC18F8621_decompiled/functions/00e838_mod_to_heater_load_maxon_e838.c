// address 0x00e838  size 4 bytes
// callers: 00aa56,

/* Auto: calls heater_load_maxon; 1 instr */

void mod_to_heater_load_maxon_e838(void)

{
  BADSPACEBASE *in_FSR1;
  undefined1 *puVar1;
  
  puVar1 = &FramePointer10x0001;
  heater_maxon_timer = eeprom_read_param();
  *puVar1 = *puVar1;
  return;
}

