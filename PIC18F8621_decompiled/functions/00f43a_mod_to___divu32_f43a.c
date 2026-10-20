// address 0x00f43a  size 26 bytes
// callers: (none: entry point, task, or reached via pointer)

/* WARNING: Instruction at (CODE,0x00f452) overlaps instruction at (CODE,0x00f450)
    */
/* Auto: calls __divu32; 11 instr */

undefined1 mod_to___divu32_f43a(byte param_1)

{
  byte bVar1;
  byte bVar2;
  undefined1 uVar3;
  bool bVar4;
  bool bVar5;
  
  math_res0 = -math_res0;
  bVar4 = '\0' < math_res0;
  bVar1 = ~math_res1;
  bVar2 = ~math_aarg_lo;
  bVar5 = CARRY1(bVar1,bVar4) || CARRY1(param_1,bVar1 + bVar4);
  math_res1 = bVar1 + param_1 + bVar4;
  math_aarg_lo = bVar2 + param_1 + bVar5;
  math_aarg_hi = ~math_aarg_hi + param_1 + (CARRY1(bVar2,bVar5) || CARRY1(param_1,bVar2 + bVar5));
  math_sign = ~math_sign;
  __divu32();
  if ((math_aarg_hi & 0x80) != 0) {
    uVar3 = mod_frag_f478();
    return uVar3;
  }
  if ((math_sign & 0x80) == 0) {
    return 0;
  }
  math_res0 = -math_res0;
  bVar1 = ~math_res1;
  bVar2 = ~math_aarg_lo;
  bVar4 = CARRY1(bVar1,'\0' < math_res0);
  math_res1 = bVar1 + ('\0' < math_res0);
  math_aarg_lo = bVar2 + bVar4;
  math_aarg_hi = ~math_aarg_hi + CARRY1(bVar2,bVar4);
  math_tmp2 = -math_tmp2;
  bVar1 = ~math_tmp3;
  bVar2 = ~math_rem_lo;
  bVar4 = CARRY1(bVar1,'\0' < math_tmp2);
  math_tmp3 = bVar1 + ('\0' < math_tmp2);
  math_rem_lo = bVar2 + bVar4;
  math_rem_hi = ~math_rem_hi + CARRY1(bVar2,bVar4);
  return 0;
}

