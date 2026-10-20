// address 0x00a9a4  size 14 bytes
// callers: 00a414,

/* Auto: Small wrapper around mod_set_lcd_delay_counter; 6 instr */

void mod_to_mod_set_lcd_delay_counter_a9a4(void)

{
  BADSPACEBASE *in_FSR1;
  undefined1 *puVar1;
  
  puVar1 = &FramePointer10x0002;
  mod_set_lcd_delay_counter_cf6e();
  *puVar1 = *puVar1;
  puVar1[-1] = puVar1[-1];
  return;
}

