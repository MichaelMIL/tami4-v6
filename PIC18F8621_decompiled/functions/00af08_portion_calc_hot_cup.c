// address 0x00af08  size 54 bytes
// callers: 00af3e,

/* Compute hot cup portion time (QTYHOTWATER) */

void portion_calc_hot_cup(void)

{
  char cVar1;
  
  cVar1 = mod_to_dispense_read_param_b060(0x42);
  if (local4 == '\0' && cVar1 == '\0') {
    mod_get_cfg_systemconfig5_afe8(0);
    mod_to_dispense_read_param_b060(0x35);
  }
  if (local4 == '\0' && local3 == '\0') {
    mod_get_cfg_systemconfig5_afe8(0);
    mod_to_dispense_read_param_b060(0x34);
  }
  mod_get_local4_b02c();
  portion_calc_flow();
  mod_to_portion_scale_b04c();
  portion_hot_lo = math_aarg_lo;
  portion_hot_hi = math_aarg_hi;
  portion_cold2_lo = 0xff;
  portion_cold2_hi = 0xff;
  return;
}

