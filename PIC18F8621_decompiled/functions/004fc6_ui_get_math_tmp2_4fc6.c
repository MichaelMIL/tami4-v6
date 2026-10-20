// address 0x004fc6  size 22 bytes
// callers: 003584,

/* Auto: reads math_tmp2,math_tmp3,math_rem_lo,math_rem_hi; 7 instr */

void ui_get_math_tmp2_4fc6(void)

{
  math_barg_lo = 0;
  math_barg_hi = 0;
  math_res0 = math_tmp2;
  math_res1 = math_tmp3;
  math_aarg_lo = math_rem_lo;
  math_aarg_hi = math_rem_hi;
  return;
}

