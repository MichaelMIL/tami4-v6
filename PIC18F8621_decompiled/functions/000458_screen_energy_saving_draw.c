// address 0x000458  size 72 bytes
// callers: 0004cc,0004f6,0004e2,

/* Draw energy-saving setting ("MODE IS OFF" / "SHUT OFF HEATER AFTER %d MIN") */

undefined1 screen_energy_saving_draw(void)

{
  BADSPACEBASE *in_FSR1;
  byte bVar1;
  undefined1 uVar2;
  undefined1 in_PRODL;
  byte unaff_Z;
  byte unaff_C;
  
  ui_get_menu_value_lo_2778();
  if ((unaff_Z & 1) != 0) {
    ui_to_ui_set_ui_wake_pending_2a20();
    *(undefined1 *)in_FSR1 = 0x22;
    *(undefined1 *)((short)in_FSR1 + 1) = 0;
    uVar2 = ui_stack_adjust_21f4(0x72);
    return uVar2;
  }
  ui_to_ui_set_ui_wake_pending_2a20();
  c18_tmp0 = menu_value_lo;
  c18_tmp1 = menu_value_hi;
  ui_get_c18_tmp1_2632(0x1e);
  *(undefined1 *)in_FSR1 = in_PRODL;
  *(undefined1 *)((short)in_FSR1 + 1) = c18_tmp1;
  *(undefined1 *)((short)in_FSR1 + 2) = 0x22;
  bVar1 = (byte)((ushort)((short)in_FSR1 + 4) >> 8);
  *(undefined1 *)((short)in_FSR1 + 3) = 0;
  ui_callw_txt_set_ui_hold_counter_25b4(0x73);
  if ((unaff_C & 1) == 0) {
    *(undefined1 *)((ushort)bVar1 << 8) = *(undefined1 *)((ushort)bVar1 << 8);
  }
  return c18_tmp2;
}

