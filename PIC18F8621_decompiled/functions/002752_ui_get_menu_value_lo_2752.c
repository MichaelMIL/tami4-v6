// address 0x002752  size 10 bytes
// callers: 001d9e,001d16,001c74,

/* Auto: reads menu_value_lo,menu_value_step_lo,menu_value_hi; 5 instr */

char ui_get_menu_value_lo_2752(void)

{
  byte unaff_BSR;
  
  return (*(char *)((ushort)unaff_BSR * 0x100 + 0x9b) - *(char *)((ushort)unaff_BSR * 0x100 + 0x95))
         - ~(*(byte *)((ushort)unaff_BSR * 0x100 + 0x94) <=
            *(byte *)((ushort)unaff_BSR * 0x100 + 0x9a));
}

