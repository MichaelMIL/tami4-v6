// address 0x001e14  size 42 bytes
// callers: 001de8,001dee,

/* Auto: writes menu_value_lo,menu_value_hi; reads cfg_systemconfig5; 21 instr */

char ui_set_menu_value_lo_1e14(void)

{
  BADSPACEBASE *in_FSR1;
  undefined1 uVar1;
  byte unaff_Z;
  
  if ((cfg_systemconfig5 & 4) == 0) {
    menu_value_lo = 0;
    menu_value_hi = 0;
    unaff_Z = 1;
  }
  ui_to_ui_get_cfg_systemconfig2_2334();
  if ((unaff_Z & 1) == 0) {
    uVar1 = 0x23;
  }
  else {
    uVar1 = 0x37;
  }
  ui_to_ui_draw_temp_units_24d2(uVar1);
  if ((byte)in_FSR1 < 5) {
    *(undefined1 *)((ushort)in_FSR1 & 0xff00) = *(undefined1 *)((ushort)in_FSR1 & 0xff00);
  }
  return (byte)in_FSR1 - 5;
}

