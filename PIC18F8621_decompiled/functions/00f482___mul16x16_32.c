// address 0x00f482  size 68 bytes
// callers: 0024ea,

/* WARNING: Instruction at (CODE,0x00f4c4) overlaps instruction at (CODE,0x00f4c2)
    */
/* C18 runtime: 16x16 -> 32-bit multiply */

undefined1 __mul16x16_32(void)

{
  char cVar1;
  byte bVar2;
  byte bVar3;
  byte bVar4;
  byte bVar5;
  byte bVar6;
  byte bVar7;
  bool bVar8;
  bool bVar9;
  
  bVar2 = math_aarg_hi;
  math_tmp13 = math_aarg_hi;
  math_tmp12 = math_aarg_lo;
  bVar6 = (byte)((ushort)math_barg_lo * (ushort)math_aarg_lo >> 8);
  math_res0 = (char)((ushort)math_barg_lo * (ushort)math_aarg_lo);
  bVar3 = (byte)((ushort)math_barg_hi * (ushort)math_aarg_hi);
  bVar4 = (byte)((ushort)math_barg_lo * (ushort)math_aarg_hi);
  bVar8 = CARRY1(bVar6,bVar4);
  bVar6 = bVar6 + bVar4;
  bVar7 = (byte)((ushort)math_barg_lo * (ushort)math_aarg_hi >> 8);
  bVar4 = bVar3 + bVar7 + bVar8;
  bVar5 = (byte)((ushort)math_barg_hi * (ushort)math_aarg_lo);
  bVar9 = CARRY1(bVar6,bVar5);
  math_res1 = bVar6 + bVar5;
  bVar5 = (byte)((ushort)math_barg_hi * (ushort)math_aarg_lo >> 8);
  bVar6 = bVar4 + bVar5 + bVar9;
  cVar1 = (char)((ushort)math_barg_hi * (ushort)math_aarg_hi >> 8) +
          (CARRY1(bVar3,bVar8) || CARRY1(bVar7,bVar3 + bVar8)) +
          (CARRY1(bVar4,bVar9) || CARRY1(bVar5,bVar4 + bVar9));
  bVar4 = bVar6;
  if ((math_barg_hi & 0x80) != 0) {
    bVar4 = bVar6 - math_aarg_lo;
    cVar1 = (cVar1 - math_aarg_hi) - ~(math_aarg_lo <= bVar6);
  }
  math_aarg_hi = cVar1;
  math_aarg_lo = bVar4;
  if ((bVar2 & 0x80) != 0) {
    bVar8 = math_barg_lo <= math_aarg_lo;
    math_aarg_lo = math_aarg_lo - math_barg_lo;
    math_aarg_hi = (math_aarg_hi - math_barg_hi) - ~bVar8;
    return 0;
  }
  return 0;
}

