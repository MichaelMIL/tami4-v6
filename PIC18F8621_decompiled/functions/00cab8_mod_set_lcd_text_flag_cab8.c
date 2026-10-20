// address 0x00cab8  size 28 bytes
// callers: 00930a,

/* Auto: writes lcd_text_flag; 14 instr */

void mod_set_lcd_text_flag_cab8(void)

{
  BADSPACEBASE *in_FSR1;
  undefined1 *puVar1;
  undefined1 uVar2;
  byte unaff_Z;
  bool bVar3;
  
  mod_calc_array_ptr_cd10();
  if ((unaff_Z & 1) == 0) {
    lcd_text_flag = '\0';
    bVar3 = true;
    while( true ) {
      mod_get_lcd_text_flag_ccf2();
      if (bVar3) break;
      uVar2 = mod_get_lcd_text_flag_ccf2();
      puVar1 = (undefined1 *)((short)in_FSR1 + 1);
      *(undefined1 *)in_FSR1 = uVar2;
      mod_get_lcd_text_width_ca50();
      in_FSR1 = (BADSPACEBASE *)(puVar1 + -1);
      *puVar1 = *puVar1;
      lcd_text_flag = lcd_text_flag + '\x01';
      bVar3 = lcd_text_flag == '\0';
    }
  }
  mod_c18_epilogue_cd24();
  return;
}

