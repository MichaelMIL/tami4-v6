// address 0x009f10  size 32 bytes
// callers: 00b482,

/* Salvo: advance OS timer tick counters */

undefined1 OSTimer(void)

{
  OStimerTicks = OStimerTicks + '\x01';
  c18_tmp0 = OSlostTicks;
  c18_tmp1 = 0;
  if (0xfe < OSlostTicks != true) {
    return 1;
  }
  OSlostTicks = OSlostTicks + 1;
  return 0;
}

