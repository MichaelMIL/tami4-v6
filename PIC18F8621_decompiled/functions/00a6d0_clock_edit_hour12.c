// address 0x00a6d0  size 34 bytes
// callers: 0006aa,

/* Edit buffer hour in 12-hour format */

byte clock_edit_hour12(void)

{
  if ((clock_edit_ampm == '\x02') || (clock_edit_hour < 0xc)) {
    return clock_edit_hour;
  }
  if ((clock_edit_ampm == '\x01') && (clock_edit_hour == 0xc)) {
    return 0xc;
  }
  return clock_edit_hour - 0xc;
}

