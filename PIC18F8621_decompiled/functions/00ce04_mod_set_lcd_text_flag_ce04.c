// address 0x00ce04  size 14 bytes
// callers: 00cb86,00cbf2,

/* Auto: writes lcd_text_flag; reads lcd_text_flag; 6 instr */

undefined1 mod_set_lcd_text_flag_ce04(void)

{
  undefined1 uVar1;
  BADSPACEBASE *in_FSR2;
  byte unaff_BSR;
  BADSPACEBASE *in_FSR0;
  
  uVar1 = *(undefined1 *)((ushort)unaff_BSR * 0x100 + 0xe8);
  *(char *)((ushort)unaff_BSR * 0x100 + 0xe8) = *(char *)((ushort)unaff_BSR * 0x100 + 0xe8) + '\x01'
  ;
  mod_frame_access_cd30(uVar1);
  *(undefined1 *)in_FSR2 = *(undefined1 *)in_FSR0;
  return *(undefined1 *)in_FSR2;
}

