// address 0x00a6a4  size 44 bytes
// callers: 00092e,

/* Load wake-up time 2 (WKUPHOUR2/WKUPMINUTE2) into edit buffer */

void clock_edit_load_wake2(void)

{
  byte unaff_BSR;
  byte unaff_Z;
  byte unaff_C;
  
  mod_set_clock_edit_hour_aa20(0x38);
  if ((unaff_C & 1) == 0) {
    *(undefined1 *)((ushort)unaff_BSR * 0x100 + 0xed) = 0;
    unaff_Z = 1;
  }
  mod_set_clock_edit_minute_aa2c(0x39);
  if ((unaff_C & 1) == 0) {
    *(undefined1 *)((ushort)unaff_BSR * 0x100 + 0xee) = 0;
    unaff_Z = 1;
  }
  mod_get_clock_pm_a99c();
  if ((unaff_Z & 1) == 0) {
    if (clock_edit_hour < 0xc) {
      clock_edit_ampm = 0;
    }
    else {
      clock_edit_ampm = 1;
    }
  }
  else {
    clock_edit_ampm = 2;
  }
  return;
}

