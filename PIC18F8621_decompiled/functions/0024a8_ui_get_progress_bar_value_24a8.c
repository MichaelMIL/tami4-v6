// address 0x0024a8  size 18 bytes
// callers: 001f12,001f6a,

/* Auto: reads progress_bar_value; 7 instr */

void ui_get_progress_bar_value_24a8(void)

{
  BADSPACEBASE *in_FSR1;
  
  ui_callw_lcd_write_data_28be(0xf0);
  *(undefined1 *)in_FSR1 = progress_bar_value;
  ui_callw_mod_set_lcd_delay_counter_2a10(0x10);
  ui_callw_lcd_write_data_28be(0xf0);
  return;
}

