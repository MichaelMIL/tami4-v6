// address 0x00a0b6  size 44 bytes
// callers: 00c926,00d3e0,

/* Salvo: stop a task (probable) */

void OSStopTask(void)

{
  BADSPACEBASE *in_FSR2;
  BADSPACEBASE *in_FSR1;
  char cVar1;
  
  mod_to_OSDisableInts_a30c();
  os_frame_push_args_a1d8();
  cVar1 = os_calc_array_ptr_a0e2();
  *(undefined1 *)in_FSR1 = *(undefined1 *)in_FSR1;
  *(undefined1 *)((short)in_FSR1 + -1) = *(undefined1 *)((short)in_FSR1 + -1);
  if (cVar1 != '\0') {
    *(undefined1 *)((short)in_FSR1 + -2) = 1;
    os_frame_push_args_a1d8();
    os_remove_from_queues();
    cVar1 = os_pop3_return_a2e4();
    if (cVar1 == '\0') {
      os_frame_load_ptr_arg_a160();
      os_frag_a260();
      *(undefined1 *)in_FSR2 = 0;
      goto LAB_CODE_00a0de;
    }
  }
  *(undefined1 *)in_FSR2 = 1;
LAB_CODE_00a0de:
  os_to_OSRestoreInts_a2d4();
  os_c18_epilogue_a180();
  return;
}

