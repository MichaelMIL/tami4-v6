// address 0x00c990  size 8 bytes
// callers: 00b104,

/* Per second: count boil timer while boil detection active */

void heating_boil_timer_tick(void)

{
  if ((heating_flags & 2) != 0) {
    boil_timer = boil_timer + '\x01';
  }
  return;
}

