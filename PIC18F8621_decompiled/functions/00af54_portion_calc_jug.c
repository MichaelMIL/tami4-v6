// address 0x00af54  size 16 bytes
// callers: 00af64,

/* Compute jug portion time (QTYJUGWATER) */

void portion_calc_jug(void)

{
  mod_chain_mod_to_dispense_re_mod_get_local4_afc2(0x43);
  portion_calc_flow();
  mod_get_local3_affc();
  portion_scale(100);
  mod_set_portion_hot_lo_afd2();
  return;
}

