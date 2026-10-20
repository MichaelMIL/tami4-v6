// address 0x00b510  size 8 bytes
// callers: 00009a,

/* Set wake request flag */

undefined1 system_request_wake(void)

{
  standby_countdown = 1;
  return 1;
}

