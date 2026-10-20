// address 0x00dc96  size 12 bytes
// callers: 00b0aa,

/* Every 100 ms: count down lamp verify delay */

char uv_verify_100ms_tick(void)

{
  char cVar1;
  
  cVar1 = -uv_verify_delay;
  if (uv_verify_delay != '\0') {
    uv_verify_delay = uv_verify_delay + -1;
  }
  return cVar1;
}

