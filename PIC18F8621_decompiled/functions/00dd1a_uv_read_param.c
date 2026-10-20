// address 0x00dd1a  size 10 bytes
// callers: 00dd3e,00dbe6,00da82,00dcce,00dd52,00dc44,00dc32,00dd46,

/* eeprom_read_param wrapper for UV module */

void uv_read_param(void)

{
  BADSPACEBASE *in_FSR1;
  undefined1 *puVar1;
  
  puVar1 = &FramePointer10x0001;
  eeprom_read_param();
  *puVar1 = *puVar1;
  return;
}

