// address 0x0075fe  size 42 bytes
// callers: 00b256,

/* Create task_serial_protocol (TCB 0x62) */

undefined1 serial_create_task(void)

{
  BADSPACEBASE *in_FSR1;
  undefined1 *puVar1;
  
  puVar1 = &FramePointer10x0005;
  c18_tmp0 = OSCreateTask();
  if ((byte)puVar1 < 5) {
    *(undefined1 *)((ushort)puVar1 & 0xff00) = *(undefined1 *)((ushort)puVar1 & 0xff00);
  }
  return 0;
}

