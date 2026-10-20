// address 0x00a666  size 18 bytes
// callers: 000814,

/* Copy current time into the edit buffer */

void clock_copy_to_edit(void)

{
  clock_edit_day = clock_day;
  clock_edit_hour = clock_hour;
  clock_edit_minute = clock_minute;
  clock_edit_ampm = clock_pm;
  return;
}

