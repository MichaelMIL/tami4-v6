// address 0x00272a  size 10 bytes
// callers: 001cb6,001c32,001d5e,

/* Auto: reads menu_value_max_lo,menu_value_lo,menu_value_max_hi; 5 instr */

char ui_get_menu_value_max_lo_272a(void)

{
  byte unaff_BSR;
  
  return (*(char *)((ushort)unaff_BSR * 0x100 + 0x95) - *(char *)((ushort)unaff_BSR * 0x100 + 0x99))
         - ~(*(byte *)((ushort)unaff_BSR * 0x100 + 0x98) <=
            *(byte *)((ushort)unaff_BSR * 0x100 + 0x94));
}

