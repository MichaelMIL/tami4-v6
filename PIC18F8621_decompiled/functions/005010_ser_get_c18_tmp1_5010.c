// address 0x005010  size 18 bytes
// callers: 004bf6,004550,

/* Auto: reads c18_tmp1,c18_tmp0; 7 instr */

char ser_get_c18_tmp1_5010(byte param_1)

{
  ushort uVar1;
  char cVar2;
  
  uVar1 = (ushort)c18_tmp0;
  c18_tmp0 = (char)(uVar1 * param_1);
  cVar2 = (char)(uVar1 * param_1 >> 8);
  c18_tmp1 = c18_tmp1 * param_1 + cVar2;
  return cVar2;
}

