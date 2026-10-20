// address 0x00cad4  size 28 bytes
// callers: 0092da,

/* WARNING: Removing unreachable block (CODE,0x00cae6) */
/* Auto: writes lcd_text_flag,lcd_text_width; reads lcd_text_width; 14 instr */

void mod_set_lcd_text_flag_cad4(void)

{
  undefined1 uVar1;
  byte unaff_Z;
  
  mod_calc_array_ptr_cd10();
  if ((unaff_Z & 1) == 0) {
    lcd_text_flag = 0;
    lcd_text_width = 0;
    mod_get_lcd_text_flag_ccf2();
    uVar1 = lcd_text_width;
  }
  else {
    uVar1 = 0;
  }
  mod_c18_epilogue_cd24(uVar1);
  return;
}

