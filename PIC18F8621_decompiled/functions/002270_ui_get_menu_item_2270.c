// address 0x002270  size 28 bytes
// callers: 0003e2,001038,0003cc,

/* Auto: reads menu_item,TABLAT; 9 instr */

void ui_get_menu_item_2270(void)

{
  undefined1 *in_TBLPTR;
  
  ui_get_menu_table_ptr_lo_2b3c();
  ui_get_TBLPTRL_2c14(3);
  menu_item = *in_TBLPTR;
  ui_get_menu_table_ptr_lo_2b3c();
  ui_get_TBLPTRL_2c14(0x16);
  ui_get_menu_table_ptr_lo_2a64();
  return;
}

