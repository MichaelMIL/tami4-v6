// address 0x000304  size 20 bytes
// callers: (none: entry point, task, or reached via pointer)

/* Auto: writes menu_cb_enter; calls lcd_clear,menu_set_cbs_enter_hi; 7 instr */

void ui_to_lcd_clear_0304(void)

{
  byte unaff_BSR;
  
  lcd_clear();
  ui_to_ui_draw_title_word_2874(0x48);
  *(undefined1 *)((ushort)unaff_BSR * 0x100 + 0x34) = 0xde;
  menu_set_cbs_enter_hi(1);
  return;
}

