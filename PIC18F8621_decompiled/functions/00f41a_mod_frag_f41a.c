// address 0x00f41a  size 10 bytes
// callers: 004fdc,

/* WARNING: Instruction at (CODE,0x00f452) overlaps instruction at (CODE,0x00f450)
    */
/* Auto: compiler fragment: CLRF 0x0000,ACCESS ; CLRF WREG,ACCESS ; BTFSS 0x000e,#0x7,ACCESS ; GOTO
   0x00f434 */

undefined1 mod_frag_f41a(void)

{
  bool bVar1;
  byte bVar2;
  byte bVar3;
  undefined1 uVar4;
  
  math_sign = 0;
  if ((math_barg_hi & 0x80) != 0) {
    math_aarg_b3 = -math_aarg_b3;
    bVar2 = ~math_barg_b0;
    bVar3 = ~math_barg_lo;
    bVar1 = CARRY1(bVar2,'\0' < math_aarg_b3);
    math_barg_b0 = bVar2 + ('\0' < math_aarg_b3);
    math_barg_lo = bVar3 + bVar1;
    math_barg_hi = ~math_barg_hi + CARRY1(bVar3,bVar1);
    math_sign = 0xff;
  }
  if ((math_aarg_hi & 0x80) != 0) {
    math_res0 = -math_res0;
    bVar2 = ~math_res1;
    bVar3 = ~math_aarg_lo;
    bVar1 = CARRY1(bVar2,'\0' < math_res0);
    math_res1 = bVar2 + ('\0' < math_res0);
    math_aarg_lo = bVar3 + bVar1;
    math_aarg_hi = ~math_aarg_hi + CARRY1(bVar3,bVar1);
    math_sign = ~math_sign;
  }
  __divu32();
  if ((math_aarg_hi & 0x80) == 0) {
    if ((math_sign & 0x80) != 0) {
      math_res0 = -math_res0;
      bVar2 = ~math_res1;
      bVar3 = ~math_aarg_lo;
      bVar1 = CARRY1(bVar2,'\0' < math_res0);
      math_res1 = bVar2 + ('\0' < math_res0);
      math_aarg_lo = bVar3 + bVar1;
      math_aarg_hi = ~math_aarg_hi + CARRY1(bVar3,bVar1);
      math_tmp2 = -math_tmp2;
      bVar2 = ~math_tmp3;
      bVar3 = ~math_rem_lo;
      bVar1 = CARRY1(bVar2,'\0' < math_tmp2);
      math_tmp3 = bVar2 + ('\0' < math_tmp2);
      math_rem_lo = bVar3 + bVar1;
      math_rem_hi = ~math_rem_hi + CARRY1(bVar3,bVar1);
      return 0;
    }
    return 0;
  }
  uVar4 = mod_frag_f478();
  return uVar4;
}

