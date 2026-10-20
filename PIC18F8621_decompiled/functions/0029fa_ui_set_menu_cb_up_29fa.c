// address 0x0029fa  size 12 bytes
// callers: 0021fc,002454,

/* Auto: writes menu_cb_up,menu_cb_up_hi,menu_cb_down,menu_cb_down_hi; 6 instr */

void ui_set_menu_cb_up_29fa(void)

{
  byte unaff_BSR;
  
  ui_set_menu_cb_enter_2c0a();
  *(undefined1 *)((ushort)unaff_BSR * 0x100 + 0x38) = 0;
  *(undefined1 *)((ushort)unaff_BSR * 0x100 + 0x39) = 0;
  *(undefined1 *)((ushort)unaff_BSR * 0x100 + 0x3a) = 0;
  *(undefined1 *)((ushort)unaff_BSR * 0x100 + 0x3b) = 0;
  return;
}

