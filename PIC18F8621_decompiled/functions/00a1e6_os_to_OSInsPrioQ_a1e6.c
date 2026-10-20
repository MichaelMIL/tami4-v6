// address 0x00a1e6  size 8 bytes
// callers: 00a2ba,009af0,00a09a,

/* Auto: calls OSInsPrioQ; 4 instr */

void os_to_OSInsPrioQ_a1e6(void)

{
  BADSPACEBASE *in_FSR1;
  
  OSInsPrioQ();
  os_pop3_return_a2e4();
  *(undefined1 *)in_FSR1 = *(undefined1 *)in_FSR1;
  return;
}

