// address 0x00d3b0  size 36 bytes
// callers: 00b256,

/* Create task_cooling (TCB 0x68) */

undefined1 cooling_create_task(void)

{
  BADSPACEBASE *in_FSR1;
  undefined1 *puVar1;
  undefined1 *puVar2;
  
  puVar1 = &FramePointer10x0001;
  mod_push_args_68_00_d49a();
  *puVar1 = 0x74;
  puVar2 = puVar1 + 2;
  puVar1[1] = 0xd1;
  c18_tmp0 = OSCreateTask();
  if ((byte)puVar2 < 5) {
    *(undefined1 *)((ushort)puVar2 & 0xff00) = *(undefined1 *)((ushort)puVar2 & 0xff00);
  }
  return 0;
}

