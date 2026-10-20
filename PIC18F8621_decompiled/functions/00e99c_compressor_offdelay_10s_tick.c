// address 0x00e99c  size 22 bytes
// callers: 00b104,

/* Every 10 s: count down restart delay */

undefined1 compressor_offdelay_10s_tick(undefined1 param_1)

{
  bool bVar1;
  
  if (((outputs_shadow & 0x40) == 0) &&
     (param_1 = 0, compressor_offdelay_hi != '\0' || compressor_offdelay_lo != '\0')) {
    bVar1 = compressor_offdelay_lo != '\0';
    compressor_offdelay_lo = compressor_offdelay_lo + -1;
    param_1 = 0;
    compressor_offdelay_hi = compressor_offdelay_hi - ~bVar1;
  }
  return param_1;
}

