// address 0x00d08c  size 146 bytes
// callers: 004e4c,

/* Draw a label and value line (service screens) */

void ui_draw_label_value(void)

{
  BADSPACEBASE *in_FSR2;
  undefined1 *puVar1;
  undefined1 *puVar2;
  undefined1 *puVar3;
  undefined1 *puVar4;
  BADSPACEBASE *in_FSR1;
  undefined1 *puVar5;
  undefined1 *puVar6;
  undefined1 *puVar7;
  undefined1 *puVar8;
  undefined1 *puVar9;
  undefined1 *puVar10;
  undefined1 *puVar11;
  undefined1 *puVar12;
  undefined1 *puVar13;
  undefined1 *puVar14;
  undefined1 *puVar15;
  
  mod_c18_prologue_d11e();
  *(undefined1 *)in_FSR1 = 0x1e;
  puVar5 = (undefined1 *)((short)in_FSR1 + 2);
  *(undefined1 *)((short)in_FSR1 + 1) = 0;
  mod_stack_adjust_d154();
  mod_stack_adjust_d13c(3);
  puVar2 = (undefined1 *)((short)in_FSR2 + 1);
  puVar1 = (undefined1 *)((short)in_FSR2 + 1);
  if (*(char *)((short)in_FSR2 + -2) == '\0') {
    mod_to_mod_set_lcd_delay_counter_d164(7);
  }
  else {
    puVar6 = puVar5 + 1;
    *puVar5 = 0x2d;
    puVar5 = puVar5 + 2;
    *puVar6 = 0x59;
    lcd_puts_rom();
    puVar2 = puVar1;
  }
  *puVar5 = *puVar5;
  puVar7 = puVar5 + -2;
  puVar5[-1] = puVar5[-1];
  mod_stack_adjust_d13c(0x11);
  puVar4 = puVar2 + 1;
  puVar3 = puVar2 + 1;
  if (puVar2[-3] == '\0') {
    mod_to_mod_set_lcd_delay_counter_d164(0xd);
  }
  else {
    puVar8 = puVar7 + 1;
    *puVar7 = 0x1e;
    puVar7 = puVar7 + 2;
    *puVar8 = 0x59;
    lcd_puts_rom();
    puVar4 = puVar3;
  }
  *puVar7 = *puVar7;
  puVar9 = puVar7 + -2;
  puVar7[-1] = puVar7[-1];
  mod_stack_adjust_d13c(0x10);
  if (puVar4[-4] == '\0') {
    mod_to_mod_set_lcd_delay_counter_d164(10);
  }
  else {
    puVar10 = puVar9 + 1;
    *puVar9 = 0x12;
    puVar9 = puVar9 + 2;
    *puVar10 = 0x59;
    lcd_puts_rom();
  }
  *puVar9 = *puVar9;
  puVar11 = puVar9 + -2;
  puVar9[-1] = puVar9[-1];
  mod_stack_adjust_d13c(2);
  *puVar11 = 0x1f;
  puVar12 = puVar11 + 2;
  puVar11[1] = 1;
  mod_stack_adjust_d154();
  puVar13 = puVar12 + 1;
  *puVar12 = 1;
  lcd_write_data();
  *puVar13 = *puVar13;
  puVar13[-1] = 0x40;
  puVar14 = puVar13 + 1;
  *puVar13 = 3;
  mod_set_lcd_delay_counter_cf6e();
  *puVar14 = *puVar14;
  puVar14[-1] = puVar14[-1];
  puVar15 = puVar14 + -1;
  puVar14[-2] = 1;
  lcd_write_data();
  *puVar15 = *puVar15;
  mod_c18_epilogue_d130();
  return;
}

