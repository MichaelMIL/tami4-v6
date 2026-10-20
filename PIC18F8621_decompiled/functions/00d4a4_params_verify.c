// address 0x00d4a4  size 140 bytes
// callers: 00b256,

/* Check parameter values against EEPROM min/max at startup (inferred) */

char params_verify(void)

{
  BADSPACEBASE *in_FSR1;
  undefined1 *puVar1;
  byte bVar7;
  undefined1 *puVar2;
  undefined1 *puVar3;
  undefined1 *puVar4;
  undefined1 *puVar5;
  undefined1 *puVar6;
  byte unaff_C;
  bool bVar8;
  
  mod_push_args_32_00_01_d700();
  puVar1 = (undefined1 *)((short)in_FSR1 + 1);
  *(undefined1 *)in_FSR1 = 0;
  mod_to_eeprom_read_byte_d724();
  bVar7 = (byte)((ushort)puVar1 >> 8);
  if ((unaff_C & 1) == 0) {
    puVar2 = (undefined1 *)((ushort)puVar1 & 0xff00);
    bVar7 = (byte)((ushort)(puVar2 + -1) >> 8);
    *puVar2 = *puVar2;
  }
  puVar4 = (undefined1 *)((ushort)bVar7 << 8);
  fault_code = c18_tmp0;
  if (c18_tmp0 < '\0') {
    return c18_tmp0;
  }
  if (adc_raw_lo == '\0') {
    return '\0';
  }
  for (adc_raw_hi = 1; adc_raw_hi < 0x4b; adc_raw_hi = adc_raw_hi + 1) {
    mod_get_TBLPTRL_d6a0(adc_raw_hi);
    mod_get_TBLPTRL_d6d2(3);
    mod_to_eeprom_write_byte_b_d740(adc_raw_hi);
    puVar3 = (undefined1 *)((ushort)puVar4 & 0xff00);
    puVar4 = puVar3 + -1;
    *puVar3 = *puVar3;
    mod_shift_multibyte_d75e();
  }
  adc_raw_hi = 1;
  while( true ) {
    if (0x4a < adc_raw_hi) {
      return '\0';
    }
    mod_get_TBLPTRL_d6a0(adc_raw_hi);
    mod_get_TBLPTRL_d6d2(5);
    bVar8 = 0xb4 < adc_raw_hi;
    mod_to_eeprom_write_byte_b_d740(adc_raw_hi + 0x4b);
    if (!bVar8) {
      puVar5 = (undefined1 *)((ushort)puVar4 & 0xff00);
      puVar4 = puVar5 + -1;
      *puVar5 = *puVar5;
    }
    mod_shift_multibyte_d75e();
    if (bVar8) break;
    mod_get_TBLPTRL_d6a0(adc_raw_hi);
    mod_get_TBLPTRL_d6d2(4);
    bVar8 = 0x69 < adc_raw_hi;
    mod_to_eeprom_write_byte_b_d740(adc_raw_hi + 0x96);
    if (!bVar8) {
      puVar6 = (undefined1 *)((ushort)puVar4 & 0xff00);
      puVar4 = puVar6 + -1;
      *puVar6 = *puVar6;
    }
    mod_shift_multibyte_d75e();
    if (bVar8) {
      return fault_code;
    }
    adc_raw_hi = adc_raw_hi + 1;
  }
  return fault_code;
}

