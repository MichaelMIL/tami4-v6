// address 0x002220  size 40 bytes
// callers: 001410,0014a6,001458,

/* "SERVICE" / "RESETTING... WAIT" */

undefined1 screen_service_resetting(void)

{
  byte unaff_BSR;
  BADSPACEBASE *in_FSR1;
  
  lcd_clear();
  ui_draw_title_word(0x34);
  *(undefined1 *)in_FSR1 = 3;
  ui_draw_word(0x59);
  ui_set_menu_timer_lo_2ade();
  *(undefined1 *)((ushort)unaff_BSR * 0x100 + 0x40) = 0xce;
  *(undefined1 *)((ushort)unaff_BSR * 0x100 + 0x41) = 0x14;
  *(undefined1 *)((ushort)unaff_BSR * 0x100 + 0x3e) = 0;
  *(undefined1 *)((ushort)unaff_BSR * 0x100 + 0x3f) = 0;
  *(undefined1 *)((ushort)unaff_BSR * 0x100 + 0x2f) = 1;
  return 1;
}

