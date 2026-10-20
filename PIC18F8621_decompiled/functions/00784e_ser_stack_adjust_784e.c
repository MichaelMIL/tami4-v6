// address 0x00784e  size 18 bytes
// callers: 007a90,007774,

/* Auto: Software stack push/pop helper; 9 instr */

undefined1 ser_stack_adjust_784e(void)

{
  undefined1 uVar1;
  BADSPACEBASE *in_FSR1;
  BADSPACEBASE *in_FSR0;
  
  ser_frame_load_ptr_arg_7a72();
  uVar1 = *(undefined1 *)
           CONCAT11((char)((ushort)in_FSR0 >> 8) + CARRY1((byte)in_FSR0,*(byte *)in_FSR1),
                    (byte)in_FSR0 + *(byte *)in_FSR1);
  *(undefined1 *)in_FSR1 = uVar1;
  return uVar1;
}

