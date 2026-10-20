// address 0x00dca2  size 44 bytes
// callers: 00b104,

/* Per second: UV on-time, verify-off, filament and verify-period countdowns */

char uv_second_tick(void)

{
  char cVar1;
  
  if (uv_on_timer != '\0') {
    uv_on_timer = uv_on_timer + -1;
  }
  if (uv_verify_off_timer != '\0') {
    uv_verify_off_timer = uv_verify_off_timer + -1;
    if (uv_verify_off_timer == '\0') {
      uv_verify_retries = 3;
    }
  }
  if (uv_verify_period_timer != '\0') {
    uv_verify_period_timer = uv_verify_period_timer + -1;
  }
  cVar1 = -uv_filament_timer;
  if (uv_filament_timer != '\0') {
    uv_filament_timer = uv_filament_timer + -1;
  }
  return cVar1;
}

