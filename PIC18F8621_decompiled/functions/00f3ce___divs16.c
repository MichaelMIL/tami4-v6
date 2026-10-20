// address 0x00f3ce  size 76 bytes
// callers: 0028c8,00a414,00ace2,00289c,00e458,00f278,004d24,004bf6,0021a0,00af9e,00097a,0020e8,003b12,00af68,

/* WARNING: Instruction at (CODE,0x00f414) overlaps instruction at (CODE,0x00f412)
    */
/* C18 runtime: signed 16-bit divide (AARG / BARG) */

undefined1 __divs16(void)

{
  math_sign = 0;
  if ((math_barg_hi & 0x80) != 0) {
    math_barg_lo = -math_barg_lo;
    math_barg_hi = ~math_barg_hi + ('\0' < math_barg_lo);
    math_sign = 0xff;
  }
  if ((math_aarg_hi & 0x80) != 0) {
    math_aarg_lo = -math_aarg_lo;
    math_aarg_hi = ~math_aarg_hi + ('\0' < math_aarg_lo);
    math_sign = ~math_sign;
  }
  __divu16();
  if ((math_aarg_hi & 0x80) == 0) {
    if ((math_sign & 0x80) == 0) {
      return 0;
    }
  }
  else if ((math_sign & 0x80) == 0) {
    math_flags = math_flags | 0x10;
    return 0xff;
  }
  math_aarg_lo = -math_aarg_lo;
  math_aarg_hi = ~math_aarg_hi + ('\0' < math_aarg_lo);
  math_rem_lo = -math_rem_lo;
  math_rem_hi = ~math_rem_hi + ('\0' < math_rem_lo);
  return 0;
}

