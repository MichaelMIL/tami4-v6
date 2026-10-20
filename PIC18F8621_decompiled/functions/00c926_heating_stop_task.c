// address 0x00c926  size 12 bytes
// callers: 003b12,00da64,

/* Stop task_heating */

undefined1 heating_stop_task(void)

{
  BADSPACEBASE *in_FSR1;
  
  mod_push_args_80_00_ca12();
  OSStopTask();
  *(undefined1 *)in_FSR1 = *(undefined1 *)in_FSR1;
  *(undefined1 *)((short)in_FSR1 + -1) = *(undefined1 *)((short)in_FSR1 + -1);
  return 0;
}

