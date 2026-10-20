// address 0x009f46  size 20 bytes
// callers: 00b256,0075e2,

/* Salvo: create semaphore (ECB pointer, initial count) */

void OSCreateSem(void)

{
  BADSPACEBASE *in_FSR2;
  BADSPACEBASE *in_FSR0;
  
  os_to_OSDisableInts_a2b2();
  *(undefined1 *)in_FSR0 = 0;
  *(undefined1 *)((short)in_FSR0 + 1) = 0;
  os_chain_fna160_fna21c_a286();
  *(undefined1 *)in_FSR0 = *(undefined1 *)((short)in_FSR2 + -4);
  OSRestoreInts();
  os_c18_epilogue_a180(0);
  return;
}

