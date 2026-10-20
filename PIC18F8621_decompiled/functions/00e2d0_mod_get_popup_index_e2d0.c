// address 0x00e2d0  size 44 bytes
// callers: 003b12,

/* Auto: reads popup_index; 22 instr */

void mod_get_popup_index_e2d0(void)

{
  BADSPACEBASE *in_FSR2;
  BADSPACEBASE *in_FSR1;
  undefined1 *puVar1;
  undefined1 *puVar2;
  undefined1 *puVar3;
  
  mod_c18_prologue_e3fc();
  puVar1 = (undefined1 *)((short)in_FSR1 + 1);
  *(undefined1 *)in_FSR1 = *(undefined1 *)in_FSR1;
  *(char *)in_FSR2 = popup_index * '\x05' + '\x03';
  c18_tmp0 = *(undefined1 *)in_FSR2;
  c18_tmp1 = 0;
  mod_to_mod_to___divs16_e3ec();
  puVar2 = puVar1;
  while( true ) {
    if (*(char *)in_FSR2 == '\0') break;
    puVar3 = puVar2 + 1;
    *puVar2 = 0;
    mod_to_lcd_write_data_e44e();
    puVar2 = puVar3;
  }
  *puVar2 = *puVar2;
  mod_c18_epilogue_e40e(0);
  return;
}

