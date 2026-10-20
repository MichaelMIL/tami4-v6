// address 0x00dd46  size 12 bytes
// callers: 00da82,

/* Reload lamp verify delay from TUVOPERATING_T3_26 (x10) */

void uv_reload_verify_delay(void)

{
  char cVar1;
  
  cVar1 = uv_read_param(0x11);
  uv_verify_delay = cVar1 * '\n';
  return;
}

