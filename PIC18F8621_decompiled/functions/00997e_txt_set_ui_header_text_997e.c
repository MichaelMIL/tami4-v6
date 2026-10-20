// address 0x00997e  size 16 bytes
// callers: 0096c0,

/* Auto: writes ui_header_text; reads text_char,TABLAT; 7 instr */

undefined1 txt_set_ui_header_text_997e(void)

{
  byte bVar1;
  byte unaff_BSR;
  undefined1 *in_TBLPTR;
  
  txt_get_printf_fmt_lo_9ab0();
  bVar1 = *(byte *)((ushort)unaff_BSR * 0x100 + 10);
  *(byte *)((ushort)unaff_BSR * 0x100 + 10) = bVar1 + 1;
  *(char *)((ushort)unaff_BSR * 0x100 + 0xb) =
       *(char *)((ushort)unaff_BSR * 0x100 + 0xb) + (0xfe < bVar1);
  text_char = *in_TBLPTR;
  return 0;
}

