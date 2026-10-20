// address 0x001684  size 62 bytes
// callers: 002708,

/* "FILL COLD WATER TANK" */

void screen_fill_cold_tank(void)

{
  BADSPACEBASE *in_FSR2;
  byte unaff_BSR;
  BADSPACEBASE *in_FSR1;
  undefined1 uVar1;
  byte unaff_Z;
  
  ui_to_ui_word_installation_2a96();
  if ((unaff_Z & 1) == 0) {
    *(undefined1 *)in_FSR1 = 2;
    uVar1 = 0x5b;
  }
  else {
    *(undefined1 *)in_FSR1 = 2;
    uVar1 = 0x5c;
  }
  ui_draw_word(uVar1);
  ui_draw_done(5);
  dispense_stop_all();
  ui_set_menu_timer_lo_2ade();
  menu_cb_aux = *(undefined1 *)((short)in_FSR2 + -4);
  menu_cb_aux_hi = *(undefined1 *)((short)in_FSR2 + -2);
  *(undefined1 *)((ushort)unaff_BSR * 0x100 + 0x3e) = 0;
  *(undefined1 *)((ushort)unaff_BSR * 0x100 + 0x3f) = 0;
  ui_to_menu_set_cbs_noop_b_2a7e();
  ui_c18_epilogue_21d8();
  return;
}

