// address 0x00d430  size 10 bytes
// callers: 00b104,

/* Per minute: count down idle time before pull-down measurement */

void cooling_idle_minute_tick(void)

{
  cooling_idle_minutes = cooling_idle_minutes + -1;
  if (cooling_idle_minutes == '\0') {
    cooling_flags = cooling_flags | 2;
  }
  return;
}

