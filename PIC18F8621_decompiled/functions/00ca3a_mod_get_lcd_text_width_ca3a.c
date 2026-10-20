// address 0x00ca3a  size 22 bytes
// callers: 00cdc6,

/* Auto: reads lcd_text_width,TABLAT; 11 instr */

void mod_get_lcd_text_width_ca3a(void)

{
  byte bVar1;
  byte unaff_BSR;
  BADSPACEBASE *in_FSR1;
  byte bVar2;
  byte in_TABLAT;
  
  mod_set_lcd_text_width_cd74();
  while( true ) {
    bVar2 = mod_to_mod_get_TBLPTRH_cdec();
    bVar1 = *(byte *)((ushort)unaff_BSR * 0x100 + 0xe7);
    if ((bVar2 & 0xf) <= bVar1) break;
    mod_get_c18_tmp0_cd58();
    mod_set_lcd_text_width_cdac(~in_TABLAT);
  }
  *(undefined1 *)in_FSR1 = 0xff;
  mod_to_lcd_write_data_ce1e(bVar1 - (bVar2 & 0xf));
  return;
}

