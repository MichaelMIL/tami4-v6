// address 0x002248  size 12 bytes
// callers: 002826,000d58,000b9c,000a90,002882,002806,0027bc,0005d0,0004f6,000b2c,00066c,

/* Store down-callback high byte and install defaults */

undefined1 menu_set_cbs_down_hi(undefined1 param_1)

{
  byte unaff_BSR;
  
  *(undefined1 *)((ushort)unaff_BSR * 0x100 + 0x3b) = param_1;
  *(undefined1 *)((ushort)unaff_BSR * 0x100 + 0x36) = 0xf2;
  *(undefined1 *)((ushort)unaff_BSR * 0x100 + 0x37) = 0x1b;
  return 0x1b;
}

