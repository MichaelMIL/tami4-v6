// address 0x0028e2  size 20 bytes
// callers: 000c32,000c62,

/* Auto: reads params TBOIL; writes menu_value_step_lo,menu_value_step_hi; 9 instr */

void ui_param_tboil_28e2(undefined1 param_1)

{
  byte unaff_BSR;
  BADSPACEBASE *in_FSR1;
  
  *(undefined1 *)((ushort)unaff_BSR * 0x100 + 0x9a) = param_1;
  *(undefined1 *)((ushort)unaff_BSR * 0x100 + 0x9b) = 0;
  ui_callw_ui_to_eeprom_read_raw_228c(0x15);
  ui_get_menu_value_max_lo_2574();
  *(undefined1 *)in_FSR1 = 0x4b;
  ui_to_ui_draw_temp_value_2356(1);
  return;
}

