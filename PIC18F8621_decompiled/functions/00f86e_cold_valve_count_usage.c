// address 0x00f86e  size 26 bytes
// callers: 00b104,

/* Cold water valve: per-second usage counter update while open */

undefined1 cold_valve_count_usage(void)

{
  BADSPACEBASE *in_FSR1;
  undefined1 *puVar1;
  undefined1 uVar2;
  
  uVar2 = 0;
  if ((outputs_shadow & 1) != 0) {
    uVar2 = 0;
    if ((outputs_shadow & 4) != 0) {
      puVar1 = &FramePointer10x0001;
      uVar2 = stat_counter_inc();
      *puVar1 = *puVar1;
    }
  }
  return uVar2;
}

