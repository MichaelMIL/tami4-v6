// address 0x001f12  size 88 bytes
// callers: 002bce,

/* Mix water temperature setting with bar graph */

void screen_mix_temp_bar(void)

{
  BADSPACEBASE *in_FSR1;
  char *pcVar1;
  char cVar2;
  bool bVar3;
  
  progress_bar_x = 0x10;
  progress_bar_width = 'd';
  progress_bar_y = 0x18;
  ui_set_progress_bar_value_2690(0xc);
  pcVar1 = (char *)((short)in_FSR1 + 1);
  *(char *)in_FSR1 = progress_bar_width + -1;
  ui_callw_fncfc6_238c(1);
  ui_get_progress_bar_value_24a8();
  menu_value_min_lo = 2;
  menu_value_min_hi = 0;
  while( true ) {
    cVar2 = '\x05';
    if ((menu_value_min_hi & 0x80) == 0) {
      bVar3 = menu_value_min_hi != ~(4 < menu_value_min_lo);
      cVar2 = menu_value_min_hi - ~(4 < menu_value_min_lo);
    }
    else {
      bVar3 = false;
    }
    if (bVar3) break;
    ui_set_menu_value_min_lo_2208();
  }
  ui_stack_adjust_2aba(cVar2);
  ui_callw_lcd_write_data_28be(3);
  *pcVar1 = progress_bar_value;
  ui_callw_mod_set_lcd_delay_counter_2a10(2);
  ui_callw_lcd_write_data_28be(3);
  ui_to_progress_bar_scale_28fe();
  return;
}

