// address 0x00cde4  size 8 bytes
// callers: 00ca90,00caa4,00caf0,

/* Auto: reads lcd_text_flag; 4 instr */

undefined1 mod_get_lcd_text_flag_cde4(void)

{
  byte unaff_BSR;
  BADSPACEBASE *in_FSR0;
  
  mod_frame_access_cd30(*(undefined1 *)((ushort)unaff_BSR * 0x100 + 0xe8));
  return *(undefined1 *)in_FSR0;
}

