// address 0x00238c  size 12 bytes
// callers: 001f12,001f6a,002aba,001e3e,001b4a,

/* Auto: Push W as argument and call 0xcfc6; 5 instr */

void ui_callw_fncfc6_238c(void)

{
  BADSPACEBASE *in_FSR1;
  undefined1 *puVar1;
  
  puVar1 = &FramePointer10x0001;
  mod_to_mod_to_lcd_write_cmd_cfc6();
  *puVar1 = *puVar1;
  puVar1[-1] = puVar1[-1];
  return;
}

