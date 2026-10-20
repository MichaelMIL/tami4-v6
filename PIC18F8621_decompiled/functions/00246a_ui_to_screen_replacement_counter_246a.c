// address 0x00246a  size 16 bytes
// callers: 000f1c,000f2e,

/* Auto: writes menu_cb_back,menu_cb_back_hi,menu_cb_down_hi; calls
   screen_replacement_counter,menu_set_cbs_updown_default; 8 instr */

void ui_to_screen_replacement_counter_246a(void)

{
  byte unaff_BSR;
  undefined1 uVar1;
  
  screen_replacement_counter();
  *(undefined1 *)((ushort)unaff_BSR * 0x100 + 0x36) = 0xb8;
  *(undefined1 *)((ushort)unaff_BSR * 0x100 + 0x37) = 0xd;
  uVar1 = menu_set_cbs_updown_default();
  *(undefined1 *)((ushort)unaff_BSR * 0x100 + 0x3b) = uVar1;
  return;
}

