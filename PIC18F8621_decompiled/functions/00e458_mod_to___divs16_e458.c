// address 0x00e458  size 38 bytes
// callers: 00e3ec,00e2fc,

/* Auto: reads c18_tmp0,c18_tmp1,math_aarg_lo,math_aarg_hi; calls __divs16; 14 instr */

void mod_to___divs16_e458(void)

{
  math_aarg_lo = -0x7e - c18_tmp0;
  math_aarg_hi = '\x02' - c18_tmp1;
  math_barg_lo = 2;
  math_barg_hi = 0;
  c18_tmp0 = math_aarg_lo;
  c18_tmp1 = math_aarg_hi;
  __divs16();
  c18_tmp0 = math_aarg_lo;
  c18_tmp1 = math_aarg_hi;
  return;
}

