// address 0x00e76a  size 22 bytes
// callers: 003b12,00da64,00c606,

/* Switch heater off (level 0) and log usage */

undefined1 heater_off(void)

{
  BADSPACEBASE *in_FSR1;
  undefined1 *puVar1;
  
  if (heater_power_level == '\0') {
    return 1;
  }
  heater_power_level = 0;
  puVar1 = &FramePointer10x0001;
  stat_counter_save();
  *puVar1 = *puVar1;
  return 0;
}

