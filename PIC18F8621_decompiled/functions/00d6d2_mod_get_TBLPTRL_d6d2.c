// address 0x00d6d2  size 30 bytes
// callers: 00d4a4,

/* Auto: reads TBLPTRL,TBLPTRH,c18_tmp0,c18_tmp1; 11 instr */

undefined1 mod_get_TBLPTRL_d6d2(byte param_1)

{
  byte in_TBLPTRL;
  char in_TBLPTRH;
  
  c18_tmp0 = in_TBLPTRL + param_1;
  c18_tmp1 = in_TBLPTRH + CARRY1(in_TBLPTRL,param_1);
  return 1;
}

