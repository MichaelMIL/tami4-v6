// address 0x00f8da  size 64 bytes
// callers: 00da82,

/* Switch UV lamp off (RF6); log usage and lamp-fail counters */

undefined1 uv_lamp_off(void)

{
  byte bVar1;
  BADSPACEBASE *in_FSR1;
  undefined1 *puVar2;
  undefined1 *puVar3;
  
  if (((outputs_shadow & 0x20) != 0) && ((cfg_systemconfig & 8) != 0)) {
    bVar1 = PORTJ;
    if ((bVar1 & RJ1) == 0) {
      puVar2 = &FramePointer10x0001;
      stat_counter_inc();
      *puVar2 = *puVar2;
      puVar2[-1] = 8;
      stat_counter_save();
      in_FSR1 = (BADSPACEBASE *)(puVar2 + -1);
      *puVar2 = *puVar2;
    }
    bVar1 = PORTF;
    PORTF = bVar1 & ~RF6;
    outputs_shadow = outputs_shadow & 0xdf;
    puVar3 = (undefined1 *)((short)in_FSR1 + 1);
    *(undefined1 *)in_FSR1 = 7;
    stat_counter_save();
    *puVar3 = *puVar3;
    return uv_alarm_code;
  }
  return 0;
}

