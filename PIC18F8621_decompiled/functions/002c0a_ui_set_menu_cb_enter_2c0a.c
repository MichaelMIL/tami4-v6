// address 0x002c0a  size 10 bytes
// callers: 0026ce,002670,0029fa,

/* Auto: writes menu_cb_enter,menu_cb_enter_hi,menu_cb_back,menu_cb_back_hi; 5 instr */

void ui_set_menu_cb_enter_2c0a(void)

{
  byte unaff_BSR;
  
  *(undefined1 *)((ushort)unaff_BSR * 0x100 + 0x34) = 0;
  *(undefined1 *)((ushort)unaff_BSR * 0x100 + 0x35) = 0;
  *(undefined1 *)((ushort)unaff_BSR * 0x100 + 0x36) = 0;
  *(undefined1 *)((ushort)unaff_BSR * 0x100 + 0x37) = 0;
  return;
}

