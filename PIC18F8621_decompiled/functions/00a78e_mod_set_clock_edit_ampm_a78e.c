// address 0x00a78e  size 16 bytes
// callers: 0007b8,

/* Auto: writes clock_edit_ampm; reads clock_edit_ampm; 8 instr */

char mod_set_clock_edit_ampm_a78e(void)

{
  char cVar1;
  bool bVar2;
  
  bVar2 = clock_edit_ampm == '\0';
  cVar1 = clock_edit_ampm;
  clock_edit_ampm = clock_edit_ampm + -1;
  if (bVar2) {
    cVar1 = '\x02';
    clock_edit_ampm = '\x02';
  }
  return cVar1;
}

