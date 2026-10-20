// address 0x00a8da  size 16 bytes
// callers: 00a826,

/* Auto: Software stack push/pop helper; 6 instr */

void mod_stack_adjust_a8da(void)

{
  undefined1 in_FSR2L;
  undefined1 in_FSR2H;
  BADSPACEBASE *in_FSR1;
  undefined1 *puVar1;
  
  puVar1 = &FramePointer10x0001;
  mod_callw_fncfc6_a9c2(7);
  *puVar1 = in_FSR2L;
  puVar1[1] = in_FSR2H;
  return;
}

