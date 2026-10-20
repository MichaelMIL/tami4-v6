// address 0x00cb0c  size 36 bytes
// callers: 0092e6,

/* Auto: writes lcd_text_flag,lcd_text_width; reads lcd_text_width; 18 instr */

void mod_set_lcd_text_flag_cb0c(void)

{
  char cVar1;
  byte unaff_Z;
  bool bVar2;
  
  mod_calc_array_ptr_cd10();
  if ((unaff_Z & 1) == 0) {
    lcd_text_flag = '\0';
    lcd_text_width = '\0';
    bVar2 = true;
    while (mod_get_lcd_text_flag_ccf2(), cVar1 = lcd_text_width, !bVar2) {
      mod_get_lcd_text_flag_ccf2();
      mod_get_TBLPTRH_cd48();
      cVar1 = mod_frag_cda0();
      lcd_text_flag = lcd_text_flag + '\x01';
      lcd_text_width = lcd_text_width + cVar1 + '\x01';
      bVar2 = lcd_text_width == '\0';
    }
  }
  else {
    cVar1 = '\0';
  }
  mod_c18_epilogue_cd24(cVar1);
  return;
}

