// address 0x00fc24  size 28 bytes
// callers: 00bac8,00a414,001e3e,00a988,00a91a,00a90e,

/* Auto: compiler fragment: CLRF 0x0005,ACCESS ; MOVLW #0x8 ; MOVWF INDF1,ACCESS ; BCF
   STATUS,#0x0,ACCESS ; RLCF 0x0009,f,ACCESS ; RLCF 0x0005,f,ACCESS ; MOVF 0x000e,w,ACCESS ; SUBWF
   0x0005,w,ACCESS ; BNC 0x00fc3a ; MOVWF 0x0005,ACCESS ; INCF 0x0009,f,ACCESS */

byte mod_shift_multibyte_fc24(void)

{
  byte bVar1;
  byte bVar2;
  bool bVar3;
  char cVar4;
  
  math_rem_hi = 0;
  cVar4 = '\b';
  bVar3 = false;
  do {
    bVar1 = math_aarg_hi << 1 | bVar3;
    bVar2 = math_rem_hi << 1 | (char)math_aarg_hi < '\0';
    math_rem_hi = bVar2;
    math_aarg_hi = bVar1;
    if (math_barg_hi <= bVar2) {
      math_aarg_hi = bVar1 + 1;
      math_rem_hi = bVar2 - math_barg_hi;
    }
    bVar3 = math_barg_hi <= bVar2 && 0xfe < bVar1;
    cVar4 = cVar4 + -1;
  } while (cVar4 != '\0');
  return bVar2 - math_barg_hi;
}

