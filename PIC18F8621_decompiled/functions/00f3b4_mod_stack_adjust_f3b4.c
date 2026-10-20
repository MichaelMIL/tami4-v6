// address 0x00f3b4  size 16 bytes
// callers: 00f334,00f364,

/* Auto: Software stack push/pop helper; 7 instr */

void mod_stack_adjust_f3b4(void)

{
  BADSPACEBASE *in_FSR2;
  BADSPACEBASE *in_FSR1;
  undefined1 *puVar1;
  
  puVar1 = &FramePointer10x0002;
  mod_to_mod_to_lcd_write_cmd_cfc6();
  *puVar1 = *puVar1;
  puVar1[-1] = puVar1[-1];
  *(undefined1 *)in_FSR2 = 0;
  return;
}

