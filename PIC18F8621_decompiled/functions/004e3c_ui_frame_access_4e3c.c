// address 0x004e3c  size 16 bytes
// callers: 003584,

/* Auto: Access stack-frame local/argument; 6 instr */

undefined1 ui_frame_access_4e3c(void)

{
  BADSPACEBASE *in_FSR2;
  BADSPACEBASE *in_FSR1;
  
  ui_stack_adjust_4f80();
  *(undefined1 *)in_FSR1 = *(undefined1 *)((short)in_FSR2 + 6);
  *(undefined1 *)((short)in_FSR1 + 1) = *(undefined1 *)((short)in_FSR2 + 8);
  return 6;
}

