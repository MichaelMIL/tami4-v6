// address 0x0028c8  size 26 bytes
// callers: 002180,000a0e,

/* Auto: reads c18_tmp0,c18_tmp1,math_aarg_lo,math_aarg_hi; calls __divs16; 8 instr */

void ui_to___divs16_28c8(undefined1 param_1)

{
  math_barg_hi = 0;
  math_aarg_lo = c18_tmp0;
  math_aarg_hi = c18_tmp1;
  math_barg_lo = param_1;
  __divs16();
  c18_tmp0 = math_aarg_lo;
  c18_tmp1 = math_aarg_hi;
  return;
}

