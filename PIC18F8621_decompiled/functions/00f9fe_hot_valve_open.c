// address 0x00f9fe  size 50 bytes
// callers: 00aa56,

/* Hot water valve (RH1): open, load TVALVEON safety timeout */

char hot_valve_open(void)

{
  byte bVar1;
  BADSPACEBASE *in_FSR1;
  undefined1 *puVar2;
  
  if ((-1 < hot_valve_fault) && ((outputs_shadow & 2) == 0)) {
    puVar2 = &FramePointer10x0001;
    hot_valve_timeout = eeprom_read_param();
    *puVar2 = *puVar2;
    if ((outputs_enable_mask & 2) != 0) {
      bVar1 = PORTH;
      PORTH = bVar1 | RH1;
      outputs_shadow = outputs_shadow | 2;
    }
    hot_valve_open_flag = 1;
  }
  return hot_valve_fault;
}

