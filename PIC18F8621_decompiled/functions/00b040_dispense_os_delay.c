// address 0x00b040  size 12 bytes
// callers: 00aa56,00afc8,

/* OSDelay wrapper for dispensing task */

void dispense_os_delay(void)

{
  BADSPACEBASE *in_FSR1;
  undefined1 *puVar1;
  
  puVar1 = &FramePointer10x0001;
  OSDelay();
  *puVar1 = *puVar1;
  puVar1[-1] = puVar1[-1];
  return;
}

