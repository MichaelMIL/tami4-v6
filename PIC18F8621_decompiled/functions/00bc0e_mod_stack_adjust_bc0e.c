// address 0x00bc0e  size 12 bytes
// callers: 00bb66,00bb4e,

/* Auto: Software stack push/pop helper; 5 instr */

void mod_stack_adjust_bc0e(void)

{
  BADSPACEBASE *in_FSR1;
  undefined1 uVar1;
  
  mod_frame_load_ptr_arg_ba1a();
  uVar1 = mod_ptr_add_ba96(3);
  *(undefined1 *)in_FSR1 = uVar1;
  mod_frame_load_ptr_arg_ba1a();
  return;
}

