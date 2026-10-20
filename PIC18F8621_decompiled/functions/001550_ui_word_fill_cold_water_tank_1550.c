// address 0x001550  size 50 bytes
// callers: 0026f6,

/* Auto: shows "FILL COLD WATER TANK"; writes menu_cb_aux,menu_cb_aux_hi; reads
   menu_cb_enter,menu_cb_enter_hi; calls ui_draw_press_ok_when_ready,menu_set_cbs_noop; 19 instr */

void ui_word_fill_cold_water_tank_1550(void)

{
  BADSPACEBASE *in_FSR2;
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
  ui_draw_press_ok_when_ready(uVar1);
  menu_cb_aux = 0;
  menu_cb_aux_hi = 0;
  menu_cb_enter = *(undefined1 *)((short)in_FSR2 + -4);
  menu_cb_enter_hi = *(undefined1 *)((short)in_FSR2 + -2);
  menu_set_cbs_noop();
  ui_c18_epilogue_21d8();
  return;
}

