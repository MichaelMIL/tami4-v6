// address 0x004daa  size 30 bytes
// callers: 003584,

/* Auto: reads math_res0,math_res1,math_aarg_lo,math_aarg_hi; calls ltoa; 10 instr */

char ui_to_ltoa_4daa(void)

{
  char cVar1;
  BADSPACEBASE *in_FSR1;
  
  ui_get_math_res0_4fdc();
  *(undefined1 *)in_FSR1 = math_res0;
  *(undefined1 *)((short)in_FSR1 + 1) = math_res1;
  *(undefined1 *)((short)in_FSR1 + 2) = math_aarg_lo;
  cVar1 = (char)(undefined1 *)((short)in_FSR1 + 4);
  *(undefined1 *)((short)in_FSR1 + 3) = math_aarg_hi;
  c18_tmp8 = ltoa();
  return cVar1 + -6;
}

