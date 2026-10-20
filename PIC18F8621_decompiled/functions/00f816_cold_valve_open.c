// address 0x00f816  size 54 bytes
// callers: 00aa56,

/* Cold water valve (RH2): open, load TVALVEON safety timeout */

char cold_valve_open(void)

{
  byte bVar1;
  BADSPACEBASE *in_FSR1;
  undefined1 *puVar2;
  
  if ((-1 < cold_valve_fault) && ((outputs_shadow & 4) == 0)) {
    puVar2 = &FramePointer10x0001;
    cold_valve_timeout = eeprom_read_param();
    *puVar2 = *puVar2;
    if ((outputs_enable_mask & 4) != 0) {
      bVar1 = PORTH;
      PORTH = bVar1 | RH2;
      outputs_shadow = outputs_shadow | 4;
    }
    cold_valve_open_flag = 1;
    cooling_abort_pulldown();
  }
  return cold_valve_fault;
}

