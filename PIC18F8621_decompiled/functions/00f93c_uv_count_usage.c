// address 0x00f93c  size 26 bytes
// callers: 00b104,

/* Per second: UV lamp usage counter while lit */

byte uv_count_usage(void)

{
  BADSPACEBASE *in_FSR1;
  undefined1 *puVar1;
  byte bVar2;
  
  bVar2 = PORTJ;
  bVar2 = bVar2 & 2;
  if (bVar2 == 0) {
    bVar2 = 0;
    if ((cfg_systemconfig & 8) != 0) {
      puVar1 = &FramePointer10x0001;
      bVar2 = stat_counter_inc();
      *puVar1 = *puVar1;
    }
  }
  return bVar2;
}

