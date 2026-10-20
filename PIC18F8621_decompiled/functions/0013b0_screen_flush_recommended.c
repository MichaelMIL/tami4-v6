// address 0x0013b0  size 30 bytes
// callers: (none: entry point, task, or reached via pointer)

/* "FLUSH SYSTEM RECOMMENDED" */

void screen_flush_recommended(void)

{
  byte unaff_BSR;
  
  ui_set_menu_timer_lo_2ade();
  *(undefined1 *)((ushort)unaff_BSR * 0x100 + 0x3e) = 0;
  *(undefined1 *)((ushort)unaff_BSR * 0x100 + 0x3f) = 0;
  *(undefined1 *)((ushort)unaff_BSR * 0x100 + 0x40) = 0xce;
  *(undefined1 *)((ushort)unaff_BSR * 0x100 + 0x41) = 0x13;
  menu_set_cbs_noop_b();
  ui_draw_power_down();
  ui_draw_word(0x7c);
  return;
}

