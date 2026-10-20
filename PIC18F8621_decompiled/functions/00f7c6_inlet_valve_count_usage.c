// address 0x00f7c6  size 28 bytes
// callers: 00b104,

/* Inlet valve: per-second usage counter update while open */

void inlet_valve_count_usage(void)

{
  BADSPACEBASE *in_FSR1;
  undefined1 *puVar1;
  
  if ((outputs_shadow & 1) != 0) {
    puVar1 = &FramePointer10x0001;
    stat_counter_inc();
    *puVar1 = *puVar1;
    puVar1[-1] = 0xf;
    stat_counter_inc();
    *puVar1 = *puVar1;
  }
  return;
}

