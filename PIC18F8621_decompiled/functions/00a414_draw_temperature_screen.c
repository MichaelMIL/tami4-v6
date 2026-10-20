// address 0x00a414  size 284 bytes
// callers: 003b12,

/* Draw temperatures (converted to Fahrenheit unless SYSTEMCONFIG3 bit2) */

void draw_temperature_screen(void)

{
  char cVar1;
  BADSPACEBASE *in_FSR2;
  undefined1 *puVar2;
  undefined1 *puVar3;
  undefined1 *puVar4;
  undefined1 *puVar5;
  undefined1 *puVar6;
  undefined1 *puVar7;
  undefined1 *puVar8;
  BADSPACEBASE *in_FSR1;
  char *pcVar9;
  char *pcVar10;
  undefined1 *puVar11;
  char *pcVar12;
  char *pcVar13;
  undefined1 uVar14;
  short sVar15;
  
  mod_c18_prologue_a8c8();
  if ((cfg_systemconfig3 & 4) == 0) {
    puVar2 = (undefined1 *)((short)in_FSR2 + 1);
    sVar15 = (ushort)*(byte *)((short)in_FSR2 + -2) * 9;
    mod_get_c18_tmp0_aa44();
    math_barg_lo = 5;
    math_barg_hi = 0;
    math_aarg_lo = (byte)sVar15;
    math_aarg_hi = (char)((ushort)sVar15 >> 8);
    __divs16();
    c18_tmp0 = math_aarg_lo + 0x20;
    c18_tmp1 = math_aarg_hi + (0xdf < math_aarg_lo);
    in_FSR2 = (BADSPACEBASE *)(puVar2 + 1);
    puVar2[-2] = c18_tmp0;
  }
  mod_frag_aa4e();
  puVar3 = (undefined1 *)((short)in_FSR2 + 1);
  math_aarg_hi = *(undefined1 *)((short)in_FSR2 + -2);
  mod_div_helper_a90e();
  puVar4 = puVar3 + 1;
  math_aarg_hi = puVar3[-2];
  mod_div_helper_a988();
  for (local0 = 0; local0 < 2; local0 = local0 + 1) {
    pcVar9 = (char *)((short)in_FSR1 + 1);
    *(undefined1 *)in_FSR1 = puVar4[-3];
    puVar5 = puVar4 + 2;
    mod_frag_a982(puVar4[-3]);
    puVar4 = puVar5 + 1;
    puVar6 = puVar5 + 1;
    if ((byte)puVar5[-2] < 100) {
      mod_to_mod_set_lcd_delay_counter_a9a4(0xe);
      in_FSR1 = (BADSPACEBASE *)pcVar9;
    }
    else {
      mod_frag_aa4e(puVar5[-2] + 0x9c);
      math_aarg_hi = local2;
      mod_shift_multibyte_fc24();
      local2 = math_rem_hi;
      local1 = 0;
      puVar4 = puVar6;
      while (in_FSR1 = (BADSPACEBASE *)pcVar9, local1 < 0xe) {
        c18_tmp4 = 100;
        math_barg_hi = 100;
        puVar7 = puVar4 + 1;
        math_aarg_hi = puVar4[-2];
        mod_shift_multibyte_fc24();
        mod_get_c18_tmp2_a892(math_aarg_hi);
        puVar4 = puVar7;
      }
    }
    local1 = 0;
    while (local1 < 0xe) {
      mod_get_c18_tmp2_a892(local2);
    }
    local1 = 0;
    while (local1 < 0xe) {
      mod_get_c18_tmp2_a892(local3);
    }
  }
  *(char *)in_FSR1 = puVar4[-3] + ',';
  pcVar10 = (char *)((short)in_FSR1 + 2);
  puVar8 = puVar4 + 2;
  *(undefined1 *)((short)in_FSR1 + 1) = puVar4[-3];
  mod_to_mod_to_lcd_write_cmd_cfc6();
  *pcVar10 = *pcVar10;
  pcVar10[-1] = pcVar10[-1];
  pcVar10[-2] = 0xe0;
  pcVar10[-1] = 0x58;
  lcd_puts_rom();
  *pcVar10 = *pcVar10;
  puVar11 = pcVar10 + -2;
  cVar1 = pcVar10[-1];
  pcVar10[-1] = cVar1;
  mod_to_mod_set_lcd_delay_counter_a9a4(2);
  pcVar12 = puVar11 + 1;
  *puVar11 = 4;
  mod_get_cfg_systemconfig3_aa02(0xfc);
  if (cVar1 == '\0') {
    uVar14 = 0xcc;
  }
  else {
    uVar14 = 0xc;
  }
  mod_callw_mod_set_lcd_delay_counter_a940(uVar14);
  pcVar13 = pcVar12 + 1;
  *pcVar12 = puVar8[-3] + '4';
  cVar1 = puVar8[-3];
  mod_callw_fncfc6_a9c2(cVar1 + '\x01');
  *pcVar13 = 4;
  mod_get_cfg_systemconfig3_aa02(0xf);
  if (cVar1 + '\x01' == '\0') {
    uVar14 = 0;
  }
  else {
    uVar14 = 0xc;
  }
  mod_callw_mod_set_lcd_delay_counter_a940(uVar14);
  mod_c18_epilogue_a902();
  return;
}

