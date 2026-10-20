// address 0x00054e  size 72 bytes
// callers: 0005bc,0005a6,0005d0,

/* Draw auto power-down setting ("OFF" / "POWER DOWN AFTER %d HOURS") */

undefined1 screen_power_down_draw(void)

{
  BADSPACEBASE *in_FSR1;
  byte bVar1;
  undefined1 uVar2;
  byte unaff_Z;
  byte unaff_C;
  
  ui_get_menu_value_lo_2778();
  if ((unaff_Z & 1) != 0) {
    ui_to_ui_set_ui_wake_pending_2a20();
    *(undefined1 *)in_FSR1 = 0x22;
    *(undefined1 *)((short)in_FSR1 + 1) = 0;
    uVar2 = ui_stack_adjust_21f4(0x70);
    return uVar2;
  }
  ui_to_ui_set_ui_wake_pending_2a20();
  ui_to___mul16x16_32_24ea(0x18);
  c18_tmp0 = math_res0;
  c18_tmp1 = math_res1;
  *(undefined1 *)in_FSR1 = math_res0;
  *(undefined1 *)((short)in_FSR1 + 1) = math_res1;
  *(undefined1 *)((short)in_FSR1 + 2) = 0x22;
  bVar1 = (byte)((ushort)((short)in_FSR1 + 4) >> 8);
  *(undefined1 *)((short)in_FSR1 + 3) = 0;
  ui_callw_txt_set_ui_hold_counter_25b4(0x71);
  if ((unaff_C & 1) == 0) {
    *(undefined1 *)((ushort)bVar1 << 8) = *(undefined1 *)((ushort)bVar1 << 8);
  }
  return c18_tmp2;
}

