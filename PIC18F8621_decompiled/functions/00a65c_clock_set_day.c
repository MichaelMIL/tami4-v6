// address 0x00a65c  size 10 bytes
// callers: 000634,

/* Set day of week */

void clock_set_day(void)

{
  BADSPACEBASE *in_FSR2;
  
  mod_c18_prologue_a8c8();
  clock_day = *(undefined1 *)((short)in_FSR2 + -2);
  mod_c18_epilogue_a902();
  return;
}

