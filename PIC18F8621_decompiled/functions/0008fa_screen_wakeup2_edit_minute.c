// address 0x0008fa  size 32 bytes
// callers: (none: entry point, task, or reached via pointer)

/* Wake up 2: edit minute (WKUPMINUTE2) */

undefined1 screen_wakeup2_edit_minute(void)

{
  byte unaff_BSR;
  
  mod_get_clock_edit_hour_a6f2();
  ui_set_menu_timer_reload_lo_269c();
  ui_to_screen_time_edit_setup_b_2964(0x38);
  *(undefined1 *)((ushort)unaff_BSR * 0x100 + 0x36) = 0xe4;
  *(undefined1 *)((ushort)unaff_BSR * 0x100 + 0x37) = 8;
  *(undefined1 *)((ushort)unaff_BSR * 0x100 + 0x34) = 0xec;
  *(undefined1 *)((ushort)unaff_BSR * 0x100 + 0x35) = 8;
  return 8;
}

