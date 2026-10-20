// address 0x00fa30  size 28 bytes
// callers: 00aa56,

/* Hot water valve (RH1): close, update usage counters */

undefined1 hot_valve_close(void)

{
  byte bVar1;
  BADSPACEBASE *in_FSR1;
  undefined1 *puVar2;
  
  if ((outputs_shadow & 2) != 0) {
    bVar1 = PORTH;
    PORTH = bVar1 & ~RH1;
    outputs_shadow = outputs_shadow & 0xfd;
    hot_valve_open_flag = 0;
    puVar2 = &FramePointer10x0001;
    stat_counter_save();
    *puVar2 = *puVar2;
  }
  return hot_valve_fault;
}

