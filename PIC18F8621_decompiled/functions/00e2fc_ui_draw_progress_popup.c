// address 0x00e2fc  size 240 bytes
// callers: 00127a,003b12,

/* WARNING: Removing unreachable block (CODE,0x00e3cc) */
/* WARNING: Removing unreachable block (CODE,0x00e3da) */
/* WARNING: Restarted to delay deadcode elimination for space: DATA */
/* Draw progress/level popup (fill tanks, dispensing) */

void ui_draw_progress_popup(void)

{
  byte bVar1;
  BADSPACEBASE *in_FSR2;
  undefined1 *puVar2;
  undefined1 *puVar3;
  undefined1 *puVar4;
  byte *pbVar5;
  BADSPACEBASE *in_FSR1;
  undefined1 *puVar6;
  undefined1 *puVar7;
  BADSPACEBASE *in_FSR0;
  bool bVar8;
  
  mod_stack_adjust_e496();
  *(undefined1 *)in_FSR1 = *(undefined1 *)in_FSR1;
  puVar6 = (undefined1 *)((short)in_FSR1 + 2);
  *(undefined1 *)((short)in_FSR1 + 1) = *(undefined1 *)((short)in_FSR1 + 1);
  c18_tmp2 = popup_index;
  c18_tmp3 = 0;
  math_aarg_lo = popup_index;
  math_aarg_hi = 0;
  math_barg_lo = *(undefined1 *)((short)in_FSR2 + -3);
  puVar2 = (undefined1 *)((short)in_FSR2 + 2);
  math_barg_hi = *(undefined1 *)((short)in_FSR2 + -1);
  __mul16();
  c18_tmp0 = math_res0;
  c18_tmp1 = math_res1;
  math_barg_lo = 100;
  math_barg_hi = 0;
  math_aarg_lo = math_res0;
  math_aarg_hi = math_res1;
  __divu16();
  puVar2[3] = math_aarg_lo;
  puVar2[5] = math_aarg_hi;
  c18_tmp0 = popup_flag;
  c18_tmp1 = 0;
  puVar3 = puVar2 + 3;
  if ((puVar2[5] != popup_flag) || (puVar3 = puVar2 + 4, puVar2[7] != '\0')) {
    c18_tmp0 = puVar3[3];
    pbVar5 = puVar3 + 2;
    puVar4 = puVar3 + 2;
    c18_tmp1 = puVar3[5];
    if (c18_tmp1 == ~(popup_flag <= c18_tmp0)) {
      ui_draw_progress_segment(c18_tmp1 - ~(popup_flag <= c18_tmp0));
      pbVar5 = puVar4;
      puVar7 = puVar6;
    }
    else {
      c18_tmp0 = popup_flag;
      c18_tmp1 = 0;
      mod_calc_array_ptr_e440();
      bVar1 = *(byte *)in_FSR0;
      *(byte *)in_FSR0 = bVar1 - c18_tmp0;
      *(byte *)((short)in_FSR0 + 1) =
           (*(byte *)((short)in_FSR0 + 1) - c18_tmp1) - ~(c18_tmp0 <= bVar1);
      puVar7 = puVar6;
    }
    c18_tmp0 = popup_index * '\x05' + 3;
    c18_tmp1 = 0;
    mod_to___divs16_e458();
    bVar8 = 0xfe < c18_tmp0;
    c18_tmp0 = c18_tmp0 + 1;
    c18_tmp1 = c18_tmp1 + bVar8;
    *pbVar5 = c18_tmp0;
    pbVar5[1] = c18_tmp1;
    bVar1 = *pbVar5;
    *pbVar5 = bVar1 + popup_flag * '\x05';
    pbVar5[1] = pbVar5[1] + CARRY1(bVar1,popup_flag * '\x05');
    puVar6 = puVar7 + 1;
    *puVar7 = *pbVar5;
    mod_get_popup_arg_e488();
    mod_calc_array_ptr_e440();
  }
  if ((byte)puVar6 < 4) {
    *(undefined1 *)((ushort)puVar6 & 0xff00) = *(undefined1 *)((ushort)puVar6 & 0xff00);
  }
  mod_c18_epilogue_e40e((byte)puVar6 - 4);
  return;
}

