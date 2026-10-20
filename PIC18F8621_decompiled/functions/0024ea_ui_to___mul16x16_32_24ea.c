// address 0x0024ea  size 16 bytes
// callers: 00054e,001a54,000596,

/* Auto: reads menu_value_lo,menu_value_hi; calls __mul16x16_32; 5 instr */

void ui_to___mul16x16_32_24ea(undefined1 param_1)

{
  math_aarg_hi = 0;
  math_barg_lo = menu_value_lo;
  math_barg_hi = menu_value_hi;
  math_aarg_lo = param_1;
  __mul16x16_32();
  return;
}

