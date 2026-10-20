// address 0x00dbe6  size 34 bytes
// callers: 00b256,

/* Initialise UV lamp state */

undefined1 uv_init(void)

{
  uv_flags = 0;
  uv_filament_timer = uv_read_param(0xf);
  uv_verify_delay = 0;
  uv_on_time = 0;
  uv_verify_off_timer = 0;
  uv_verify_retries = 0;
  uv_verify_period_timer = 0;
  uv_long_verify_timer = 0;
  uv_reload_period();
  uv_on_timer = 0;
  uv_service_clear();
  return 0;
}

