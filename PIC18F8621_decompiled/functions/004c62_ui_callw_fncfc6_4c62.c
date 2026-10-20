// address 0x004c62  size 12 bytes
// callers: 00505a,0048b2,003584,

/* Auto: Push W as argument and call 0xcfc6; 5 instr */

void ui_callw_fncfc6_4c62(void)

{
  BADSPACEBASE *in_FSR1;
  undefined1 *puVar1;
  
  puVar1 = &FramePointer10x0001;
  mod_to_mod_to_lcd_write_cmd_cfc6();
  *puVar1 = *puVar1;
  puVar1[-1] = puVar1[-1];
  return;
}

