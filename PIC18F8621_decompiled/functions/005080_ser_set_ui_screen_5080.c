// address 0x005080  size 14 bytes
// callers: 004dfa,003b12,

/* Auto: writes ui_screen,ui_dispense_state,ui_hold_counter; 7 instr */

undefined1 ser_set_ui_screen_5080(void)

{
  byte unaff_BSR;
  
  *(undefined1 *)((ushort)unaff_BSR * 0x100) = 0xb;
  *(undefined1 *)((ushort)unaff_BSR * 0x100 + 0xd) = 2;
  *(undefined1 *)((ushort)unaff_BSR * 0x100 + 0xe) = 3;
  return 3;
}

