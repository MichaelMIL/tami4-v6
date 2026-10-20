// address 0x00a718  size 24 bytes
// callers: 000794,000846,

/* Auto: writes clock_edit_hour; reads clock_edit_hour; 12 instr */

void mod_set_clock_edit_hour_a718(void)

{
  BADSPACEBASE *in_FSR2;
  
  mod_c18_prologue_a8c8();
  clock_edit_hour = clock_edit_hour + '\x01';
  if (clock_edit_hour == '\x18') {
    clock_edit_hour = '\0';
  }
  if (*(char *)((short)in_FSR2 + -2) != '\0') {
    mod_set_clock_edit_ampm_a6fe(*(char *)((short)in_FSR2 + -2));
  }
  mod_c18_epilogue_a902();
  return;
}

