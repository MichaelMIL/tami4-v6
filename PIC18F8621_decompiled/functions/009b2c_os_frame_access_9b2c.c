// address 0x009b2c  size 56 bytes
// callers: 009af0,

/* Auto: Access stack-frame local/argument; 27 instr */

void os_frame_access_9b2c(void)

{
  undefined1 uVar1;
  BADSPACEBASE *in_FSR2;
  undefined1 *puVar2;
  undefined1 *puVar3;
  BADSPACEBASE *in_FSR1;
  BADSPACEBASE *in_FSR0;
  
  os_stack_adjust_a28c();
  puVar2 = (undefined1 *)((short)in_FSR2 + 1);
  if (*(byte *)((short)in_FSR2 + -4) < 0x10) {
    *(undefined1 *)((short)in_FSR2 + 1) = 0;
  }
  else {
    puVar2 = (undefined1 *)((short)in_FSR2 + 2);
    *(undefined1 *)((short)in_FSR2 + -3) = 0xf;
    *(undefined1 *)((short)in_FSR2 + 2) = 1;
  }
  puVar3 = puVar2 + 1;
  c18_tmp0 = puVar2[-4];
  os_frame_load_ptr_arg_a160();
  *(byte *)in_FSR0 = c18_tmp0 & 0xf | *(byte *)in_FSR0 & 0xf0;
  uVar1 = *puVar3;
  *(undefined1 *)in_FSR1 = *(undefined1 *)in_FSR1;
  os_c18_epilogue_a180(uVar1);
  return;
}

