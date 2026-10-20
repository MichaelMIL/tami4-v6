// address 0x009af0  size 60 bytes
// callers: 00c8f6,00b256,0075fe,00d3b0,00dc08,0044d4,00ac46,00d8fc,

/* Salvo: create task (function pointer, TCB pointer, priority) */

void OSCreateTask(void)

{
  BADSPACEBASE *in_FSR2;
  undefined1 *puVar1;
  BADSPACEBASE *in_FSR1;
  BADSPACEBASE *in_FSR0;
  undefined1 *puVar2;
  
  os_c18_prologue_a16e();
  OSDisableInts();
  puVar1 = (undefined1 *)((short)in_FSR2 + 1);
  *(byte *)in_FSR1 = *(byte *)((short)in_FSR2 + -6) & 0x7f;
  os_frame_push_args_a244();
  os_frame_access_9b2c();
  os_pop3_return_a2e4();
  os_frame_load_ptr_arg_a19c();
  os_frag_a260();
  os_frame_load_ptr_arg_a19c();
  *(byte *)in_FSR0 = *(byte *)in_FSR0 & 0x7f;
  os_frame_load_ptr_arg_a19c();
  puVar2 = (undefined1 *)((short)in_FSR0 + 1);
  *(undefined1 *)in_FSR0 = *(undefined1 *)in_FSR0;
  os_frame_access_a200();
  os_frame_load_ptr_arg_a19c();
  os_const_then_a2dc_a1ca();
  *puVar2 = OStimerTicks;
  if ((puVar1[-6] & 0x80) == 0) {
    os_frame_load_ptr_arg_a19c();
    os_stack_adjust_a220();
    os_frame_push_args_a244();
    os_to_OSInsPrioQ_a1e6();
  }
  OSRestoreInts();
  os_c18_epilogue_a180(0);
  return;
}

