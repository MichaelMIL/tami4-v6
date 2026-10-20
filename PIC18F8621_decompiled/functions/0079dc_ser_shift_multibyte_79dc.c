// address 0x0079dc  size 14 bytes
// callers: 006e5c,

/* Auto: compiler fragment: BCF STATUS,#0x0,ACCESS ; RRCF 0x0017,f,ACCESS ; RRCF 0x0016,f,ACCESS ;
   RRCF 0x0015,f,ACCESS ; RRCF 0x0014,f,ACCESS ; DECF WREG,f,ACCESS ; RETURN 0x0 */

char ser_shift_multibyte_79dc(char param_1)

{
  byte bVar1;
  byte bVar2;
  byte bVar3;
  
  bVar3 = c18_tmp3;
  bVar2 = c18_tmp2;
  bVar1 = c18_tmp1;
  c18_tmp3 = c18_tmp3 >> 1;
  c18_tmp2 = c18_tmp2 >> 1 | bVar3 << 7;
  c18_tmp1 = c18_tmp1 >> 1 | bVar2 << 7;
  c18_tmp0 = c18_tmp0 >> 1 | bVar1 << 7;
  return param_1 + -1;
}

