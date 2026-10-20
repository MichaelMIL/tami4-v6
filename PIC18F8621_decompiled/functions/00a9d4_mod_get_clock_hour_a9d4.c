// address 0x00a9d4  size 14 bytes
// callers: 00a312,00a826,

/* Auto: reads clock_hour; 5 instr */

void mod_get_clock_hour_a9d4(void)

{
  mod_frag_aa4e();
  math_aarg_hi = clock_hour;
  mod_div_helper_a90e();
  math_aarg_hi = clock_hour;
  return;
}

