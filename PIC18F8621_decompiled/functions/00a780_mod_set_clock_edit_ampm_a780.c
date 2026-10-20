// address 0x00a780  size 14 bytes
// callers: 0007c0,

/* Auto: writes clock_edit_ampm; reads clock_edit_ampm; 7 instr */

char mod_set_clock_edit_ampm_a780(void)

{
  char cVar1;
  
  clock_edit_ampm = clock_edit_ampm + 1;
  cVar1 = '\x02' - clock_edit_ampm;
  if (2 < clock_edit_ampm) {
    clock_edit_ampm = 0;
  }
  return cVar1;
}

