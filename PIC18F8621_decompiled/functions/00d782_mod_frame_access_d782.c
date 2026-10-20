// address 0x00d782  size 10 bytes
// callers: 00d640,00d654,

/* Auto: Access stack-frame local/argument; 5 instr */

undefined1 mod_frame_access_d782(void)

{
  BADSPACEBASE *in_FSR2;
  undefined1 in_FSR1L;
  char cVar1;
  
  mod_c18_prologue_d6b4();
  cVar1 = mod_stack_adjust_d710(in_FSR1L);
  return *(undefined1 *)((short)in_FSR2 + (short)cVar1 + 1);
}

