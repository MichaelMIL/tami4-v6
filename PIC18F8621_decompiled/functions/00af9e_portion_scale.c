// address 0x00af9e  size 36 bytes
// callers: 00ace2,00af54,00b04c,

/* Multiply/divide helper for portion timing */

void portion_scale(byte param_1)

{
  math_aarg_lo = (undefined1)((ushort)c18_tmp0 * (ushort)param_1);
  math_aarg_hi = c18_tmp1 * param_1 + (char)((ushort)c18_tmp0 * (ushort)param_1 >> 8);
  math_barg_lo = portion_flow_lo;
  math_barg_hi = portion_flow_hi;
  c18_tmp0 = math_aarg_lo;
  c18_tmp1 = math_aarg_hi;
  __divs16();
  return;
}

