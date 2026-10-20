// address 0x00acd2  size 12 bytes
// callers: 00acde,

/* Compute cold cup portion time (QTYCOLDWATER) */

void portion_calc_cold_cup(void)

{
  mod_chain_mod_to_dispense_re_mod_get_local4_afc2(0x3e);
  portion_calc_flow();
  mod_to_portion_scale_b04c();
  mod_set_portion_hot_lo_afd2();
  return;
}

