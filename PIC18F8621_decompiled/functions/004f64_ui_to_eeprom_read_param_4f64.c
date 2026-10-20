// address 0x004f64  size 10 bytes
// callers: 002c22,004cc2,004eb2,004de4,004efc,003584,003b12,00323c,002d86,

/* Auto: calls eeprom_read_param; 4 instr */

void ui_to_eeprom_read_param_4f64(void)

{
  BADSPACEBASE *in_FSR1;
  undefined1 *puVar1;
  
  puVar1 = &FramePointer10x0001;
  eeprom_read_param();
  *puVar1 = *puVar1;
  return;
}

