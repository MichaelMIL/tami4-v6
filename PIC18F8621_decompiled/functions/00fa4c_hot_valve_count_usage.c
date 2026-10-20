// address 0x00fa4c  size 24 bytes
// callers: 00b104,

/* Hot water valve: per-second usage counter update while open */

undefined1 hot_valve_count_usage(void)

{
  BADSPACEBASE *in_FSR1;
  undefined1 *puVar1;
  undefined1 uVar2;
  
  uVar2 = 0;
  if ((outputs_shadow & 1) != 0) {
    uVar2 = 0;
    if ((outputs_shadow & 2) != 0) {
      puVar1 = &FramePointer10x0001;
      uVar2 = stat_counter_inc(outputs_shadow & 2);
      *puVar1 = *puVar1;
    }
  }
  return uVar2;
}

