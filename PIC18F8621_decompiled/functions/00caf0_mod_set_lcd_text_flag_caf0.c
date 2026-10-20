// address 0x00caf0  size 28 bytes
// callers: (none: entry point, task, or reached via pointer)

/* WARNING: Removing unreachable block (CODE,0x00cb02) */
/* Auto: writes lcd_text_flag,lcd_text_width; reads lcd_text_width; 14 instr */

void mod_set_lcd_text_flag_caf0(void)

{
  undefined1 uVar1;
  byte unaff_Z;
  
  mod_calc_array_ptr_cd10();
  if ((unaff_Z & 1) == 0) {
    lcd_text_flag = 0;
    lcd_text_width = 0;
    mod_get_lcd_text_flag_cde4();
    uVar1 = lcd_text_width;
  }
  else {
    uVar1 = 0;
  }
  mod_c18_epilogue_cd24(uVar1);
  return;
}

