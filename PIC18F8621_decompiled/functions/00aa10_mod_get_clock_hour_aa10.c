// address 0x00aa10  size 16 bytes
// callers: 00a91a,

/* Auto: reads clock_hour,c18_tmp0; 7 instr */

undefined1 mod_get_clock_hour_aa10(char param_1)

{
  byte unaff_BSR;
  
  c18_tmp0 = *(char *)((ushort)unaff_BSR * 0x100 + 0xdb) - param_1;
  c18_tmp1 = 10;
  math_barg_hi = 10;
  math_aarg_hi = c18_tmp0;
  return 10;
}

