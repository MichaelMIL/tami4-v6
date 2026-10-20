// address 0x00f79c  size 42 bytes
// callers: 004f30,00b054,

/* Inlet valve (RH0): close, update usage counters */

undefined1 inlet_valve_close(void)

{
  byte bVar1;
  BADSPACEBASE *in_FSR1;
  undefined1 *puVar2;
  
  if ((outputs_shadow & 1) != 0) {
    bVar1 = PORTH;
    PORTH = bVar1 & ~RH0;
    outputs_shadow = outputs_shadow & 0xfe;
    bVar1 = PORTH;
    PORTH = bVar1 | RH7;
    inlet_valve_open_flag = 0;
    puVar2 = &FramePointer10x0001;
    stat_counter_save();
    *puVar2 = *puVar2;
    puVar2[-1] = 0xf;
    stat_counter_save();
    *puVar2 = *puVar2;
  }
  return inlet_valve_fault;
}

