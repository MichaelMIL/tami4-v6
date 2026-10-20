// address 0x00097a  size 148 bytes
// callers: 002356,

/* Draw a temperature with deg C/deg F symbol (converts when imperial) */

void ui_draw_temp_value(void)

{
  BADSPACEBASE *in_FSR2;
  undefined1 *puVar1;
  BADSPACEBASE *in_FSR1;
  byte *pbVar2;
  char cVar3;
  undefined1 uVar4;
  byte unaff_Z;
  
  cVar3 = ui_frag_2b16();
  text_row = *(undefined1 *)((short)in_FSR2 + (short)cVar3 + 1);
  puVar1 = (undefined1 *)((short)in_FSR2 + 2);
  text_x = *(undefined1 *)((short)in_FSR2 + -2);
  text_fill_width = 0x23;
  ui_get_cfg_systemconfig3_258a();
  if ((unaff_Z & 1) == 0) {
    uVar4 = 0x4c;
  }
  else {
    uVar4 = 0x4b;
  }
  ui_to_ui_word_ptr_2536(uVar4);
  if ((cfg_systemconfig3 & 4) == 0) {
    ui_get_c18_tmp2_26d4();
    math_aarg_lo = (byte)((ushort)c18_tmp2 * 9);
    math_aarg_hi = c18_tmp3 * '\t' + (char)((ushort)c18_tmp2 * 9 >> 8);
    math_barg_lo = 5;
    math_barg_hi = 0;
    c18_tmp2 = math_aarg_lo;
    c18_tmp3 = math_aarg_hi;
    __divs16();
    c18_tmp2 = math_aarg_lo + 0x20;
    c18_tmp3 = math_aarg_hi + (0xdf < math_aarg_lo);
  }
  else {
    ui_get_c18_tmp2_26d4();
  }
  *(byte *)in_FSR1 = c18_tmp2;
  pbVar2 = (byte *)((short)in_FSR1 + 2);
  *(char *)((short)in_FSR1 + 1) = c18_tmp3;
  c18_tmp4 = puVar1[-6];
  c18_tmp5 = ui_stack_adjust_2644(c18_tmp4 | 0x60);
  if ((byte)pbVar2 < 8) {
    *(undefined1 *)((ushort)pbVar2 & 0xff00) = *(undefined1 *)((ushort)pbVar2 & 0xff00);
  }
  ui_c18_epilogue_21d8(c18_tmp5);
  return;
}

