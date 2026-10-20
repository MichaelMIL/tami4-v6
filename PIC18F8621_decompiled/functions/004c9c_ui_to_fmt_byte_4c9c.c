// address 0x004c9c  size 12 bytes
// callers: 003584,004fbc,

/* Auto: calls fmt_byte; 4 instr */

void ui_to_fmt_byte_4c9c(void)

{
  BADSPACEBASE *in_FSR2;
  BADSPACEBASE *in_FSR1;
  
  ui_stack_adjust_4f80();
  *(undefined1 *)in_FSR1 = *(undefined1 *)((short)in_FSR2 + 6);
  fmt_byte();
  return;
}

