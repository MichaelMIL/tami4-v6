// address 0x002b7a  size 12 bytes
// callers: 002344,0027d2,000c62,

/* Auto: calls param_read_min; 5 instr */

void ui_to_param_read_min_2b7a(void)

{
  BADSPACEBASE *in_FSR1;
  undefined1 *puVar1;
  
  puVar1 = &FramePointer10x0001;
  param_read_min();
  *puVar1 = *puVar1;
  return;
}

