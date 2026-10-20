// address 0x002652  size 12 bytes
// callers: 000e04,

/* Auto: reads menu_edit_mode; 6 instr */

undefined1 ui_get_menu_edit_mode_2652(char param_1)

{
  byte unaff_C;
  
  c18_tmp3 = (c18_tmp7 - param_1) - ~(unaff_C & 1);
  ui_get_c18_tmp0_29a2();
  return menu_edit_mode;
}

