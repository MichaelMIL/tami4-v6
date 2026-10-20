// address 0x000cf8  size 32 bytes
// callers: (none: entry point, task, or reached via pointer)

/* Auto: writes menu_cb_enter; calls menu_set_cbs_enter_hi_d; 11 instr */

void ui_to_menu_set_cbs_enter_hi_d_0cf8(void)

{
  byte unaff_BSR;
  
  ui_to_param_read_max_2360(0x34);
  ui_set_menu_value_step_lo_27d2(0x34);
  ui_chain_ui_get_TBLPTRL_ui_to_ui_draw_set__2992();
  ui_to_screen_mix_temp_bar_2bce(0x34);
  *(undefined1 *)((ushort)unaff_BSR * 0x100 + 0x34) = 0x18;
  menu_set_cbs_enter_hi_d(0xd);
  return;
}

