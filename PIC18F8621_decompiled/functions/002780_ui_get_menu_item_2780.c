// address 0x002780  size 16 bytes
// callers: 002344,002bf2,002178,

/* Auto: reads menu_item; 8 instr */

void ui_get_menu_item_2780(void)

{
  BADSPACEBASE *in_FSR1;
  undefined1 uVar1;
  
  ui_get_menu_table_ptr_lo_2b3c();
  ui_get_c18_tmp0_2b52(4);
  uVar1 = ui_get_TBLPTRL_2b68(menu_item);
  *(undefined1 *)in_FSR1 = uVar1;
  return;
}

