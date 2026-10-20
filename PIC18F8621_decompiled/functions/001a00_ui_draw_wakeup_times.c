// address 0x001a00  size 84 bytes
// callers: (none: entry point, task, or reached via pointer)

/* Draw wake-up 1/2 times (WKUPHOUR/WKUPMINUTE) */

void ui_draw_wakeup_times(void)

{
  BADSPACEBASE *in_FSR2;
  BADSPACEBASE *in_FSR1;
  byte bVar1;
  char cVar2;
  byte unaff_C;
  
  cVar2 = ui_frag_2b16();
  if (*(char *)((short)in_FSR2 + (short)cVar2 + 1) == '\0') {
    *(bool *)in_FSR1 = (cfg_systemconfig3 & 0x10) != 0;
    *(undefined1 *)((short)in_FSR1 + 1) = 0x37;
    bVar1 = (byte)((ushort)((short)in_FSR1 + 3) >> 8);
    *(undefined1 *)((short)in_FSR1 + 2) = 0x36;
    ui_frame_push_args_25cc();
    ui_to_menu_draw_item_line_270e(0x36);
  }
  else {
    *(bool *)in_FSR1 = (cfg_systemconfig3 & 0x20) != 0;
    *(undefined1 *)((short)in_FSR1 + 1) = 0x39;
    bVar1 = (byte)((ushort)((short)in_FSR1 + 3) >> 8);
    *(undefined1 *)((short)in_FSR1 + 2) = 0x38;
    ui_frame_push_args_25cc();
    ui_to_menu_draw_item_line_270e(0x37);
  }
  if ((unaff_C & 1) == 0) {
    *(undefined1 *)((ushort)bVar1 << 8) = *(undefined1 *)((ushort)bVar1 << 8);
  }
  ui_c18_epilogue_21d8(c18_tmp0);
  return;
}

