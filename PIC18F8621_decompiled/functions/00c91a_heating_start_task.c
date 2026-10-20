// address 0x00c91a  size 12 bytes
// callers: 003470,00d998,

/* Start task_heating */

undefined1 heating_start_task(void)

{
  BADSPACEBASE *in_FSR1;
  
  mod_push_args_80_00_ca12();
  OSStartTask();
  *(undefined1 *)in_FSR1 = *(undefined1 *)in_FSR1;
  *(undefined1 *)((short)in_FSR1 + -1) = *(undefined1 *)((short)in_FSR1 + -1);
  return 0;
}

