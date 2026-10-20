// address 0x002720  size 10 bytes
// callers: 000656,0005a6,0004cc,

/* Auto: writes menu_value_lo; 5 instr */

undefined1 ui_set_menu_value_lo_2720(void)

{
  bool bVar1;
  
  bVar1 = 0xfe < menu_value_lo;
  menu_value_lo = menu_value_lo + 1;
  menu_value_hi = menu_value_hi + bVar1;
  return 0;
}

