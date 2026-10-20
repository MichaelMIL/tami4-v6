// address 0x00e290  size 42 bytes
// callers: 003b12,

/* Auto: Small wrapper around mod_get_c18_tmp0; 21 instr */

void mod_to_mod_get_c18_tmp0_e290(void)

{
  BADSPACEBASE *in_FSR2;
  undefined1 *puVar1;
  BADSPACEBASE *in_FSR1;
  undefined1 *puVar2;
  undefined1 *puVar3;
  bool bVar4;
  
  mod_stack_adjust_e496();
  bVar4 = 0xfc < (byte)(popup_index * '\x05');
  mod_to_mod_get_c18_tmp0_e47e(popup_index * '\x05' + 3);
  puVar1 = (undefined1 *)in_FSR2;
  puVar2 = (undefined1 *)in_FSR1;
  while( true ) {
    mod_get_c18_tmp0_e436();
    if ((c18_tmp1 & 0x80) != 0) break;
    puVar3 = puVar2 + 1;
    *puVar2 = 0;
    mod_to_lcd_write_data_e44e();
    puVar2 = puVar3;
    if (!bVar4) {
      bVar4 = puVar1[3] != '\0';
      puVar1[2] = puVar1[3] + -1;
      puVar1 = puVar1 + 2;
    }
  }
  *puVar2 = *puVar2;
  puVar2[-1] = puVar2[-1];
  mod_c18_epilogue_e40e(c18_tmp1 & 0x80);
  return;
}

