// address 0x00a750  size 16 bytes
// callers: 0007a0,000854,

/* Auto: writes clock_edit_minute; reads clock_edit_minute; 8 instr */

char mod_set_clock_edit_minute_a750(void)

{
  char cVar1;
  bool bVar2;
  
  bVar2 = clock_edit_minute == '\0';
  cVar1 = clock_edit_minute;
  clock_edit_minute = clock_edit_minute + -1;
  if (bVar2) {
    cVar1 = ';';
    clock_edit_minute = ';';
  }
  return cVar1;
}

