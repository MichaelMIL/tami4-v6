// address 0x00a2d4  size 8 bytes
// callers: 00a0b6,009f7a,009f5a,

/* Auto: calls OSRestoreInts; 4 instr */

undefined1 os_to_OSRestoreInts_a2d4(void)

{
  undefined1 uVar1;
  BADSPACEBASE *in_FSR2;
  BADSPACEBASE *in_FSR1;
  
  OSRestoreInts();
  uVar1 = *(undefined1 *)in_FSR2;
  *(undefined1 *)in_FSR1 = *(undefined1 *)in_FSR1;
  return uVar1;
}

