// address 0x002a10  size 12 bytes
// callers: 001f12,001f6a,0024a8,

/* Auto: Push W as argument and call mod_set_lcd_delay_counter; 5 instr */

void ui_callw_mod_set_lcd_delay_counter_2a10(void)

{
  BADSPACEBASE *in_FSR1;
  undefined1 *puVar1;
  
  puVar1 = &FramePointer10x0001;
  mod_set_lcd_delay_counter_cf6e();
  *puVar1 = *puVar1;
  puVar1[-1] = puVar1[-1];
  return;
}

