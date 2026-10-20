// address 0x00f458  size 32 bytes
// callers: 00f478,

/* Auto: compiler fragment: NEGF 0x0006,ACCESS ; COMF 0x0007,f,ACCESS ; COMF 0x0008,f,ACCESS ; COMF
   0x0009,f,ACCESS ; CLRF WREG,ACCESS ; ADDWFC 0x0007,f,ACCESS ; ADDWFC 0x0008,f,ACCESS ; ADDWFC
   0x0009,f,ACCESS ; NEGF 0x0002,ACCESS ; COMF 0x0003,f,ACCESS ; CO */

undefined1 mod_frag_f458(void)

{
  bool bVar1;
  byte bVar2;
  byte bVar3;
  
  math_res0 = -math_res0;
  bVar2 = ~math_res1;
  bVar3 = ~math_aarg_lo;
  bVar1 = CARRY1(bVar2,'\0' < math_res0);
  math_res1 = bVar2 + ('\0' < math_res0);
  math_aarg_lo = bVar3 + bVar1;
  math_aarg_hi = ~math_aarg_hi + CARRY1(bVar3,bVar1);
  math_tmp2 = -math_tmp2;
  bVar2 = ~math_tmp3;
  bVar3 = ~math_rem_lo;
  bVar1 = CARRY1(bVar2,'\0' < math_tmp2);
  math_tmp3 = bVar2 + ('\0' < math_tmp2);
  math_rem_lo = bVar3 + bVar1;
  math_rem_hi = ~math_rem_hi + CARRY1(bVar3,bVar1);
  return 0;
}

