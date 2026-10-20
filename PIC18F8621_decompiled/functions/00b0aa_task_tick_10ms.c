// address 0x00b0aa  size 90 bytes
// callers: (none: entry point, task, or reached via pointer)

/* Priority 1 task: every 10 ms tick; 100 ms and 1 s sub-schedules */

void task_tick_10ms(void)

{
  BADSPACEBASE *in_FSR1;
  undefined1 *puVar1;
  undefined1 *puVar2;
  byte bVar3;
  byte unaff_Z;
  
  do {
    while( true ) {
      puVar1 = (undefined1 *)((short)in_FSR1 + 1);
      *(undefined1 *)in_FSR1 = 0x9e;
      os_wait_sem_helper(0);
      if ((unaff_Z & 1) != 0) break;
      OS_Yield();
      in_FSR1 = (BADSPACEBASE *)puVar1;
    }
    ui_10ms_tick();
    tick_div_100ms = tick_div_100ms + '\x01';
    in_FSR1 = (BADSPACEBASE *)puVar1;
    if (tick_div_100ms == '\n') {
      dispense_100ms_tick(0);
      uv_verify_100ms_tick();
      ui_100ms_tick();
      tick_div_100ms = '\0';
      in_FSR1 = (BADSPACEBASE *)puVar1;
    }
    c18_tmp0 = tick_div_1s + 1;
    c18_tmp1 = 0;
    bVar3 = c18_tmp0 ^ 100;
    unaff_Z = bVar3 == 0;
    tick_div_1s = c18_tmp0;
    if ((bool)unaff_Z) {
      *(undefined1 *)in_FSR1 = 0xa2;
      puVar2 = (undefined1 *)((short)in_FSR1 + 2);
      *(undefined1 *)((short)in_FSR1 + 1) = 0;
      bVar3 = OSSignalSem();
      *puVar2 = *puVar2;
      in_FSR1 = (BADSPACEBASE *)(puVar2 + -2);
      puVar2[-1] = puVar2[-1];
      tick_div_1s = 0;
    }
    heater_burst_tick(bVar3);
  } while( true );
}

