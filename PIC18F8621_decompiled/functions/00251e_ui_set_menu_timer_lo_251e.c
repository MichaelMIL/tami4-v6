// address 0x00251e  size 14 bytes
// callers: 0013ce,001780,00111c,001334,

/* Auto: writes
   menu_timer_lo,menu_timer_hi,menu_cb_timeout,menu_cb_timeout_hi,menu_cb_aux,menu_cb_aux_hi; 7
   instr */

void ui_set_menu_timer_lo_251e(void)

{
  byte unaff_BSR;
  
  *(undefined1 *)((ushort)unaff_BSR * 0x100 + 0x2b) = 0;
  *(undefined1 *)((ushort)unaff_BSR * 0x100 + 0x2c) = 0;
  *(undefined1 *)((ushort)unaff_BSR * 0x100 + 0x3e) = 0;
  *(undefined1 *)((ushort)unaff_BSR * 0x100 + 0x3f) = 0;
  *(undefined1 *)((ushort)unaff_BSR * 0x100 + 0x40) = 0;
  *(undefined1 *)((ushort)unaff_BSR * 0x100 + 0x41) = 0;
  return;
}

