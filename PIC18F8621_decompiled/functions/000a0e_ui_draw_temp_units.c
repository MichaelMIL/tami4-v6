// address 0x000a0e  size 130 bytes
// callers: 004550,004d8e,0024d2,

/* Draw temperature in selected units */

void ui_draw_temp_units(void)

{
  byte bVar1;
  byte bVar2;
  BADSPACEBASE *in_FSR2;
  undefined1 *puVar3;
  undefined1 *puVar4;
  BADSPACEBASE *in_FSR1;
  byte bVar6;
  byte *pbVar5;
  byte bVar7;
  char cVar8;
  byte unaff_C;
  
  ui_c18_prologue_2166();
  text_row = *(undefined1 *)((short)in_FSR2 + -4);
  text_x = *(undefined1 *)((short)in_FSR2 + -4);
  if ((cfg_systemconfig3 & 4) == 0) {
    *(undefined1 *)in_FSR1 = 0xf;
    bVar1 = *(byte *)((short)in_FSR2 + -1);
    puVar3 = (undefined1 *)((short)in_FSR2 + 4);
    bVar2 = *(byte *)((short)in_FSR2 + 1);
    bVar7 = *(byte *)in_FSR1;
    c18_tmp0 = bVar1 + bVar7;
    c18_tmp1 = bVar2 + CARRY1(bVar1,bVar7);
    ui_to___divs16_28c8(0x1e);
    *(undefined1 *)in_FSR1 = math_aarg_lo;
    *(undefined1 *)((short)in_FSR1 + 1) = math_aarg_hi;
    *(undefined1 *)((short)in_FSR1 + 2) = puVar3[-6];
    bVar6 = (byte)((ushort)((short)in_FSR1 + 4) >> 8);
    *(undefined1 *)((short)in_FSR1 + 3) = 0;
    ui_callw_txt_set_ui_hold_counter_25b4(0x61);
    cVar8 = c18_tmp2;
    if (!CARRY1(bVar2,CARRY1(bVar1,bVar7))) {
      *(undefined1 *)((ushort)bVar6 << 8) = *(undefined1 *)((ushort)bVar6 << 8);
      cVar8 = c18_tmp2;
    }
  }
  else {
    pbVar5 = (byte *)((short)in_FSR1 + 1);
    puVar4 = (undefined1 *)((short)in_FSR2 + 3);
    *(undefined1 *)in_FSR1 = *(undefined1 *)((short)in_FSR2 + -1);
    ui_frame_push_args_25cc();
    *pbVar5 = puVar4[-6];
    pbVar5[1] = 0;
    bVar7 = (byte)((ushort)(pbVar5 + 3) >> 8);
    pbVar5[2] = 0x60;
    txt_set_ui_hold_counter_98fc();
    ui_compare_multibyte_2b1e();
    cVar8 = c18_tmp0;
    if ((unaff_C & 1) == 0) {
      *(undefined1 *)((ushort)bVar7 << 8) = *(undefined1 *)((ushort)bVar7 << 8);
      cVar8 = c18_tmp0;
    }
  }
  ui_c18_epilogue_21d8(cVar8);
  return;
}

