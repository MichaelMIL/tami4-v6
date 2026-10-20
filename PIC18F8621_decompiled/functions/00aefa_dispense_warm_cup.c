// address 0x00aefa  size 14 bytes
// callers: 005002,

/* Start a measured warm (mixed) cup: TNORMALWARMCUTOUT, QTYWARMWATER */

void dispense_warm_cup(void)

{
  portion_target_temp = dispense_read_param(0x33);
  mod_chain_mod_to_dispense_re_mod_get_local4_afc2(0x35);
  portion_calc_mixed();
  return;
}

