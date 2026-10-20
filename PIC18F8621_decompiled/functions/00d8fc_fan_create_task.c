// address 0x00d8fc  size 42 bytes
// callers: 00b256,

/* Create task_fan_and_safety (TCB 0x92) */

undefined1 fan_create_task(void)

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

