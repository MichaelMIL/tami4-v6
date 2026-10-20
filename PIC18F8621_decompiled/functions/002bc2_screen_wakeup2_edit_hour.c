// address 0x002bc2  size 12 bytes
// callers: 0008e4,00092e,

/* Wake up 2: edit hour */

undefined1 screen_wakeup2_edit_hour(void)

{
  byte unaff_BSR;
  
  screen_time_edit_setup();
  *(undefined1 *)((ushort)unaff_BSR * 0x100 + 0x34) = 0xfa;
  *(undefined1 *)((ushort)unaff_BSR * 0x100 + 0x35) = 8;
  return 8;
}

