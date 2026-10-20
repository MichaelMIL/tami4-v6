// address 0x00dd52  size 8 bytes
// callers: 00da82,00dc32,

/* Load UV on-time from given parameter */

void uv_load_on_time(void)

{
  uv_on_time = uv_read_param();
  return;
}

