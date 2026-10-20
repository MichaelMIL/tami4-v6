// address 0x002826  size 32 bytes
// callers: 000c32,000c62,

/* Auto: writes menu_cb_enter,menu_cb_enter_hi,menu_cb_up,menu_cb_up_hi,menu_cb_down; calls
   menu_set_cbs_down_hi; 15 instr */

void ui_to_menu_set_cbs_down_hi_2826(void)

{
  byte unaff_BSR;
  
  ui_to_screen_cold_temp_bar_2684(c18_tmp0);
  *(undefined1 *)((ushort)unaff_BSR * 0x100 + 0x34) = 0x94;
  *(undefined1 *)((ushort)unaff_BSR * 0x100 + 0x35) = 0xc;
  *(undefined1 *)((ushort)unaff_BSR * 0x100 + 0x38) = 0x9e;
  *(undefined1 *)((ushort)unaff_BSR * 0x100 + 0x39) = 0xc;
  *(undefined1 *)((ushort)unaff_BSR * 0x100 + 0x3a) = 0xa6;
  menu_set_cbs_down_hi(0xc);
  return;
}

