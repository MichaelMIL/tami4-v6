// address 0x00aa02  size 14 bytes
// callers: 00a414,

/* Auto: reads cfg_systemconfig3; 7 instr */

byte mod_get_cfg_systemconfig3_aa02(void)

{
  BADSPACEBASE *in_FSR1;
  
  mod_callw_mod_set_lcd_delay_counter_a940();
  *(undefined1 *)in_FSR1 = 6;
  return cfg_systemconfig3 & 4;
}

