// address 0x00a9b2  size 16 bytes
// callers: 00a312,00a826,

/* Auto: reads clock_minute; 5 instr */

void mod_get_clock_minute_a9b2(void)

{
  mod_frag_aa4e();
  math_aarg_hi = clock_minute;
  mod_div_helper_a90e();
  math_aarg_hi = clock_minute;
  mod_div_helper_a988();
  return;
}

