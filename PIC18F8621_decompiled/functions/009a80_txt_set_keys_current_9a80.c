// address 0x009a80  size 10 bytes
// callers: 0096c0,

/* Auto: writes keys_current; 5 instr */

undefined1 txt_set_keys_current_9a80(void)

{
  byte bVar1;
  byte unaff_BSR;
  
  txt_get_printf_out_lo_99b6();
  bVar1 = *(byte *)((ushort)unaff_BSR * 0x100 + 0xc);
  *(byte *)((ushort)unaff_BSR * 0x100 + 0xc) = bVar1 + 1;
  *(char *)((ushort)unaff_BSR * 0x100 + 0xd) =
       *(char *)((ushort)unaff_BSR * 0x100 + 0xd) + (0xfe < bVar1);
  return 0;
}

