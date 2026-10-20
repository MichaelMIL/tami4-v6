// address 0x00fc48  size 10 bytes
// callers: 00da82,

/* Drive RF5 high (UV service/test) and clear override */

undefined1 uv_service_on(void)

{
  byte bVar1;
  
  bVar1 = PORTF;
  PORTF = bVar1 | RF5;
  uv_service_override = 0;
  return 0;
}

