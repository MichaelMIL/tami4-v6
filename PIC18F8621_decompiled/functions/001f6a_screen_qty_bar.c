// address 0x001f6a  size 136 bytes
// callers: 000d58,000d22,

/* Water quantity setting with bar graph */

void screen_qty_bar(void)

{
  BADSPACEBASE *in_FSR1;
  char *pcVar1;
  char *pcVar2;
  char *pcVar3;
  char *pcVar4;
  undefined1 *puVar5;
  char *pcVar6;
  char *pcVar7;
  char cVar8;
  bool bVar9;
  
  progress_bar_x = 0x18;
  progress_bar_width = 'd';
  progress_bar_y = 0x10;
  ui_set_progress_bar_value_2690(0xd);
  pcVar1 = (char *)((short)in_FSR1 + 1);
  *(char *)in_FSR1 = progress_bar_width + -1;
  ui_callw_fncfc6_238c(2);
  ui_get_progress_bar_value_24a8();
  menu_value_min_lo = 3;
  menu_value_min_hi = 0;
  while( true ) {
    cVar8 = '\x05';
    if ((menu_value_min_hi & 0x80) == 0) {
      bVar9 = menu_value_min_hi != ~(4 < menu_value_min_lo);
      cVar8 = menu_value_min_hi - ~(4 < menu_value_min_lo);
    }
    else {
      bVar9 = false;
    }
    if (bVar9) break;
    ui_set_menu_value_min_lo_2208(cVar8);
  }
  pcVar2 = pcVar1 + 1;
  *pcVar1 = progress_bar_width + -6;
  ui_callw_fncfc6_238c(3);
  pcVar3 = pcVar2 + 1;
  *pcVar2 = 0x70;
  ui_to_lcd_puts_rom_23f6(0x58);
  pcVar4 = pcVar3 + 1;
  *pcVar3 = progress_bar_width + -6;
  ui_callw_fncfc6_238c(4);
  puVar5 = pcVar4 + 1;
  *pcVar4 = 0x69;
  ui_to_lcd_puts_rom_23f6(0x58);
  ui_stack_adjust_2aba();
  pcVar6 = puVar5 + 1;
  *puVar5 = 0x65;
  ui_to_lcd_puts_rom_23f6(0x58);
  pcVar7 = pcVar6 + 1;
  *pcVar6 = progress_bar_value + -2;
  ui_callw_mod_set_lcd_delay_counter_2a10(5);
  *pcVar7 = 0x61;
  ui_to_lcd_puts_rom_23f6(0x58);
  ui_to_progress_bar_scale_28fe();
  return;
}

