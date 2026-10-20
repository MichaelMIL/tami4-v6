// address 0x00d154  size 8 bytes
// callers: 00cfee,00d08c,00d008,

/* Auto: Software stack push/pop helper; 4 instr */

void mod_stack_adjust_d154(void)

{
  BADSPACEBASE *in_FSR1;
  
  mod_to_mod_to_lcd_write_cmd_cfc6();
  *(undefined1 *)in_FSR1 = *(undefined1 *)in_FSR1;
  *(undefined1 *)((short)in_FSR1 + -1) = *(undefined1 *)((short)in_FSR1 + -1);
  return;
}

