// address 0x00a91a  size 20 bytes
// callers: 00a312,00a826,

/* Auto: Small wrapper around mod_get_clock_hour; 8 instr */

void mod_to_mod_get_clock_hour_a91a(void)

{
  mod_get_clock_hour_aa10(0xc);
  mod_shift_multibyte_fc24();
  local2 = math_aarg_hi;
  mod_get_clock_hour_aa10(0xc);
  return;
}

