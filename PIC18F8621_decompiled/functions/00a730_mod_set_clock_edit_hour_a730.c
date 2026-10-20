// address 0x00a730  size 26 bytes
// callers: 000838,000788,

/* Auto: writes clock_edit_hour; reads clock_edit_hour; 13 instr */

void mod_set_clock_edit_hour_a730(void)

{
  BADSPACEBASE *in_FSR2;
  
  mod_c18_prologue_a8c8();
  clock_edit_hour = clock_edit_hour + -1;
  if (clock_edit_hour == -1) {
    clock_edit_hour = '\x17';
  }
  if (*(char *)((short)in_FSR2 + -2) != '\0') {
    mod_set_clock_edit_ampm_a6fe(*(char *)((short)in_FSR2 + -2));
  }
  mod_c18_epilogue_a902();
  return;
}

