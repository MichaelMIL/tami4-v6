// address 0x0044d4  size 42 bytes
// callers: 00b256,

/* Create task_ui (TCB 0x6e) */

undefined1 ui_create_task(void)

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

