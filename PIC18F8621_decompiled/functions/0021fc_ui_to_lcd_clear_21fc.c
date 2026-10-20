// address 0x0021fc  size 12 bytes
// callers: 002a58,0010d4,001178,002a06,

/* Auto: writes menu_table_ptr_lo,menu_table_ptr_hi; calls lcd_clear; 4 instr */

void ui_to_lcd_clear_21fc(void)

{
  byte unaff_BSR;
  
  *(undefined1 *)((ushort)unaff_BSR * 0x100 + 0x25) = 0;
  *(undefined1 *)((ushort)unaff_BSR * 0x100 + 0x26) = 0;
  ui_set_menu_cb_up_29fa();
  lcd_clear();
  return;
}

