// address 0x002580  size 10 bytes
// callers: 000342,000304,

/* Store enter-callback high byte and install defaults */

void menu_set_cbs_enter_hi(undefined1 param_1)

{
  byte unaff_BSR;
  
  *(undefined1 *)((ushort)unaff_BSR * 0x100 + 0x35) = param_1;
  *(undefined1 *)((ushort)unaff_BSR * 0x100 + 0x36) = 0xf2;
  menu_clear_cbs(0x1b);
  return;
}

