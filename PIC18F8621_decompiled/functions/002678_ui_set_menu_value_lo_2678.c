// address 0x002678  size 12 bytes
// callers: 000642,0004e2,0005bc,

/* Auto: writes menu_value_lo; 6 instr */

byte ui_set_menu_value_lo_2678(void)

{
  bool bVar1;
  
  bVar1 = menu_value_lo != '\0';
  menu_value_lo = menu_value_lo - 1;
  menu_value_hi = menu_value_hi - ~bVar1;
  return ~menu_value_lo;
}

