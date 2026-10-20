// address 0x00a940  size 12 bytes
// callers: 00a880,00aa02,00a826,00a414,

/* Auto: Push W as argument and call mod_set_lcd_delay_counter; 5 instr */

void mod_callw_mod_set_lcd_delay_counter_a940(void)

{
  BADSPACEBASE *in_FSR1;
  undefined1 *puVar1;
  
  puVar1 = &FramePointer10x0001;
  mod_set_lcd_delay_counter_cf6e();
  *puVar1 = *puVar1;
  puVar1[-1] = puVar1[-1];
  return;
}

