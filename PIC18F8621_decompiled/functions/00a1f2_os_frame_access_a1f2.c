// address 0x00a1f2  size 14 bytes
// callers: 00a116,00a0e2,

/* Auto: Access stack-frame local/argument; 6 instr */

undefined1 os_frame_access_a1f2(void)

{
  BADSPACEBASE *in_FSR2;
  BADSPACEBASE *in_FSR1;
  undefined1 uVar1;
  
  uVar1 = os_tcb_get_state_a2c6();
  *(undefined1 *)in_FSR1 = uVar1;
  *(undefined1 *)((short)in_FSR2 + 2) = *(undefined1 *)in_FSR1;
  return *(undefined1 *)((short)in_FSR2 + 3);
}

