// address 0x00d480  size 16 bytes
// callers: 00d3a2,00d174,

/* Reset pull-down measurement: 120 min idle wait */

undefined1 cooling_reset_pulldown(void)

{
  cooling_idle_minutes = 0x78;
  pulldown_time_lo = 0;
  pulldown_time_hi = 0;
  cooling_flags = cooling_flags & 0xfc;
  return 0x78;
}

