// address 0x004bf6  size 62 bytes
// callers: 004ffc,003584,

/* Convert deg C to deg F (x9/5+32) */

undefined1 temp_c_to_f(void)

{
  byte bVar1;
  BADSPACEBASE *in_FSR2;
  BADSPACEBASE *in_FSR1;
  byte in_PRODL;
  
  ui_stack_adjust_4f80();
  c18_tmp0 = *(undefined1 *)((short)in_FSR2 + 6);
  c18_tmp1 = *(char *)((short)in_FSR2 + 8);
  bVar1 = in_PRODL;
  ser_get_c18_tmp1_5010(9);
  math_aarg_lo = bVar1;
  math_barg_lo = 5;
  math_barg_hi = 0;
  math_aarg_hi = c18_tmp1;
  __divs16();
  c18_tmp0 = math_aarg_lo + 0x20;
  c18_tmp1 = math_aarg_hi + (0xdf < math_aarg_lo);
  *(char *)in_FSR1 = c18_tmp0;
  *(char *)((short)in_FSR1 + 1) = c18_tmp1;
  return 0;
}

