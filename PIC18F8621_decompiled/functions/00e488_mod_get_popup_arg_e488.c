// address 0x00e488  size 14 bytes
// callers: 00e3ec,00e2fc,

/* Auto: reads popup_arg; 5 instr */

void mod_get_popup_arg_e488(void)

{
  BADSPACEBASE *in_FSR1;
  undefined1 *puVar1;
  
  puVar1 = &FramePointer10x0001;
  mod_to_mod_to_lcd_write_cmd_cfc6();
  *puVar1 = *puVar1;
  puVar1[-1] = puVar1[-1];
  return;
}

