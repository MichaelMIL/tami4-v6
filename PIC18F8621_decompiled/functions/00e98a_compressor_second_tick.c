// address 0x00e98a  size 18 bytes
// callers: 00b104,

/* Per second: compressor usage counter while running */

void compressor_second_tick(void)

{
  BADSPACEBASE *in_FSR1;
  undefined1 *puVar1;
  
  if ((outputs_shadow & 0x40) != 0) {
    puVar1 = &FramePointer10x0001;
    stat_counter_inc();
    *puVar1 = *puVar1;
  }
  return;
}

