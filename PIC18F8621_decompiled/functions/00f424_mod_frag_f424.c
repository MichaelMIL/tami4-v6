// address 0x00f424  size 22 bytes
// callers: (none: entry point, task, or reached via pointer)

/* WARNING: Instruction at (CODE,0x00f452) overlaps instruction at (CODE,0x00f450)
    */
/* Auto: compiler fragment: NEGF 0x000b,ACCESS ; COMF 0x000c,f,ACCESS ; COMF 0x000d,f,ACCESS ; COMF
   0x000e,f,ACCESS ; ADDWFC 0x000c,f,ACCESS ; ADDWFC 0x000d,f,ACCESS ; ADDWFC 0x000e,f,ACCESS ; COMF
   0x0000,f,ACCESS ; BTFSS 0x0009,#0x7,ACCESS ; GOTO 0x00f44a */

undefined1 mod_frag_f424(byte param_1)

{
  byte bVar1;
  byte bVar2;
  undefined1 uVar3;
  bool bVar4;
  bool bVar5;
  
  math_aarg_b3 = -math_aarg_b3;
  bVar4 = '\0' < math_aarg_b3;
  bVar1 = ~math_barg_b0;
  bVar2 = ~math_barg_lo;
  bVar5 = CARRY1(bVar1,bVar4) || CARRY1(param_1,bVar1 + bVar4);
  math_barg_b0 = bVar1 + param_1 + bVar4;
  math_barg_lo = bVar2 + param_1 + bVar5;
  math_barg_hi = ~math_barg_hi + param_1 + (CARRY1(bVar2,bVar5) || CARRY1(param_1,bVar2 + bVar5));
  bVar1 = ~math_sign;
  if ((math_aarg_hi & 0x80) != 0) {
    math_res0 = -math_res0;
    bVar4 = '\0' < math_res0;
    bVar1 = ~math_res1;
    bVar2 = ~math_aarg_lo;
    bVar5 = CARRY1(bVar1,bVar4) || CARRY1(param_1,bVar1 + bVar4);
    math_res1 = bVar1 + param_1 + bVar4;
    math_aarg_lo = bVar2 + param_1 + bVar5;
    math_aarg_hi = ~math_aarg_hi + param_1 + (CARRY1(bVar2,bVar5) || CARRY1(param_1,bVar2 + bVar5));
    bVar1 = math_sign;
  }
  math_sign = bVar1;
  __divu32();
  if ((math_aarg_hi & 0x80) == 0) {
    if ((math_sign & 0x80) != 0) {
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
    return 0;
  }
  uVar3 = mod_frag_f478();
  return uVar3;
}

