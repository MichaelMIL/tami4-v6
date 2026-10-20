// address 0x00af68  size 54 bytes
// callers: 00af08,00ace2,00acd2,00af54,

/* Flow factor from WATERFLOW (x100/60) */

void portion_calc_flow(void)

{
  byte bVar1;
  
  bVar1 = dispense_read_param(0x26);
  math_aarg_lo = (undefined1)((ushort)bVar1 * 100);
  math_aarg_hi = (undefined1)((ushort)bVar1 * 100 >> 8);
  math_barg_lo = 0x3c;
  math_barg_hi = 0;
  portion_flow_lo = math_aarg_lo;
  portion_flow_hi = math_aarg_hi;
  __divs16();
  portion_flow_lo = math_aarg_lo;
  portion_flow_hi = math_aarg_hi;
  return;
}

