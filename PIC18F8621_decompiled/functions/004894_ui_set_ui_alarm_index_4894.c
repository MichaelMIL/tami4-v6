// address 0x004894  size 30 bytes
// callers: 00ac80,00ac9a,00ac92,00aa56,

/* Auto: writes ui_alarm_index,ui_blink_phase; reads ui_screen; 15 instr */

byte ui_set_ui_alarm_index_4894(void)

{
  if ((((ui_screen != 0xd) && (ui_screen != 9)) && (ui_screen != 0x13)) && ((ui_screen ^ 0xf) != 0))
  {
    return ui_screen ^ 0xf;
  }
  ui_alarm_index = 1;
  ui_blink_phase = 0;
  return 1;
}

