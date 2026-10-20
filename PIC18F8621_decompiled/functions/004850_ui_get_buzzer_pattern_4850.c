// address 0x004850  size 10 bytes
// callers: 00b256,004264,004e32,002d86,

/* Auto: reads buzzer_pattern; 4 instr */

void ui_get_buzzer_pattern_4850(void)

{
  BADSPACEBASE *in_FSR2;
  
  ui_frag_4c90();
  buzzer_pattern = *(undefined1 *)((short)in_FSR2 + -2);
  ui_c18_epilogue_4d6e();
  return;
}

