// address 0x00dd34  size 10 bytes
// callers: 00dd3e,

/* Set UV period countdown (and 10-minute sub-counter) */

undefined1 uv_set_period(undefined1 param_1)

{
  uv_period_counter = param_1;
  uv_period_subcounter = 10;
  return 10;
}

