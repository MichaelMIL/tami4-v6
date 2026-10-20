// address 0x00a2f2  size 10 bytes
// callers: 009b64,009c40,

/* Auto: Access stack-frame local/argument; 4 instr */

void os_frame_access_a2f2(void)

{
  BADSPACEBASE *in_FSR2;
  char cVar1;
  BADSPACEBASE *in_FSR0;
  
  os_frame_load_ptr_arg_a160();
  cVar1 = os_frag_a292();
  *(undefined1 *)((short)in_FSR2 + (short)cVar1 + 1) = *(undefined1 *)in_FSR0;
  return;
}

