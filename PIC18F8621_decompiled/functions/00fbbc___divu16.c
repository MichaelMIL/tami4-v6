// address 0x00fbbc  size 44 bytes
// callers: 00127a,00beae,00f3ce,00e2fc,

/* C18 runtime: unsigned 16-bit divide, remainder in math_rem */

byte __divu16(void)

{
  byte bVar1;
  byte bVar2;
  bool bVar3;
  bool bVar4;
  char cVar5;
  
  math_rem_hi = 0;
  math_rem_lo = 0;
  cVar5 = '\x10';
  bVar3 = false;
  do {
    bVar4 = (char)math_aarg_lo < '\0';
    math_aarg_lo = math_aarg_lo << 1 | bVar3;
    bVar3 = (char)math_aarg_hi < '\0';
    math_aarg_hi = math_aarg_hi << 1 | bVar4;
    bVar4 = (char)math_rem_lo < '\0';
    math_rem_lo = math_rem_lo << 1 | bVar3;
    math_rem_hi = math_rem_hi << 1 | bVar4;
    bVar1 = ~(math_barg_lo <= math_rem_lo);
    bVar4 = math_barg_hi < math_rem_hi - bVar1;
    bVar3 = math_rem_hi < bVar1 || bVar4;
    bVar2 = (math_rem_hi - math_barg_hi) - ~(math_barg_lo <= math_rem_lo);
    if (math_rem_hi < bVar1 || bVar4) {
      bVar3 = math_barg_lo <= math_rem_lo;
      math_rem_lo = math_rem_lo - math_barg_lo;
      math_rem_hi = (math_rem_hi - math_barg_hi) - ~bVar3;
      bVar3 = 0xfe < math_aarg_lo;
      math_aarg_lo = math_aarg_lo + 1;
      bVar2 = math_barg_hi;
    }
    cVar5 = cVar5 + -1;
  } while (cVar5 != '\0');
  return bVar2;
}

