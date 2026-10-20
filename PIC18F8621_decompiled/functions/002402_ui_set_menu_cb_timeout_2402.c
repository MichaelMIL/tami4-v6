// address 0x002402  size 50 bytes
// callers: 00122e,001334,

/* Auto: writes
   menu_cb_timeout,menu_cb_timeout_hi,menu_cb_enter,menu_cb_enter_hi,menu_cb_back,menu_cb_back_hi;
   25 instr */

undefined1 ui_set_menu_cb_timeout_2402(void)

{
  byte unaff_BSR;
  
  *(undefined1 *)((ushort)unaff_BSR * 0x100 + 0x3e) = 0x7a;
  *(undefined1 *)((ushort)unaff_BSR * 0x100 + 0x3f) = 0x12;
  *(undefined1 *)((ushort)unaff_BSR * 0x100 + 0x34) = 4;
  *(undefined1 *)((ushort)unaff_BSR * 0x100 + 0x35) = 0x13;
  *(undefined1 *)((ushort)unaff_BSR * 0x100 + 0x36) = 4;
  *(undefined1 *)((ushort)unaff_BSR * 0x100 + 0x37) = 0x13;
  *(undefined1 *)((ushort)unaff_BSR * 0x100 + 0x38) = 4;
  *(undefined1 *)((ushort)unaff_BSR * 0x100 + 0x39) = 0x13;
  *(undefined1 *)((ushort)unaff_BSR * 0x100 + 0x3a) = 4;
  *(undefined1 *)((ushort)unaff_BSR * 0x100 + 0x3b) = 0x13;
  *(undefined1 *)((ushort)unaff_BSR * 0x100 + 0x3c) = 4;
  *(undefined1 *)((ushort)unaff_BSR * 0x100 + 0x3d) = 0x13;
  return 0x13;
}

