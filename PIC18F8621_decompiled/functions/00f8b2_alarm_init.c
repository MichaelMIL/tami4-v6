// address 0x00f8b2  size 10 bytes
// callers: 00b256,

/* Clear UV status and alarm code */

undefined1 alarm_init(void)

{
  uv_status = 0;
  uv_alarm_code = 0;
  return 0;
}

