// address 0x00e892  size 16 bytes
// callers: 00e70a,

/* Load heater maximum on-time from EEPROM (THEATERMAXON) */

void heater_load_maxon(void)

{
  BADSPACEBASE *in_FSR1;
  undefined1 *puVar1;
  
  puVar1 = &FramePointer10x0001;
  heater_maxon_timer = eeprom_read_param();
  *puVar1 = *puVar1;
  return;
}

