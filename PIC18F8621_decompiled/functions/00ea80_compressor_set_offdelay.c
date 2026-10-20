// address 0x00ea80  size 10 bytes
// callers: 00e9b2,00e8ae,00e926,

/* Set restart delay counter */

undefined1 compressor_set_offdelay(undefined1 param_1)

{
  compressor_offdelay_lo = param_1;
  compressor_offdelay_hi = 0;
  return 0xc;
}

