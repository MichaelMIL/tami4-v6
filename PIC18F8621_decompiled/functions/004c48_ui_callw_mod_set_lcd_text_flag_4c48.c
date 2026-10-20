// address 0x004c48  size 12 bytes
// callers: 00505a,00502e,003584,

/* Auto: Push W as argument and call mod_set_lcd_text_flag; 5 instr */

void ui_callw_mod_set_lcd_text_flag_4c48(void)

{
  BADSPACEBASE *in_FSR1;
  undefined1 *puVar1;
  
  puVar1 = &FramePointer10x0001;
  mod_set_lcd_text_flag_ca68();
  *puVar1 = *puVar1;
  puVar1[-1] = puVar1[-1];
  return;
}

