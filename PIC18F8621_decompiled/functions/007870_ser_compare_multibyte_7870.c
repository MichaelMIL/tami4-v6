// address 0x007870  size 32 bytes
// callers: 007a26,007a58,

/* Auto: compiler fragment: MOVWF 0x001d,ACCESS ; CLRF 0x001e,ACCESS ; CLRF 0x001f,ACCESS ; MOVF
   0x001c,w,ACCESS ; SUBWF 0x003c,w,ACCESS ; MOVWF 0x0014,ACCESS ; MOVF 0x001d,w,ACCESS ; SUBWFB
   0x003d,w,ACCESS ; MOVWF 0x0015,ACCESS ; MOVF 0x001e,w,ACCESS ; SUBW */

char ser_compare_multibyte_7870(byte param_1)

{
  byte bVar1;
  bool bVar2;
  
  c18_tmp9 = param_1;
  c18_tmp10 = 0;
  c18_tmp11 = 0;
  c18_tmp0 = serial_ptr_lo - c18_tmp8;
  bVar1 = ~(c18_tmp8 <= serial_ptr_lo);
  bVar2 = serial_ptr_hi < bVar1 || param_1 < serial_ptr_hi - bVar1;
  c18_tmp1 = (serial_ptr_hi - param_1) - ~(c18_tmp8 <= serial_ptr_lo);
  c18_tmp2 = c18_tmp6 - ~bVar2;
  c18_tmp3 = c18_tmp7 - ~(c18_tmp6 != ~bVar2);
  return c18_tmp3;
}

