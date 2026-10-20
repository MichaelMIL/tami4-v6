// address 0x00dcce  size 76 bytes
// callers: 00b104,

/* Per minute: UV period countdown, long-verify timer, usage counters */

char uv_minute_tick(void)

{
  BADSPACEBASE *in_FSR1;
  undefined1 *puVar1;
  char cVar2;
  
  if ((((uv_flags & 1) == 0) && (uv_period_counter != '\0')) &&
     (uv_period_subcounter = uv_period_subcounter + -1, uv_period_subcounter == '\0')) {
    uv_period_counter = uv_period_counter + -1;
    uv_period_subcounter = '\n';
  }
  if (uv_long_verify_timer == '\0') {
    uv_long_verify_timer = uv_read_param(0x49);
    if (uv_verify_off_timer == '\0') {
      uv_verify_retries = 3;
    }
  }
  else {
    uv_long_verify_timer = uv_long_verify_timer + -1;
  }
  cVar2 = uv_service_override;
  if (uv_service_override == '\0') {
    puVar1 = (undefined1 *)((short)in_FSR1 + 1);
    *(undefined1 *)in_FSR1 = 6;
    stat_counter_inc();
    *puVar1 = *puVar1;
    puVar1[-1] = 6;
    cVar2 = stat_counter_save();
    *puVar1 = *puVar1;
  }
  return cVar2;
}

