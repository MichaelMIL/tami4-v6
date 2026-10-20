// address 0x001df4  size 32 bytes
// callers: 001ddc,002bce,000d58,000d22,001de2,

/* Auto: Small wrapper around ui_to_ui_draw_temp_units; 15 instr */

undefined1 ui_to_ui_to_ui_draw_temp_units_1df4(void)

{
  BADSPACEBASE *in_FSR1;
  byte bVar1;
  undefined1 uVar2;
  byte unaff_Z;
  byte unaff_C;
  
  bVar1 = (byte)((ushort)in_FSR1 >> 8);
  ui_to_ui_get_cfg_systemconfig2_2334();
  if ((unaff_Z & 1) == 0) {
    uVar2 = 0x23;
  }
  else {
    uVar2 = 0x37;
  }
  ui_to_ui_draw_temp_units_24d2(uVar2);
  ui_compare_multibyte_2b1e();
  if ((unaff_C & 1) == 0) {
    *(undefined1 *)((ushort)bVar1 << 8) = *(undefined1 *)((ushort)bVar1 << 8);
  }
  return c18_tmp0;
}

