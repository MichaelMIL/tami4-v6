// address 0x00f84c  size 34 bytes
// callers: 00da82,00aa56,

/* Cold water valve (RH2): close, update usage counters */

undefined1 cold_valve_close(void)

{
  byte bVar1;
  BADSPACEBASE *in_FSR1;
  undefined1 *puVar2;
  
  if ((outputs_shadow & 4) != 0) {
    bVar1 = PORTH;
    PORTH = bVar1 & ~RH2;
    outputs_shadow = outputs_shadow & 0xfb;
    cold_valve_open_flag = 0;
    puVar2 = &FramePointer10x0001;
    stat_counter_save();
    *puVar2 = *puVar2;
    mod_to_cooling_reset_pulldown_d47c();
  }
  return cold_valve_fault;
}

