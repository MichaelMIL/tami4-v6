// address 0x00afd2  size 16 bytes
// callers: 00ace2,00acd2,00af54,

/* Auto: writes portion_hot_lo,portion_hot_hi; reads math_aarg_lo,math_aarg_hi; 6 instr */

void mod_set_portion_hot_lo_afd2(void)

{
  portion_cold_lo = math_aarg_lo;
  portion_cold_hi = math_aarg_hi;
  portion_hot_lo = 0xff;
  portion_hot_hi = 0xff;
  return;
}

