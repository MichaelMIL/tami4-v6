// address 0x009a4c  size 14 bytes
// callers: 0096c0,

/* Auto: reads printf_args_lo,printf_args_hi; 5 instr */

undefined1 txt_get_printf_args_lo_9a4c(void)

{
  byte unaff_BSR;
  byte unaff_C;
  
  *(byte *)((ushort)unaff_BSR * 0x100 + 0xf) =
       *(char *)((ushort)unaff_BSR * 0x100 + 0xf) - ~(unaff_C & 1);
  return 0;
}

