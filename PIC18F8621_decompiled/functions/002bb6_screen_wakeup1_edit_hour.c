// address 0x002bb6  size 12 bytes
// callers: 00089a,000864,

/* Wake up 1: edit hour */

undefined1 screen_wakeup1_edit_hour(void)

{
  byte unaff_BSR;
  
  screen_time_edit_setup();
  *(undefined1 *)((ushort)unaff_BSR * 0x100 + 0x34) = 0x7a;
  *(undefined1 *)((ushort)unaff_BSR * 0x100 + 0x35) = 8;
  return 8;
}

