// address 0x0099ea  size 22 bytes
// callers: 0095f2,

/* Auto: reads printf_out_lo,printf_out_hi,printf_args_lo,printf_args_hi; 7 instr */

undefined1 txt_get_printf_out_lo_99ea(void)

{
  byte unaff_BSR;
  byte unaff_C;
  
  *(byte *)((ushort)unaff_BSR * 0x100 + 0xf) =
       *(char *)((ushort)unaff_BSR * 0x100 + 0xf) - ~(unaff_C & 1);
  return 0;
}

