// address 0x00ca90  size 20 bytes
// callers: 005036,

/* WARNING: Removing unreachable block (CODE,0x00ca9c) */
/* Auto: writes lcd_text_flag; 10 instr */

void mod_set_lcd_text_flag_ca90(void)

{
  byte unaff_Z;
  
  mod_calc_array_ptr_cd10();
  if ((unaff_Z & 1) == 0) {
    lcd_text_flag = 0;
    mod_get_lcd_text_flag_cde4();
  }
  mod_c18_epilogue_cd24();
  return;
}

