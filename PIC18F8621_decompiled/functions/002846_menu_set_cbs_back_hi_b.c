// address 0x002846  size 20 bytes
// callers: 00254a,002150,002434,

/* Store back-callback high byte (variant) */

undefined1 menu_set_cbs_back_hi_b(undefined1 param_1)

{
  byte unaff_BSR;
  
  *(undefined1 *)((ushort)unaff_BSR * 0x100 + 0x37) = param_1;
  *(undefined1 *)((ushort)unaff_BSR * 0x100 + 0x38) = 0xfa;
  *(undefined1 *)((ushort)unaff_BSR * 0x100 + 0x39) = 0x1b;
  *(undefined1 *)((ushort)unaff_BSR * 0x100 + 0x3a) = 0xfa;
  *(undefined1 *)((ushort)unaff_BSR * 0x100 + 0x3b) = 0x1b;
  return 0x1b;
}

