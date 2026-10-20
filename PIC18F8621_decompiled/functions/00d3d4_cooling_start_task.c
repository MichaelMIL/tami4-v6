// address 0x00d3d4  size 12 bytes
// callers: 003470,00d998,

/* Start task_cooling */

undefined1 cooling_start_task(void)

{
  BADSPACEBASE *in_FSR1;
  
  mod_push_args_68_00_d49a();
  OSStartTask();
  *(undefined1 *)in_FSR1 = *(undefined1 *)in_FSR1;
  *(undefined1 *)((short)in_FSR1 + -1) = *(undefined1 *)((short)in_FSR1 + -1);
  return 0;
}

