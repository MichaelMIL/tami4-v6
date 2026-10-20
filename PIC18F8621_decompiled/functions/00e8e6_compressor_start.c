// address 0x00e8e6  size 64 bytes
// callers: 00d174,

/* Start compressor (returns 0x83 if restart delay still running) */

char compressor_start(void)

{
  byte bVar1;
  BADSPACEBASE *in_FSR1;
  undefined1 *puVar2;
  bool bVar3;
  
  bVar3 = (char)compressor_offdelay_hi < '\0';
  if (!bVar3) {
    bVar1 = ~(compressor_offdelay_lo == '\0');
    bVar3 = bVar1 != 0 || compressor_offdelay_hi < -bVar1;
    if (bVar1 == 0 && compressor_offdelay_hi >= -bVar1) {
      return -0x7d;
    }
  }
  if (compressor_fault < '\0') {
    return compressor_fault;
  }
  if ((outputs_shadow & 0x40) != 0) {
    return '\x01';
  }
  compressor_load_maxon(compressor_fault << 1 | bVar3);
  compressor_start_flag = 0;
  heater_holdoff_5s();
  if (compressor_output_enable != '\0') {
    bVar1 = PORTG;
    PORTG = bVar1 | RG3;
    outputs_shadow = outputs_shadow | 0x40;
  }
  puVar2 = (undefined1 *)((short)in_FSR1 + 1);
  *(undefined1 *)in_FSR1 = 1;
  ui_get_ui_compressor_indicator_4bd8();
  *puVar2 = *puVar2;
  return '\0';
}

