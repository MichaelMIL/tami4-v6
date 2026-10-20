// address 0x0024d2  size 24 bytes
// callers: 001e14,001df4,

/* Auto: writes ui_substate; calls ui_draw_temp_units; 11 instr */

void ui_to_ui_draw_temp_units_24d2(undefined1 param_1)

{
  byte unaff_BSR;
  
  *(undefined1 *)((ushort)unaff_BSR * 0x100 + 2) = param_1;
  ui_get_menu_value_lo_2ace();
  ui_draw_temp_units();
  return;
}

