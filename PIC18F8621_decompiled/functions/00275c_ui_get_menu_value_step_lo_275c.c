// address 0x00275c  size 10 bytes
// callers: 001d9e,001d16,001c74,

/* Auto: reads menu_value_step_lo,menu_value_step_hi; 5 instr */

char ui_get_menu_value_step_lo_275c(void)

{
  byte unaff_BSR;
  
  return (c18_tmp1 - *(char *)((ushort)unaff_BSR * 0x100 + 0x9b)) -
         ~(*(byte *)((ushort)unaff_BSR * 0x100 + 0x9a) <= c18_tmp0);
}

