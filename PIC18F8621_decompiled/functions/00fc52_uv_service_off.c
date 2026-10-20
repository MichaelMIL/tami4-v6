// address 0x00fc52  size 10 bytes
// callers: 00da82,

/* Drive RF5 low and set override flag (0x80) */

undefined1 uv_service_off(void)

{
  byte bVar1;
  
  bVar1 = PORTF;
  PORTF = bVar1 & ~RF5;
  uv_service_override = 0x80;
  return 0;
}

