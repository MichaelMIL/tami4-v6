// address 0x00c998  size 18 bytes
// callers: 00b104,

/* Every 10 s: count down heating timers */

char heating_timers_10s(void)

{
  char cVar1;
  
  if (heating_startup_timer != '\0') {
    heating_startup_timer = heating_startup_timer + -1;
  }
  cVar1 = -extra_hot_timer;
  if (extra_hot_timer != '\0') {
    extra_hot_timer = extra_hot_timer + -1;
  }
  return cVar1;
}

