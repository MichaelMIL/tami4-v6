// address 0x009f5a  size 32 bytes
// callers: 00b63c,006e5c,

/* Salvo: wait on semaphore (returns 'must wait' flag) */

void OSWaitSem(void)

{
  BADSPACEBASE *in_FSR2;
  BADSPACEBASE *in_FSR1;
  undefined1 uVar1;
  BADSPACEBASE *in_FSR0;
  
  mod_to_OSDisableInts_a30c();
  os_chain_fna160_fna21c_a286();
  *(undefined1 *)in_FSR2 = *(undefined1 *)in_FSR0;
  *(undefined1 *)in_FSR1 = *(undefined1 *)in_FSR2;
  os_frame_push_args_a1d8();
  os_wait_event_internal();
  uVar1 = os_pop3_return_a2e4();
  *(undefined1 *)in_FSR2 = uVar1;
  if ((*(byte *)in_FSR2 & 8) != 0) {
    os_chain_fna160_fna21c_a286();
    *(char *)in_FSR0 = *(char *)in_FSR0 + -1;
  }
  os_to_OSRestoreInts_a2d4();
  os_c18_epilogue_a180();
  return;
}

