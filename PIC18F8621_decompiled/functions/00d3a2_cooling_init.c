// address 0x00d3a2  size 14 bytes
// callers: 00b256,

/* Initialise cooling state */

undefined1 cooling_init(void)

{
  cooling_flags = 0;
  cold_temp_a = 0;
  cold_temp_b = 0;
  cooling_fault = 0;
  cooling_reset_pulldown();
  return 0;
}

