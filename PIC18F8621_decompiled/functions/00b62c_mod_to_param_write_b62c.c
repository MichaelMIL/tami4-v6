// address 0x00b62c  size 16 bytes
// callers: 00b518,00b52a,

/* Auto: calls param_write; 7 instr */

void mod_to_param_write_b62c(void)

{
  BADSPACEBASE *in_FSR1;
  undefined1 *puVar1;
  
  puVar1 = &FramePointer10x0002;
  param_write();
  *puVar1 = *puVar1;
  puVar1[-1] = puVar1[-1];
  return;
}

