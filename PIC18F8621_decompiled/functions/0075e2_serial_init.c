// address 0x0075e2  size 28 bytes
// callers: 00b256,

/* Create serial line semaphore, reset receive state */

undefined1 serial_init(void)

{
  BADSPACEBASE *in_FSR1;
  undefined1 *puVar1;
  
  puVar1 = &FramePointer10x0001;
  serial_push_sem();
  OSCreateSem();
  *puVar1 = *puVar1;
  puVar1[-1] = puVar1[-1];
  puVar1[-2] = puVar1[-2];
  uart2_rx_count = 0;
  uart2_rx_buffer = 0;
  serial_cmd_hash = 0;
  uart2_rx_flags = uart2_rx_flags | 3;
  return 0;
}

