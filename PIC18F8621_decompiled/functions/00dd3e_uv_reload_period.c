// address 0x00dd3e  size 8 bytes
// callers: 00dbe6,00da82,

/* Reload UV period from TUVPERIOD_T3_26 */

void uv_reload_period(void)

{
  uv_read_param(0xe);
  uv_set_period();
  return;
}

