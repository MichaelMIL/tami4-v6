// address 0x00a09a  size 28 bytes
// callers: 00c91a,00d3d4,

/* Salvo: start a stopped task (probable) */

void OSStartTask(void)

{
  char cVar1;
  
  os_to_OSDisableInts_a2b2();
  cVar1 = os_tcb_get_state_a2c6();
  if (cVar1 == '\x01') {
    os_frame_load_ptr_arg_a160();
    os_stack_adjust_a220();
    os_frame_push_args_a1d8();
    os_to_OSInsPrioQ_a1e6();
    OSRestoreInts();
  }
  else {
    OSRestoreInts();
  }
  os_c18_epilogue_a180(cVar1 != '\x01');
  return;
}

