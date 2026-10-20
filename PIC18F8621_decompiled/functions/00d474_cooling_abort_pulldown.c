// address 0x00d474  size 8 bytes
// callers: 00f816,

/* Cancel pull-down measurement (cold water drawn) */

void cooling_abort_pulldown(void)

{
  cooling_flags = cooling_flags & 0xfc;
  return;
}

