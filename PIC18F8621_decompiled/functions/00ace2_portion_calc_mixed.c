// address 0x00ace2  size 354 bytes
// callers: 00aeec,00aefa,

/* WARNING: Restarted to delay deadcode elimination for space: DATA */
/* Compute hot/cold split to reach a target temperature */

undefined1 portion_calc_mixed(void)

{
  byte bVar1;
  BADSPACEBASE *in_FSR1;
  byte bVar2;
  bool bVar3;
  
  portion_cold_temp = cold_temp_read_ch5();
  bVar2 = hot_temp_read_top();
  portion_hot_temp = bVar2 - 2;
  *(undefined1 *)in_FSR1 = 1;
  if ((portion_cold_temp & 0x80) == 0) {
    bVar3 = *(byte *)in_FSR1 <= portion_cold_temp;
    bVar2 = portion_cold_temp - *(byte *)in_FSR1;
  }
  else {
    bVar3 = *(char *)in_FSR1 < '\0';
    bVar2 = *(char *)in_FSR1 << 1 | 1 < bVar2;
  }
  if (!bVar3) {
    bVar2 = 1;
    portion_cold_temp = 1;
  }
  portion_calc_flow(bVar2);
  bVar2 = portion_cold_temp;
  if ((cfg_systemconfig & 3) != 0) {
    *(byte *)in_FSR1 = portion_cold_temp;
    bVar1 = portion_hot_temp;
    if (((bVar2 ^ portion_target_temp) & 0x80) == 0) {
      bVar3 = *(byte *)in_FSR1 <= portion_target_temp;
    }
    else {
      bVar3 = *(char *)in_FSR1 < '\0';
    }
    if (bVar3) {
      *(byte *)in_FSR1 = portion_hot_temp;
      if (((bVar1 ^ portion_target_temp) & 0x80) == 0) {
        bVar3 = *(byte *)in_FSR1 < 0xfe || portion_target_temp < *(byte *)in_FSR1 + 2;
      }
      else {
        bVar3 = (char)portion_target_temp < '\0';
      }
      if (bVar3) {
        math_barg_lo = portion_hot_temp - portion_cold_temp;
        c18_tmp5 = 0;
        if ((math_barg_lo & 0x80) != 0) {
          c18_tmp5 = 0xff;
        }
        c18_tmp2 = portion_hot_temp - portion_target_temp;
        c18_tmp3 = '\0';
        if ((c18_tmp2 & 0x80) != 0) {
          c18_tmp3 = -1;
        }
        math_aarg_lo = (byte)((ushort)local3 * (ushort)c18_tmp2);
        math_aarg_hi = (char)((ushort)local3 * (ushort)c18_tmp2 >> 8) + local4 * c18_tmp2 +
                       local3 * c18_tmp3;
        math_barg_hi = c18_tmp5;
        c18_tmp0 = math_aarg_lo;
        c18_tmp1 = math_aarg_hi;
        c18_tmp4 = math_barg_lo;
        __divs16();
        c18_tmp0 = math_aarg_lo - 2;
        c18_tmp1 = math_aarg_hi - ~(1 < math_aarg_lo);
        portion_tmp1 = local3 - c18_tmp0;
        portion_tmp1_hi = (local4 - c18_tmp1) - ~(c18_tmp0 <= local3);
        portion_tmp0 = c18_tmp0;
        portion_tmp0_hi = c18_tmp1;
        portion_scale(10);
        portion_cold_lo = math_aarg_lo;
        portion_cold_hi = math_aarg_hi;
        c18_tmp0 = portion_tmp1;
        c18_tmp1 = portion_tmp1_hi;
        portion_scale(10);
        portion_hot_lo = math_aarg_lo;
        portion_hot_hi = math_aarg_hi;
        portion_cold2_lo = portion_cold_lo;
        portion_cold2_hi = portion_cold_hi;
        math_barg_lo = 2;
        math_barg_hi = 0;
        math_aarg_lo = portion_cold_lo;
        math_aarg_hi = portion_cold_hi;
        __divs16();
        portion_cold2_lo = math_aarg_lo;
        portion_cold2_hi = math_aarg_hi;
        bVar3 = math_aarg_lo <= portion_cold_lo;
        portion_cold_lo = portion_cold_lo - math_aarg_lo;
        portion_cold_hi = (portion_cold_hi - math_aarg_hi) - ~bVar3;
        if ((portion_hot_hi & 0x80) != 0 || portion_hot_hi == ~(1 < portion_hot_lo)) {
          portion_hot_lo = 2;
          portion_hot_hi = 0;
        }
        if (portion_cold_hi == 0 && portion_cold_lo == 0) {
          portion_cold_lo = 1;
          portion_cold_hi = 0;
        }
        if (math_aarg_hi == 0 && math_aarg_lo == 0) {
          portion_cold2_lo = 1;
          portion_cold2_hi = 0;
        }
        portion_mode = 1;
        dispense_cold_request();
        return 0;
      }
    }
  }
  portion_mode = 1;
  mod_to_portion_scale_b04c();
  mod_set_portion_hot_lo_afd2();
  dispense_request = dispense_request & 0xfb | 1;
  return 0;
}

