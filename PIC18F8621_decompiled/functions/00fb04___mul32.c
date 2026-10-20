// address 0x00fb04  size 112 bytes
// callers: 004cc2,

/* C18 runtime: 32-bit multiply */

char __mul32(void)

{
  byte bVar1;
  byte bVar2;
  byte bVar3;
  byte bVar4;
  byte bVar5;
  byte bVar6;
  byte bVar7;
  byte bVar8;
  bool bVar9;
  
  math_tmp2 = (char)((ushort)math_aarg_b3 * (ushort)math_res0);
  bVar7 = (byte)((ushort)math_aarg_b3 * (ushort)math_res0 >> 8);
  bVar2 = (byte)((ushort)math_barg_b0 * (ushort)math_res0);
  bVar1 = bVar7 + bVar2;
  bVar7 = (char)((ushort)math_barg_b0 * (ushort)math_res0 >> 8) + CARRY1(bVar7,bVar2);
  bVar3 = (byte)((ushort)math_barg_lo * (ushort)math_res0);
  bVar2 = bVar7 + bVar3;
  bVar4 = (byte)((ushort)math_aarg_b3 * (ushort)math_res1);
  bVar9 = CARRY1(bVar1,bVar4);
  math_tmp3 = bVar1 + bVar4;
  bVar8 = (byte)((ushort)math_aarg_b3 * (ushort)math_res1 >> 8);
  bVar4 = bVar2 + bVar8 + bVar9;
  bVar5 = (byte)((ushort)math_barg_b0 * (ushort)math_res1);
  bVar1 = bVar4 + bVar5;
  bVar6 = (byte)((ushort)math_aarg_b3 * (ushort)math_aarg_lo);
  math_rem_lo = bVar1 + bVar6;
  math_rem_hi = (char)((ushort)math_barg_lo * (ushort)math_res0 >> 8) + CARRY1(bVar7,bVar3) +
                math_barg_hi * math_res0 + (CARRY1(bVar2,bVar9) || CARRY1(bVar8,bVar2 + bVar9)) +
                (char)((ushort)math_barg_b0 * (ushort)math_res1 >> 8) + CARRY1(bVar4,bVar5) +
                math_barg_lo * math_res1 + (char)((ushort)math_aarg_b3 * (ushort)math_aarg_lo >> 8)
                + CARRY1(bVar1,bVar6) + math_barg_b0 * math_aarg_lo + math_aarg_b3 * math_aarg_hi;
  return math_aarg_b3 * math_aarg_hi;
}

