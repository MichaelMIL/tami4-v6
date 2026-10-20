// address 0x009f30  size 22 bytes
// callers: 00b0aa,002c22,00c606,00d174,00d794,00b104,00da82,00aa56,006e5c,

/* Salvo context switch: save resume address in TCB and return to OSSched */

void OS_Yield(void)

{
  BADSPACEBASE *in_FSR0;
  
  OSDisableInts();
  os_get_os_tmp_tcb_ptr_a1ce();
  *(undefined1 *)((short)in_FSR0 + 2) = 0x9f;
  *(undefined1 *)((short)in_FSR0 + 4) = 0;
  OSRestoreInts();
  return;
}

