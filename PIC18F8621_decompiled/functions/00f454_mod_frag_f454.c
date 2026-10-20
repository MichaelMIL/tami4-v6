// address 0x00f454  size 4 bytes
// callers: (none: entry point, task, or reached via pointer)

/* Auto: compiler fragment: BTFSS 0x0000,#0x7,ACCESS ; RETLW #0x0 */

undefined1 mod_frag_f454(void)

{
  bool bVar1;
  byte bVar2;
  byte bVar3;
  
  if ((math_sign & 0x80) == 0) {
    return 0;
  }
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

