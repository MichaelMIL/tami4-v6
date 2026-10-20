// address 0x002778  size 8 bytes
// callers: 000da0,0004a0,00054e,000458,0006aa,

/* Auto: reads menu_value_lo,menu_value_hi; 4 instr */

byte ui_get_menu_value_lo_2778(void)

{
  return menu_value_hi | menu_value_lo;
}

