// address 0x00f4dc  size 60 bytes
// callers: 00beae,00e2fc,

/* C18 runtime: 16 x 16 bit multiply */

undefined1 __mul16(void)

{
  byte bVar1;
  byte bVar2;
  byte bVar3;
  byte bVar4;
  byte bVar5;
  bool bVar6;
  bool bVar7;
  
  math_tmp12 = math_aarg_lo;
  bVar4 = (byte)((ushort)math_barg_lo * (ushort)math_aarg_lo >> 8);
  math_res0 = (char)((ushort)math_barg_lo * (ushort)math_aarg_lo);
  bVar1 = (byte)((ushort)math_barg_hi * (ushort)math_aarg_hi);
  bVar2 = (byte)((ushort)math_barg_lo * (ushort)math_aarg_hi);
  bVar6 = CARRY1(bVar4,bVar2);
  bVar4 = bVar4 + bVar2;
  bVar5 = (byte)((ushort)math_barg_lo * (ushort)math_aarg_hi >> 8);
  bVar2 = bVar1 + bVar5 + bVar6;
  bVar3 = (byte)((ushort)math_barg_hi * (ushort)math_aarg_lo);
  bVar7 = CARRY1(bVar4,bVar3);
  math_res1 = bVar4 + bVar3;
  bVar4 = (byte)((ushort)math_barg_hi * (ushort)math_aarg_lo >> 8);
  math_aarg_lo = bVar2 + bVar4 + bVar7;
  math_aarg_hi = (char)((ushort)math_barg_hi * (ushort)math_aarg_hi >> 8) +
                 (CARRY1(bVar1,bVar6) || CARRY1(bVar5,bVar1 + bVar6)) +
                 (CARRY1(bVar2,bVar7) || CARRY1(bVar4,bVar2 + bVar7));
  return 0;
}

