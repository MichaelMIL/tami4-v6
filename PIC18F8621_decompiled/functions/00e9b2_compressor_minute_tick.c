// address 0x00e9b2  size 136 bytes
// callers: 00b104,

/* Per minute: run time, maximum run time (TCOMPMAXON) then forced pause (TCOMPPAUSEMIN) */

byte compressor_minute_tick(byte param_1)

{
  byte bVar1;
  BADSPACEBASE *in_FSR1;
  undefined1 *puVar2;
  byte bVar3;
  char cVar4;
  bool bVar5;
  bool bVar6;
  
  bVar3 = compressor_run_minutes;
  if ((outputs_shadow & 0x40) == 0) {
    return param_1;
  }
  c18_tmp0 = compressor_run_minutes;
  c18_tmp1 = 0;
  bVar5 = 0xfe < compressor_run_minutes != true;
  if (!bVar5) {
    compressor_run_minutes = compressor_run_minutes + 1;
  }
  bVar5 = bVar5 || 0xfe < bVar3;
  if (compressor_maxon_hi != 0 || compressor_maxon_lo != 0) {
    bVar6 = compressor_maxon_lo != 0;
    compressor_maxon_lo = compressor_maxon_lo - 1;
    bVar5 = compressor_maxon_hi != ~bVar6;
    compressor_maxon_hi = compressor_maxon_hi - ~bVar6;
  }
  if ((compressor_maxon_hi | compressor_maxon_lo) != 0) {
    c18_tmp0 = bVar3;
    c18_tmp1 = 0;
    return compressor_maxon_hi | compressor_maxon_lo;
  }
  bVar3 = PORTG;
  PORTG = bVar3 & ~RG3;
  outputs_shadow = outputs_shadow & 0xbf;
  bVar1 = 0;
  compressor_output_enable = 0;
  bVar3 = is_factory_jumper(0);
  if (bVar3 == 0) {
    cVar4 = compressor_read_param(0x2d);
    bVar3 = compressor_set_offdelay(cVar4 * '\x06');
    if ((bDATA00e3 & 0x80) == 0) {
      bVar5 = bDATA00e3 != ~(bVar3 <= stat_CSS);
      bVar3 = bDATA00e3 - ~(bVar3 <= stat_CSS);
    }
    else {
      bVar5 = false;
    }
    if (bVar5 != false) goto LAB_CODE_00ea1c;
    bVar3 = 0xc;
    stat_CSS = 0xc;
  }
  else {
    bVar1 = 1;
    compressor_offdelay_lo = 0;
  }
  *(undefined1 *)((ushort)bVar1 * 0x100 + 0xe3) = 0;
LAB_CODE_00ea1c:
  puVar2 = (undefined1 *)((short)in_FSR1 + 1);
  *(undefined1 *)in_FSR1 = compressor_offdelay_lo;
  fan_set_runon_minutes(bVar3);
  *puVar2 = *puVar2;
  puVar2[-1] = 0;
  ui_get_ui_compressor_indicator_4bd8();
  *puVar2 = *puVar2;
  bVar3 = compressor_fault << 1 | bVar5;
  if (-1 < compressor_fault) {
    bVar3 = 0x84;
    compressor_fault = -0x7c;
  }
  return bVar3;
}

