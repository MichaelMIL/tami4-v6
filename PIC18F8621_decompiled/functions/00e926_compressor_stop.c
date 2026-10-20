// address 0x00e926  size 100 bytes
// callers: 00e8ae,00d794,003b12,00da64,00d174,

/* WARNING: Restarted to delay deadcode elimination for space: DATA */
/* Stop compressor, start restart delay, log run time */

undefined1 compressor_stop(void)

{
  char cVar1;
  byte bVar2;
  BADSPACEBASE *in_FSR1;
  undefined1 *puVar3;
  byte bVar4;
  bool bVar5;
  
  bVar2 = 0xe;
  if ((outputs_shadow & 0x40) == 0) {
    return 1;
  }
  bVar4 = is_factory_jumper();
  if (bVar4 == 0) {
    compressor_read_param(9);
    bVar4 = compressor_set_offdelay();
    if ((compressor_offdelay_b_hi & 0x80) == 0) {
      bVar5 = compressor_offdelay_b_hi != ~(bVar4 <= compressor_offdelay_b);
      bVar4 = compressor_offdelay_b_hi - ~(bVar4 <= compressor_offdelay_b);
    }
    else {
      bVar5 = false;
    }
    if (bVar5) goto LAB_CODE_00e956;
    bVar4 = 0xc;
    compressor_offdelay_b = 0xc;
  }
  else {
    bVar2 = 1;
    compressor_offdelay_lo = 0;
  }
  *(undefined1 *)((ushort)bVar2 * 0x100 + 0xe3) = 0;
LAB_CODE_00e956:
  bVar2 = PORTG;
  PORTG = bVar2 & ~RG3;
  outputs_shadow = outputs_shadow & 0xbf;
  fan_start_runon(bVar4);
  puVar3 = (undefined1 *)((short)in_FSR1 + 1);
  *(undefined1 *)in_FSR1 = 0;
  ui_get_ui_compressor_indicator_4bd8();
  *puVar3 = *puVar3;
  puVar3[-1] = 0xc;
  stat_counter_save();
  *puVar3 = *puVar3;
  cVar1 = stat_CMM - compressor_run_minutes;
  if (stat_CMM < compressor_run_minutes) {
    stat_CMM = compressor_run_minutes;
    puVar3[-1] = 0;
    stat_byte_save(cVar1);
    *puVar3 = *puVar3;
  }
  return 0;
}

