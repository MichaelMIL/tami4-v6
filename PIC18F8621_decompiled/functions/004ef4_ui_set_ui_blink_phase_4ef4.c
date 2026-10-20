// address 0x004ef4  size 8 bytes
// callers: 004550,

/* Auto: writes ui_blink_phase; reads ui_blink_phase; 4 instr */

char ui_set_ui_blink_phase_4ef4(void)

{
  char cVar1;
  byte unaff_BSR;
  
  cVar1 = *(char *)((ushort)unaff_BSR * 0x100 + 0x1b);
  *(char *)((ushort)unaff_BSR * 0x100 + 0x1b) = *(char *)((ushort)unaff_BSR * 0x100 + 0x1b) + -1;
  return -cVar1;
}

