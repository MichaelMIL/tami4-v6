// address 0x00bbfa  size 10 bytes
// callers: 00bb32,00baa0,00bb2a,

/* Auto: Access stack-frame local/argument; 4 instr */

char mod_frame_access_bbfa(char param_1)

{
  BADSPACEBASE *in_FSR2;
  char in_PRODL;
  
  return (&FramePointer20x0001)[param_1] - in_PRODL;
}

