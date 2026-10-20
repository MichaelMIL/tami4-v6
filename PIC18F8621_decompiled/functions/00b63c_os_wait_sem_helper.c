// address 0x00b63c  size 14 bytes
// callers: 00b0aa,00b104,

/* Wait on a semaphore; returns non-zero if task must yield */

byte os_wait_sem_helper(void)

{
  BADSPACEBASE *in_FSR1;
  undefined1 *puVar1;
  byte bVar2;
  
  puVar1 = &FramePointer10x0001;
  bVar2 = OSWaitSem();
  *puVar1 = *puVar1;
  puVar1[-1] = puVar1[-1];
  return bVar2 & 2;
}

