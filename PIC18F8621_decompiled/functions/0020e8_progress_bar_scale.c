// address 0x0020e8  size 92 bytes
// callers: 0028fe,001d5e,001d9e,001e3e,

/* Scale a value to bar width */

void progress_bar_scale(char param_1)

{
  BADSPACEBASE *in_FSR1;
  
  c18_tmp4 = progress_bar_y;
  c18_tmp5 = 0;
  math_aarg_lo = (byte)((ushort)c18_tmp2 * (ushort)progress_bar_y);
  math_aarg_hi = (char)((ushort)c18_tmp2 * (ushort)progress_bar_y >> 8) + param_1 * progress_bar_y;
  math_barg_lo = c18_tmp6;
  math_barg_hi = c18_tmp7;
  c18_tmp0 = math_aarg_lo;
  c18_tmp1 = math_aarg_hi;
  c18_tmp3 = param_1;
  __divs16();
  menu_value_min_lo = c18_tmp8 + math_aarg_lo;
  menu_value_min_hi = c18_tmp9 + math_aarg_hi + CARRY1(c18_tmp8,math_aarg_lo);
  *(char *)in_FSR1 = menu_value_min_lo;
  *(undefined1 *)((short)in_FSR1 + 1) = 0x4c;
  *(undefined1 *)((short)in_FSR1 + 2) = 1;
  gfx_bitmap_blit();
  ui_pop3_return_2b9c();
  return;
}

