// address 0x00fc40  size 8 bytes
// callers: 00dbe6,

/* Clear UV service override */

undefined1 uv_service_clear(void)

{
  uv_service_override = 0;
  return 0;
}

