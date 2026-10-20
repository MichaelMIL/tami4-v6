// address 0x002972  size 20 bytes
// callers: 0011e2,002198,

/* Store back-callback high byte and install defaults */

undefined1 menu_set_cbs_back_hi(undefined1 param_1)

{
  byte unaff_BSR;
  
  *(undefined1 *)((ushort)unaff_BSR * 0x100 + 0x37) = param_1;
  *(undefined1 *)((ushort)unaff_BSR * 0x100 + 0x38) = 0x98;
  *(undefined1 *)((ushort)unaff_BSR * 0x100 + 0x39) = 0;
  *(undefined1 *)((ushort)unaff_BSR * 0x100 + 0x3a) = 0x98;
  *(undefined1 *)((ushort)unaff_BSR * 0x100 + 0x3b) = 0;
  return 0;
}

