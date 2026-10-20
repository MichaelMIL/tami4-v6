// address 0x002a64  size 14 bytes
// callers: 002254,002270,

/* Auto: reads menu_table_ptr_lo,TABLAT,menu_table_ptr_hi; 5 instr */

void ui_get_menu_table_ptr_lo_2a64(void)

{
  undefined1 *in_TBLPTR;
  
  menu_table_ptr_lo = *in_TBLPTR;
  menu_table_ptr_hi = in_TBLPTR[1];
  return;
}

