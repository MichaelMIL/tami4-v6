// address 0x00a880  size 18 bytes
// callers: 00a538,

/* Auto: reads clock_colon_blink; 8 instr */

void mod_get_clock_colon_blink_a880(void)

{
  undefined1 uVar1;
  
  mod_stack_adjust_a974();
  if (clock_colon_blink == '\0') {
    uVar1 = 0;
  }
  else {
    uVar1 = 0x6c;
  }
  mod_callw_mod_set_lcd_delay_counter_a940(uVar1);
  return;
}

