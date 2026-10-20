// address 0x00a760  size 14 bytes
// callers: 00085c,0007a8,

/* Auto: writes clock_edit_minute; reads clock_edit_minute; 7 instr */

char mod_set_clock_edit_minute_a760(void)

{
  char cVar1;
  
  cVar1 = clock_edit_minute + -0x3b;
  clock_edit_minute = clock_edit_minute + '\x01';
  if (cVar1 == '\0') {
    clock_edit_minute = '\0';
  }
  return cVar1;
}

