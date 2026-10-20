// address 0x002344  size 18 bytes
// callers: 000a90,000b2c,

/* Auto: writes menu_value_step_lo,menu_value_step_hi; 7 instr */

void ui_set_menu_value_step_lo_2344(void)

{
  byte unaff_BSR;
  BADSPACEBASE *in_FSR1;
  undefined1 uVar1;
  
  uVar1 = ui_to_param_read_min_2b7a();
  *(undefined1 *)((ushort)unaff_BSR * 0x100 + 0x9a) = uVar1;
  *(undefined1 *)((ushort)unaff_BSR * 0x100 + 0x9b) = 0;
  *(undefined1 *)in_FSR1 = 1;
  ui_get_menu_item_2780();
  ui_to_ui_draw_set_hint_2b86();
  return;
}

