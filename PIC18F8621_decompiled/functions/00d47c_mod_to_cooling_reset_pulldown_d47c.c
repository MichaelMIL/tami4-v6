// address 0x00d47c  size 4 bytes
// callers: 00f84c,

/* Auto: calls cooling_reset_pulldown; 1 instr */

undefined1 mod_to_cooling_reset_pulldown_d47c(void)

{
  cooling_idle_minutes = 0x78;
  pulldown_time_lo = 0;
  pulldown_time_hi = 0;
  cooling_flags = cooling_flags & 0xfc;
  return 0x78;
}

