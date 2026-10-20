// address 0x00aeec  size 14 bytes
// callers: (none: entry point, task, or reached via pointer)

/* Start a measured cool (mixed) cup: TNORMALCOOLCUTOUT, QTYCOOLWATER */

void dispense_cool_cup(void)

{
  portion_target_temp = dispense_read_param(0x32);
  mod_chain_mod_to_dispense_re_mod_get_local4_afc2(0x34);
  portion_calc_mixed();
  return;
}

