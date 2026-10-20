// address 0x00cdf4  size 16 bytes
// callers: 00ca50,00cd58,

/* Auto: reads TBLPTRL,TBLPTRH; 8 instr */

char mod_get_TBLPTRL_cdf4(byte param_1)

{
  return c18_tmp1 + CARRY1(c18_tmp0,param_1);
}

