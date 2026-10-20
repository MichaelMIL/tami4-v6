// address 0x00e7c4  size 116 bytes
// callers: 00b0aa,

/* WARNING: Restarted to delay deadcode elimination for space: DATA */
/* Every 10 ms: shift burst-fire pattern and drive RG0 */

byte heater_burst_tick(void)

{
  byte bVar1;
  BADSPACEBASE *in_FSR1;
  undefined1 *puVar2;
  byte bVar3;
  byte unaff_C;
  char cVar4;
  
  cVar4 = '\0';
  if ((heater_power_level != '\0') && (cVar4 = heater_holdoff, heater_holdoff == '\0')) {
    bVar3 = heater_zc_counter;
    if (heater_zc_counter != 0) {
      heater_zc_counter = heater_zc_counter - 1;
      return bVar3;
    }
    heater_zc_counter = heater_zc_cycle_len;
    bVar3 = 0;
    if (((heater_pattern_lo & 1) == 0) ||
       (bVar3 = heater_fault << 1 | unaff_C & 1, heater_fault < '\0')) {
      bVar1 = PORTG;
      PORTG = bVar1 & ~RG0;
      outputs_shadow = outputs_shadow & 0x7f;
    }
    else {
      if (heater_output_enable != '\0') {
        bVar3 = PORTG;
        PORTG = bVar3 | RG0;
        outputs_shadow = outputs_shadow | 0x80;
      }
      bVar3 = 1;
    }
    puVar2 = &FramePointer10x0001;
    ui_get_ui_heater_indicator_4bce(bVar3);
    *puVar2 = *puVar2;
    c18_tmp1 = heater_pattern_hi >> 1;
    c18_tmp0 = heater_pattern_lo >> 1 | heater_pattern_hi << 7;
    if ((heater_pattern_lo & 1) == 0) {
      c18_tmp3 = 0;
    }
    else {
      c18_tmp3 = 0x80;
    }
    c18_tmp2 = 0;
    heater_pattern_lo = c18_tmp0;
    heater_pattern_hi = c18_tmp3 | c18_tmp1;
    return heater_pattern_hi;
  }
  bVar3 = heater_output_off(cVar4);
  return bVar3;
}

