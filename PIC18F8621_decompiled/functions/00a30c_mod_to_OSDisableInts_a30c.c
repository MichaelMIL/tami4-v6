// address 0x00a30c  size 6 bytes
// callers: 00a038,00a0b6,009f5a,

/* Auto: calls OSDisableInts; 2 instr */

void mod_to_OSDisableInts_a30c(void)

{
  os_stack_adjust_a28c();
  OSDisableInts();
  return;
}

