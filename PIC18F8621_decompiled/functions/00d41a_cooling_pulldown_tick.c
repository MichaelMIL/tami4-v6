// address 0x00d41a  size 22 bytes
// callers: 00b104,

/* Per second: count pull-down time while measuring */

undefined1 cooling_pulldown_tick(void)

{
  bool bVar1;
  
  if ((cooling_flags & 1) != 0) {
    if ((cooling_flags & 2) != 0) {
      bVar1 = 0xfe < pulldown_time_lo;
      pulldown_time_lo = pulldown_time_lo + 1;
      pulldown_time_hi = pulldown_time_hi + bVar1;
    }
  }
  return 0;
}

