// address 0x002632  size 18 bytes
// callers: 00127a,000458,

/* Auto: reads c18_tmp1,c18_tmp0; 7 instr */

char ui_get_c18_tmp1_2632(byte param_1)

{
  ushort uVar1;
  char cVar2;
  
  uVar1 = (ushort)c18_tmp0;
  c18_tmp0 = (char)(uVar1 * param_1);
  cVar2 = (char)(uVar1 * param_1 >> 8);
  c18_tmp1 = c18_tmp1 * param_1 + cVar2;
  return cVar2;
}

