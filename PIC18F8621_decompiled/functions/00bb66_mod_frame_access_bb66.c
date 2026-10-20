// address 0x00bb66  size 26 bytes
// callers: 00b6a6,

/* Auto: Access stack-frame local/argument; 13 instr */

undefined1 mod_frame_access_bb66(void)

{
  undefined1 uVar1;
  byte unaff_BSR;
  BADSPACEBASE *in_FSR1;
  undefined1 *puVar2;
  BADSPACEBASE *in_FSR0;
  byte in_FramePointer2_0000fffc;
  
  c18_tmp0 = 8;
  *(byte *)((ushort)unaff_BSR * 0x100 + 0x54) = '\b' - (in_FramePointer2_0000fffc & 7);
  puVar2 = &FramePointer10x0001;
  mod_stack_adjust_bc0e();
  *(undefined1 *)in_FSR0 = *(undefined1 *)in_FSR0;
  uVar1 = *(undefined1 *)((short)in_FSR0 + 1);
  *puVar2 = uVar1;
  return uVar1;
}

