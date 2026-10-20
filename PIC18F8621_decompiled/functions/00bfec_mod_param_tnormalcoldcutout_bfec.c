// address 0x00bfec  size 12 bytes
// callers: 00bff8,

/* Auto: reads params TNORMALCOLDCUTOUT; calls eeprom_read_raw; 5 instr */

void mod_param_tnormalcoldcutout_bfec(void)

{
  BADSPACEBASE *in_FSR1;
  undefined1 *puVar1;
  
  puVar1 = &FramePointer10x0001;
  eeprom_read_raw();
  *puVar1 = *puVar1;
  return;
}

