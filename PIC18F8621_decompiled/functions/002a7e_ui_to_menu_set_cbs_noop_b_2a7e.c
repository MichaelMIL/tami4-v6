// address 0x002a7e  size 12 bytes
// callers: 001684,0012d0,

/* Auto: writes menu_cb_key,menu_cb_key_hi; calls menu_set_cbs_noop_b,menu_set_cbs_noop; 5 instr */

void ui_to_menu_set_cbs_noop_b_2a7e(void)

{
  byte unaff_BSR;
  
  menu_set_cbs_noop_b();
  menu_set_cbs_noop();
  *(undefined1 *)((ushort)unaff_BSR * 0x100 + 0x3c) = 0;
  *(undefined1 *)((ushort)unaff_BSR * 0x100 + 0x3d) = 0;
  return;
}

