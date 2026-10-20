// address 0x004844  size 12 bytes
// callers: 00b0aa,

/* Every 100 ms: UI countdown */

char ui_100ms_tick(void)

{
  char cVar1;
  
  cVar1 = -ui_countdown_100ms;
  if (ui_countdown_100ms != '\0') {
    ui_countdown_100ms = ui_countdown_100ms + -1;
  }
  return cVar1;
}

