// address 0x00b006  size 16 bytes
// callers: 00ac80,00ac34,

/* Clear portion timers and mode */

void portion_clear(void)

{
  byte unaff_BSR;
  
  *(undefined1 *)((ushort)unaff_BSR * 0x100 + 0x80) = 0xff;
  *(undefined1 *)((ushort)unaff_BSR * 0x100 + 0x81) = 0xff;
  *(undefined1 *)((ushort)unaff_BSR * 0x100 + 0x82) = 0xff;
  *(undefined1 *)((ushort)unaff_BSR * 0x100 + 0x83) = 0xff;
  *(undefined1 *)((ushort)unaff_BSR * 0x100 + 0x84) = 0xff;
  *(undefined1 *)((ushort)unaff_BSR * 0x100 + 0x85) = 0xff;
  *(undefined1 *)((ushort)unaff_BSR * 0x100 + 0x7f) = 0;
  return;
}

