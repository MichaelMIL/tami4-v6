// address 0x004d24  size 74 bytes
// callers: 0034ae,

/* Multiply/divide helper for display values */

char ui_scale_mul(byte param_1)

{
  BADSPACEBASE *in_FSR1;
  char cVar1;
  
  c18_tmp7 = 0;
  math_aarg_lo = (byte)((ushort)c18_tmp4 * (ushort)param_1);
  math_aarg_hi = (char)((ushort)c18_tmp4 * (ushort)param_1 >> 8) + c18_tmp5 * param_1;
  math_barg_lo = c18_tmp8;
  math_barg_hi = c18_tmp9;
  c18_tmp2 = math_aarg_lo;
  c18_tmp3 = math_aarg_hi;
  c18_tmp6 = param_1;
  __divs16();
  c18_tmp0 = c18_tmp10 + math_aarg_lo;
  c18_tmp1 = c18_tmp11 + math_aarg_hi + CARRY1(c18_tmp10,math_aarg_lo);
  cVar1 = c18_tmp1;
  DAT_DATA_0118 = c18_tmp0;
  *(char *)in_FSR1 = c18_tmp0;
  return cVar1;
}

