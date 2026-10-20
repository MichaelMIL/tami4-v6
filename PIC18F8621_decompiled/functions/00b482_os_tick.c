// address 0x00b482  size 22 bytes
// callers: 00bd4a,

/* Called every Timer0 tick: OSTimer + signal tick semaphore (ECB 0x9e) */

void os_tick(void)

{
  BADSPACEBASE *in_FSR1;
  undefined1 *puVar1;
  
  OSTimer();
  *(undefined1 *)in_FSR1 = 0x9e;
  puVar1 = (undefined1 *)((short)in_FSR1 + 2);
  *(undefined1 *)((short)in_FSR1 + 1) = 0;
  OSSignalSem();
  *puVar1 = *puVar1;
  puVar1[-1] = puVar1[-1];
  return;
}

