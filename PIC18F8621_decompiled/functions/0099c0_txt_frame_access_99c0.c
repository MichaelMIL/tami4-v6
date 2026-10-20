// address 0x0099c0  size 10 bytes
// callers: 0092ae,009282,

/* Auto: Access stack-frame local/argument; 5 instr */

byte txt_frame_access_99c0(void)

{
  BADSPACEBASE *in_FSR2;
  
  txt_c18_prologue_9a5a();
  return *(byte *)((short)in_FSR2 + -3) ^ 4;
}

