// address 0x0092f2  size 12 bytes
// callers: 00096e,

/* Auto: Small wrapper around mod_set_lcd_text_flag; 5 instr */

void txt_to_mod_set_lcd_text_flag_92f2(void)

{
  BADSPACEBASE *in_FSR1;
  
  txt_to_txt_get_c18_tmp0_9964();
  mod_set_lcd_text_flag_ca68();
  *(undefined1 *)in_FSR1 = *(undefined1 *)in_FSR1;
  *(undefined1 *)((short)in_FSR1 + -1) = *(undefined1 *)((short)in_FSR1 + -1);
  txt_c18_epilogue_9972();
  return;
}

