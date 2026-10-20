// address 0x001e3e  size 212 bytes
// callers: 002684,000a90,

/* WARNING: Restarted to delay deadcode elimination for space: DATA */
/* Cold water temperature setting with bar graph */

void screen_cold_temp_bar(void)

{
  BADSPACEBASE *in_FSR2;
  BADSPACEBASE *in_FSR1;
  char *pcVar1;
  char *pcVar2;
  char *pcVar3;
  char cVar4;
  undefined1 uVar5;
  bool bVar6;
  
  ui_c18_prologue_2166();
  progress_bar_x = 0x10;
  progress_bar_width = 'n';
  progress_bar_y = 0x28;
  ui_set_progress_bar_value_2690(7);
  pcVar1 = (char *)((short)in_FSR1 + 1);
  *(char *)in_FSR1 = progress_bar_width + -2;
  ui_callw_fncfc6_238c(1);
  pcVar2 = pcVar1 + 1;
  *pcVar1 = 0x7b;
  ui_to_lcd_puts_rom_23f6(0x58);
  pcVar3 = pcVar2 + 1;
  *pcVar2 = progress_bar_value + progress_bar_width;
  mod_to_mod_to_lcd_write_cmd_cfd8();
  *pcVar3 = *pcVar3;
  pcVar3[-1] = 0x77;
  ui_to_lcd_puts_rom_23f6(0x58);
  menu_value_min_lo = 2;
  menu_value_min_hi = 0;
  while( true ) {
    cVar4 = '\a';
    if ((menu_value_min_hi & 0x80) == 0) {
      bVar6 = menu_value_min_hi != ~(6 < menu_value_min_lo);
      cVar4 = menu_value_min_hi - ~(6 < menu_value_min_lo);
    }
    else {
      bVar6 = false;
    }
    if (bVar6) break;
    ui_set_menu_value_min_lo_2208(cVar4);
  }
  *pcVar3 = progress_bar_width + -1;
  ui_callw_fncfc6_238c(7);
  ui_callw_lcd_write_data_28be(0x1f);
  menu_value_min_lo = 0;
  for (menu_value_min_hi = 0;
      (menu_value_min_hi & 0x80) != 0 ||
      menu_value_min_hi == ~(progress_bar_value <= menu_value_min_lo);
      menu_value_min_hi = menu_value_min_hi + bVar6) {
    c18_tmp2 = 3;
    math_barg_hi = 3;
    math_aarg_hi = progress_bar_value;
    mod_shift_multibyte_fc24();
    c18_tmp0 = math_aarg_hi;
    c18_tmp1 = 0;
    if ((math_aarg_hi == menu_value_min_lo) && (menu_value_min_hi == 0)) {
      uVar5 = 0x20;
    }
    else {
      uVar5 = 0x3f;
    }
    ui_callw_lcd_write_data_28be(uVar5);
    bVar6 = 0xfe < menu_value_min_lo;
    menu_value_min_lo = menu_value_min_lo + 1;
  }
  ui_callw_lcd_write_data_28be(0x1f);
  if (*(char *)((short)in_FSR2 + -2) == '\0') {
    ui_get_menu_value_lo_21ca(0);
  }
  else {
    ui_get_menu_value_step_lo_2378();
  }
  progress_bar_scale();
  ui_c18_epilogue_21d8();
  return;
}

