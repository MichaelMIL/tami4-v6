// address 0x00289c  size 14 bytes
// callers: 00122e,0022aa,001a54,0004f6,

/* Auto: reads math_aarg_lo,math_aarg_hi; calls __divs16; 4 instr */

void ui_to___divs16_289c(void)

{
  __divs16();
  menu_value_lo = math_aarg_lo;
  menu_value_hi = math_aarg_hi;
  return;
}

