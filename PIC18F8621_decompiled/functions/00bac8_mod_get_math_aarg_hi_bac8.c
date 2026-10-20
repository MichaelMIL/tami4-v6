// address 0x00bac8  size 24 bytes
// callers: 00b982,00b9be,

/* Auto: reads math_aarg_hi,anim_index; 10 instr */

char mod_get_math_aarg_hi_bac8(void)

{
  char in_FramePointer2_0000fffc;
  
  c18_tmp0 = 3;
  math_barg_hi = 3;
  math_aarg_hi = in_FramePointer2_0000fffc;
  mod_shift_multibyte_fc24();
  return anim_index - math_aarg_hi;
}

