// address 0x00acc6  size 12 bytes
// callers: 00b0aa,

/* Every 100 ms: hot dispense time limit and portion countdown */

void dispense_100ms_tick(void)

{
  char cVar1;
  
  cVar1 = hot_dispense_timer;
  if (hot_dispense_timer != '\0') {
    hot_dispense_timer = hot_dispense_timer + -1;
  }
  portion_tick(cVar1);
  return;
}

