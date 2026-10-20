// address 0x00a6fe  size 26 bytes
// callers: 00a718,00a730,

/* Auto: writes clock_edit_ampm; reads clock_edit_ampm,clock_edit_hour; 13 instr */

bool mod_set_clock_edit_ampm_a6fe(void)

{
  if (clock_edit_ampm == '\x02') {
    return false;
  }
  clock_edit_ampm = 0xb < clock_edit_hour;
  return 0xb < clock_edit_hour;
}

