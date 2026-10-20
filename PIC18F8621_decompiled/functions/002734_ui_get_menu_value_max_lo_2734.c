// address 0x002734  size 10 bytes
// callers: 001cb6,001c32,001d5e,

/* Auto: reads menu_value_max_lo; 5 instr */

char ui_get_menu_value_max_lo_2734(void)

{
  byte unaff_BSR;
  
  return (*(char *)((ushort)unaff_BSR * 0x100 + 0x99) - c18_tmp1) -
         ~(c18_tmp0 <= *(byte *)((ushort)unaff_BSR * 0x100 + 0x98));
}

