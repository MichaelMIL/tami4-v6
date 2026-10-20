// address 0x00290e  size 20 bytes
// callers: 000c32,000c62,

/* Auto: Small wrapper around ui_get_menu_value_step_lo; 8 instr */

void ui_to_ui_get_menu_value_step_lo_290e(undefined1 param_1)

{
  BADSPACEBASE *in_FSR1;
  undefined1 *puVar1;
  
  puVar1 = (undefined1 *)CONCAT11((char)((ushort)in_FSR1 >> 8),param_1);
  ui_push_args_01_46_03_ui_to_ui_draw_temp_value_0cae(c18_tmp0);
  ui_get_menu_value_step_lo_2568();
  *puVar1 = 0x4b;
  ui_to_ui_draw_temp_value_2356(7);
  return;
}

