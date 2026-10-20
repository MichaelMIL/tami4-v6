// address 0x004cc2  size 66 bytes
// callers: 003584,

/* Filter usage from FWU counter and WATERFLOW */

void filter_usage_calc(void)

{
  ui_stack_adjust_4f80();
  math_aarg_b3 = ui_to_eeprom_read_param_4f64(0x26);
  c18_tmp5 = 0;
  c18_tmp6 = 0;
  c18_tmp7 = 0;
  math_res0 = stat_IWS;
  math_res1 = DAT_DATA_00bb;
  math_aarg_lo = DAT_DATA_00bc;
  math_aarg_hi = DAT_DATA_00bd;
  math_barg_b0 = 0;
  math_barg_lo = 0;
  math_barg_hi = 0;
  c18_tmp4 = math_aarg_b3;
  __mul32();
  c18_tmp0 = math_tmp2;
  c18_tmp1 = math_tmp3;
  c18_tmp2 = math_rem_lo;
  c18_tmp3 = math_rem_hi;
  return;
}

