// address 0x004e84  size 8 bytes
// callers: 004ae6,00331e,002d86,

/* Auto: writes ui_screen; calls clock_display_off; 3 instr */

void ui_to_clock_display_off_4e84(void)

{
  byte unaff_BSR;
  
  *(undefined1 *)((ushort)unaff_BSR * 0x100) = 0x14;
  clock_display_off();
  return;
}

