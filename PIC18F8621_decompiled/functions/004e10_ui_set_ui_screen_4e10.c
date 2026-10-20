// address 0x004e10  size 10 bytes
// callers: 005002,00323c,002d86,

/* Auto: writes ui_screen,ui_alarm_index,ui_blink_phase; 5 instr */

undefined1 ui_set_ui_screen_4e10(undefined1 param_1)

{
  byte unaff_BSR;
  
  *(undefined1 *)((ushort)unaff_BSR * 0x100) = param_1;
  *(undefined1 *)((ushort)unaff_BSR * 0x100 + 0x1a) = 0;
  *(undefined1 *)((ushort)unaff_BSR * 0x100 + 0x1b) = 100;
  return 100;
}

