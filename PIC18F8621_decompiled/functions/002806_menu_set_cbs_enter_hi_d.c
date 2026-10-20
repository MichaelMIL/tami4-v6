// address 0x002806  size 20 bytes
// callers: 000cf8,000ccc,000d22,

/* Store enter-callback high byte (variant) */

void menu_set_cbs_enter_hi_d(undefined1 param_1)

{
  byte unaff_BSR;
  
  *(undefined1 *)((ushort)unaff_BSR * 0x100 + 0x35) = param_1;
  *(undefined1 *)((ushort)unaff_BSR * 0x100 + 0x38) = 0xdc;
  *(undefined1 *)((ushort)unaff_BSR * 0x100 + 0x39) = 0x1d;
  *(undefined1 *)((ushort)unaff_BSR * 0x100 + 0x3a) = 0xe2;
  menu_set_cbs_down_hi(0x1d);
  return;
}

