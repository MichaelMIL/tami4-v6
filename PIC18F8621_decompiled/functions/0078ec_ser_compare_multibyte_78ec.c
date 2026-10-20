// address 0x0078ec  size 18 bytes
// callers: 006e5c,

/* Auto: compiler fragment: MOVF 0x0018,w,ACCESS ; SUBWF 0x0014,w,ACCESS ; MOVF 0x0019,w,ACCESS ;
   SUBWFB 0x0015,w,ACCESS ; MOVF 0x001a,w,ACCESS ; SUBWFB 0x0016,w,ACCESS ; MOVF 0x001b,w,ACCESS ;
   SUBWFB 0x0017,w,ACCESS ; RETURN 0x0 */

char ser_compare_multibyte_78ec(void)

{
  byte bVar1;
  
  bVar1 = ~(c18_tmp1 < (byte)~(c18_tmp4 <= c18_tmp0) ||
           c18_tmp5 < c18_tmp1 - ~(c18_tmp4 <= c18_tmp0));
  return (c18_tmp3 - c18_tmp7) - ~(c18_tmp2 < bVar1 || c18_tmp6 < c18_tmp2 - bVar1);
}

