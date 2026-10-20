// address 0x00beae  size 230 bytes
// callers: 00bf94,

/* Convert raw ADC to deg C via NTC table (FF=open, FE=short, 81=out of range) */

void ntc_table_lookup(void)

{
  undefined1 *puVar1;
  BADSPACEBASE *in_FSR2;
  BADSPACEBASE *in_FSR1;
  undefined1 *puVar2;
  byte bVar3;
  char cVar4;
  byte bVar5;
  byte in_TABLAT;
  byte *in_TBLPTR;
  bool bVar6;
  
  mod_c18_prologue_c116();
  *(undefined1 *)in_FSR1 = *(undefined1 *)in_FSR1;
  puVar2 = (undefined1 *)((short)in_FSR1 + 2);
  *(undefined1 *)((short)in_FSR1 + 1) = *(undefined1 *)((short)in_FSR1 + 1);
  if (adc_raw_lo == 0xff) {
    if (adc_raw_hi == 3) {
      puVar2 = (undefined1 *)((short)in_FSR1 + 2);
      cVar4 = -1;
      goto LAB_CODE_00bf8e;
    }
  }
  bVar5 = adc_raw_hi | adc_raw_lo;
  puVar1 = (undefined1 *)((short)in_FSR1 + 2);
  if (bVar5 == 0) {
    cVar4 = -2;
  }
  else {
    while( true ) {
      puVar2 = puVar1;
      bVar3 = mod_get_c18_tmp0_c0f4(bVar5);
      bVar5 = ~(bVar3 <= adc_raw_lo);
      if (adc_raw_hi < bVar5 || c18_tmp1 < adc_raw_hi - bVar5) break;
      cVar4 = mod_get_c18_tmp0_c0f4((adc_raw_hi - c18_tmp1) - ~(bVar3 <= adc_raw_lo));
      if (c18_tmp1 == 0 && cVar4 == '\0') {
        cVar4 = -0x7f;
        goto LAB_CODE_00bf8e;
      }
      bVar6 = 0xf5 < ntc_table_ptr_lo;
      ntc_table_ptr_lo = ntc_table_ptr_lo + 10;
      bVar5 = 0;
      ntc_table_ptr_hi = ntc_table_ptr_hi + bVar6;
      puVar1 = puVar2;
    }
    *(byte *)in_FSR2 = adc_raw_lo;
    *(byte *)((short)in_FSR2 + 1) = adc_raw_hi;
    mod_get_ntc_table_ptr_lo_c144();
    mod_get_TBLPTRL_c14e(8);
    c18_tmp12 = in_TABLAT;
    c18_tmp13 = *in_TBLPTR;
    bVar5 = c18_tmp13;
    mod_get_ntc_table_ptr_lo_c144();
    mod_get_TBLPTRL_c14e(4);
    c18_tmp10 = bVar5;
    c18_tmp11 = *in_TBLPTR;
    bVar5 = c18_tmp11;
    mod_get_ntc_table_ptr_lo_c144();
    mod_get_TBLPTRL_c14e(6);
    c18_tmp8 = bVar5;
    c18_tmp9 = *in_TBLPTR;
    mod_get_ntc_table_ptr_lo_c144();
    c18_tmp6 = *in_TBLPTR;
    c18_tmp7 = in_TBLPTR[1];
    math_aarg_lo = c18_tmp6 - *(byte *)in_FSR2;
    math_aarg_hi = (c18_tmp7 - *(byte *)((short)in_FSR2 + 1)) - ~(*(byte *)in_FSR2 <= c18_tmp6);
    math_barg_lo = c18_tmp8;
    math_barg_hi = c18_tmp9;
    c18_tmp4 = math_aarg_lo;
    c18_tmp5 = math_aarg_hi;
    __mul16();
    c18_tmp2 = math_res0;
    c18_tmp3 = math_res1;
    math_aarg_lo = math_res0;
    math_aarg_hi = math_res1;
    math_barg_lo = c18_tmp10;
    math_barg_hi = c18_tmp11;
    __divu16();
    bVar6 = CARRY1(c18_tmp12,math_aarg_lo);
    math_aarg_lo = c18_tmp12 + math_aarg_lo;
    math_aarg_hi = c18_tmp13 + math_aarg_hi + bVar6;
    math_barg_lo = 10;
    math_barg_hi = 0;
    c18_tmp0 = math_aarg_lo;
    c18_tmp1 = math_aarg_hi;
    __divu16();
    cVar4 = math_aarg_lo;
  }
LAB_CODE_00bf8e:
  *puVar2 = *puVar2;
  puVar2[-1] = puVar2[-1];
  mod_c18_epilogue_c138(cVar4);
  return;
}

