// address 0x00ce12  size 12 bytes
// callers: 00caf0,00cad4,

/* Auto: writes lcd_text_flag,lcd_text_width; reads lcd_text_width; 6 instr */

void mod_set_lcd_text_flag_ce12(void)

{
  byte unaff_BSR;
  byte bVar1;
  
  bVar1 = mod_get_TBLPTRH_cd48();
  *(byte *)((ushort)unaff_BSR * 0x100 + 0xe7) =
       *(char *)((ushort)unaff_BSR * 0x100 + 0xe7) + (bVar1 & 0xf);
  *(char *)((ushort)unaff_BSR * 0x100 + 0xe8) = *(char *)((ushort)unaff_BSR * 0x100 + 0xe8) + '\x01'
  ;
  *(char *)((ushort)unaff_BSR * 0x100 + 0xe7) = *(char *)((ushort)unaff_BSR * 0x100 + 0xe7) + '\x01'
  ;
  return;
}

