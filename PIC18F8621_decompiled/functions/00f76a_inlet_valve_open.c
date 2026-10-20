// address 0x00f76a  size 50 bytes
// callers: 00aa56,

/* Inlet valve (RH0): open, load TVALVEON safety timeout */

char inlet_valve_open(void)

{
  byte bVar1;
  BADSPACEBASE *in_FSR1;
  undefined1 *puVar2;
  
  if ((-1 < inlet_valve_fault) && ((outputs_shadow & 1) == 0)) {
    puVar2 = &FramePointer10x0001;
    inlet_valve_timeout = eeprom_read_param();
    *puVar2 = *puVar2;
    if ((outputs_enable_mask & 1) != 0) {
      bVar1 = PORTH;
      PORTH = bVar1 | RH0;
      outputs_shadow = outputs_shadow | 1;
    }
    inlet_valve_open_flag = 1;
  }
  return inlet_valve_fault;
}

