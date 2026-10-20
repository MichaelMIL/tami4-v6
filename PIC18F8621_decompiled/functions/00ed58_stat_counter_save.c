// address 0x00ed58  size 60 bytes
// callers: 006e5c,00f8da,00f84c,00a588,00d174,00aa56,00c606,00e76a,002904,00dcce,00c936,00e926,00f79c,00fa30,

/* Save 32-bit usage counter [id] to EEPROM */

void stat_counter_save(void)

{
  BADSPACEBASE *in_FSR1;
  byte bVar1;
  byte bVar2;
  
  adc_raw_lo = mod_c18_prologue_edc4();
  bVar1 = (byte)((ushort)adc_raw_lo * 4);
  c18_tmp0 = bVar1 + 0xb2;
  c18_tmp1 = (char)((ushort)adc_raw_lo * 4 >> 8) + (0x4d < bVar1);
  mod_get_c18_tmp0_edfc();
  *(undefined1 *)in_FSR1 = 4;
  bVar1 = (byte)((ushort)((short)in_FSR1 + 2) >> 8);
  *(undefined1 *)((short)in_FSR1 + 1) = 0;
  bVar2 = adc_raw_lo * '\x04';
  c18_tmp3 = 0;
  c18_tmp2 = bVar2 - 0x1c;
  stats_eeprom_write(0);
  if (bVar2 < 0x1c) {
    *(undefined1 *)((ushort)bVar1 << 8) = *(undefined1 *)((ushort)bVar1 << 8);
  }
  mod_c18_epilogue_edda(c18_tmp4);
  return;
}

