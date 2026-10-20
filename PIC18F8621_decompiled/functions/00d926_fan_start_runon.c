// address 0x00d926  size 16 bytes
// callers: 00e926,

/* Start fan run-on after compressor stop (TFANOPERATING minutes) */

char fan_start_runon(void)

{
  char cVar1;
  
  cVar1 = fan_read_param(0x3d);
  fan_runon_lo = cVar1 * '<';
  fan_runon_hi = 0;
  return cVar1 * '<';
}

