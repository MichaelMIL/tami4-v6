// address 0x00f4c6  size 22 bytes
// callers: (none: entry point, task, or reached via pointer)

/* Auto: compiler fragment: MOVF 0x0012,w,ACCESS ; SUBWF 0x0008,f,ACCESS ; MOVF 0x0013,w,ACCESS ;
   SUBWFB 0x0009,f,ACCESS ; BTFSS 0x0013,#0x7,ACCESS ; RETLW #0x0 ; MOVF 0x000d,w,ACCESS ; SUBWF
   0x0008,f,ACCESS ; MOVF 0x000e,w,ACCESS ; SUBWFB 0x0009,f,ACCESS ;  */

undefined1 mod_compare_multibyte_f4c6(void)

{
  byte bVar1;
  bool bVar2;
  
  bVar2 = math_tmp12 <= math_aarg_lo;
  bVar1 = math_aarg_lo - math_tmp12;
  math_aarg_lo = bVar1;
  math_aarg_hi = (math_aarg_hi - math_tmp13) - ~bVar2;
  if ((math_tmp13 & 0x80) == 0) {
    return 0;
  }
  math_aarg_lo = bVar1 - math_barg_lo;
  math_aarg_hi = (math_aarg_hi - math_barg_hi) - ~(math_barg_lo <= bVar1);
  return 0;
}

