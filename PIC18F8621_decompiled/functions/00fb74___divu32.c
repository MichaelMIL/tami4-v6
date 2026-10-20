// address 0x00fb74  size 72 bytes
// callers: 00f43a,

/* C18 runtime: 32-bit unsigned divide */

byte __divu32(void)

{
  byte bVar1;
  byte bVar2;
  bool bVar3;
  bool bVar4;
  bool bVar5;
  char cVar6;
  
  math_rem_hi = 0;
  math_rem_lo = 0;
  math_tmp3 = 0;
  math_tmp2 = 0;
  cVar6 = ' ';
  bVar3 = false;
  do {
    bVar4 = (char)math_res0 < '\0';
    math_res0 = math_res0 << 1 | bVar3;
    bVar3 = (char)math_res1 < '\0';
    math_res1 = math_res1 << 1 | bVar4;
    bVar4 = (char)math_aarg_lo < '\0';
    math_aarg_lo = math_aarg_lo << 1 | bVar3;
    bVar3 = (char)math_aarg_hi < '\0';
    math_aarg_hi = math_aarg_hi << 1 | bVar4;
    bVar4 = (char)math_tmp2 < '\0';
    math_tmp2 = math_tmp2 << 1 | bVar3;
    bVar3 = (char)math_tmp3 < '\0';
    math_tmp3 = math_tmp3 << 1 | bVar4;
    bVar4 = (char)math_rem_lo < '\0';
    math_rem_lo = math_rem_lo << 1 | bVar3;
    math_rem_hi = math_rem_hi << 1 | bVar4;
    bVar1 = ~(math_tmp3 < (byte)~(math_aarg_b3 <= math_tmp2) ||
             math_barg_b0 < math_tmp3 - ~(math_aarg_b3 <= math_tmp2));
    bVar5 = math_rem_lo < bVar1 || math_barg_lo < math_rem_lo - bVar1;
    bVar1 = ~bVar5;
    bVar4 = math_barg_hi < math_rem_hi - bVar1;
    bVar3 = math_rem_hi < bVar1 || bVar4;
    bVar2 = (math_rem_hi - math_barg_hi) - ~bVar5;
    if (math_rem_hi < bVar1 || bVar4) {
      bVar3 = math_aarg_b3 <= math_tmp2;
      math_tmp2 = math_tmp2 - math_aarg_b3;
      bVar1 = ~bVar3;
      bVar4 = math_tmp3 < bVar1 || math_barg_b0 < math_tmp3 - bVar1;
      math_tmp3 = (math_tmp3 - math_barg_b0) - ~bVar3;
      bVar1 = ~bVar4;
      bVar3 = math_rem_lo < bVar1;
      bVar1 = math_rem_lo - bVar1;
      math_rem_lo = (math_rem_lo - math_barg_lo) - ~bVar4;
      math_rem_hi = (math_rem_hi - math_barg_hi) - ~(bVar3 || math_barg_lo < bVar1);
      bVar3 = 0xfe < math_res0;
      math_res0 = math_res0 + 1;
      bVar2 = math_barg_hi;
    }
    cVar6 = cVar6 + -1;
  } while (cVar6 != '\0');
  return bVar2;
}

