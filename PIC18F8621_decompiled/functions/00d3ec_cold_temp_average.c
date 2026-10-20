// address 0x00d3ec  size 46 bytes
// callers: (none: entry point, task, or reached via pointer)

/* Average of the two cold tank temperatures */

byte cold_temp_average(void)

{
  portion_flow_lo = '\0';
  if ((cold_temp_b & 0x80) != 0) {
    portion_flow_lo = -1;
  }
  c18_tmp1 = '\0';
  if ((cold_temp_a & 0x80) != 0) {
    c18_tmp1 = -1;
  }
  local4 = cold_temp_b + cold_temp_a;
  portion_flow_lo = portion_flow_lo + c18_tmp1 + CARRY1(cold_temp_b,cold_temp_a);
  c18_tmp1 = portion_flow_lo >> 1;
  c18_tmp0 = cold_temp_b + cold_temp_a >> 1 | portion_flow_lo * -0x80;
  return c18_tmp0;
}

