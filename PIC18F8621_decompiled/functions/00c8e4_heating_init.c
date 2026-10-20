// address 0x00c8e4  size 18 bytes
// callers: 00b256,

/* Initialise heating state */

undefined1 heating_init(void)

{
  heating_flags = 8;
  heating_fault = 0;
  heating_startup_timer = heating_read_param(0x27);
  return 0;
}

