// address 0x00a9c2  size 12 bytes
// callers: 00a982,00a974,00a8da,00a414,

/* Auto: Push W as argument and call 0xcfc6; 5 instr */

void mod_callw_fncfc6_a9c2(void)

{
  BADSPACEBASE *in_FSR1;
  undefined1 *puVar1;
  
  puVar1 = &FramePointer10x0001;
  mod_to_mod_to_lcd_write_cmd_cfc6();
  *puVar1 = *puVar1;
  puVar1[-1] = puVar1[-1];
  return;
}

