// address 0x002882  size 26 bytes
// callers: 000814,000806,

/* Auto: writes menu_cb_up,menu_cb_up_hi,menu_cb_down,menu_cb_enter,menu_cb_enter_hi; calls
   menu_set_cbs_down_hi; 13 instr */

undefined1 ui_to_menu_set_cbs_down_hi_2882(void)

{
  byte unaff_BSR;
  
  *(undefined1 *)((ushort)unaff_BSR * 0x100 + 0x38) = 0x94;
  *(undefined1 *)((ushort)unaff_BSR * 0x100 + 0x39) = 7;
  *(undefined1 *)((ushort)unaff_BSR * 0x100 + 0x3a) = 0x88;
  menu_set_cbs_down_hi(7);
  *(undefined1 *)((ushort)unaff_BSR * 0x100 + 0x34) = 0xfe;
  *(undefined1 *)((ushort)unaff_BSR * 0x100 + 0x35) = 7;
  return 7;
}

