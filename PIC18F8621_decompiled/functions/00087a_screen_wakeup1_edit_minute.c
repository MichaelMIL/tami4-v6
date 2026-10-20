// address 0x00087a  size 32 bytes
// callers: (none: entry point, task, or reached via pointer)

/* Wake up 1: edit minute (WKUPMINUTE1) */

undefined1 screen_wakeup1_edit_minute(void)

{
  byte unaff_BSR;
  
  mod_get_clock_edit_hour_a6f2();
  ui_set_menu_timer_reload_lo_269c();
  ui_to_screen_time_edit_setup_b_2964(0x36);
  *(undefined1 *)((ushort)unaff_BSR * 0x100 + 0x36) = 100;
  *(undefined1 *)((ushort)unaff_BSR * 0x100 + 0x37) = 8;
  *(undefined1 *)((ushort)unaff_BSR * 0x100 + 0x34) = 0x6c;
  *(undefined1 *)((ushort)unaff_BSR * 0x100 + 0x35) = 8;
  return 8;
}

