// address 0x00c8f6  size 36 bytes
// callers: 00b256,

/* Create task_heating (TCB 0x80) */

undefined1 heating_create_task(void)

{
  BADSPACEBASE *in_FSR1;
  undefined1 *puVar1;
  undefined1 *puVar2;
  
  puVar1 = &FramePointer10x0001;
  mod_push_args_80_00_ca12();
  *puVar1 = 6;
  puVar2 = puVar1 + 2;
  puVar1[1] = 0xc6;
  c18_tmp0 = OSCreateTask();
  if ((byte)puVar2 < 5) {
    *(undefined1 *)((ushort)puVar2 & 0xff00) = *(undefined1 *)((ushort)puVar2 & 0xff00);
  }
  return 0;
}

