// address 0x00ed94  size 48 bytes
// callers: 006e5c,00d174,00e926,

/* Save byte statistic [id] (0xF2+id) to EEPROM */

void stat_byte_save(void)

{
  BADSPACEBASE *in_FSR1;
  byte bVar1;
  bool bVar2;
  
  adc_raw_lo = mod_c18_prologue_edc4();
  c18_tmp1 = 0xd < adc_raw_lo;
  c18_tmp0 = adc_raw_lo - 0xe;
  mod_get_c18_tmp0_edfc();
  *(undefined1 *)in_FSR1 = 1;
  bVar1 = (byte)((ushort)((short)in_FSR1 + 2) >> 8);
  *(undefined1 *)((short)in_FSR1 + 1) = 0;
  c18_tmp3 = 0;
  bVar2 = adc_raw_lo < 0xdc;
  c18_tmp2 = adc_raw_lo + 0x24;
  stats_eeprom_write(1);
  if (bVar2) {
    *(undefined1 *)((ushort)bVar1 << 8) = *(undefined1 *)((ushort)bVar1 << 8);
  }
  mod_c18_epilogue_edda(c18_tmp4);
  return;
}

